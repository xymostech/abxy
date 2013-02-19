#include <abxy/loader/LoaderCache.hpp>

void LoaderCache::SetCache(LoaderCache *set_cache) {
	cache = set_cache;
}

bool LoaderCache::HasTextureLoaded(std::string name) {
	if (cache && cache->HasTextureLoaded(name)) {
		return true;
	} else {
		return loader.GetTextureLoader()->HasLoaded(name);
	}
}

bool LoaderCache::HasProgramLoaded(std::string name) {
	if (cache && cache->HasProgramLoaded(name)) {
		return true;
	} else {
		return loader.GetProgramLoader()->HasLoaded(name);
	}
}

bool LoaderCache::HasFontLoaded(std::string name) {
	if (cache && cache->HasFontLoaded(name)) {
		return true;
	} else {
		return loader.GetFontLoader()->HasLoaded(name);
	}
}

bool LoaderCache::HasSoundLoaded(std::string name) {
	if (cache && cache->HasSoundLoaded(name)) {
		return true;
	} else {
		return loader.GetSoundLoader()->HasLoaded(name);
	}
}

bool LoaderCache::HasVertexShaderLoaded(std::string name) {
	if (cache && cache->HasVertexShaderLoaded(name)) {
		return true;
	} else {
		return loader.GetVertexShaderLoader()->HasLoaded(name);
	}
}

bool LoaderCache::HasFragmentShaderLoaded(std::string name) {
	if (cache && cache->HasFragmentShaderLoaded(name)) {
		return true;
	} else {
		return loader.GetFragmentShaderLoader()->HasLoaded(name);
	}
}

std::shared_ptr<Texture> LoaderCache::LoadTexture(std::string name) {
	if (cache && cache->HasTextureLoaded(name)) {
		return cache->LoadTexture(name);
	} else {
		return loader.GetTextureLoader()->Load(name);
	}
}

std::shared_ptr<GLProgram> LoaderCache::LoadProgram(std::string name) {
	if (cache && cache->HasProgramLoaded(name)) {
		return cache->LoadProgram(name);
	} else {
		return loader.GetProgramLoader()->Load(name);
	}
}

std::shared_ptr<Font> LoaderCache::LoadFont(std::string name) {
	if (cache && cache->HasFontLoaded(name)) {
		return cache->LoadFont(name);
	} else {
		return loader.GetFontLoader()->Load(name);
	}
}

std::shared_ptr<Sound> LoaderCache::LoadSound(std::string name) {
	if (cache && cache->HasSoundLoaded(name)) {
		return cache->LoadSound(name);
	} else {
		return loader.GetSoundLoader()->Load(name);
	}
}

std::shared_ptr<GLShader> LoaderCache::LoadVertexShader(std::string name) {
	if (cache && cache->HasVertexShaderLoaded(name)) {
		return cache->LoadVertexShader(name);
	} else {
		return loader.GetVertexShaderLoader()->Load(name);
	}
}

std::shared_ptr<GLShader> LoaderCache::LoadFragmentShader(std::string name) {
	if (cache && cache->HasFragmentShaderLoaded(name)) {
		return cache->LoadFragmentShader(name);
	} else {
		return loader.GetFragmentShaderLoader()->Load(name);
	}
}

