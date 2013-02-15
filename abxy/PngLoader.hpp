#ifndef PNGLOADER_HPP
#define PNGLOADER_HPP

#include <iostream>
#include <fstream>
#include <string>

#include <libpng15/png.h>

#include <abxy/Exceptions.hpp>
#include <abxy/ImageDataLoader.hpp>

class PngLoader : public ImageDataLoader {
	static void ReadData(png_structp pngPtr, png_bytep data, png_size_t length);
	void Load(std::istream &in);
public:
	PngLoader(std::string filename);

	void Load(std::string filename);
};

#endif /* PNGLOADER_HPP */

