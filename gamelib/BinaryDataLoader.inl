#ifndef BINARYDATALOADER_INL
#define BINARYDATALOADER_INL

#include <gamelib/BinaryDataLoader.hpp>

template <typename data_type>
void BinaryDataLoader<data_type>::SetData(data_type *newdata) {
	if (data == NULL) {
		data = newdata;
	}
}

template <typename data_type>
BinaryDataLoader<data_type>::BinaryDataLoader()
: data(NULL)
{
	
}

template <typename data_type>
BinaryDataLoader<data_type>::~BinaryDataLoader() {
	if (data) {
		delete[] data;
	}
}

template <typename data_type>
data_type const *BinaryDataLoader<data_type>::GetData() {
	return data;
}

#endif /* BINARYDATALOADER_INL */

