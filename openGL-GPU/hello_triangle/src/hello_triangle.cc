#include "display.h"
// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
int main()
{
	Display display;
	/* GL clear color in RGB*/
	display.set_clear_color(100, 100, 100);
	/*create window object*/
	display.create_window(SCR_WIDTH, SCR_HEIGHT, "openGL", 3, 3, GL_FALSE);
	display.set_resize_cb(framebuffer_size_callback);
	while (!display.is_closing()) {
		display.process_input();
		display.update_window();
		display.poll_events();
	}
	display.close();
	return 0;
}
