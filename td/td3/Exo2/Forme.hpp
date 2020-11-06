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

    /* Setters */
    void setX(double x);
    void setY(double y);

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
    /* Builder */
    Forme(); // Default
    Forme(const Forme&); // Copy
    Forme(Point* points, int numPoints);

    /* Overloaded */
    virtual Forme& operator=(const Forme&);

    friend std::ostream &operator<<(std::ostream &flux, const Forme &);

    /* Methodes */
		virtual void move(double dx, double dy);

    /* Getters */
    int getNumPoint() const;
    Point* getPoints() const;
    Point getPointsIndex(int index) const;

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
    Segment(const Point &, const Point &);

    /* Methods */
    float length();
    bool isVertical();
    bool isHorizontal();
    bool isOnTheDiagonal();
};

class Rectangle : public Forme
{
  public:
    /* Builders */
    Rectangle();                // Default
    Rectangle(const Rectangle &); // Copy
    Rectangle(const Point&, const Point&, const Point&, const Point&);
};

#endif
