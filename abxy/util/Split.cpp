#include <abxy/util/Split.hpp>

#include <sstream>

namespace Util {

	std::vector<std::string> &Split(const std::string &s,
	                                std::vector<std::string> &elems,
	                                char delim) {
		std::stringstream ss(s);
		std::string item;
		while (std::getline(ss, item, delim)) {
			elems.push_back(item);
		}
		return elems;
	}

}
