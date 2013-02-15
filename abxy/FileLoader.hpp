#ifndef FILELOADER_HPP
#define FILELOADER_HPP

#include <string>

#include <abxy/BinaryDataLoader.hpp>

class FileLoader : public BinaryDataLoader<char> {
	void Load(std::string file);
public:
	FileLoader(std::string file);
};

#endif /* FILELOADER_HPP */

