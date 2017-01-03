/*
#include <data structure\linked list\linked list.h>
#include <data structure\node\node.h>
#include <general\Assert.h>
#include <vector>
#include <algorithm>


void LinkedList::inseret_node(int i_key)
{
	Node* new_Node = new Node(i_key);
	ASSERT(new_Node);

	if (m_pRoot == nullptr)
	{
		m_pRoot = new_Node;
	}
	else
	{
		Node* this_Node = m_pRoot;
		Node* prev_Node = nullptr;

		if (new_Node->m_data <= this_Node->m_data)
		{
			m_pRoot = new_Node;
			new_Node->pNext = this_Node;
		}
		else
		{
			while (this_Node != nullptr)
			{
				if (new_Node->m_data <= this_Node->m_data)
				{
					prev_Node->pNext = new_Node;
					new_Node->pNext = this_Node;
					return;
				}
				else
				{
					prev_Node = this_Node;
					this_Node = this_Node->pNext;
				}
			}

			prev_Node->pNext = new_Node;
			new_Node->pNext = nullptr;
			return;
		}
	}
}

bool LinkedList::delete_node(int i_key)
{
	if (m_pRoot == nullptr)
	{
		printf("The List is NULL\n");
		return false;
	}
	else
	{
		Node* this_Node = m_pRoot;
		Node* prev_Node = nullptr;

		if (i_key == this_Node->m_data)
		{
			m_pRoot = this_Node->pNext;

			printf("Delete: %d\n", this_Node->m_data);

			delete this_Node;
			return true;
		}
		else
		{
			while (this_Node != nullptr)
			{
				if (i_key == this_Node->m_data)
				{
					prev_Node->pNext = this_Node->pNext;
					printf("Delete: %d\n", this_Node->m_data);

					delete this_Node;
					return true;
				}
				else
				{
					prev_Node = this_Node;
					this_Node = this_Node->pNext;
				}
			}
		}
	}

	printf("Cannot find the node (%d)...\n", i_key);
	return false;
}

void LinkedList::reverse()
{
	if (m_pRoot == nullptr)
		return;
	else
	{
		Node* prev_Node = nullptr;
		Node* this_Node = m_pRoot;
		Node* next_Node = m_pRoot->pNext;

		while (next_Node != nullptr)
		{
			this_Node->pNext = prev_Node;
			prev_Node = this_Node;
			this_Node = next_Node;
			next_Node = next_Node->pNext;
		}

		this_Node->pNext = prev_Node;
		m_pRoot = this_Node;
	}
}

void LinkedList::display() const
{
	if (m_pRoot == nullptr)
	{
		printf("The List is NULL\n");
	}
	else
	{
		Node* this_Node = m_pRoot;

		while (this_Node != nullptr)
		{
			printf("(%d)->", this_Node->m_data);
			this_Node = this_Node->pNext;
		}
		printf("NULL\n");
	}
}

void LinkedList::destroy()
{
	if (m_pRoot == nullptr)
		return;
	else
	{
		Node* this_Node = m_pRoot;
		Node* next_Node = m_pRoot->pNext;

		while (next_Node != nullptr)
		{
			int key = this_Node->m_data;

			this_Node = next_Node;
			next_Node = next_Node->pNext;

			delete_node(key);
		}

		delete this_Node;
		m_pRoot = nullptr;
	}
}

bool List_UnitTest()
{
	const size_t times = 1024;
	size_t index = 0;

	std::vector<int> keyBase;
	LinkedList list;

	while (index < times)
	{
		index++;

		int key = rand() % 50;
		keyBase.push_back(key);
		list.inseret_node(key);
	}

	printf("After add nodes to the list:\n");

	if (!keyBase.empty())
	{
		// randomize the keys
		std::random_shuffle(keyBase.begin(), keyBase.end());

		while (!keyBase.empty())
		{
			int key = keyBase.back();
			keyBase.pop_back();

			bool success = list.delete_node(key);
			ASSERT(success);
		}
	}

	printf("success!!!\n");
	return true;
}
*/