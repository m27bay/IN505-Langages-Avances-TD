#ifndef VECTOR_HPP
#define VECTOR_HPP

class VectorTab
{
  private :
    /* attributes */
    int* tab;
    int size;

  public :
    /* Builders */
    VectorTab(); // Default
    VectorTab(const VectorTab&); // Copy
    VectorTab(int* tab, int size);
    VectorTab(int size);

    /* Getter */
    // Empty

    /* Setter */
    // Empty

    /* Overloaded */
    VectorTab &operator=(const VectorTab&);

    VectorTab &operator+=(const VectorTab&);
    VectorTab &operator-=(const VectorTab&);

    bool operator<(const VectorTab&);
    bool operator<=(const VectorTab&);
    bool operator>(const VectorTab&);
    bool operator>=(const VectorTab&);

    int operator[](const int);

    friend std::ostream &operator<<(std::ostream &flux, const VectorTab&);
    friend std::istream &operator>>(std::istream &flux, VectorTab&);

    /* Methods */
    // Empty

    /* Destructor */
    ~VectorTab();
};

class VectorList
{
  private :
    /* attributes */
    struct elem
    {
        int data;
        elem* next;
    };

    elem* first;
    elem* end;
    int size;

  public :
    /* Builders */
    VectorList(); // Default
    VectorList(const VectorList&); // Copy
    VectorList(int size);
    VectorList(int* tab, int size);

    /* Getter */
    // Empty

    /* Setter */
    // Empty

    /* Overloaded */
    VectorList &operator=(const VectorList&);

    VectorList &operator+=(const VectorList&);
    VectorList &operator-=(const VectorList&);

    bool operator<(const VectorList&);
    bool operator<=(const VectorList&);
    bool operator>(const VectorList&);
    bool operator>=(const VectorList&);

    int operator[](const int);

    friend std::ostream &operator<<(std::ostream &flux, const VectorList&);
    friend std::istream &operator>>(std::istream &flux, VectorList&);

    /* Methods */
    // Empty

    /* Destructor */
    ~VectorList();
};

#endif
