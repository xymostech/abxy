#ifndef FILELOADER_HPP
#define FILELOADER_HPP

#include <string>

#include <abxy/loader/BinaryDataLoader.hpp>

class FileLoader : public BinaryDataLoader<char> {
	void Load(std::string file);
public:
	FileLoader(std::string file);
};

#endif /* FILELOADER_HPP */

