#ifndef APP_HPP
#define APP_HPP

#include <abxy/GL/GL.hpp>

class App {
public:
	virtual ~App();

	virtual void Startup();
	virtual void Shutdown();

	virtual bool IsOpen();

	virtual void Update();
	virtual void Draw();
};

#endif /* APP_HPP */

