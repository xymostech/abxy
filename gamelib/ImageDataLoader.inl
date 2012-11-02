#ifndef IMAGEDATALOADER_INL
#define IMAGEDATALOADER_INL

#include <gamelib/ImageDataLoader.hpp>

void ImageDataLoader::SetSize(int neww, int newh) {
	if (w < 0) {
		w = neww;
		h = newh;
	}
}

ImageDataLoader::ImageDataLoader()
: w(-1)
, h(-1)
{
	
}

void ImageDataLoader::GetSize(int *setw, int *seth) {
	*setw = w;
	*seth = h;
}

#endif /* IMAGEDATALOADER_INL */

