#include "..\heap.h"

void Heap::_push(int i_key)
{
	m_heap.push_back(i_key);

	int index = m_heap.size() - 1;
	int parent_index = (index - 1) / 2;

	while (index !=  0 && m_heap[index] > m_heap[parent_index])
	{

		m_heap[index] = m_heap[parent_index];
		m_heap[parent_index] = i_key;

		index = parent_index;
		parent_index = (parent_index - 1) / 2;
	}
}

void Heap::_pop()
{
	int current_index = 0;
	int index_L = 0;
	int index_R = 0;

	int tmp = m_heap.back();
	m_heap[0] = tmp;
	m_heap.pop_back();


	while (current_index < m_heap.size() / 2)
	{
		index_L = 2 * current_index + 1;
		index_R = index_L + 1;

		if (index_R < m_heap.size() && m_heap[index_L] < m_heap[index_R])
		{
			if (m_heap[index_R] < tmp)
			{
				break;
			}
			else
			{
				m_heap[current_index] = m_heap[index_R];
				current_index = index_R;
			}
		}
		else
		{
			if (m_heap[index_L] < tmp)
			{
				break;
			}
			else
			{
				m_heap[current_index] = m_heap[index_L];
				current_index = index_L;
			}
		}
	}

	if(!m_heap.empty())
		m_heap[current_index] = tmp;
}

int Heap::_peek() const
{
	return m_heap[0];
}
