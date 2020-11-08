#ifndef CList_HPP
#define CList_HPP

#include <iostream>

class Node
{
	friend class CList;
	friend class CPile;
	friend class CFile;

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

		void operator<(int newData); // pop
		virtual void operator>(int ret) = 0; // push

		friend std::ostream &operator<<(std::ostream &flux, const CList&);

		/* Methodes */
		void empty();

		/* Getters */
		int getSize() const;
		Node *getFirst() const;

		/* Destructor */
		~CList();
};

class CPile : public CList
{
	public:
		/* Builder */
		CPile(); // Default

		/* Overloaded */
		virtual void operator>(int ret);
};

class CFile : public CList
{
	public:
		/* Builder */
		CFile(); // Default

		/* Overloaded */
		virtual void operator>(int ret);
};

#endif