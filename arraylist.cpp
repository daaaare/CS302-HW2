#include "arraylist.h"

template<class ItemType>
ArrayList<ItemType>::ArrayList() : maxCount(DEFAULT_CAPACITY), itemCount(0){}

//creates a deep copy
template<class ItemType>
ArrayList<ItemType>::ArrayList(const ArrayList<ItemType>& aList){
	//copy number of items in list
	itemCount = aList.itemCount;
	//copy the max capacity of the list
	maxCount = aList.maxCount;

	//loops through each element
	for(int i = 0; i < itemCount; i++){
		items[i] = aList.items[i]; //creates a deep copy of each element
	}
}

//checks if list is empty
template<class ItemType>
bool ArrayList<ItemType>::isEmpty() const{

	return itemCount == 0;
}

template<class ItemType>
int ArrayList<ItemType>::getLength() const{
	return itemCount;
}

template<class ItemType>
bool ArrayList<ItemType>::insert(int newPosition, const ItemType& newEntry){
	bool ableToInsert = (newPosition >= 1) &&
                            (newPosition <= itemCount + 1) &&
                            (itemCount < maxCount);
	if (ableToInsert){
		for(int pos = itemCount + 1; pos > newPosition; pos--){
			items[pos] = items[pos - 1];
        	}
        	items[newPosition] = newEntry;
        	itemCount++;
    	}
    	return ableToInsert;
}

template<class ItemType>
bool ArrayList<ItemType>::remove(int position){
	//Check if position is within range (not less than 1 and not greater than number of items on list)
	bool abltToRemove = (position >= 1) && (position <= itemCount);
	//if position is valid then "able to remove"
	if(abltToRemove){
		//shift elemnts down to fill the gap left by the removed item
		for(int pos = position; pos < itemCount; pos++){
			items[pos - 1]= items[pos];
		}
		itemCount--;
	}
	//return true if the item was removed otherwise false
	return abltToRemove;
}

template<class ItemType>
void ArrayList<ItemType>::clear(){
	itemCount = 0;
}

template<class ItemType>
ItemType ArrayList<ItemType>::getEntry(int position) const {
	bool ableToGet = (position >= 1) && (position <= itemCount);

	if (ableToGet){
		return items[position];
	} 
	throw "Item not found";
} 

template<class ItemType>
ItemType ArrayList<ItemType>::replace(int position, const ItemType& newEntry){
		//Checks if the position is within range of the list (not less than one and not greater than number of items on list)
    	bool ableToReplace = (position >= 1) && (position <= itemCount);
		if (ableToReplace){
			//if able to replace saves the old entry before it gets overwritten
			ItemType oldEntry = items[position - 1]; //adjust index because 0 (zero based indexing)

			//set new item at the new position
			items[position - 1] = newEntry;

			//return previous item if needed
			return oldEntry;
		} else {
			//else throws an error
			throw "Invalid position";
		}
}
