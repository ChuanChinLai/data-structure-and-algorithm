#include "..\stack.h"
#include <data structure\node\node.h>
#include <general\Assert.h>
#include <vector>
#include <algorithm>

void stack_UnitTest()
{
	const size_t times = 1024 * 1024;
	size_t index = 0;

	std::vector<int> keyBase;
	Stack stack;

	while (index < times)
	{
		index++;
		int key = rand() % times;
		
		keyBase.push_back(key);
		stack._push(key);
	}

//	stack._display();

	printf("After add nodes to the stack:\n");

	ASSERT(stack._size() == keyBase.size());

	while (!keyBase.empty())
	{
		int key_1 = keyBase.back();
		int key_2 = stack._top();

		ASSERT(key_1 == key_2);
		keyBase.pop_back();
		stack._pop();
	}

	ASSERT(stack._empty());
	ASSERT(stack._size() == keyBase.size());

	printf("success!!!\n");
	return;
}

void Stack::_push(const int i_key)
{
	Node* new_node = new Node(i_key);
	m_size++;

	new_node->pNext = m_pTop;
	m_pTop = new_node;
	return;
}

void Stack::_pop()
{
	if (m_pTop == nullptr)
		return;
	else
	{
		m_size--;
		Node* this_node = m_pTop;
		m_pTop = m_pTop->pNext;
		delete this_node;

		return;
	}
}

void Stack::_display()
{

}

bool Stack::_empty() const
{
	if (m_pTop == nullptr)
		return true;
	else
		return false;
}

int Stack::_top() const
{
	return m_pTop->m_data;
}

size_t Stack::_size() const
{
	return m_size;
}

void Stack::_destroy()
{
	if (m_pTop != nullptr)
	{
		while (!_empty())
		{
			_pop();
		}
	}
}
