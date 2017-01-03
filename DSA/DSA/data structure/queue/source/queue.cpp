#include "..\queue.h"
#include <data structure\node\node.h>
#include <general\Assert.h>
#include <vector>
#include <queue>
#include <algorithm>

void queue_UnitTest()
{
	const size_t times = 1024 * 1024;
	size_t index = 0;

	std::queue<int> keyBase;
	Queue queue;

	while (index < times)
	{
		index++;
		int key = rand() % 50;

		keyBase.push(key);
		queue._push(key);
	}

	printf("After add nodes to the queue:\n");
	ASSERT(queue._size() == keyBase.size());

	while (!keyBase.empty())
	{
		int key_1 = keyBase.front();
		int key_2 = queue._front();

		ASSERT(key_1 == key_2);

		keyBase.pop();
		queue._pop();
	}
	ASSERT(queue._empty());


	printf("success!!!\n");
	return;
}

void Queue::_push(const int i_key)
{
	Node* new_node = new Node(i_key);
	m_size++;

	if (pFront == nullptr)
	{
		pFront = new_node;
		pRear = new_node;
		new_node->pNext = nullptr;
	}
	else
	{
		pRear->pNext = new_node;
		new_node->pNext = nullptr;
		pRear = new_node;
	}
	return;
}

void Queue::_pop()
{
	if (pFront == nullptr)
	{
		return;
	}
	else
	{
		m_size--;

		Node* pop_node = pFront;
		pFront = pFront->pNext;

		delete pop_node;
		return;
	}
}

void Queue::_display()
{
}

int Queue::_front()
{
	return pFront->m_data;
}

int Queue::_back()
{
	return pRear->m_data;
}

bool Queue::_empty()
{
	if (pFront == nullptr)
		return true;
	else
		return false;
}

size_t Queue::_size() const
{
	return m_size;
}

void Queue::_destroy()
{
	if (!_empty())
	{
		_pop();
	}
}
