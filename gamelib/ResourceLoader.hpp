#ifndef RESOURCELOADER_HPP
#define RESOURCELOADER_HPP

#include <iostream>
#include <map>
#include <memory>

#include <gamelib/GL/GLProgram.hpp>
#include <gamelib/Texture.hpp>
#include <gamelib/Perspective.hpp>

class ResourceLoader {
	std::map<std::string, std::shared_ptr<GLProgram>> gl_programs;
	std::map<std::string, std::shared_ptr<Texture>> textures;
	Perspective &perspective;
public:
	ResourceLoader(Perspective &perspective)
	: perspective(perspective)
	{
		
	}

	std::shared_ptr<GLProgram> GetGLProgram(std::string name) {
		try {
			if (gl_programs.count(name) == 0) {
				std::shared_ptr<GLProgram> p(
					new GLProgram(name + ".vertex.shader",
						      name + ".fragment.shader")
				);
				p->Setup(perspective);
				gl_programs[name] = p;
			}
			return gl_programs[name];
		} catch (std::exception &e) {
			std::cout << "Error loading GLProgram: " << e.what() << std::endl;
			throw e;
		}
	}

	std::shared_ptr<Texture> GetTexture(std::string name) {
		if (textures.count(name) == 0) {
			std::shared_ptr<Texture> t(new Texture(name));
			textures[name] = t;
		}
		return textures[name];
	}
};

#endif /* RESOURCELOADER_HPP */

