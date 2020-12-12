#include <iostream>

#include "Point.hpp"

int main(void)
{

    Point A = Point();
    std::cout << "Point A" << std::endl;
    A.print();

    Point B = Point(10, 3);
    std::cout << "Point B" << std::endl;
    B.print();

    Point C = Point(B);
    std::cout << "Point C" << std::endl;
    C.print();

    Point D = Point();
    Point E = Point(64, 5);
    std::cout << "Point D" << std::endl;
    D.clone(E);
    D.print();

    return 0;
}
