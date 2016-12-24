#pragma once

class TreeNode
{
public:
	TreeNode(int i_key) : m_left(nullptr), m_right(nullptr), m_key(i_key)
	{

	}
	~TreeNode()
	{
		if (m_left != nullptr)
		{
			delete m_left;
			m_left = nullptr;
		}
		if (m_right != nullptr)
		{
			delete m_right;
			m_right = nullptr;
		}
	}

	inline int getKey() const
	{
		return m_key;
	}

	inline TreeNode* getLeftNode()
	{
		return m_left;
	}

	inline TreeNode* getRightNode()
	{
		return m_right;
	}

	inline void setLeftNode(TreeNode* i_node)
	{
		m_left = i_node;
	}

	inline void setRightNode(TreeNode* i_node)
	{
		m_right = i_node;
	}

private:
	TreeNode* m_left;
	TreeNode* m_right;
	int m_key;
};

class BinaryTree
{
public:
	BinaryTree() : m_root(nullptr)
	{

	}
	~BinaryTree()
	{
		if (m_root != nullptr)
		{
			delete m_root;
			m_root = nullptr;
		}
	}

	bool _push(int i_key);
	bool _search(int i_key);
	bool _delete(int i_key);

	void _display_PreOrder();
	void _display_InOrder();
	void _display_PostOrder();


private:
	TreeNode* m_root;

	void _display_PreOrder(TreeNode* i_node);
	void _display_InOrder(TreeNode* i_node);
	void _display_PostOrder(TreeNode* i_node);
};
