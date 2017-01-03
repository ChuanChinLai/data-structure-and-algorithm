#include <data structure\linked list\linked list.h>
#include <data structure\node\node.h>
#include <general\Assert.h>
#include <vector>
#include <algorithm>


void LinkedList::inseret_node(int i_key)
{
	Node* new_node = new Node(i_key);
	ASSERT(new_node);

	if (m_pRoot == nullptr)
	{
		m_pRoot = new_node;
		return;
	}
	else
	{
		Node* prev_node = nullptr;
		Node* this_node = m_pRoot;

		if (i_key <= this_node->m_data)
		{
			m_pRoot = new_node;
			new_node->pNext = this_node;
			return;
		}
		else
		{
			while (this_node != nullptr)
			{
				if (i_key <= this_node->m_data)
				{
					prev_node->pNext = new_node;
					new_node->pNext = this_node;
					return;
				}
				else
				{
					prev_node = this_node;
					this_node = this_node->pNext;
				}
			}
			prev_node->pNext = new_node;
			new_node->pNext = nullptr;
			return;
		}
	}
}

bool LinkedList::delete_node(int i_key)
{
	if (m_pRoot == nullptr)
	{
		return false;
	}
	else
	{
		Node* prev_node = nullptr;
		Node* this_node = m_pRoot;

		if (this_node->m_data == i_key)
		{
			m_pRoot = this_node->pNext;
			delete this_node;
			return true;
		}
		else
		{
			while (this_node != nullptr)
			{
				if (this_node->m_data == i_key)
				{
					prev_node->pNext = this_node->pNext;
					delete this_node;
					return true;
				}
				else
				{
					prev_node = this_node;
					this_node = this_node->pNext;
				}
			}
		}
	}
	return false;
}

void LinkedList::reverse()
{
	if (m_pRoot == nullptr)
		return;
	else
	{
		Node* prev_node = nullptr;
		Node* this_node = m_pRoot;
		Node* next_node = m_pRoot->pNext;

		while (next_node != nullptr)
		{
			this_node->pNext = prev_node;

			prev_node = this_node;
			this_node = next_node;
			next_node = next_node->pNext;
		}

		this_node->pNext = prev_node;
		m_pRoot = this_node;
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

Node * LinkedList::getRoot()
{
	return m_pRoot;
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

		int key = rand() % times;
		keyBase.push_back(key);
		list.inseret_node(key);
	}

	printf("After add nodes to the list:\n");

//	list.display();

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
			list.reverse();
		}
	}

	ASSERT(list.getRoot() == nullptr);

	printf("success!!!\n");
	return true;
}
