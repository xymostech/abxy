#include "Model.hpp"

#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

namespace {
	template <typename T>
	bool FromString(const std::string &s, T &t) {
		std::istringstream ss(s);

		ss >> t;

		return !ss.fail();
	}
}

Model::Model(std::string model_file) {
	std::vector<std::string> tokens = GetTokens(model_file);

	token_iterator it = tokens.cbegin(), end = tokens.cend();

	try {
		while (it != end) {
			objects.push_back(ReadObject(it));
		}
	} catch (std::exception &e) {
		throw std::runtime_error(
			"Error loading file: " + model_file +
			": " + e.what()
		);
	}

	for (const Object &o : objects) {
		prims.emplace_back(MakePrimitive(o));
	}
}

Primitive Model::MakePrimitive(const Object &o) {
	Primitive prim("res/standard.program");

	prim.AddAttrib("position", 4, o.verts);
	prim.AddAttrib("color", 4, o.colors);

	prim.AddIndices(o.indices);

	return prim;
}

Model::Object Model::ReadObject(token_iterator &it) {
	if (*it != "object") {
		throw std::runtime_error("Error reading object, expected 'object'");
	}

	Object o;

	it++;
	o.name = *it;
	it++;

	if (*it != "{") {
		throw std::runtime_error("Error reading object, expected '{'");
	}
	it++;

	while (*it != "}") {
		if (*it == "attrib") {
			o.attribs.push_back(ReadAttrib(it));
		} else if (*it == "indices") {
			o.indices = ReadIndices(it);
		} else {
			throw std::runtime_error("Error, invalid type: " + *it);
		}
	}
	it++;

	return o;
}

Model::Object::AttribData Model::ReadAttrib(token_iterator &it) {
	if (*it != "attrib") {
		throw std::runtime_error("Error reading attrib, expected 'attrib'");
	}
	it++;

	Object::AttribData attrib;
	attrib.name = *it;
	it++;

	if (!FromString<int>(*it, attrib.size)) {
		throw std::runtime_error("Error reading attrib '" + attrib.name + "', expected integral size");
	}
	it++;

	if (*it != "{") {
		throw std::runtime_error("Error reading attrib '" + attrib.name + "', expected '{'");
	}
	it++;

	while (*it != "}") {
		float f;
		if (!FromString<float>(*it, f)) {
			throw std::runtime_error("Error reading float in attrib '" + attrib.name + "'");
		}
		attrib.data.push_back(f);
		it++;
	}
	it++;

	return attrib;
}

std::vector<unsigned int> Model::ReadIndices(token_iterator &it) {
	if (*it != "indices") {
		throw std::runtime_error(
			"Error reading indices, expected 'indices'"
		);
	}
	it++;
	if (*it != "{") {
		throw std::runtime_error("Error reading indices, expected '{'");
	}
	it++;

	std::vector<unsigned int> indices;

	while (*it != "}") {
		unsigned int u;
		if (!FromString<unsigned int>(*it, u)) {
			throw std::runtime_error("Error reading int in indices");
		}
		indices.push_back(u);
		it++;
	}
	it++;

	return indices;
}

std::vector<std::string> Model::GetTokens(std::string file) {
	std::ifstream fin(file);

	std::vector<std::string> tokens;

	std::string line;

	while (fin.good()) {
		std::getline(fin, line);

		if (line.length() == 0 || line.at(0) == '#') {
			continue;
		}

		std::istringstream ss(line);
		std::string token;

		while (ss.good()) {
			ss >> token;
			tokens.emplace_back(token);
		}
	}

	return tokens;
}

void Model::OnLoad(LoadData &data) {
	for (Primitive &prim : prims) {
		prim.OnLoad(data);
	}
}

void Model::OnUnload() {
	for (Primitive &prim : prims) {
		prim.OnUnload();
	}
}

void Model::Draw(Matrix4 model_matrix) const {
	for (const Primitive &prim : prims) {
		prim.DrawAll(model_matrix);
	}
}
