#ifndef RESOURCELOADER_INL
#define RESOURCELOADER_INL

#include <gamelib/ResourceLoader.hpp>

ResourceLoader::ResourceLoader(Perspective &perspective)
: perspective(perspective)
{
	
}

std::shared_ptr<GLProgram> ResourceLoader::GetGLProgram(std::string name) {
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

std::shared_ptr<Texture> ResourceLoader::GetTexture(std::string name) {
	if (textures.count(name) == 0) {
		std::shared_ptr<Texture> t(new Texture(name));
		textures[name] = t;
	}
	return textures[name];
}

#endif /* RESOURCELOADER_INL */

