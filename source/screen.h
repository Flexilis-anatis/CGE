#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

namespace cge {

class Screen
{
    struct Point {unsigned short y,x;} cursorPosition;

    void resetCursor();

    typedef const char* CString;

public:
    Screen(Point startCursorPos = {0, 0});
    ~Screen();

    void write(CString towrite);
    void write(CString Point position);

    void writenow(CString towrite);
    void writenow(CString towrite, Point position);

    void move(Point position);
    void display();
};

} // namespace cge

#endif /* end of include guard: SCREEN_H_INCLUDED */
