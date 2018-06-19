namespace curses {
#include <curses.h>
}

#include "screen.h"

namespace cge {

Screen::Screen(Point startCursorPos)
{
    curses::initscr();
    this->move(startCursorPos);
}


~Screen::Screen()
{
    curses::endwin();
}


template<typename StringType>
void Screen::write(StringType towrite)
{
    curses::printw(towrite);
}

template<typename StringType>
void Screen::write(StringType towrite, Point position)
{
    this->move(position);
    curses::printw(towrite);
    curses::move(cursorPosition.x, cursorPosition.y);
}


void Screen::move(Point position)
{
    cursorPosition = position;
    this->move(cursorPosition.x, cursorPositon.y);
}


void Screen::display()
{
    curses::refresh();
}

} // namespace cge
