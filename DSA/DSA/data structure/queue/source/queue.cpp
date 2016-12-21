#include "..\queue.h"
#include <data structure\node\node.h>
#include <general\Assert.h>
#include <vector>
#include <algorithm>

void Queue::_push(const int i_key)
{
	Node* new_Node = new Node(i_key);
	ASSERT(new_Node);

	m_size++;

	if (pFront == nullptr && pRear == nullptr)
	{
		pFront = new_Node;
		pRear = new_Node;

		return;
	}
	else
	{
		Node* this_Node = pRear;
		this_Node->pNext = new_Node;
		pRear = new_Node;
	}
}

void Queue::_pop()
{
	ASSERT(pFront);

	m_size--;

	Node* this_Node = pFront;
	pFront = this_Node->pNext;
	printf("pop (%d)\n", this_Node->m_data);
	delete this_Node;
}

void Queue::_display()
{
	if (_empty())
	{
		printf("Queue is NULL\n");
		return;
	}
	else
	{
		printf("Front->");
		Node* this_Node = pFront;

		while (this_Node != nullptr)
		{
			printf("(%d)->", this_Node->m_data);
			this_Node = this_Node->pNext;
		}
		printf("Rear\n");
	}
}

int Queue::_front()
{
	ASSERT(pFront);
	return pFront->m_data;
}

int Queue::_back()
{
	ASSERT(pRear);
	return pRear->m_data;
}

bool Queue::_empty()
{
	if (pFront == nullptr)
		return true;
	else
		return false;
}

size_t Queue::_size()
{
	return m_size;
}

void Queue::_destroy()
{
	while (!_empty())
	{
		_pop();
	}
}

void queue_UnitTest()
{
	const size_t times = 1024 * 1024;
	size_t index = 0;

	std::vector<int> keyBase;
	Queue queue;

	while (index < times)
	{
		index++;
		int key = rand() % 50;

		keyBase.push_back(key);
		queue._push(key);
	}

	queue._display();

	printf("After add nodes to the queue:\n");

	while (index > 0)
	{
		int key_1 = keyBase.at(times - index);
		int key_2 = queue._front();

		ASSERT(key_1 == key_2);

		queue._pop();
		index--;
	}

	printf("success!!!\n");
	return;
}
