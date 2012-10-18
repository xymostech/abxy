#ifndef IMAGEDATALOADER_HPP
#define IMAGEDATALOADER_HPP

#include <gamelib/BinaryDataLoader.hpp>

class ImageDataLoader : public BinaryDataLoader<unsigned char> {
	int w, h;
protected:
	void SetSize(int neww, int newh) {
		if (w < 0) {
			w = neww;
			h = newh;
		}
	}
public:
	ImageDataLoader()
	: w(-1)
	, h(-1)
	{
		
	}

	void GetSize(int *setw, int *seth) {
		*setw = w;
		*seth = h;
	}
};

#endif /* IMAGEDATALOADER_HPP */

