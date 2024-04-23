 #include "SortedMultiMap.h"
#include "SMMIterator.h"

// SortedMultiMap constructor.
// The BC = WC = AC = Theta(1). The complexity of the SortedMultiMap(Relation r) method is Theta(1).
SortedMultiMap::SortedMultiMap(Relation r) {
	this->bst.root = NULL;
	this->bst.size = 0;
	this->relation = r;
}

// Method for adding an element in the SortedMultiMap's BST.
// The BC = Theta(log n), AC = WC = Theta(n). The overall complexity of the add(TKey c, TValue v) method is O(h) = O(n).
void SortedMultiMap::add(TKey c, TValue v) {
	this->bst.root = this->insertRec(this->bst.root, c, v);
	this->bst.size++;
}

// Method for initializing an BSTNode that's then added to the tree.
// The BC = AC = WC = Theta(1). The overall complexity of the initNode(TKey c, TValue v) method is Theta(1).
BSTNode* SortedMultiMap::initNode(TKey c, TValue v) {
	BSTNode* node = new BSTNode();
	node->key = c;
	node->values.add(v);
	node->left = NULL;
	node->right = NULL;
	return node;
}

// Method for recursively inserting a node in the tree.
// The BC = Theta(log n), AC = WC = Theta(n). The overall complexity of the insertRec(BSTNode* node, TKey c, TValue v) method is O(h) = O(n).
BSTNode* SortedMultiMap::insertRec(BSTNode* node, TKey c, TValue v) {
	if (node == NULL) {
		node = this->initNode(c, v);
	}
	else if (node->key == c) {
		node->values.add(v);
	}
	else if (this->relation(node->key, c)) {
		node->right = insertRec(node->right, c, v);
	}
	else {
		node->left = insertRec(node->left, c, v);
	}
	return node;
}

// Method for searching for a key in the SortedMultiMap's BST and returning the values associated to it.
// The BC = Theta(log n), AC = WC = Theta(n). The overall complexity of the search(TKey c) method is O(h) = O(n).
vector<TValue> SortedMultiMap::search(TKey c) const {
	vector<TValue> values;

	BSTNode* currentNode = this->bst.root;
	bool found = false;
	while (currentNode != NULL && !found) {
		if (currentNode->key == c) {
			for (int i = 0; i < currentNode->values.getSize(); i++) {
				values.push_back(currentNode->values[i]);
			}
			found = true;
		}
		else if (this->relation(currentNode->key, c)) {
			currentNode = currentNode->right;
		}
		else {
			currentNode = currentNode->left;
		}
	}

	return values;
}

// Method for removing an element from the SortedMultiMap's BST.
// The BC = Theta(log n), AC = WC = Theta(n). The overall complexity of the remove(TKey c, TValue v) method is O(h) = O(n).
bool SortedMultiMap::remove(TKey c, TValue v) {
	bool found = false;
	this->removeRec(this->bst.root, c, v, found);
	if (found) {
		this->bst.size--;
	}
	return found;
}

// Method for finding the minimum node of a subtree.
// The BC = Theta(log n), AC = WC = Theta(n). The overall complexity of the minimum(BSTNode* node) method is O(h) = O(n).
BSTNode* SortedMultiMap::minimum(BSTNode* node) {
	if (node == NULL) {
		return NULL;
	}
	else {
		while (node->left != NULL) {
			node = node->left;
		}
		return node;
	}
}

// Method for recursively removing a node from the tree.
// The BC = Theta(log n), AC = WC = Theta(n). The overall complexity of the removeRec(BSTNode* node, TKey c, TValue v, bool& found) method is O(h) = O(n).
BSTNode* SortedMultiMap::removeRec(BSTNode* node, TKey c, TValue v, bool& found) {
	if (node == NULL) {
		return NULL;
	}
	else if (node->key == c) {
		if (node->values.getSize() != 0) {
			auto compareFn = [v](const TValue& val) { return v == val; };
			int valueIndex = node->values.getIndex(compareFn);
			if (valueIndex != -1) {
				node->values.remove(valueIndex);
				found = true;
			}
		} else {
			found = true;
			if (node->left == NULL && node->right == NULL) {
				return NULL;
			}
			else if (node->left == NULL) {
				return node->right;
			}
			else if (node->right == NULL) {
				return node->left;
			}
			else {
				BSTNode* min = this->minimum(node->right);
				node->key = min->key;
				node->values = min->values;
				node->right = this->removeRec(node->right, min->key, v, found);
				return node;
			}
		}
	}
	else if (this->relation(node->key, c)) {
		node->right = removeRec(node->right, c, v, found);
		return node;
	}
	else {
		node->left = removeRec(node->left, c, v, found);
		return node;
	}
	return node;
}

// Method for getting the size of the SortedMultiMap.
// The BC = WC = AC = Theta(1). The overall complexity of the size() method is Theta(1).
int SortedMultiMap::size() const {
	return this->bst.size;
}

// Method for checking if the SortedMultiMap is empty or not.
// The BC = WC = AC = Theta(1). The overall complexity of the isEmpty() method is Theta(1).
bool SortedMultiMap::isEmpty() const {
	return this->bst.size == 0;
}

// Method for getting an iterator for the current SortedMultiMap.
// The BC = WC = AC = Theta(1). The overall complexity of the iterator() method is Theta(1).
SMMIterator SortedMultiMap::iterator() const {
	return SMMIterator(*this);
}

// Method that returns a vector with all the keys from the SortedMultiMap.
// The BC = Theta(log n), AC = WC = Theta(n). The overall complexity of the keySet() method is O(h) = O(n).
vector<TKey> SortedMultiMap::keySet() const {
	vector<TKey> keys;
	this->keySetRec(this->bst.root, keys);
	return keys;
}

// Recursive method for getting all the keys from a tree.
// The BC = Theta(log n), AC = WC = Theta(n). The overall complexity of the keySetRec(BSTNode* node, vector<TKey>& keys) method is O(h) = O(n).
void SortedMultiMap::keySetRec(BSTNode* node, vector<TKey>& keys) const {
	if (node != NULL) {
		keys.push_back(node->key);
		this->keySetRec(node->left, keys);
		this->keySetRec(node->right, keys);
	}
}

// SortedMultiMap destructor.
// The BC = Theta(log n), WC = AC = Theta(n). The overall complexity of the ~SortedMultiMap() method is O(h) = O(n).
SortedMultiMap::~SortedMultiMap() {
	this->destroyRec(this->bst.root);
}

// Method for recursively destroying a tree.
// The BC = Theta(log n), WC = AC = Theta(n). The overall complexity of the destroyRec(BSTNode* node) method is O(h) = O(n).
void SortedMultiMap::destroyRec(BSTNode* node) {
	if (node != NULL){
		this->destroyRec(node->left);
		this->destroyRec(node->right);
		delete node;
	}
}