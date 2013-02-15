#ifndef BINARYDATALOADER_HPP
#define BINARYDATALOADER_HPP

#include <vector>

template <typename data_type>
class BinaryDataLoader {
protected:
	std::vector<data_type> data;
public:
	const std::vector<data_type> &GetData() const;
};

#include <abxy/BinaryDataLoader.inl>

#endif /* BINARYDATALOADER_HPP */

