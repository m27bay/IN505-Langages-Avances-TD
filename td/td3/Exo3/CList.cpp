#include "CList.hpp"

/* Builders */
// Default
Node::Node() : data(0), next(nullptr) {}
CList::CList() : size(0), first(nullptr) {}

// Copy
CList::CList(const CList& other)
{
  // Init list
  this->size = other.size;
  this->first = nullptr;

  // Create the first element
  Node *firstNode = new Node(other.first->data);
  this->first = firstNode;

  // Creation current
  Node *currentThis = first;
  Node *currentOther = other.first->next;

  // Ride in currentOther
  while (currentOther)
  {
    // Init next
    currentThis->next = currentOther;

    // Skip to the next
    currentOther = currentOther->next;
    currentThis = currentThis->next;
  }
}

// Parameters builders
Node::Node(int newData)
{
  this->data = newData;
  this->next = nullptr;
}

CList::CList(int newData)
{
  Node *firstNode = new Node(newData);
  this->first = firstNode;
  this->size = 1;
}
/* End builders */

/* Overloaded */
CList &CList::operator=(const CList &other)
{
  this->size = other.size;

  // Create the first element
  Node *firstNode = new Node(other.first->data);
  this->first = firstNode;

  // Creation current
  Node *currentThis = first;
  Node *currentOther = other.first->next;

  // Ride in currentOther
  while (currentOther)
  {
    // Init next
    currentThis->next = currentOther;

    // Skip to the next
    currentOther = currentOther->next;
    currentThis = currentThis->next;
  }

  return *this;
}

std::ostream &operator<<(std::ostream &flux, const CList& other)
{
  if (!other.getFirst())
  {
    std::cout << "*empty*" << std::endl;
  }
  else
  {
    Node *current = other.getFirst();

    std::cout << "{ ";
    while (current->getNext())
    {
      std::cout << current->getData() << ", ";
      current = current->getNext();
    }
    std::cout << current->getData() << " }, size : " << other.getSize() << std::endl;
  }
}
/* end overloaded */

/* Getter */
int Node::getData() const
{
  return this->data;
}

Node *Node::getNext() const
{
  return this->next;
}

int CList::getSize() const
{
  return this->size;
}

Node *CList::getFirst() const
{
  return this->first;
}
/* End getters */

/* Methodes */

/* End methodes */

/* Destructors */

/* End destructors */