#pragma once
class IntArray
{
private:
	int m_langth{};
	int* m_data{};

public:
	IntArray() = default;
	IntArray(int langth) : m_langth(langth)
	{
		if (langth == 0)
		{
			throw "The length is zero!";
		}

		if (langth > 0)
		{
			m_data = new int[langth] {};
		}
	}
	virtual ~IntArray()
	{
		delete[] m_data;
	}

	void erase()
	{
		delete[] m_data;
		m_data = nullptr;
		m_langth = 0;
	}

	int& operator[] (int index)
	{
		if (index >= 0 && index < m_langth)
		{
			return m_data[index];
		}
		else
		{
			throw "Index out of range!";
		}
	}

	void reallocate(int newLength)
	{
		erase();

		if (newLength <= 0)
			return;

		m_data = new int[newLength];
		m_langth = newLength;
	}

	void resize(int newLength)
	{
		
		if (newLength == m_langth)
			return;

		
		if (newLength <= 0)
		{
			erase();
			return;
		}

		int* data{ new int[newLength] };

		if (m_langth> 0)
		{
			int elementsToCopy{ (newLength > m_langth) ? m_langth : newLength };

			
			for (int index{ 0 }; index < elementsToCopy; ++index)
				data[index] = m_data[index];
		}

		delete[] m_data;

		m_data = data;
		m_langth = newLength;
	}

	void insertBefore(int value, int index)
	{
		// Sanity check our index value
		if (index >= 0 && index <= m_langth)
		{
			// First create a new array one element larger than the old array
			int* data{ new int[m_langth + 1] };

			// Copy all of the elements up to the index
			for (int before{ 0 }; before < index; ++before)
				data[before] = m_data[before];

			// Insert our new element into the new array
			data[index] = value;

			// Copy all of the values after the inserted element
			for (int after{ index }; after < m_langth; ++after)
				data[after + 1] = m_data[after];

			// Finally, delete the old array, and use the new array instead
			delete[] m_data;
			m_data = data;
			++m_langth;
		}
		else
		{
			throw "Bad_range. Index out of range!";
		}
	}

	void remove(int index)
	{
		// Sanity check our index value
		if (index >= 0 && index <= m_langth)
		{
			// If we're removing the last element in the array, we can just erase the array and return early
			if (m_langth == 1)
			{
				erase();
				return;
			}

			// First create a new array one element smaller than the old array
			int* data{ new int[m_langth - 1] };

			// Copy all of the elements up to the index
			for (int before{ 0 }; before < index; ++before)
				data[before] = m_data[before];

			// Copy all of the values after the removed element
			for (int after{ index + 1 }; after < m_langth; ++after)
				data[after - 1] = m_data[after];

			// Finally, delete the old array, and use the new array instead
			delete[] m_data;
			m_data = data;
			--m_langth;
		}
		else
		{
			throw "Bad_range. Index out of range!";
		}
	}

	// A couple of additional functions just for convenience
	void insertAtBeginning(int value) { insertBefore(value, 0); }
	void insertAtEnd(int value) { insertBefore(value, m_langth); }

	int getLength() const 
	{
		return m_langth;
	}
};
