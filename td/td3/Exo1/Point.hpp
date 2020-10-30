#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

class Point
{
    private :
        /* Attributes */
        double x, y;

    public :
        /* Builders */
        Point(); // Default
        Point(const Point&); // Copy
        Point(double Px, double Py);

        /* Overloaded */
        Point& operator=(const Point&);

        friend std::ostream& operator<<(std::ostream &flux, const Point&);

        /* Destructor */
        ~Point();
};

#endif
