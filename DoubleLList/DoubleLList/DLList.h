#pragma once
#include <iostream>

template<class T>
struct Box
{
	Box* next;
	Box* prev;
	T data;

	Box()
	{
		next = nullptr;
		prev = nullptr;
	}
	Box(const T& data, Box* prev = nullptr, Box* next = nullptr)
	{
		this->data = data;
		this->prev = prev;
		this->next = next;
	}
};

template<class T>
class DLList
{
private:
	Box<T>* first;
	Box<T>* last;
	
	int count;

	void copy(const DLList& other);
	void erase();

public:

	DLList();
	DLList(const DLList& other);
	DLList& operator=(const DLList& other);
	~DLList();

	DLList<T> operator + (const T& element)const;
	DLList<T>& operator += (const T& element);

	DLList<T>& pushBack(const T& inf);
	DLList<T>& pushFront(T inf);
	void pushAfter(int pos, const T& inf);
	T& popBack();
	T& popFront();
	void removeAt(T inf);
	T& getFromPos(int index);
	T& operator[](int pos);
	bool member(const T& other);

	void reverse();
	bool empty();
	void sort();

	int getCount()const;

	void print()
	{
		Box<T>* current = this->first;
		while (current != nullptr)
		{
			std::cout << current->data << " ";
			current = current->next;
		}
	}

	template<class E>
	friend std::ostream& operator << (std::ostream&, const DLList<E>&);
};

template<class T>
inline void DLList<T>::copy(const DLList& other)
{
	Box<T>* current = other.first;

	while (current != nullptr)
	{
		pushBack(current->data);
		current = current->next;
	}
}

template<class T>
inline void DLList<T>::erase()
{
	Box<T>* current = this->first;
	Box<T>* save;
	while (current != nullptr)
	{
		save = current->next;
		delete current;
		current = save;
	}

	this->first = nullptr;
	this->last = nullptr;
	this->count = 0;
}

template<class T>
inline DLList<T>::DLList():first(nullptr), last(nullptr), count(0){}

template<class T>
inline DLList<T>::DLList(const DLList<T>& other)
{
	copy(other);
}

template<class T>
inline DLList<T>& DLList<T>::operator=(const DLList<T>& other)
{
	if (this != &other)
	{
		erase();
		copy(other);
	}

	return *this;
}

template<class T>
inline DLList<T>::~DLList()
{
	erase();
}

template<class T>
inline DLList<T> DLList<T>::operator+(const T& element) const
{
	DLList<T> result(*this);
	result += element;
	return result;
}

template<class T>
inline DLList<T>& DLList<T>::operator+=(const T& element)
{
	pushBack(element);
	return *this;
}

template<class T>
inline DLList<T>& DLList<T>::pushBack(const T& inf)
{
	Box<T>* newBox = new Box<T>(inf, this->last, nullptr);
	if (count == 0)
	{
		this->first = newBox;
		this->last = newBox;
	}
	else
	{
		this->last->next = newBox;
		this->last = newBox;
	}

	count++;

	return *this;
}

template<class T>
inline DLList<T>& DLList<T>::pushFront(T inf)
{
	Box<T>* newBox = new Box<T>(inf, nullptr , this->first);

	if (count == 0)
	{
		this->first = newBox;
		this->last = newBox;
	}
	else
	{
		this->first->prev = newBox;
		this->first = newBox;
	}
	count++;
	
	return *this;
}

template<class T>
inline void DLList<T>::pushAfter(int pos, const T& inf)
{
	if (pos >= count)
	{
		pushBack(inf);
		return;
	}
	else if (pos == 0)
	{
		pushFront(inf);
		return;
	}
	
	Box<T>* current = this->first;
	for (int i = 0; i < pos - 1; i++)
	{
		current = current->next;
	}

	Box<T>* newBox = new Box<T>(inf, current, current->next);
	current->next = newBox;
	count++;

}

template<class T>
inline T& DLList<T>::popBack()
{
	if (count == 0) return this->first->data;

	T save = this->last->data;

	Box<T>* crr = this->last->prev;
	delete this->last;
	crr->next = nullptr;
	this->last = crr;

	count--;

	if (count == 0)
	{
		first = nullptr;
		last = nullptr;
	}

	return save;
}

template<class T>
inline T& DLList<T>::popFront()
{
	if (count == 0) return this->first->data;

	T save = this->first->data;

	Box<T>* curr = this->first;
	this->first = first->next;
	this->first->prev = nullptr;
	delete curr;

	count--;

	if (count == 0)
	{
		first = nullptr;
		last = nullptr;
	}

	return save;
}

template<class T>
inline void DLList<T>::removeAt(T inf)
{
	Box<T>* crr = this->first;
	for (int i = 1; i <= count; i++)
	{
		if (crr->data == inf)
		{
			if (i == count)
			{
				popBack();
				return;
			}
			if (i == 1)
			{
				popFront();
				return;
			}
			crr->prev->next = crr->next;
			crr->next->prev = crr->prev;
			delete crr;
			break;
		}
		
		crr = crr->next;
	}
}

template<class T>
inline T& DLList<T>::getFromPos(int index)
{
	if (index >= count) return last->data;
	Box<T>* crr = this->first;
	for (int i = 0; i < index - 1; i++) crr = crr->next;
	return crr->data;
}

template<class T>
inline T& DLList<T>::operator[](int pos)
{
	return getFromPos(pos);
}

template<class T>
inline bool DLList<T>::member(const T& other)
{
	Box<T>* crr = this->first;
	for (int i = 1; i <= count; i++)
	{
		if (crr->data == other) return true;
		crr = crr->next;
	}
	return false;
}

template<class T>
inline void DLList<T>::reverse()
{
	Box<T>* crr = this->first , *savenext;

	for (int i = 1; i <= count; i++)
	{
		savenext = crr->next;
		crr->next = crr->prev;
		crr->prev = savenext;

		crr = savenext;
	}

	savenext = this->first;
	this->first = this->last;
}

template<class T>
inline bool DLList<T>::empty()
{
	return this->first == nullptr;
}

template<class T>
inline void DLList<T>::sort()
{
	

	for (int i = 0; i <= count - 2; i++)
	{
		Box<T>* crr = this->first;
		for (int j = 0; j < count - i - 1; j++)
		{
			if (crr->data > crr->next->data)
			{
				T save = crr->data;
				crr->data = crr->next->data;
				crr->next->data = save;
			}

			crr = crr->next;
		}
	}
}

template<class T>
inline int DLList<T>::getCount() const
{
	return this->count;
}

template<class T>
std::ostream& operator << (std::ostream& out, const DLList<T>& list)
{
	Box<T>* crr = list.first;
	while (crr != nullptr)
	{
		out << crr->data << " ";
		crr = crr->next;
	}
	return out;
}
