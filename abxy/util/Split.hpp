#ifndef SPLIT_HPP
#define SPLIT_HPP

#include <string>
#include <vector>

namespace Util {

	std::vector<std::string> &Split(const std::string &s,
	                                std::vector<std::string> &elems,
	                                char delim = ' ');

}

#endif /* SPLIT_HPP */

