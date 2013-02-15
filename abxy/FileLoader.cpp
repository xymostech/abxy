#include <abxy/FileLoader.hpp>

#include <iterator>
#include <fstream>

void FileLoader::Load(std::string file) {
	std::ifstream f(file, std::ios::binary);

	f.seekg(0, std::ios::end);
	size_t size = f.tellg();
	f.seekg(0, std::ios::beg);
	
	data.reserve(size);
	data.assign(std::istreambuf_iterator<char>(f),
	            std::istreambuf_iterator<char>());
}

FileLoader::FileLoader(std::string file) {
	Load(file);
}

