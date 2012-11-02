#ifndef BINARYDATALOADER_HPP
#define BINARYDATALOADER_HPP

#include <string>
#include <fstream>

template <typename data_type>
class BinaryDataLoader {
	data_type *data;
protected:
	void SetData(data_type *newdata);
public:
	BinaryDataLoader();
	virtual ~BinaryDataLoader();

	data_type const *GetData();
};

#include <gamelib/BinaryDataLoader.inl>

#endif /* BINARYDATALOADER_HPP */

