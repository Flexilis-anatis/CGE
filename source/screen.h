#pragma once


namespace cge {

class Screen
{
    struct Point {unsigned short y, x;};

    Point cursorPosition;

public:
    Screen(Point startCursorPos = {0, 0});
    ~Screen();

    template<typename StringType>
    void write(StringType towrite);
    template<typename StringType>
    void write(StringType towrite, Point position);

    void move(Point position);
    void display();
};

}
