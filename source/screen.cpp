namespace curses {
#include <curses.h>
}

#include "screen.h"

namespace cge {

void Screen::resetCursor()
{
    this->move(cursorPosition);
}


Screen::Screen(Point startCursorPos)
{
    curses::initscr();
    this->move(startCursorPos);
}


Screen::~Screen()
{
    curses::endwin();
}


void Screen::write(CString towrite)
{
    curses::printw(towrite);
}

void Screen::write(CString towrite, Point position)
{
    this->move(position);
    curses::printw(towrite);
    this->resetCursor();
}


void Screen::writenow(CString towrite)
{
    write(towrite);
    display();
}


void Screen::writenow(CString towrite, Point position)
{
    write(towrite, position);
    display();
}


void Screen::move(Point position)
{
    curses::move(position.x, position.y);
}


void Screen::display()
{
    curses::refresh();
}

} // namespace cge
