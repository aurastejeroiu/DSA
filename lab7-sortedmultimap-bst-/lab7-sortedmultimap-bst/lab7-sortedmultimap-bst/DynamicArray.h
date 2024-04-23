#pragma once

#include <functional>
#include <utility>

template <typename TElem>
class DynamicArray {

private:
	TElem* elements;
	int size;
	int capacity;

public:
	// default constructor for a DynamicArray
	DynamicArray(int capacity = 10);

	// copy constructor for a DynamicArray
	DynamicArray(const DynamicArray& array);

	// destructor for a DynamicArray
	~DynamicArray();

	// assignment operator for a DynamicArray
	DynamicArray& operator=(const DynamicArray& array);

	/*
		Overloading the subscript operator
		Input: pos - a valid position within the array.
		Output: a reference to the element o position pos.
	*/
	TElem& operator[](int position);

	// Adds an element to the current DynamicArray.
	void add(TElem element);

	// Updates an element in the current DynamicArray.
	void update(int index, TElem element);

	// Removes an element from the current DynamicArray.
	void remove(int index);

	using CompareFunction = std::function<bool(const TElem&)>;

	int getIndex(CompareFunction compareFunction) const;

	using FilterFunction = std::function<bool(const TElem&)>;

	int getSize() const;

private:
	// Resizes the current DynamicArray, multiplying its capacity by a given factor (real number).
	void resize(double factor = 2);

public:
	class Iterator {

	private:
		TElem* pointerToElement;

	public:
		// constructor with parameter DynamicArray<TElem>
		Iterator(DynamicArray<TElem> array) {
			this->pointerToElement = array.elements;
		}

		// constructor with parameter TElem*
		Iterator(TElem* pointerToElement) {
			this->pointerToElement = pointerToElement;
		}

		// operator++ - pre-incrementing
		Iterator operator++() const {
			this->pointerToElement++;
			return *this;
		}

		// operator++ - post-incrementing
		Iterator operator++(int) {
			Iterator currentIterator = *this;
			this->pointerToElement++;
			return currentIterator;
		}

		// operator== - equality
		bool operator==(const Iterator& iteratorToCompare) {
			return this->pointerToElement == iteratorToCompare.pointerToElement;
		}

		// operator!= - inequality
		bool operator!=(const Iterator& iteratorToCompare) {
			return this->pointerToElement != iteratorToCompare.pointerToElement;
		}

		// dereferencing operator
		TElem operator*() {
			return *this->pointerToElement;
		}
	};

	Iterator begin() {
		return Iterator{ elements };
	}

	Iterator end() {
		return Iterator{ elements + size };
	}
};

template <typename TElem>
DynamicArray<TElem>::DynamicArray(int capacity) {
	this->size = 0;
	this->capacity = capacity;
	this->elements = new TElem[capacity];
}

template <typename TElem>
DynamicArray<TElem>::DynamicArray(const DynamicArray<TElem>& array) {
	this->size = array.size;
	this->capacity = array.capacity;
	this->elements = new TElem[this->capacity];
	for (int i = 0; i < this->size; i++) {
		this->elements[i] = array.elements[i];
	}
}

template <typename TElem>
DynamicArray<TElem>::~DynamicArray() {
	delete[] this->elements;
}

template <typename TElem>
DynamicArray<TElem>& DynamicArray<TElem>::operator=(const DynamicArray<TElem>& arrayToCopy) {
	if (this == &arrayToCopy) {
		return *this;
	}

	this->size = arrayToCopy.size;
	this->capacity = arrayToCopy.capacity;

	TElem* auxiliaryElements = new TElem[this->capacity];

	delete[] this->elements;
	
	this->elements = auxiliaryElements;
	for (int i = 0; i < this->size; i++) {
		this->elements[i] = arrayToCopy.elements[i];
	}

	return *this;
}

template <typename TElem>
TElem& DynamicArray<TElem>::operator[](int position) {
	return this->elements[position];
}

template <typename TElem>
void DynamicArray<TElem>::add(TElem element) {
	if (this->size == this->capacity)
		this->resize();
	this->elements[this->size] = element;
	this->size++;
}

template <typename TElem>
void DynamicArray<TElem>::resize(double factor) {
	this->capacity *= (int)factor;

	TElem* newElements = new TElem[this->capacity];
	for (int i = 0; i < this->size; i++)
		newElements[i] = this->elements[i];

	delete[] this->elements;
	this->elements = newElements;
}

template <typename TElem>
void DynamicArray<TElem>::update(int index, TElem element) {
	if (index > -1 && index < this->size) {
		this->elements[index] = element;
	}
}

template <typename TElem>
void DynamicArray<TElem>::remove(int index) {
	if (index > -1 && index < this->size) {
		this->size--;
		for (int j = index; j < this->size; j++) {
			this->elements[j] = this->elements[j + 1];
		}
	}
}

template <typename TElem>
int DynamicArray<TElem>::getIndex(CompareFunction compareFunction) const {
	for (int i = 0; i < this->size; i++) {
		if (compareFunction(this->elements[i])) {
			return i;
		}
	}
	return -1;
}

template <typename TElem>
int DynamicArray<TElem>::getSize() const {
	return this->size;
}
