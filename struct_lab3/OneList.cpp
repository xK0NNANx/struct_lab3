#include <iostream>
#include <string>

using namespace std;

template<typename Type>
struct Node {
	Type element;
	Node<Type>* NextEl;
	Node(Type el) :element(el), NextEl(nullptr){}
};


template<typename Type>
class OneList {
private:
	Node<Type>* FirstEl;
	Node<Type>* LastEL;
public:
	OneList() :FirstEl(nullptr), LastEL(nullptr) {}

	OneList(OneList& p) {
		FirstEl = p.FirstEl;
		LastEL = p.LastEL;
	}

	void push_back(Type el) {
		Node<Type>* Pointer = new Node<Type>(el);
		if (FirstEl == nullptr) {
			FirstEl = Pointer;
			LastEL = Pointer;
		}
		else {
			LastEL->NextEl = Pointer;
			LastEL = Pointer;
		}
	}

	void push_front(Type el) {
		Node<Type>* Pointer = new Node<Type>(el);
		if (FirstEl == nullptr) {
			FirstEl = Pointer;
			LastEL = Pointer;
		}
		else {
			Pointer->NextEl = FirstEl;
			FirstEl = Pointer;
		}

	}

	Node<Type>* back() {
		return LastEL;
	}

	Node<Type>* front() {
		return FirstEl;
	}

	int size() {
		if (FirstEl == nullptr) {
			return 0;
		}
		else {
			Node<Type>* point = FirstEl;
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
		if (position == 0) {
			push_front(el);
		}
		else {
			if (position == size()) {
				push_back(el);
			}
			else {
				Node<Type>* newEl = new Node<Type>(el);
				Node<Type>* point = FirstEl;
				int countElements = 1;
				while (countElements != position) {
					countElements++;
					point = point->NextEl;
				}
				newEl->NextEl = point->NextEl;
				point->NextEl = newEl;
			}
		}
	}

	void pop_back() {
		if (LastEL == nullptr) throw "Error";
		Node<Type>* point = FirstEl;
		if (point->NextEl != nullptr) {
			while (point->NextEl->NextEl != nullptr) {
				point = point->NextEl;
			}
		}
		point->NextEl = nullptr;
		delete LastEL;
		LastEL = point;
	}

	void pop_front() {
		if (FirstEl == nullptr) throw "Error";
		Node<Type>* point = FirstEl->NextEl;
		delete FirstEl;
		FirstEl = point;
	}

	void remove(Type DeleteEL) {
		if (LastEL == nullptr) throw "Error";
		Node<Type>* point = FirstEl;
		Node<Type>* lastPoint = FirstEl;
		while (point->NextEl != nullptr) {
			if (point->element == DeleteEL) {
				if (point == FirstEl) {
					pop_front();
					point = FirstEl;
					lastPoint = FirstEl;
				}
				else {
					lastPoint->NextEl = point->NextEl;
					Node<Type>* TimePoint = point;
					point = point->NextEl;
					delete TimePoint;
				}
			}
			else
			{
				lastPoint = point;
				point = point->NextEl;
			}

		}
		if (DeleteEL == LastEL->element) pop_back();
	}

	Type& operator [] (int id) {
		if (FirstEl == nullptr) {
			throw "Error";
		}
		else
		{
			Node<Type>* point = FirstEl;
			for (int i = 0; i < id; i++) {
				point = point->NextEl;
				if (point == nullptr) throw "Error";
			}
			return point->element;
		}
	}


};