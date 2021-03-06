#include <abxy/loader/PngLoader.hpp>

#include <stdexcept>

void PngLoader::ReadData(png_structp pngPtr, png_bytep data, png_size_t length) {
	png_voidp in = png_get_io_ptr(pngPtr);
	((std::istream*)in)->read((char *)data, length);
}

void PngLoader::Load(std::istream &in) {
	png_byte header[8];
	in.read((char *)header, 8);
	if(png_sig_cmp(header, 0, 8)) {
		throw std::exception();
	}

	png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if(!png_ptr) {
		throw std::exception();
	}

	png_infop info_ptr = png_create_info_struct(png_ptr);
	if(!info_ptr) {
		png_destroy_read_struct(&png_ptr, NULL, NULL);
		throw std::exception();
	}

	png_infop end_ptr = png_create_info_struct(png_ptr);
	if(!end_ptr) {
		png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
		throw std::exception();
	}

	if(setjmp(png_jmpbuf(png_ptr))) {
		png_destroy_read_struct(&png_ptr, &info_ptr, &end_ptr);
		throw std::exception();
	}

	png_set_read_fn(png_ptr, (png_voidp)&in, ReadData);
	png_set_sig_bytes(png_ptr, 8);

	png_read_info(png_ptr, info_ptr);

	int bit_depth = png_get_bit_depth(png_ptr, info_ptr);

	switch(png_get_color_type(png_ptr, info_ptr)) {
		case PNG_COLOR_TYPE_PALETTE:
			png_set_palette_to_rgb(png_ptr);
			png_set_filler(png_ptr, 0xff, PNG_FILLER_AFTER);
			break;
		case PNG_COLOR_TYPE_GRAY:
			png_set_filler(png_ptr, 0xff, PNG_FILLER_AFTER);
		case PNG_COLOR_TYPE_GRAY_ALPHA:
			if(bit_depth < 8) png_set_expand_gray_1_2_4_to_8(png_ptr);
			if(bit_depth==16) png_set_strip_16(png_ptr);
			png_set_gray_to_rgb(png_ptr);
			break;
		case PNG_COLOR_TYPE_RGB:
			if(bit_depth <  8 ) png_set_packing(png_ptr);
			if(bit_depth == 16) png_set_strip_16(png_ptr);
			png_set_filler(png_ptr, 0xff, PNG_FILLER_AFTER);
			break;
		default:
			break;
	}

	png_read_update_info(png_ptr, info_ptr);

	int w = png_get_image_width(png_ptr, info_ptr);
	int h = png_get_image_height(png_ptr, info_ptr);
	int rowbytes = (int)png_get_rowbytes(png_ptr, info_ptr);

	data.resize(h * rowbytes * sizeof(png_bytep));

	png_bytep row_pointers[h];

	for(int i = 0; i < h; ++i) {
		row_pointers[i] = &data[i * rowbytes];
	}

	png_read_image(png_ptr, row_pointers);

	png_destroy_read_struct(&png_ptr, &info_ptr, &end_ptr);

	SetSize(w, h);
}

PngLoader::PngLoader(std::string filename) {
	Load(filename);
}

void PngLoader::Load(std::string filename) {
	std::ifstream f(filename.c_str());

	if (f.is_open()) {
		try {
			Load(f);
		} catch (std::exception &ex) {
			throw std::runtime_error("Error loading: " + filename);
		}
	} else {
		throw std::runtime_error("Error loading: " + filename);
	}
}

