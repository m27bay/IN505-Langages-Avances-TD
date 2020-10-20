#ifndef VECTOR_HPP
#define VECTOR_HPP

class Vector
{
  private :

    /* attributes */
    int* tab;
    int size;

  public :

    /* Builders */
    Vector(); // Default
    Vector(const Vector&); // Copy
    Vector(int* tab, int size);
    Vector(int size);

    /* Getter */
    // Empty

    /* Setter */
    // Empty

    /* Overloaded */
    Vector &operator=(const Vector&);

    Vector &operator+=(const Vector&);
    Vector &operator-=(const Vector&);

    bool operator<(const Vector&);
    bool operator<=(const Vector&);
    bool operator>(const Vector&);
    bool operator>=(const Vector&);

    int operator[](const int);

    friend std::ostream &operator<<(std::ostream &flux, const Vector&);
    friend std::istream &operator>>(std::istream &flux, Vector&);

    /* Methods */
    // Empty

    /* Destructor */
    ~Vector();
};

#endif
