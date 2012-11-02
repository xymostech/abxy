#ifndef BINARYDATALOADER_INL
#define BINARYDATALOADER_INL

#include <gamelib/BinaryDataLoader.hpp>

template <typename data_type>
const std::vector<data_type> &BinaryDataLoader<data_type>::GetData() const {
	return data;
}

#endif /* BINARYDATALOADER_INL */

