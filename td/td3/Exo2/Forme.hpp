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

    /* Getters */
    double getX() const;
    double getY() const;

    /* Destructor */
    ~Point();
};

class Forme
{
	protected :
		/* Attributes */
		Point* points;
		int numPoints;

	public :
		/* Builders */
		Forme(); // Default

		/* methodes */
		virtual void move(const Forme&);

		/* Destructor */
		virtual ~Forme();
};

class Segment : public Forme
{
  private :
    /* attributes */
    float size;

  public :
    /* Builders */
  	Segment(); // Default
  	Segment(const Segment&); // Copy
    Segment(double Px, double Py, double P2x, double P2y);
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
    virtual ~Segment();
};

#endif
