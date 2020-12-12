#include "CList.hpp"

/* Builders */
// Default
Node::Node() : data(0), next(nullptr) {}
CList::CList() : size(0), first(nullptr) {}
CPile::CPile() : CList() {}
CFile::CFile() : CList() {}

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

void CList::operator<(int newData)
{
  Node *newNode = new Node(newData);
  if (!newNode)
  {
    std::cout << "ERROR : alloc Node failed" << std::endl;
    return;
  }

  if (!this->first)
  {
    this->first = newNode;
    this->size = 1;
  }
  else
  {
    Node *current = this->first;

    while (current->next)
    {
      current = current->next;
    }

    current->next = newNode;
    this->size += 1;
  }
}

std::ostream &operator<<(std::ostream &flux, const CList& other)
{
  if (!other.getFirst())
  {
    flux << "*empty*";
    return flux;
  }
  else
  {
    Node *current = other.getFirst();

    std::cout << "{ ";
    while (current->getNext())
    {
      flux << current->getData() << ", ";
      current = current->getNext();
    }
    flux << current->getData() << " }, size : " << other.getSize();
  }
  return flux;
}

void CList::operator>(int* ret)
{
  if (!this->first)
  {
    std::cout << "ERROR : list empty" << std::endl;
    return;
  }
  else
  {
    Node *tmp = this->first;
    this->first = this->first->next;
    *ret = tmp->data;
    delete tmp;
    this->size -= 1;
  }
}

void CPile::operator>(int* ret)
{
  if (!this->first)
  {
    std::cout << "ERROR : pile empty" << std::endl;
    return;
  }
  else
  {
    Node *current = this->first;
    while (current->next->next)
    {
      current = current->next;
    }
    *ret = current->next->data;
    delete current->next;
    current->next = nullptr;
    this->size -= 1;
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
void CList::empty()
{
  while (this->size)
  {
    int tmp = 0;
    *this > &tmp;
  }
}
/* End methodes */

/* Destructors */
CList::~CList()
{
  empty();
}
/* End destructors */