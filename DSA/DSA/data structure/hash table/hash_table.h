#pragma once
#include <general\Assert.h>
#include <general\math\math.h>

template<typename T>
class HashItem
{
public:
	HashItem(): m_key(-1)
	{

	}

	int getKey() const
	{
		return m_key;
	}

	void setKey(const int i_key)
	{
		m_key = i_key;
	}

	T getObject() const
	{
		return m_object;
	}

	void setObject(const T i_object)
	{
		m_object = i_object;
	}

	bool operator==(HashItem &i_item)
	{
		return (m_key == i_item.getKey());
	}

	void operator=(HashItem &i_item) 
	{
		m_key = i_item.getKey();
		m_object = i_item.getObject();
	}

private:
	int m_key;
	T m_object;
};


template<typename T>
class HashTable
{
public:
	HashTable(size_t i_size): m_size(0), m_TotalItems(0), m_table(nullptr)
	{
		ASSERT(i_size > 0);
		m_size = GetNextPrimeNumber(i_size);
		m_table = new HashItem<T>[m_size];
	}

	~HashTable()
	{
		if (m_table != nullptr)
		{
			delete m_table;
			m_table = nullptr;
		}
	}

	int HashFunction(int i_key)
	{
		return i_key % m_size;
	}

	bool _insert(int i_key, T &i_Object) 
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
	bool _delete(int i_key)
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
	bool _find(int i_key, T* i_pObject)
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

private:

	size_t m_size;
	size_t m_TotalItems;
	HashItem<T>* m_table;
};


