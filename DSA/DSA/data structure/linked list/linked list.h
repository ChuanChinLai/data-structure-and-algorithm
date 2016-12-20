#pragma once

class Node 
{
public:
	Node(int i_data) : pNext(nullptr), m_data(i_data)
	{

	}

	Node* pNext;
	int m_data;
};


class LinkedList
{
public:

	LinkedList() : m_pRoot(nullptr)
	{

	}

	~LinkedList()
	{

	}

	//insert a node to a ordered list, small -> large
	void inseret_node(int i_key);

	//delete a node
	bool delete_node(int i_key);

	//reverse a list
	void reverse();

	//print a list
	void display() const;

	//destroy a list
	void destroy();

private:

	Node* m_pRoot;
};

extern bool List_UnitTest();