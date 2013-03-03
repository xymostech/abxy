#ifndef APP_HPP
#define APP_HPP

#include <abxy/GL/GL.hpp>

class App {
public:
	App();
	virtual ~App();

	virtual void Startup();
	void Shutdown();

	virtual bool IsOpen();

	virtual void Update();
	virtual void Draw() const;
};

#endif /* APP_HPP */

