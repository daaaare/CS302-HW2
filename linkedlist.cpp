#include "linkedlist.h"

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const{
	// enforce precondition
	if((position >= 1) && (position <= itemCount)){
		// Count from the beginning of the chain
		Node<ItemType>* curPtr = headPtr;
		for (int skip = 1; skip < position; skip++){
			curPtr = curPtr->getNext();
		}
		return curPtr;
	}
	return nullptr;
} 

template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0){}

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList){
    Node<ItemType>* origChainPtr = aList.headPtr; //point to nodes in original chain
}

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const{
	return itemCount == 0;
}

template<class ItemType>
int LinkedList<ItemType>::getLength() const{
	return itemCount;
}

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry) {
    Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry); //Create a new node
    if (newPosition == 1) { //Inserting at the head
        newNodePtr->setNext(headPtr); //Set new node to point to the old head
        headPtr = newNodePtr; //Update head to be the new node
    } else {
        Node<ItemType>* prevPtr = getNodeAt(newPosition - 1); //Get the node just before the new position
        newNodePtr->setNext(prevPtr->getNext()); //Set new node to point to the next node
        prevPtr->setNext(newNodePtr); //Update previous node to point to the new node
    }
    itemCount++; //Increment the count of items
    return true;
}


template<class ItemType>
bool LinkedList<ItemType>::remove(int position){
	bool ableToRemove = (position >= 1) && (position <= itemCount);
	if (ableToRemove){
		Node<ItemType>* ptrToDelete = nullptr;
		if (position == 1){
			// Remove the first node in the chain
			ptrToDelete = headPtr; // Save pointer to node 
			headPtr = headPtr->getNext();// save pointer to next node
		}
		else{
			// Find node that is before the one to remove
			Node<ItemType>* prevPtr = getNodeAt(position - 1);
			// Point to node to remove
			ptrToDelete = prevPtr->getNext();
			// Disconnect indicated node from chain by connecting the prior node with the one after
			prevPtr->setNext(ptrToDelete->getNext());
		}

		ptrToDelete->setNext(nullptr);
		delete ptrToDelete;
		ptrToDelete = nullptr;
		itemCount--; // Decrease count of entries
	}
	return ableToRemove;
}

template<class ItemType>
void LinkedList<ItemType>::clear() {
    while (headPtr != nullptr) {
        Node<ItemType>* nodeToDeletePtr = headPtr;
        headPtr = headPtr->getNext(); //Move head pointer to the next node
        delete nodeToDeletePtr; //Free memory of the current node
    }
    itemCount = 0; //Reset the item count
}

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const {
    Node<ItemType>* nodePtr = getNodeAt(position); //Get the node at the specified position
    return nodePtr->getItem(); //Return the item stored in the node
}


template<class ItemType>
ItemType LinkedList<ItemType>::replace(int position, const ItemType& newEntry){
	// enforce precondition
	bool ableToReplace = (position >= 1) && (position <= itemCount);
	if (ableToReplace){
		Node<ItemType>* nodePtr = getNodeAt(position);
		ItemType oldEntry = nodePtr->getItem();
		nodePtr->setItem(newEntry);	
		return oldEntry;	
	} 
	throw "Item not found";
}

template<class ItemType>
LinkedList<ItemType>::~LinkedList(){
	clear();
} 
