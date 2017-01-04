#include <stdio.h>
#include <vector>
#include <algorithm>
#include <general\Assert.h>
#include <data structure\tree\binary_tree.h>

bool BinaryTree::_push(int i_key)
{
	TreeNode* new_Node = new TreeNode(i_key);

	if (m_root == nullptr)
	{
		m_root = new_Node;
		return true;
	}
	else
	{
		TreeNode* parent_Node = m_root;
		TreeNode* current_Node = m_root;

		while (1)
		{
			parent_Node = current_Node;

			if (i_key == current_Node->getKey())
			{
				delete new_Node;
				return false;
			}

			else if (i_key < current_Node->getKey())
			{
				current_Node = current_Node->getLeftNode();

				if (current_Node == nullptr)
				{
					parent_Node->setLeftNode(new_Node);
					return true;
				}
			}
			else
			{
				current_Node = current_Node->getRightNode();

				if (current_Node == nullptr)
				{
					parent_Node->setRightNode(new_Node);
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
		TreeNode* current_Node = m_root;

		while (current_Node != nullptr)
		{
			if (i_key == current_Node->getKey())
			{
				return true;
			}
			else if (i_key < current_Node->getKey())
			{
				current_Node = current_Node->getLeftNode();
			}
			else
			{
				current_Node = current_Node->getRightNode();
			}
		}
	}
	return false;
}

bool BinaryTree::_delete(int i_key)
{
	if(m_root == nullptr)
		return false;

	TreeNode* parent_Node = m_root;
	TreeNode* current_Node = m_root;
	bool isLeftNode = false;

	while (current_Node->getKey() != i_key)
	{
		parent_Node = current_Node;
	
		if (i_key < current_Node->getKey())
		{
			isLeftNode = true;
			current_Node = current_Node->getLeftNode();
		}
		else
		{
			isLeftNode = false;
			current_Node = current_Node->getRightNode();
		}

		//if cannot find the i_key
		if (current_Node == nullptr)
			return false;
	}

	if (current_Node->getLeftNode() == nullptr && current_Node->getRightNode() == nullptr)
	{
		if (current_Node == m_root)
			m_root = nullptr;
		else if (isLeftNode == true)
			parent_Node->setLeftNode(nullptr);
		else
			parent_Node->setRightNode(nullptr);
	}
	else if (current_Node->getLeftNode() == nullptr)
	{
		if (current_Node == m_root)
			m_root = current_Node->getRightNode();
		else if (isLeftNode == true)
			parent_Node->setLeftNode(current_Node->getRightNode());
		else
			parent_Node->setRightNode(current_Node->getRightNode());
	}
	else if (current_Node->getRightNode() == nullptr)
	{
		if (current_Node == m_root)
			m_root = current_Node->getLeftNode();
		if (isLeftNode == true)
			parent_Node->setLeftNode(current_Node->getLeftNode());
		else
			parent_Node->setRightNode(current_Node->getLeftNode());
	}
	else
	{
		TreeNode* temp_successor = current_Node->getRightNode();
		TreeNode* successor = current_Node;
		TreeNode* successorParent = current_Node;

		while (temp_successor != nullptr)
		{
			successorParent = successor;
			successor = temp_successor;
			temp_successor = temp_successor->getLeftNode();
		}

		if (successor != current_Node->getRightNode())
		{
			successorParent->setLeftNode(successor->getRightNode());
			successor->setRightNode(current_Node->getRightNode());
		}
		successor->setLeftNode(current_Node->getLeftNode());


		if (current_Node == m_root)
		{
			m_root = successor;
		}
		else if(isLeftNode == true)
		{
//			current_Node = parent_Node->getLeftNode();
			parent_Node->setLeftNode(successor);
		}
		else
		{
//			current_Node = parent_Node->getRightNode();
			parent_Node->setRightNode(successor);
		}
	}

	current_Node->setLeftNode(nullptr);
	current_Node->setRightNode(nullptr);
	delete current_Node;

	return true;
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

void BinaryTree::_display_PreOrder(TreeNode* i_node)
{
	if (i_node != nullptr)
	{
		printf("%d ", i_node->getKey());
		_display_PreOrder(i_node->getLeftNode());
		_display_PreOrder(i_node->getRightNode());
	}
}

void BinaryTree::_display_InOrder(TreeNode * i_node)
{
	if (i_node != nullptr)
	{
		_display_InOrder(i_node->getLeftNode());
		printf("%d ", i_node->getKey());
		_display_InOrder(i_node->getRightNode());
	}
}

void BinaryTree::_display_PostOrder(TreeNode * i_node)
{
	if (i_node != nullptr)
	{
		_display_PostOrder(i_node->getLeftNode());
		_display_PostOrder(i_node->getRightNode());
		printf("%d ", i_node->getKey());
	}
}

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
		// randomize the keys
		std::random_shuffle(keyBase.begin(), keyBase.end());

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
	printf("success!!!\n");
}
