#include <abxy/loader/ProgramLoader.hpp>

#include <fstream>
#include <string>

#include <abxy/util/Path.hpp>

GLProgram *ProgramLoader::GetResource(std::string name) {
	std::ifstream program_file(name);
	std::string line;

	std::string base_path = Util::GetDirectory(name);

	std::vector<std::shared_ptr<GLShader>> shaders;

	while (std::getline(program_file, line)) {
		auto pos = line.find_first_of(" ");

		std::string shader_type = line.substr(0, pos);
		std::string shader_file = line.substr(pos + 1);

		if (shader_file[0] != '/' && shader_file[0] != '\\') {
			shader_file = base_path + shader_file;
		}
		std::shared_ptr<GLShader> shader;

		if (shader_type == "vertex") {
			shader = loader_cache->LoadVertexShader(shader_file);
		} else {
			shader = loader_cache->LoadFragmentShader(shader_file);
		}

		shaders.push_back(shader);
	}

	GLProgram *p = new GLProgram(shaders);
	return p;
}

void ProgramLoader::SetLoader(LoaderCache *loader) {
	loader_cache = loader;
}
