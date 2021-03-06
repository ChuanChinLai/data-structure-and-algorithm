#pragma once
#include <vector>

class Heap
{
public:
	void _push(int i_key);
	void _pop();
	int _peek() const;

private:
	std::vector<int> m_heap;
};