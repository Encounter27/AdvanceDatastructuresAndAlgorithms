#ifndef DLIST_H
#define DLIST_H


template<typename T>
class DList
{
	private:
		struct Node
		{
			public:
				T data;
				Node* prev;
				Node* next;

			private:
				Node& operator = (const Node* ob){}
		};

		iterator Head, Tail;

		DList(DList& ob){}
		DList(const DList& ob){}
		DList& operator = (DList& ob){}
		DList& operator = (const DList& ob){}
	public:
		typedef Node* iterator;

		DList();
		~DList();

		void push_front();
		void push_back();
		T& pop_front();
		T& pop_back();
		iterator begin();
		iterator end();
		void erase();
		void clear();
		unsigned size();
		bool empty();
};

template<typename T>
DList::DList()
{
}

template<typename T>
DList::~DList()
{
}

template<typename T>
void DList::push_front()
{
}

template<typename T>
void DList::push_back()
{
}

template<typename T>
T& DList::pop_front()
{
}

template<typename T>
T& DList::pop_back()
{
}

template<typename T>
iterator DList::begin()
{
}

template<typename T>
iterator DList::end()
{
}

template<typename T>
void DList::erase()
{
}

template<typename T>
unsigned DList::size()
{
}

template<typename T>
bool DList::empty()
{
}

#endif
