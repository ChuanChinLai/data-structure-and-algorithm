#include <data structure\hash table\hash_table.h>
/*
template<typename T>
bool HashTable<T>::_insert(int i_key, T& i_Object)
{
	
	if (m_TotalItems == m_size)
		return false;
	
	int hash = HashFunction(i_key);

	while (m_table[hash].getKey() != -1)
	{
		hash++;
		hash = HashFunction(i_key);
	}

	m_table[hash].setKey(i_key);
	m_table[hash].setObject(i_Object);

	m_TotalItems++;
	return true;
}

template<typename T>
bool HashTable<T>::_delete(int i_key)
{
	int hash = HashFunction(i_key);
	int init_hash = hash;

	while (m_table[hash].getKey() != -1)
	{
		if (m_table[hash].getKey() == i_key)
		{
			m_table[hash].setKey(-1);
			m_TotalItems--;
			return true;
		}

		hash++;
		hash = HashFunction(hash);

		if (init_hash == hash)
			return false;
	}
	return false;
}

template<typename T>
bool HashTable<T>::_find(int i_key, T * o_Object)
{
	int hash = HashFunction(i_key);
	int init_hash = hash;

	while (m_table[hash].getKey() != -1)
	{
		if (m_table[hash].getKey() == i_key)
		{
			*i_pObject = m_table[hash].getObject();
			return true;
		}

		hash++;
		hash = HashFunction(hash);

		if (hash == init_hash)
		{
			return false;
		}

	}
	return false;
}
*/