#pragma once

class Node;

class Stack
{
public:
	Stack() : m_pTop(nullptr), m_pRoot(nullptr), m_size(0)
	{

	}

	//Inserts a node into the list
	void _push(const int key);
	//Removes the last item into the list
	void _pop();

	//Display the stack
	void _display();
	//Returns if the stack is empty
	bool _empty() const;
	//Returns a reference to the element on the top of the stack
	int  _top() const;
	//Returns the number of elements in the stack;
	size_t _size() const;
	//Destroy the stack
	void _destroy();

private:

	Node* m_pTop;
	Node* m_pRoot;
	size_t m_size;
};

extern void stack_UnitTest();