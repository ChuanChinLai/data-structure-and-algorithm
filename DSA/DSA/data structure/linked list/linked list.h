#pragma once

class Node;

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

	Node* getRoot();

private:

	Node* m_pRoot;
};

extern bool List_UnitTest();