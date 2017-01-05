#include <stdio.h>
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
	
	binarytree._display_PostOrder();
	printf("\n");
	binarytree._display_PreOrder();
	printf("\n");
	binarytree._display_InOrder();
	
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
		TreeNode* current_Node = m_root;
		TreeNode* parent_Node = m_root;

		while (1)
		{
			parent_Node = current_Node;

			if (current_Node->getKey() == i_key)
			{
				delete new_node;
				return false;
			}
			else if (current_Node->getKey() > i_key)
			{
				current_Node = current_Node->getLeftNode();

				if (current_Node == nullptr)
				{
					parent_Node->setLeftNode(new_node);
					return true;
				}
			}
			else
			{
				current_Node = current_Node->getRightNode();

				if (current_Node == nullptr)
				{
					parent_Node->setRightNode(new_node);
					return true;
				}
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

		while (current_node != nullptr)
		{
			if (current_node->getKey() == i_key)
			{
				return true;
			}
			else if (current_node->getKey() > i_key)
			{
				current_node = current_node->getLeftNode();
			}
			else
			{
				current_node = current_node->getRightNode();
			}
		}
		return false;
	}
}

bool BinaryTree::_delete(int i_key)
{
	TreeNode* current_node = m_root;
	TreeNode* parent_node = m_root;
	bool isLeft = false;

	if(current_node == nullptr)
		return false;
	else
	{
		while (1)
		{
			parent_node = current_node;

			if(current_node->getKey() > i_key)
			{
				current_node = current_node->getLeftNode();
				isLeft = true;
			}
			else if(current_node->getKey() < i_key)
			{
				current_node = current_node->getRightNode();
				isLeft = false;
			}

			if (current_node == nullptr)
				return false;
			else if (current_node->getKey() == i_key)
				break;
		}


		if (current_node->getLeftNode() == nullptr && current_node->getRightNode() == nullptr)
		{
			if (current_node == m_root)
				m_root = nullptr;
			else if (isLeft == true)
				parent_node->setLeftNode(nullptr);
			else
				parent_node->setRightNode(nullptr);
		}
		else if (current_node->getLeftNode() == nullptr)
		{
			if (current_node == m_root)
				m_root = current_node->getRightNode();
			else if (isLeft == true)
				parent_node->setLeftNode(current_node->getRightNode());
			else
				parent_node->setRightNode(current_node->getRightNode());
		}
		else if (current_node->getRightNode() == nullptr)
		{
			if (current_node == m_root)
				m_root = current_node->getLeftNode();
			else if (isLeft == true)
				parent_node->setLeftNode(current_node->getLeftNode());
			else
				parent_node->setRightNode(current_node->getLeftNode());
		}
		else
		{
			TreeNode* tmp = current_node->getRightNode();
			TreeNode* successor = current_node;
			TreeNode* successor_parent = current_node;

			while (tmp != nullptr)
			{
				successor_parent = successor;
				successor = tmp;
				tmp = tmp->getLeftNode();
			}

			if (successor != current_node->getRightNode())
			{
				successor_parent->setLeftNode(successor->getRightNode());
				successor->setRightNode(current_node->getRightNode());
			}
			successor->setLeftNode(current_node->getLeftNode());
			
			if (current_node == m_root)
				m_root = successor;
			else if (isLeft == true)
				parent_node->setLeftNode(successor);
			else
				parent_node->setRightNode(successor);
		}
	}

	current_node->setLeftNode(nullptr);
	current_node->setRightNode(nullptr);
	delete current_node;
	return true;
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
		printf("%d->", i_node->getKey());
		_display_PreOrder(i_node->getLeftNode());
		_display_PreOrder(i_node->getRightNode());
	}
}

void BinaryTree::_display_InOrder(TreeNode * i_node)
{
	if (i_node != nullptr)
	{
		_display_InOrder(i_node->getLeftNode());
		printf("%d->", i_node->getKey());
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
		printf("%d->", i_node->getKey());
	}
}
