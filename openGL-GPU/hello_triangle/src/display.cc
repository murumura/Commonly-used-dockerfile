#include "display.h"
void Display::create_window(int width, int height, std::string window_title,
                            int openGLMinVersion, int openGLMaxVersion, bool resizeable)
{
	glfwInit();
	//glfw settings
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, openGLMaxVersion);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, openGLMinVersion);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_RESIZABLE, resizeable);
	/*unique_ptr :reset():replaces the managed object*/
	this->window.reset(glfwCreateWindow(width, height, window_title.c_str(), nullptr, nullptr));
	/*unique_ptr :get():returns a pointer to the managed object*/
	glfwMakeContextCurrent(this->window.get());
	/*check if we have a pointer to the window*/
	if (this->window == nullptr) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}
	//load all openGL function pointer
	GLADloadproc loader = reinterpret_cast<GLADloadproc>(glfwGetProcAddress);
	if (!gladLoadGLLoader(loader)) {
		std::cerr << "failed to load proc address" << std::endl;
	}

	//Setup the OpenGL Viewport
	glViewport(0, 0, width, height);
}
void Display::set_clear_color(float r, float g, float b)
{
	this->clearR = r / 255.0;
	this->clearG = g / 255.0;
	this->clearB = b / 255.0;
	this->clearA = r / 255.0;
}
void Display::update_window()
{
	glClearColor(clearR, clearG, clearB, clearA);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(this->window.get());
}
void Display::poll_events() const
{
	/** 
	 * checks if any events are triggered (like keyboard input or mouse movement events),
	 * updates the window state, and calls the corresponding functions
	*/
	glfwPollEvents();
}
void Display::process_input()
{
	if (glfwGetKey(this->window.get(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(this->window.get(), true);
}
bool Display::is_closing() const
{
	return glfwWindowShouldClose(this->window.get());
}
void Display::close() const
{
	glfwTerminate();
}
Display::~Display()
{
	std::cout << "Display Closing" << std::endl;
}
void Display::set_resize_cb(GLFW_cb_t func)
{
	glfwSetFramebufferSizeCallback(this->window.get(), func);
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}