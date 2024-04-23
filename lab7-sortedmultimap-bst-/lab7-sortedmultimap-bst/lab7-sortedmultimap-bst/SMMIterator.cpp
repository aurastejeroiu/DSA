 #include "SMMIterator.h"

// SMMIterator constructor.
// The BC = Theta(log n), AC = WC = Theta(n). The overall complexity of the SMMIterator(const SortedMultiMap & c) method is O(n).
SMMIterator::SMMIterator(const SortedMultiMap & c) : c(c) {
	BSTNode* node = this->c.bst.root;
	while (node != NULL) {
		this->stack.push(node);
		node = node->left;
	}

	if (!this->stack.empty()) {
		this->currentNode = stack.top();
	}
	else {
		this->currentNode = NULL;
	}
	this->valueIndex = 0;
}

// Method for resetting the iterator to the first element of the SMMIterator.
// The BC = Theta(log n), AC = WC = Theta(n). The overall complexity of the first() method is Theta(n).
void SMMIterator::first() {
	while (!this->stack.empty()) {
		this->stack.pop();
	}

	BSTNode* node = this->c.bst.root;
	while (node != NULL) {
		this->stack.push(node);
		node = node->left;
	}

	if (!this->stack.empty()) {
		this->currentNode = stack.top();
	}
	else {
		this->currentNode = NULL;
	}
	this->valueIndex = 0;
}

// Method for advancing the iterator to the next element of the SMMIterator.
// The BC = Theta(log n), AC = WC = Theta(n). The overall complexity of the next() method is O(n).
void SMMIterator::next() {
	if (!this->valid()) {
		throw std::runtime_error("Invalid iterator.");
	}

	if (this->valueIndex < this->currentNode->values.getSize() - 1) {
		this->valueIndex++;
	}
	else {
		BSTNode* node = this->stack.top();
		this->stack.pop();

		if (node->right != NULL) {
			node = node->right;
			while (node != NULL) {
				this->stack.push(node);
				node = node->left;
			}
		}

		if (!this->stack.empty()) {
			this->currentNode = this->stack.top();
		}
		else {
			this->currentNode = NULL;
		}
	}
}

// Method for checking if the validator is valid.
// The BC = WC = AC = Theta(1). The overall complexity of the valid() method is Theta(1).
bool SMMIterator::valid() const {
	return !this->c.isEmpty() && this->currentNode != NULL;
}

// Method for retrieving the current element from the iterator's position.
// The BC = WC = AC = Theta(1). The overall complexity of the getCurrent() method is Theta(1).
TElem SMMIterator::getCurrent() const {
	if (!this->valid()) {
		throw std::runtime_error("Invalid iterator.");
	}
	return std::make_pair(this->currentNode->key, this->currentNode->values[this->valueIndex]);
}
