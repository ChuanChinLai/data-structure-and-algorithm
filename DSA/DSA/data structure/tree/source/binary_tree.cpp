#include <stdio.h>
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
		TreeNode* parent_Node = nullptr;
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
		TreeNode* temp = current_Node->getRightNode();
		TreeNode* successor = current_Node;
		TreeNode* successorParent = current_Node;

		while (temp != nullptr)
		{
			successorParent = successor;
			successor = temp;
			temp = temp->getLeftNode();
		}

		if (successor != m_root->getRightNode())
		{
			successorParent->setLeftNode(successor->getRightNode());
			successor->setRightNode(current_Node->getRightNode());
		}

		if (m_root == current_Node)
		{
			m_root = successor;
		}
		else if(isLeftNode == true)
		{
			current_Node = parent_Node->getLeftNode();
			parent_Node->setLeftNode(successor);
		}
		else
		{
			current_Node = parent_Node->getRightNode();
			parent_Node->setRightNode(successor);
		}

		successor->setLeftNode(current_Node->getLeftNode());
	}

	current_Node->setLeftNode(nullptr);
	current_Node->setRightNode(nullptr);
	delete current_Node;
}

void BinaryTree::_display_PreOrder()
{
	_display_PreOrder(m_root);
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
