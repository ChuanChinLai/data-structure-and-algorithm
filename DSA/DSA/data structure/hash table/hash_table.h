#pragma once
#include <general\Assert.h>
#include <general\math\math.h>

class HashItem
{
public:
	HashItem(): m_key(-1)
	{

	}

	int getKey() const;
	void setKey(const int i_key);

	int getObject() const;
	void setObject(const int i_object);

	bool operator==(HashItem &i_item);
	void operator=(HashItem &i_item);

private:
	int m_key;
	int m_object;
};

class HashTable
{
public:
	HashTable(size_t i_size): m_size(0), m_TotalItems(0), m_table(nullptr)
	{
		ASSERT(i_size > 0);
		m_size = GetNextPrimeNumber(i_size);
		m_table = new HashItem[m_size];
	}

	~HashTable()
	{
		if (m_table != nullptr)
		{
			delete[] m_table;
			m_table = nullptr;
		}
	}

	int HashFunction(int i_key);

	bool _insert(int i_key, int i_Object);
	bool _delete(int i_key);
	bool _find(int i_key, int* i_pObject);

	size_t getSize() const;

private:

	size_t m_size;
	size_t m_TotalItems;
	HashItem* m_table;
};

extern void Hash_Table_UnitTest();