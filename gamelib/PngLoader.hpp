#ifndef PNGLOADER_HPP
#define PNGLOADER_HPP

#include <iostream>
#include <fstream>
#include <string>

#include <libpng15/png.h>

#include <gamelib/Exceptions.inl>
#include <gamelib/ImageDataLoader.inl>

class PngLoader : public ImageDataLoader {
	static void ReadData(png_structp pngPtr, png_bytep data, png_size_t length);
	void Load(std::istream &in);
public:
	PngLoader();
	PngLoader(std::string filename);
	virtual ~PngLoader();

	void Load(std::string filename);
};

#endif /* PNGLOADER_HPP */

