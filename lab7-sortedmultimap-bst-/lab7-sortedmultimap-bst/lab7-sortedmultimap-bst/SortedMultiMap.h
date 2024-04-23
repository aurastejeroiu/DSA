#pragma once

#include "DynamicArray.h"

#include <vector>

typedef int TKey;
typedef int TValue;

#include <utility>

typedef std::pair<TKey, TValue> TElem;

using namespace std;

typedef bool(*Relation)(TKey, TKey);

typedef struct BSTNode {
	TKey key;
	DynamicArray<TValue> values;
	BSTNode* left;
	BSTNode* right;
} BSTNode;

typedef struct BST {
	BSTNode* root;
	int size;
} BST;

class SMMIterator;

class SortedMultiMap {

	friend class SMMIterator;

private:

	/* representation of the SortedMultiMap */

	BST bst;
	Relation relation;

	BSTNode* initNode(TKey c, TValue v);
	BSTNode* insertRec(BSTNode* node, TKey c, TValue v);

	BSTNode* minimum(BSTNode* node);
	BSTNode* removeRec(BSTNode* node, TKey c, TValue v, bool& found);

	void destroyRec(BSTNode* node);

	void keySetRec(BSTNode* node, vector<TKey>& keys) const;

public:



	// constructor

	SortedMultiMap(Relation r);



	//adds a new key value pair to the sorted multi map

	void add(TKey c, TValue v);



	//returns the values belonging to a given key

	vector<TValue> search(TKey c) const;



	//removes a key value pair from the sorted multimap

	//returns true if the pair was removed (it was part of the multimap), false if nothing is removed

	bool remove(TKey c, TValue v);



	//returns the number of key-value pairs from the sorted multimap

	int size() const;



	//verifies if the sorted multi map is empty

	bool isEmpty() const;



	// returns an iterator for the sorted multimap. The iterator will returns the pairs as required by the relation (given to the constructor)	

	SMMIterator iterator() const;


	//returns a vector with all the keys from the SortedMultiMap

	vector<TKey> keySet() const;


	// destructor

	~SortedMultiMap();

};
