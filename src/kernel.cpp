#include "../include/keyboard.h"
#include "../include/frame_buffer.h"

typedef void (*ctor)();
extern "C" ctor begin_constructors;
extern "C" ctor end_constructors;
extern "C" void call_ctors()
{
	for (ctor *i = &begin_constructors; i != &end_constructors; i++)
	{
		(*i)();
	}
}

extern void mouse_install();

extern "C" void k_main(const void *multiboot_structure, unsigned int multiboot_magic)
{
	FrameBuffer::Writer p(FrameBuffer::Colours::WHITE, FrameBuffer::Colours::BLACK);

	// p.writeString("\n\n\n\n\n\n");
	// p.writeString("       \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\n");
	// p.writeString("       \b  \b\b\b\b  \b\b\b\b\b\b\b\b\b  \b\b\b\b\b\b\b\b\b  \b\b\b\b\b\b\b\b\b\b\b    \b\b\b\b\b      \b\b\n");
	// p.writeString("       \b  \b\b\b\b  \b\b\b\b\b\b\b\b\b  \b\b\b\b\b\b\b\b\b  \b\b\b\b\b\b\b\b\b\b  \b\b  \b\b\b  \b\b\b\b  \b\n");
	// p.writeString("       \b  \b\b\b\b  \b\b\b\b\b\b\b\b\b  \b\b\b\b\b\b\b\b\b  \b\b\b\b\b\b\b\b\b  \b\b\b\b  \b\b  \b\b\b\b  \b\n");
	// p.writeString("       \b  \b\b\b\b  \b\b\b   \b\b\b  \b\b  \b\b\b\b\b  \b\b\b   \b\b\b  \b\b\b\b  \b\b\b  \b\b\b\b\b\b\n");
	// p.writeString("       \b        \b\b  \b  \b\b  \b\b\b\b\b\b\b    \b\b  \b  \b\b  \b\b\b\b  \b\b\b\b\b  \b\b\b\b\n");
	// p.writeString("       \b  \b\b\b\b  \b\b\b\b\b  \b\b  \b\b  \b\b  \b  \b\b     \b\b  \b\b\b\b  \b\b\b\b\b\b\b  \b\b\n");
	// p.writeString("       \b  \b\b\b\b  \b\b\b    \b\b  \b\b  \b\b  \b  \b\b  \b\b\b\b\b  \b\b\b\b  \b\b  \b\b\b\b  \b\n");
	// p.writeString("       \b  \b\b\b\b  \b\b  \b  \b\b  \b\b  \b\b  \b  \b\b  \b  \b\b\b  \b\b  \b\b\b  \b\b\b\b  \b\n");
	// p.writeString("       \b  \b\b\b\b  \b\b\b    \b\b  \b\b  \b\b\b    \b\b\b   \b\b\b\b\b    \b\b\b\b\b      \b\b\n");
	// p.writeString("       \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\n");

	p.writeString("\n\n\n\n\n\n");
	p.writeString("       \f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\n");
	p.writeString("       \f  \f\f\f\f  \f\f\f\f\f\f\f\f\f  \f\f\f\f\f\f\f\f\f  \f\f\f\f\f\f\f\f\f\f\f    \f\f\f\f\f      \f\f\n");
	p.writeString("       \f  \f\f\f\f  \f\f\f\f\f\f\f\f\f  \f\f\f\f\f\f\f\f\f  \f\f\f\f\f\f\f\f\f\f  \f\f  \f\f\f  \f\f\f\f  \f\n");
	p.writeString("       \f  \f\f\f\f  \f\f\f\f\f\f\f\f\f  \f\f\f\f\f\f\f\f\f  \f\f\f\f\f\f\f\f\f  \f\f\f\f  \f\f  \f\f\f\f  \f\n");
	p.writeString("       \f  \f\f\f\f  \f\f\f   \f\f\f  \f\f  \f\f\f\f\f  \f\f\f   \f\f\f  \f\f\f\f  \f\f\f  \f\f\f\f\f\f\n");
	p.writeString("       \f        \f\f  \f  \f\f  \f\f\f\f\f\f\f    \f\f  \f  \f\f  \f\f\f\f  \f\f\f\f\f  \f\f\f\f\n");
	p.writeString("       \f  \f\f\f\f  \f\f\f\f\f  \f\f  \f\f  \f\f  \f  \f\f     \f\f  \f\f\f\f  \f\f\f\f\f\f\f  \f\f\n");
	p.writeString("       \f  \f\f\f\f  \f\f\f    \f\f  \f\f  \f\f  \f  \f\f  \f\f\f\f\f  \f\f\f\f  \f\f  \f\f\f\f  \f\n");
	p.writeString("       \f  \f\f\f\f  \f\f  \f  \f\f  \f\f  \f\f  \f  \f\f  \f  \f\f\f  \f\f  \f\f\f  \f\f\f\f  \f\n");
	p.writeString("       \f  \f\f\f\f  \f\f\f    \f\f  \f\f  \f\f\f    \f\f\f   \f\f\f\f\f    \f\f\f\f\f      \f\f\n");
	p.writeString("       \f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\n");

	KEYBOARD_DRIVER::readInput(p);

	while (1)
		;
}
