#include <console.h>
#include <halidestdlib.h>
static void writeString_man(FrameBuffer::Writer &);

int init_console(FrameBuffer::Writer &p, Window &win) {
	p.writeString("Now running console instance : \n");
	/* p.writeString("root", (string)0x76);
	p.writeString("@", (string)0x0a);
	p.writeString("night_os ", (string)0x0a); */
	unsigned int loop = 1;
	int _id = 0;
	char *command;
	while (loop) {

		p.writeString("");
		p.writeString("root", FrameBuffer::Colours::BLACK);
		p.writeString("@");
		p.writeString("halideOS $ ");

		command = KEYBOARD_DRIVER::readInput(p);

		if (hldstd::stringCompare(command, "help")) {
			writeString_man(p);
		} else if (hldstd::stringCompare(command, "clear")) {
			p.clearLine(win.m_y1 + 1, win.m_y2 - 1);
		} else if (hldstd::stringCompare(command, "switch console")) {
			p.writeString("switchched console\n");
			p.clearLine(win.m_y1 + 1, win.m_y2 - 1); // Use this line of code till we impliment local state storage
			_id = 1;
			loop = 0;
			break;
		} else if (hldstd::stringCompare(command, "greet")) {
			p.writeString("Hello World\n");
		} else if (hldstd::stringCompare(command, "exit")) {
			loop = 0;
		} else {
			p.writeString("Invalid command\n"); // For info on how to set color codes please visit that website
		}
	}
	p.writeString("Exiting console\n");
	return _id;
}

inline void writeString_man(FrameBuffer::Writer &p) {
	// ! Add new line protectors if man creates window over flow
	p.writeString("List of commands :\ngreet\nclear\nswitch console\nexit\n", FrameBuffer::Colours::BLACK);
}