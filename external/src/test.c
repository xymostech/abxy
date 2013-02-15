#include <stdio.h>

#include <GL/glew.h>

#ifdef __APPLE__
#define GLFW_INCLUDE_GL3
#endif

#define GLFW_NO_GLU

#include <GL/glfw.h>

int main(int argc, char *argv[]) {
	if (glfwInit() != GL_TRUE) {
		fprintf(stderr, "Error initializing glfw\n");
		return 1;
	}

	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3);
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 1);
	glfwOpenWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	if (glfwOpenWindow(0, 0, 0, 0, 0, 0, 0, 0, GLFW_WINDOW) != GL_TRUE) {
		fprintf(stderr, "Error opening a window\n");
		glfwTerminate();
		return 1;
	}

	glewExperimental = GL_TRUE;

	GLenum err = glewInit();
	if (GLEW_OK != err) {
		fprintf(stderr, "Error loading glew: %s\n", glewGetErrorString(err));
	}

	fprintf(stdout, "Opened successfully!\n");
	fprintf(stdout, "OpenGL Version %s\n", glGetString(GL_VERSION));
	fprintf(stdout, "GLEW Version %s\n", glewGetString(GLEW_VERSION));

	GLuint vertex_array;

	glGenVertexArrays(1, &vertex_array);

	glfwCloseWindow();
	glfwTerminate();
	return 0;
}
