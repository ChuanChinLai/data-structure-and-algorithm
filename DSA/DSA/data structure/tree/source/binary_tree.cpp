#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <general\Assert.h>
#include <data structure\tree\binary_tree.h>

void binarytree_UnitTest()
{
	const size_t times = 1024*1024;
	size_t index = 0;

	std::vector<int> keyBase;
	BinaryTree binarytree;

	while (index < times)
	{
		index++;

		int key = rand() % times;

		if (!binarytree._search(key))
		{
			printf("key: %d\n", key);
			binarytree._push(key);
			keyBase.push_back(key);
		}
	}
	
	/*
	binarytree._display_PostOrder();
	printf("\n");
	binarytree._display_PreOrder();
	printf("\n");
	binarytree._display_InOrder();
	*/

	printf("Size: %d\n", keyBase.size());
	printf("After add nodes to the tree:\n");

	if (!keyBase.empty())
	{
		std::sort(keyBase.begin(), keyBase.end());

		int index = 0;

		for (std::vector<int>::iterator i = keyBase.begin(); i != keyBase.end(); i++)
		{
			ASSERT(*i == binarytree.inOrderVector.at(index));
			index++;
		}

		// randomize the keys
		std::random_shuffle(keyBase.begin(), keyBase.end());
		printf("Size: %d\n", keyBase.size());

		while (!keyBase.empty())
		{
			int key = keyBase.back();
			printf("key: %d\n", key);

			bool success = binarytree._search(key);
			ASSERT(success);

			success = binarytree._delete(key);
			ASSERT(success);

			keyBase.pop_back();
		}
	}

	ASSERT(binarytree.getRoot() == nullptr);

	printf("success!!!\n");
}

bool BinaryTree::_push(int i_key)
{
	TreeNode* new_node = new TreeNode(i_key);

	if (m_root == nullptr)
	{
		m_root = new_node;
		return true;
	}
	else
	{
		TreeNode* current_node = m_root;

		while (1)
		{
			if (i_key == current_node->getKey())
			{
				delete new_node;
				return false;
			}
			else if (i_key < current_node->getKey())
			{
				if (current_node->getLeftNode() == nullptr)
				{
					current_node->setLeftNode(new_node);
					return true;
				}
				else
					current_node = current_node->getLeftNode();
			}
			else
			{
				if (current_node->getRightNode() == nullptr)
				{
					current_node->setRightNode(new_node);
					return true;
				}
				else
					current_node = current_node->getRightNode();
			}
		}
	}
}

bool BinaryTree::_search(int i_key)
{
	if (m_root == nullptr)
		return false;
	else
	{
		TreeNode* current_node = m_root;

		while (1)
		{
			if (current_node == nullptr)
				return false;
			else if (i_key == current_node->getKey())
				return true;
			else if (i_key < current_node->getKey())
				current_node = current_node->getLeftNode();
			else
				current_node = current_node->getRightNode();
		}
	}


}

bool BinaryTree::_delete(int i_key)
{
	if (m_root == nullptr)
		return false;
	else
	{
		TreeNode* current_node = m_root;
		TreeNode* parents_node = m_root;
		bool isLeft = true;

		while (i_key != current_node->getKey())
		{
			parents_node = current_node;

			if (i_key < current_node->getKey())
			{
				isLeft = true;
				current_node = current_node->getLeftNode();
			}
			else
			{
				isLeft = false;
				current_node = current_node->getRightNode();
			}

			if (current_node == nullptr)
				return false;
		}


		if (current_node->getLeftNode() == nullptr && current_node->getRightNode() == nullptr)
		{
			if (current_node == m_root)
				m_root = nullptr;
			else if (isLeft == true)
				parents_node->setLeftNode(nullptr);
			else
				parents_node->setRightNode(nullptr);
		}
		else if (current_node->getLeftNode() == nullptr)
		{
			if (current_node == m_root)
				m_root = current_node->getRightNode();
			else if (isLeft == true)
				parents_node->setLeftNode(current_node->getRightNode());
			else
				parents_node->setRightNode(current_node->getRightNode());
		}
		else if (current_node->getRightNode() == nullptr)
		{
			if (current_node == m_root)
				m_root = current_node->getLeftNode();
			else if (isLeft == true)
				parents_node->setLeftNode(current_node->getLeftNode());
			else
				parents_node->setRightNode(current_node->getLeftNode());
		}

		else
		{
			TreeNode* temp_successor = current_node->getRightNode();
			TreeNode* successor = current_node;
			TreeNode* successor_parent = current_node;

			while (temp_successor != nullptr)
			{
				successor_parent = successor;
				successor = temp_successor;
				temp_successor = temp_successor->getLeftNode();
			}

			if (successor != current_node->getRightNode())
			{
				successor_parent->setLeftNode(successor->getRightNode());
				successor->setRightNode(current_node->getRightNode());
			}
			successor->setLeftNode(current_node->getLeftNode());

			if (current_node == m_root)
			{
				m_root = successor;
			}
			else if (isLeft == true)
			{
				parents_node->setLeftNode(successor);
			}
			else
			{
				parents_node->setRightNode(successor);
			}
		}

		current_node->setLeftNode(nullptr);
		current_node->setRightNode(nullptr);
		delete current_node;

		return true;
	}
}

TreeNode * BinaryTree::getRoot()
{
	return m_root;
}

void BinaryTree::_display_PreOrder()
{
	_display_PreOrder(m_root);
}

void BinaryTree::_display_InOrder()
{
	_display_InOrder(m_root);
}

void BinaryTree::_display_PostOrder()
{
	_display_PostOrder(m_root);
}

void BinaryTree::_display_PreOrder(TreeNode * i_node)
{
	if (i_node != nullptr)
	{
		std::cout << i_node->getKey() << std::endl;
		_display_PreOrder(i_node->getLeftNode());
		_display_PreOrder(i_node->getRightNode());
	}
}

void BinaryTree::_display_InOrder(TreeNode * i_node)
{
	if (i_node != nullptr)
	{
		_display_InOrder(i_node->getLeftNode());
		std::cout << i_node->getKey() << std::endl;
		inOrderVector.push_back(i_node->getKey());
		_display_InOrder(i_node->getRightNode());
	}
}

void BinaryTree::_display_PostOrder(TreeNode * i_node)
{
	if (i_node != nullptr)
	{
		_display_PostOrder(i_node->getLeftNode());
		_display_PostOrder(i_node->getRightNode());
		std::cout << i_node->getKey() << std::endl;
	}
}
