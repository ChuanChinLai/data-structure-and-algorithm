#include "..\heap.h"

void Heap::_push(int i_key)
{
	m_heap.push_back(i_key);

	int index = static_cast<int>(m_heap.size() - 1);
	int index_parent = (index - 1) / 2;

	while (index > 0 && m_heap[index_parent] <= i_key)
	{
		m_heap[index] = m_heap[index_parent];
		index = index_parent;
		index_parent = (index - 1) / 2;
	}
	
	m_heap[index] = i_key;
}

void Heap::_pop()
{
	int index = 0;
	int tmp = m_heap.back();
	m_heap[index] = tmp;
	m_heap.pop_back();

	int index_parent = 0;
	int debug = 0;
	int index_L = 0;
	int index_R = 0;

	while (index < static_cast<int>(m_heap.size() / 2))
	{
		debug = index;
		index_L = index * 2 + 1;
		index_R = index_L + 1;

		if (index_R < m_heap.size() && m_heap[index_R] > m_heap[index_L])
		{
			index = index_R;
		}
		else
		{
			index = index_L;
		}

		if (m_heap[index] <= tmp)
		{
			break;
		}

		m_heap[index_parent] = m_heap[index];
		index_parent = index;
	}

	if (!m_heap.empty())
	{
//		printf("%d  %d\n", index_parent, debug);
		m_heap[index_parent] = tmp;
	}

}

int Heap::_peek() const
{
	return m_heap[0];
}
