#include <iostream>
#include <string>

using namespace std;

template<typename Type>
struct Node2 {
	Type element;
	Node2<Type>* NextEl;
	Node2<Type>* PreviosEl;
	Node2(Type el) :element(el), NextEl(nullptr), PreviosEl(nullptr) {}
};


template<typename Type>
class DoubleList {
private:
	Node2<Type>* FirstEl;
	Node2<Type>* LastEL;

public:
	DoubleList() :FirstEl(nullptr), LastEL(nullptr) {}

	void push_back(Type el) {
		Node2<Type>* Pointer = new Node2<Type>(el);
		if (FirstEl == nullptr) {
			FirstEl = Pointer;
			LastEL = Pointer;
		}
		else {
			LastEL->NextEl = Pointer;
			Pointer->PreviosEl = LastEL;
			LastEL = Pointer;
		}
	}

	void push_front(Type el) {
		Node2<Type>* Pointer = new Node2<Type>(el);
		if (FirstEl == nullptr) {
			FirstEl = Pointer;
			LastEL = Pointer;
		}
		else {
			Pointer->NextEl = FirstEl;
			FirstEl = Pointer;
		}

	}

	Node2<Type>* back() {
		return LastEL;
	}

	Node2<Type>* front() {
		return FirstEl;
	}

	int size() {
		if (FirstEl == nullptr) {
			return 0;
		}
		else {
			Node2<Type>* point = FirstEl;
			int countElements = 1;
			while (point->NextEl != nullptr) {
				countElements++;
				point = point->NextEl;
			}
			return countElements;
		}
	}

	bool empty() {
		if (FirstEl == nullptr) {
			return 1;
		}
		else return 0;
	}

	void insert(int position, Type el) {
		if (position < size()) {
			if (position == 0) {
				push_front(el);
			}
			else
			{
				Node2<Type>* newEl = new Node2<Type>(el);
				Node2<Type>* point = FirstEl;
				int countElements = 1;
				while (countElements != position) {
					countElements++;
					point = point->NextEl;
				}
				newEl->NextEl = point->NextEl;
				point->NextEl = newEl;
			}
		}
		else
		{
			if (position == size()) {
				push_back(el);
			}
			else
			{
				Node2<Type>* newEl = new Node2<Type>(el);
				Node2<Type>* point = LastEL;
				int countElements = size();
				while (countElements != position) {
					countElements--;
					point = point->PreviosEl;
				}
				newEl->PreviosEl = point->PreviosEl;
				point->PreviosEl = newEl;
			}
		}
	}

	void pop_back() {
		Node2<Type>* DelEl = LastEL;
		LastEL->PreviosEl->NextEl = nullptr;
		LastEL = LastEL->PreviosEl;
		delete DelEl;
	}

	void pop_front() {
		Node2<Type>* DelEl = FirstEl;
		FirstEl->NextEl->PreviosEl = nullptr;
		FirstEl = FirstEl->NextEl;
		delete DelEl;
	}

	void remove(Type DeleteEL) {
		Node2<Type>* point = FirstEl;
		Node2<Type>* lastPoint = FirstEl;
		while (point->NextEl != nullptr) {
			if (point->element == DeleteEL) {
				if (point == FirstEl) pop_front(); else {
					if (point == LastEL) pop_back(); else
					{
						lastPoint->NextEl = point->NextEl;
						Node2<Type>* TimePoint = point;
						point = point->NextEl;
						point->PreviosEl = lastPoint;
						delete TimePoint;
					}
				}
			}
			else
			{
				lastPoint = point;
				point = point->NextEl;
			}
		}
	}

	Type& operator [] (int id) {
		if (FirstEl == nullptr) {
			std::cout << "MissingEl";
		}
		else
		{
			Node2<Type>* point = FirstEl;
			for (int i = 0; i < id; i++) {
				point = point->NextEl;
				if (point == nullptr) {
					std::cout << "MissingEl";
				}
			}
			return point->element;
		}
	}
};
