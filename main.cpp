#include "source/screen.h"

int main()
{
    cge::Screen screen = cge::Screen();

    screen.write("Hello!", {5, 10});
    screen.display();

    return 0;
}
