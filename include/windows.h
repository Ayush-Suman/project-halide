#ifndef __WINDOWS_H
#define __WINDOWS_H

/*
 ^ Overview of class window
 ^ has 4 coords and one title thats it
*/
class Window {
public:
	int m_x1, m_x2, m_y1, m_y2;
	char *m_title;
	Window() : m_x1(0), m_x2(80), m_y1(0), m_y2(25), m_title((char *)"HALIDE OS v.0.1") {}
	Window(int x1, int x2, int y1, int y2, char *title) : m_x1(x1), m_x2(x2), m_y1(y1), m_y2(y2), m_title(title) {}
};

#endif