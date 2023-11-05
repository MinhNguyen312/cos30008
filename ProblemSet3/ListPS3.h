#pragma once
#include "DoublyLinkedList.h"
#include "DoublyLinkedListIterator.h"
#include <stdexcept>


template<typename T>
class List {
private:
	//	auxilliary definition to simplify node usage
	using Node = DoublyLinkedList<T>;

	Node* fRoot;
	size_t fCount;

public:
	//	auxilliary definition to simplify iterator usage
	using Iterator = DoublyLinkedListIterator<T>;

	List() : fRoot(nullptr),fCount(0) {
	};	//	Default Constructor



	List(const List& aOtherList) : fRoot(nullptr),fCount(0) {

		*this = aOtherList;
		
		
	}; //	Copy constructor



	List& operator=(const List& aOtherList) {
		
		this->~List();
		fCount = 0;
		for (Iterator iter = aOtherList.begin(); iter != aOtherList.end(); iter++) {
			push_back(*iter);
		}
		
		return *this;
	};	//	assignment operator


	~List() {
		while (fRoot != nullptr) {
			if (fRoot != &fRoot->getPrevious()) {
				Node* temp = const_cast<Node*>(&fRoot->getPrevious());
				temp->isolate();
				delete temp;
			}
			else {
				delete fRoot;
				break;
			}
		}
	}; //	Destructor - frees all nodes


	bool isEmpty() const {
		if (fRoot == nullptr) {
			return true;
		}
		return false;
	}; //	is list empty?


	size_t size() const { return fCount; };	//	list size


	void push_front(const T& aElement) {


		Node* lNode = new Node(aElement);
		
		if (fRoot == nullptr) {
			fRoot = lNode;
		}
		else {
			fRoot->push_front(*lNode);
			fRoot = lNode;
		}

		fCount++;

	};	//	adds aElement at front



	void push_back(const T& aElement) {

		Node* lNode = new Node(aElement);

		if (fRoot == nullptr) {
			fRoot = lNode;
		}
		else {
			const_cast<Node*>(&fRoot->getPrevious())->push_back(*lNode);
		}

		fCount++;
	}
	;//	adds aElement at back

	void remove(const T& aElement) {
		Node* removeNode = fRoot;

	


		for (size_t i = 0; i < fCount; i++) {
			if (this->operator[](i) == aElement) {
				removeNode->isolate();
				fCount--;
				break;
			}
			else {
				removeNode = const_cast<Node*>(&removeNode->getNext());
			}
		}
	};	//	remove first match from list

	const T& operator[](size_t aIndex) const {
		size_t lIndexer = 0;
		
		if (aIndex >= fCount) {
			throw std::out_of_range("Index out of bounds.");
		};


		for (const T& element : *this) {
			if (lIndexer == aIndex) {
				return element;
			}

			lIndexer++;
		}

	
	}
	//	list indexer

	Iterator begin() const {
		Iterator iter(fRoot);
		return iter.begin();
	};	//	return a forward iterator


	Iterator end() const {
		Iterator iter(fRoot);
		return iter.end();
	};	//	return a forward end iterator


	Iterator rbegin() const {
		Iterator iter(fRoot);
		return iter.rbegin();
	};	//	return a backward iterator


	Iterator rend() const {
		Iterator iter(fRoot);
		return iter.rend();
	}	//	return a backwards end iterator



	//	move features
	List(List&& aOtherList) :fRoot(nullptr),fCount(0) {
		*this = std::move(aOtherList);
		
	};	//	move constructor
	List& operator=(List&& aOtherList) {

		this->~List();
		for (Iterator iter = aOtherList.begin(); iter != aOtherList.end(); iter++) {
			push_back(*iter);
		}

		aOtherList.fRoot = nullptr;
		aOtherList.fCount = 0;

		return *this;
	};	//	move assignment operator


	void push_front(T&& aElement) {
		Node* lNode = new Node(std::move(aElement));

		if (fRoot == nullptr) {
			fRoot = lNode;
		}
		else {
			fRoot->push_front(*lNode);
			fRoot = lNode;
		}

		fCount++;

	};	//	adds aElement at front


	void push_back(T&& aElement) {
		Node* lNode = new Node(std::move(aElement));

		if (fRoot == nullptr) {
			fRoot = lNode;
		}
		else {
			const_cast<Node*>(&fRoot->getPrevious())->push_back(*lNode);
		}

		fCount++;
	};	//	adds aElement at back

};

