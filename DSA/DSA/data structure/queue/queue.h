#pragma once

class Node;

class Queue
{
public:
	Queue(): m_size(0), pFront(nullptr), pRear(nullptr)
	{

	}

	void _push(const int i_key);
	void _pop();

	void _display();
	int _front();
	int _back();

	bool _empty();
	size_t _size() const;
	void _destroy();

private:

	size_t m_size;

	Node* pFront;
	Node* pRear;
};

extern void queue_UnitTest();
