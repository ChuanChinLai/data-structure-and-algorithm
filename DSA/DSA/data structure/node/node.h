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