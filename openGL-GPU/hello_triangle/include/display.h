#ifndef TRI_H
#define TRI_H
#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <functional>
#include <iostream>
#include <memory>
#include <string>
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
typedef void (*GLFW_cb_t)(GLFWwindow*, int, int);
struct glfwDeleter {
	void operator()(GLFWwindow* wnd)
	{
		std::cout << "Destroying GLFW Window Context" << std::endl;
		glfwDestroyWindow(wnd);
	}
};
// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// -----------------------------------------------------------------------------------------
class Display {
   public:
	void create_window(int width, int height, std::string window_title, int openGLMinVersion, int openGLMaxVersion, bool resizeable);
	void set_clear_color(float r, float g, float b);
	void update_window();
	void process_input();
	void set_resize_cb(GLFW_cb_t func);
	void poll_events() const;
	bool is_closing() const;
	void close() const;
	~Display();

   private:
	std::unique_ptr<GLFWwindow, glfwDeleter> window;
	float clearR = 1.0f, clearG = 1.0f, clearB = 1.0f, clearA = 1.0f;
};
#endif