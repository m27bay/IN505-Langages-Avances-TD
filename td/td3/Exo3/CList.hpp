#ifndef CList_HPP
#define CList_HPP

#include <iostream>

class Node
{
	friend class CList;

	private:
		/* Attributes */
		int data;
		Node *next;

		/* Builders */
		Node(); // Default
		Node(int newData);

	public:
		/* Getters */
		int getData() const;
		Node* getNext() const;
};

class CList
{
	protected:
		/* Attributes */
		int size;
		Node *first;

	public:
	 /* Builder */
	 	CList(); // Default
		CList(const CList&); // Copy
		CList(int first);

		/* Overloaded */
		virtual CList &operator=(const CList&);

		virtual void operator<(const Node);
		virtual int operator>(int ret);

		friend std::ostream &operator<<(std::ostream &flux, const CList&);

		/* Getters */
		int getSize() const;
		Node *getFirst() const;

		/* Destructor */
		virtual ~CList();
};

#endif