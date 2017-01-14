#include <data structure\hash table\hash_table.h>
#include <general\Assert.h>
#include <algorithm>
#include <vector>

void Hash_Table_UnitTest()
{
	const size_t times = 1024 * 1024;
	size_t index = 0;

	std::vector<HashItem> keyBase;
	HashTable hashtable(times);

	while (index < times)
	{
		index++;
		HashItem item;
		item.setKey(rand() % times);
		item.setObject(rand() % times);

		int foundObject = 0;

		if (!hashtable._find(item.getKey(), &foundObject))
		{
			hashtable._insert(item.getKey(), item.getObject());
			keyBase.push_back(item);
		}
	}

	printf("After add nodes to the hashtable:\n");

	ASSERT(static_cast<size_t>(keyBase.size()) == hashtable.getSize());




	if (!keyBase.empty())
	{
		// randomize the keys
		std::random_shuffle(keyBase.begin(), keyBase.end());

		while (!keyBase.empty())
		{
			HashItem item = keyBase.back();
			keyBase.pop_back();

			int foundObject = 0;

			bool success = hashtable._find(item.getKey(), &foundObject);
			ASSERT(success);
			ASSERT(foundObject == item.getObject());

			success = hashtable._delete(item.getKey());
			ASSERT(success);
		}
	}

	ASSERT(hashtable.getSize() == 0);
	printf("success!!!\n");
	return;
}

int HashItem::getKey() const
{
	return m_key;
}

void HashItem::setKey(const int i_key)
{
	m_key = i_key;
}

int HashItem::getObject() const
{
	return m_object;
}

void HashItem::setObject(const int i_object)
{
	m_object = i_object;
}

bool HashItem::operator==(HashItem & i_item)
{
	return (m_key == i_item.getKey() && m_object == i_item.getObject() );
}

void HashItem::operator=(HashItem & i_item)
{
	m_key = i_item.getKey();
	m_object = i_item.getObject();
}

int HashTable::HashFunction(int i_key)
{
	return i_key % m_size;
}

bool HashTable::_insert(int i_key, int i_Object)
{
	if (m_TotalItems >= m_size)
		return false;
	
	int key = HashFunction(i_key);

	while (m_table[key].getKey() != -1)
	{
		key++;
		key = HashFunction(key);
	}

	m_table[key].setKey(i_key);
	m_table[key].setObject(i_Object);

	m_TotalItems++;
	return true;
}

bool HashTable::_delete(int i_key)
{
	int hash = HashFunction(i_key);
	int initHash = hash;

	while (m_table[hash].getKey() != -1)
	{
		if (m_table[hash].getKey() == i_key)
		{
			m_TotalItems--;
			m_table[hash].setKey(-1);
			return true;
		}
		else
		{
			hash++;
			hash = HashFunction(hash);
		}

		if (hash == initHash)
			return false;
	}
	return false;
}

bool HashTable::_find(int i_key, int * i_pObject)
{
	int hash = HashFunction(i_key);
	int initHash = hash;

	while (m_table[hash].getKey() != -1)
	{
		if (m_table[hash].getKey() == i_key)
		{
			*i_pObject = m_table[hash].getObject();
			return true;
		}
		else
		{
			hash++;
			hash = HashFunction(hash);
		}
		if (hash == initHash)
			return false;
	}
	return false;
}

size_t HashTable::getSize() const
{
	return m_TotalItems;
}
