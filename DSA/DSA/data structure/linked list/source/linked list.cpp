#include <data structure\linked list\linked list.h>
#include <data structure\node\node.h>
#include <general\Assert.h>
#include <vector>
#include <algorithm>

bool sortDecreasing(int i, int j) 
{ 
	return (i > j); 
}

bool List_UnitTest()
{
	const size_t times = 1024 * 32;
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

	std::sort(keyBase.begin(), keyBase.end());

	for (size_t i = 0; i < times; i++)
	{
		ASSERT(keyBase.at(i) == list.at(i));
	}

	std::sort(keyBase.begin(), keyBase.end(), sortDecreasing);
	list.reverse();

	for (size_t i = 0; i < times; i++)
	{
		ASSERT(keyBase.at(i) == list.at(i));
	}

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

void LinkedList::inseret_node(int i_key)
{
	Node* new_node = new Node(i_key);
	ASSERT(new_node);

	if (m_pRoot == nullptr)
	{
		m_pRoot = new_node;
		new_node->pNext = nullptr;
		return;
	}
	else
	{
		if (m_pRoot->m_data >= i_key)
		{
			new_node->pNext = m_pRoot;
			m_pRoot = new_node;
			return;
		}
		else
		{
			Node* this_node = m_pRoot;
			Node* prev_node = m_pRoot;

			while (this_node != nullptr)
			{
				if (this_node->m_data >= i_key)
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
		Node* this_node = m_pRoot;
		Node* prev_node = m_pRoot;

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

int LinkedList::at(int i_node)
{
	if (m_pRoot == nullptr)
		return -1;
	else
	{
		int index = 0;
		Node* this_node = m_pRoot;

		while (this_node != nullptr)
		{
			if (index != i_node)
			{
				index++;
				this_node = this_node->pNext;
			}
			else
			{
				return this_node->m_data;
			}
		}
		return -1;
	}
}

void LinkedList::reverse()
{
	if (m_pRoot == nullptr)
	{
		return;
	}
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
		return;
	else
	{
		Node* this_node = m_pRoot;
		
		while (this_node != nullptr)
		{
			printf("%d->", this_node->m_data);
			this_node = this_node->pNext;
		}
	}
}

void LinkedList::destroy()
{

}

Node * LinkedList::getRoot()
{
	return m_pRoot;
}
