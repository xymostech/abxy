#ifndef IMAGEDATALOADER_HPP
#define IMAGEDATALOADER_HPP

#include <abxy/loader/BinaryDataLoader.hpp>

class ImageDataLoader : public BinaryDataLoader<unsigned char> {
	int w, h;
protected:
	void SetSize(int neww, int newh);
public:
	ImageDataLoader();

	void GetSize(int *setw, int *seth);
};

#endif /* IMAGEDATALOADER_HPP */

