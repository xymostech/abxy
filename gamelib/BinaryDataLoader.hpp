#ifndef BINARYDATALOADER_HPP
#define BINARYDATALOADER_HPP

#include <string>
#include <fstream>
#include <vector>

template <typename data_type>
class BinaryDataLoader {
	std::vector<data_type> data;
protected:
	std::vector<data_type> &GetData();
public:
	const std::vector<data_type> &GetConstData() const;
};

#include <gamelib/BinaryDataLoader.inl>

#endif /* BINARYDATALOADER_HPP */

