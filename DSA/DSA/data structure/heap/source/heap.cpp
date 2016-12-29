#include "..\heap.h"

void Heap::_push(int i_key)
{
	m_heap.push_back(i_key);

	int index = static_cast<int>(m_heap.size() - 1);
	int tmp_key = m_heap[index];
	int index_parent = (index - 1) / 2;

	while (index > 0 && tmp_key >= m_heap[index_parent])
	{
		m_heap[index] = m_heap[index_parent];
		index = index_parent;
		index_parent = (index_parent - 1) / 2;
	}

	m_heap[index] = tmp_key;
}

void Heap::_pop()
{
	int index = 0;
	m_heap[index] = m_heap[static_cast<int>(m_heap.size() - 1)];
	int tmp_key = m_heap[index];
	m_heap.pop_back();

	int index_current = 0;
	int index_L = 0;
	int index_R = 0;

	while (index < static_cast<int>(m_heap.size() / 2) )
	{
		index_L = 2 * index + 1;
		index_R = index_L + 1;

		if (index_R < static_cast<int>(m_heap.size()) && m_heap[index_L] < m_heap[index_R])
		{
			index_current = index_R;
		}
		else
		{
			index_current = index_L;
		}

		if (tmp_key >= m_heap[index_current])
		{
			break;
		}

		m_heap[index] = m_heap[index_current];
		index = index_current;
	}

	if (!m_heap.empty())
	{
		m_heap[index] = tmp_key;
	}
}

int Heap::_peek()
{
	return m_heap[0];
}
