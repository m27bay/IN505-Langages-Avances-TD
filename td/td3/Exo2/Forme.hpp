#ifndef Forme_HPP
#define Forme_HPP

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

class Forme
{
	protected :
		/* Attributes */
		Point* points;
		int size;

	public :
		/* Builders */
		Forme(); // Default

		/* methodes */
		virtual void move(const Forme&);

		/* Destructor */
		~Forme();
};

class Segment
{
  private :
    /* attributes */
    Point P, P2;

  public :
    /* Builders */
  	Segment(); // Default
  	Segment(const Segment&); // Copy
    Segment(int Px, int Py, int P2x, int P2y);
    Segment(const Point &_P, const Point &_P2);

    /* Overloaded */
    Segment& operator=(const Segment&);

    friend std::ostream& operator<<(std::ostream& flux, const Segment&);

    /* Override */
    virtual void move(const Segment&);

    /* Methods */
    float length();
    bool isVertical();
    bool isHorizontal();
    bool isOnTheDiagonal();

    /* Destructor */
    ~Segment();
};

#endif
