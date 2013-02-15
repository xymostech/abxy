#ifndef GL_HPP
#define GL_HPP

// Use OpenGL 3
#ifdef __APPLE__
#define GLFW_INCLUDE_GL3
#else
#include <GL/glew.h>
#endif
// Don't include GLU
#define GLFW_NO_GLU
#include <GL/glfw.h>

// Mac's extensions
#ifdef __APPLE__
#include <OpenGL/gl3ext.h>
#endif

#endif /* GL_HPP */

