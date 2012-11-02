#ifndef RESOURCELOADER_HPP
#define RESOURCELOADER_HPP

#include <iostream>
#include <map>
#include <memory>

#include <gamelib/GL/GLProgram.inl>
#include <gamelib/Texture.inl>
#include <gamelib/Perspective.inl>

class ResourceLoader {
	std::map<std::string, std::shared_ptr<GLProgram>> gl_programs;
	std::map<std::string, std::shared_ptr<Texture>> textures;
	Perspective &perspective;
public:
	ResourceLoader(Perspective &perspective);

	std::shared_ptr<GLProgram> GetGLProgram(std::string name);
	std::shared_ptr<Texture> GetTexture(std::string name);
};

#endif /* RESOURCELOADER_HPP */

