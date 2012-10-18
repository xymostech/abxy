#ifndef FILE_HPP
#define FILE_HPP

#include <iostream>

namespace File {
	std::string Read(std::string filename) {
		std::ifstream f(filename.c_str(), std::ios::binary);

		if (!f.is_open()) {
			throw std::runtime_error("Error opening file: " + filename);
		}

		std::stringstream buffer;
		buffer << f.rdbuf();
		return buffer.str();
	}
}

#endif /* FILE_HPP */

