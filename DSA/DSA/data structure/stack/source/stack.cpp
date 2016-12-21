#include "..\stack.h"
#include <data structure\node\node.h>
#include <general\Assert.h>
#include <vector>
#include <algorithm>

void Stack::_push(const int key)
{
	Node* new_Node = new Node(key);
	ASSERT(new_Node);

	m_size++;

	if (m_pTop == nullptr)
	{
		m_pRoot = new_Node;
		m_pTop = new_Node;
	}
	else
	{
		Node* this_Node = m_pTop;
		m_pTop = new_Node;
		new_Node->pNext = this_Node;
	}

}

void Stack::_pop()
{
	if (m_pTop == nullptr)
	{
		printf("Nothing can be pop\n");
		return;
	}
	else
	{
		m_size--;

		Node* pThisNode = m_pTop;
		m_pTop = m_pTop->pNext;

		printf("pop: (%d)\n", pThisNode->m_data);
		delete pThisNode;
	}
}

void Stack::_display()
{
	if (_empty())
	{
		printf("The stack is empty");
	}
	else
	{
		Node* pThisNode = m_pTop;
		
		while (pThisNode != nullptr)
		{
			printf("(%d)->", pThisNode->m_data);
			pThisNode = pThisNode->pNext;
		}
		printf("NULL \n");
	}
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
	if(m_pTop != nullptr)
		return m_pTop->m_data;
}

size_t Stack::_size() const
{
	return m_size;
}

void Stack::_destroy()
{
	while (!_empty())
	{
		_pop();
	}
}

void stack_UnitTest()
{
	const size_t times = 1024*1024;
	size_t index = 0;

	std::vector<int> keyBase;
	Stack stack;

	while (index < times)
	{
		index++;
		int key = rand() % 50;
		
		keyBase.push_back(key);
		stack._push(key);
	}

	stack._display();

	printf("After add nodes to the stack:\n");

	while (index > 0)
	{
		int key_1 = keyBase.back();
		int key_2 = stack._top();

		ASSERT(key_1 == key_2);
		keyBase.pop_back();
		stack._pop();
		index--;
	}

	printf("success!!!\n");
	return;
}
