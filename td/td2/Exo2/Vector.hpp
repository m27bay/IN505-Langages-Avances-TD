#ifndef VECTOR_HPP
#define VECTOR_HPP

class Vector
{
  private :

    /* attributes */
    int* vector;
    int numComponents;

  public :

    /* Builders */
    Vector(); // Default
    Vector(const Vector&); // Copy
    Vector(int size);
    Vector(int* tab, int tabSize);

    /* Getter */
    int* getVector() const;
    int getNumComponents() const;

    /* Setter */

    /* Overloaded */
    void operator=(const Vector&);

    Vector operator+(const Vector&);
    Vector operator-(const Vector&);

    bool operator<(const Vector&);
    bool operator>(const Vector&);

    /* Methods */

    /* Destructor */
    ~Vector();
};

#endif
