#ifndef IMAGEDATALOADER_HPP
#define IMAGEDATALOADER_HPP

#include <gamelib/BinaryDataLoader.inl>

class ImageDataLoader : public BinaryDataLoader<unsigned char> {
	int w, h;
protected:
	void SetSize(int neww, int newh);
public:
	ImageDataLoader();

	void GetSize(int *setw, int *seth);
};

#endif /* IMAGEDATALOADER_HPP */

