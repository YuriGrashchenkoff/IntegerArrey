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
		if (langth >= 0)
		{
			m_data = new int[langth] {};
		}
		else
		{
			throw "Bad_length";
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
		
		if (index >= 0 && index <= m_langth)
		{
			int* data{ new int[m_langth + 1] };

			for (int before{ 0 }; before < index; ++before)
				data[before] = m_data[before];

			data[index] = value;

			for (int after{ index }; after < m_langth; ++after)
				data[after + 1] = m_data[after];

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
		if (index >= 0 && index <= m_langth)
		{
			if (m_langth == 1)
			{
				erase();
				return;
			}

			int* data{ new int[m_langth - 1] };

			for (int before{ 0 }; before < index; ++before)
				data[before] = m_data[before];

			for (int after{ index + 1 }; after < m_langth; ++after)
				data[after - 1] = m_data[after];

			delete[] m_data;
			m_data = data;
			--m_langth;
		}
		else
		{
			throw "Bad_range. Index out of range!";
		}
	}

	void insertAtBeginning(int value) { insertBefore(value, 0); }
	void insertAtEnd(int value) { insertBefore(value, m_langth); }

	int getLength() const 
	{
		return m_langth;
	}
};
