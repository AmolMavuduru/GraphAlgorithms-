//
//  DoubleLinkedList.h
//  ProjectLinkedList
//
//  Created by Amol on 11/11/16.
//  Copyright © 2016 Amol. All rights reserved.
//
//Programmer: Amol Mavuduru
//Assignment: Project 3: Double Linked Lists
//This file implements a doubly linked list as a template class that can be applied to any object given the necessary relational operators.

#ifndef DoubleLinkedList_h
#define DoubleLinkedList_h

#include <iostream>
#include <iomanip>
#include <cstddef>
#include <stdio.h>


// forward declaration of the template class DoubleLinkedList
template <class DataType>
class DoubleLinkedList;

template <class DataType>
class OrderedDoubleLinkedList;


// ListNode class
template <class DataType>
class ListNode
{
    // make DoubleLinkedList<DataType> a friend class
    friend class DoubleLinkedList<DataType>;
    friend OrderedDoubleLinkedList<DataType>;
    
    
private:
    // contains the actual data
    DataType dataType;
    // pointer to the next item in the list or nullptr
    // if at the end
    ListNode<DataType>* pNext;
    // pointer to the previous item in the list or nullptr
    // if at the start
    ListNode<DataType>* pPrevious;
public:
    // default constructor
    ListNode();
    // copy constructor
    ListNode(const DataType &newItem);
    // get the next node
    ListNode* next() const;
    // get the previous node
    ListNode* previous() const;
    // return the data stored in the node as a const
    const DataType& data() const;
    // return the data stored in the node
    DataType& data();
private:
    // update the next node
    void next(ListNode *nextNode);
    // update the previous node
    void previous(ListNode *previousNode);
};

// DoubleLinkedList class
template<class DataType>
class DoubleLinkedList
{
private:
    // number of nodes in the list. Note that std::size_t
    // is defined in header file cstddef.
    std::size_t numberNodes;
    // point to the first node or nullptr for empty list
    ListNode<DataType>* firstNode;
    // point to the last node or nullptr for empty list
    ListNode<DataType>* lastNode;
public:
    // default constructor
    DoubleLinkedList();
    // copy constructor
    DoubleLinkedList(const DoubleLinkedList &other);
    // destructor
    virtual ~DoubleLinkedList();
    // return the number of nodes in the list
    std::size_t size() const;
    // return true if the list is empty
    bool empty() const;
    // display the contents of the list to std::cout
    void print() const;
    // dump the contends in debug format to passed in
    // ostream - usage to cout would be:
    //   list.debug(std::cout);
    void debug(std::ostream &out) const;
    // first node in the list (or nullptr for empty)
    virtual ListNode<DataType>* first() const;
    // last node in the list (or nullptr for empty)
    virtual ListNode<DataType>* last() const;
    // add an item to the front of the list
    virtual void push_front(const DataType &newItem);
    // add an item to the back of the list
    virtual void push_back(const DataType &newItem);
    // remove an item from the front of the list
    virtual void pop_front();
    // remove an item from the back of the list
    virtual void pop_back();
    // insert newItem before the existingNode
    virtual void insert_before (ListNode<DataType>* existingNode,
                                const DataType &newItem);
    // insert newItem after the existingNode
    virtual void insert_after (ListNode<DataType>* existingNode,
                               const DataType &newItem);
    // find the node and return the address to the node. Return
    // nullptr if not found
    virtual ListNode<DataType>* find(const DataType &existingItem);
    // remove the node equal to currentItem
    virtual bool erase(const DataType &currentItem);
    // remove the node by address existingNode
    virtual bool erase(ListNode<DataType> *existingNode);
};

// your implementation code goes here
template<class DataType>
ListNode<DataType>::ListNode() //Default constructor
{
    //Sets both pointers equal to nullptr
    pNext = nullptr;
    pPrevious = nullptr;
    
    
}

template<class DataType>
ListNode<DataType>::ListNode(const DataType &newItem)//Copy constructor
{
    dataType = newItem;
    pNext = nullptr;
    pPrevious = nullptr;
    
}


template<class DataType>
ListNode<DataType>* ListNode<DataType>::next()const
{
    return pNext; //gets the node that the next pointer points to
}

template<class DataType>
ListNode<DataType>* ListNode<DataType>::previous()const
{
    return pPrevious; //gets the node that the previous pointer points to.
}

template<class DataType>
const DataType& ListNode<DataType>::data()const
{
    return dataType;
}

template<class DataType>
DataType& ListNode<DataType>::data()
{
    return dataType;
}

template<class DataType>
void ListNode<DataType>::next(ListNode *nextNode)
{
    //update the next node
    ListNode<DataType>* current;
    current = pNext;
    pNext = nextNode;
    delete current;
    
}

template<class DataType>
void ListNode<DataType>::previous(ListNode *previousNode)
{
    //update the previous node
    ListNode<DataType>* current;
    current = pPrevious;
    pPrevious = previousNode;
    delete current;
}

//All of the methods for DoubleLinkedList class below:

template<class DataType>
DoubleLinkedList<DataType>::DoubleLinkedList() //default constructor
{
    firstNode = nullptr;
    lastNode = nullptr;
    numberNodes = 0;
    
}

template<class DataType>
DoubleLinkedList<DataType>::DoubleLinkedList(const DoubleLinkedList &other) //copy constructor
{
    ListNode<DataType> *newNode;
    ListNode<DataType> *current;
    
    if(other.first() == nullptr)  //If the other list is empty
    {
        firstNode = nullptr; //Initialize both pointers to nullptr
        lastNode = nullptr;
        numberNodes = 0;
    }
    else
    {
        current = other.first();
        
        numberNodes = other.size();
        
        firstNode = new ListNode<DataType>;
        firstNode->dataType = current->dataType;
        firstNode->pNext = nullptr;
        
        lastNode = firstNode;
        
        current = current->pNext;
        
        while(current != nullptr)
        {
            newNode = new ListNode<DataType>;
            newNode->dataType = current->dataType;
            newNode->pNext = current->pNext;
            
        }
    }
    
}

template<class DataType>
DoubleLinkedList<DataType>::~DoubleLinkedList() //Destructor deletes all nodes in list.
{
    ListNode<DataType> *temp;
    
    while(firstNode != nullptr) //While there are nodes in the list
    {
        temp = firstNode;   //set temp to first node
        firstNode = firstNode->pNext; //advance firstNode to the next node
        delete temp; //delete temp
    }
    
    lastNode = nullptr;
    numberNodes = 0;
}

template<class DataType>
std::size_t DoubleLinkedList<DataType>::size()const
{
    return numberNodes; //Returns the number of nodes
}

template<class DataType>
bool DoubleLinkedList<DataType>::empty()const
{
    if(firstNode == nullptr) //If the number of nodes is zero
    {
        return true;  //The list is empty.
    }
    else
    {
        return false;
    }
}

template<class DataType>
void DoubleLinkedList<DataType>::print()const
{
    ListNode<DataType>* current;
    current = firstNode;
    
    while(current != nullptr)
    {
        std::cout << current->dataType<< " ";
        current = current->pNext;
        std::cout << " " << std::endl;
    }
}

template<class DataType>
ListNode<DataType>* DoubleLinkedList<DataType>::first()const
{
    return firstNode; //return the first node.
}

template<class DataType>
ListNode<DataType>* DoubleLinkedList<DataType>::last()const
{
    
    return lastNode; //return the last node
}

template<class DataType>
void DoubleLinkedList<DataType>::push_front(const DataType &newItem) //FIX THIS
{
    ListNode<DataType> *current; //this pointer will be used to traverse the list
    ListNode<DataType> *afterCurrent; //this is the pointer after the current pointer
    ListNode<DataType> *newNode; //the pointer used to create a new node at the back of the list
    bool found;
    
    newNode = new ListNode<DataType>;
    
    newNode->dataType = newItem;
    newNode->pNext = nullptr; //initialize the next node to nullptr
    newNode->pPrevious = nullptr; //initialize the previous node to nullptr
    
    if(firstNode == nullptr)
    {
        firstNode = newNode;
        lastNode = newNode;
        numberNodes++;
    }
    else
    {
        found = false;
        current = lastNode;
        
        while(current != nullptr && !found)
        {
            if(current->dataType == newItem)
            {
                found = true;
            }
            else
            {
                afterCurrent = current;
                current = current->pPrevious; //In this case, the code is used to iterate through the list from the back of the list to the front
            }
            if(current == lastNode)
            {
                lastNode->pNext = newNode;
                newNode->pPrevious = lastNode;
                lastNode = newNode;
                numberNodes++;
            }
            else
            {
                if(current != nullptr)
                {
                    afterCurrent->pPrevious = newNode;
                    newNode->pNext = afterCurrent;
                    newNode->pPrevious = current;
                    
                }
                else
                {
                    afterCurrent->pPrevious = newNode;
                    newNode->pNext = afterCurrent;
                    firstNode = newNode;
                }
                numberNodes++;
            }
            
        }
    }
    
    
}

template<class DataType>
void DoubleLinkedList<DataType>::push_back(const DataType &newItem) //FIX THIS
{
    
    ListNode<DataType> *newNode; //the pointer used to create a new node at the back of the list
    
    
    newNode = new ListNode<DataType>;
    
    newNode->dataType = newItem;
    newNode->pNext = nullptr;    //initialize next node to nullptr
    newNode->pPrevious = nullptr; //initialize the previous node to nullptr (of course both of these are temporary assignments)
    
    if(firstNode == nullptr) //If the list is empty make newItem the first node.
    {
        //Initialize the first and last nodes to the new node;
        firstNode = newNode;
        lastNode = newNode;
        numberNodes ++; //Increment the number of nodes
    }
    else   //Otherwise insert newItem after the last node.
    {
        lastNode->pNext = newNode;
        newNode->pPrevious = lastNode;
        lastNode = newNode;
        numberNodes++;
    }
    
    
}

template<class DataType>
void DoubleLinkedList<DataType>::pop_front()
{
    
    ListNode<DataType> *current;
    
    if(firstNode != nullptr)
    {
        current = firstNode;
        firstNode = firstNode->pNext;
        
        if(firstNode != nullptr)
        {
            firstNode->pPrevious = nullptr;
        }
        else
        {
            lastNode = nullptr;
        }
        
        numberNodes--;
        delete current;
    }
    
}

template<class DataType>
void DoubleLinkedList<DataType>::pop_back()
{
    
    ListNode<DataType> *current;
    
    if(lastNode != nullptr)
    {
        current = lastNode;
        lastNode = lastNode->pPrevious;
        
        if(lastNode != nullptr)
        {
            lastNode->pNext = nullptr;
        }
        else
        {
            firstNode = nullptr;
        }
        
        numberNodes--;
        delete current;
    }
}

template<class DataType>
void DoubleLinkedList<DataType>::insert_before(ListNode<DataType>*existingNode, const DataType &newitem)
{
    ListNode<DataType> *current;
    ListNode<DataType> *trailCurrent;
    ListNode<DataType> *newNode;
    bool found = false;
    
    newNode = new ListNode<DataType>;
    newNode->dataType = newitem;
    newNode->pPrevious = nullptr;
    newNode->pNext = nullptr;
    
    current = firstNode;
    
    
    while(current != nullptr && !found)
    {
        if (current == existingNode)
        {
            found = true;
        }
        else
        {
            trailCurrent = current;
            current = current->pNext;
        }
        
    }
    
    if(current == firstNode)
    {
        firstNode->pPrevious = newNode;
        newNode->pNext = firstNode;
        firstNode = newNode;
        numberNodes++; //increase the number of nodes
    }
    else
    {
        if(current != nullptr)
        {
            trailCurrent->pNext = newNode;
            newNode->pPrevious = trailCurrent;
            newNode->pNext = current;
            current->pPrevious = newNode;
        }
        else
        {
            trailCurrent->pNext = newNode;
            newNode->pPrevious = trailCurrent;
            lastNode = newNode;
        }
    }
    numberNodes++;
    
}

template<class DataType>
void DoubleLinkedList<DataType>::insert_after(ListNode<DataType>*existingNode, const DataType &newitem)
{
    ListNode<DataType> *current;
    ListNode<DataType> *trailCurrent;
    ListNode<DataType> *newNode;
    bool found = false;
    
    newNode = new ListNode<DataType>;
    newNode->dataType = newitem;
    newNode->pPrevious = nullptr;
    newNode->pNext = nullptr;
    
    trailCurrent = firstNode;
    current = trailCurrent->pNext;
    
    while(current != nullptr && !found)
    {
        if (trailCurrent == existingNode)
        {
            found = true;
        }
        else
        {
            trailCurrent = current;
            current = current->pNext;
        }
        
    }
    
    if(current == firstNode)
    {
        firstNode->pNext = newNode;
        newNode->pPrevious = firstNode;
        firstNode = newNode;
        numberNodes++; //increase the number of nodes
    }
    else
    {
        if(current != nullptr)
        {
            newNode->pPrevious = current;
            newNode->pNext = current;
            current->pPrevious = newNode;
        }
        else
        {
            trailCurrent->pNext = newNode;
            newNode->pPrevious = trailCurrent;
            lastNode = newNode;
        }
    }
    
}

template<class DataType>
ListNode<DataType>* DoubleLinkedList<DataType>::find(const DataType &existingItem)
{
    ListNode<DataType> *current;
    bool found;
    
    if(firstNode != nullptr)
    {
        current = firstNode;
        found = false;
        
        while(current != nullptr && !found)
        {
            if(current->dataType == existingItem)
            {
                found = true;
                return current; //returns address
            }
            else
            {
                current = current->pNext; //to traverse the list
            }
        }
        
        if(!found)
        {
            return nullptr;
        }
    }
    return nullptr;
    //TODO method stub
    
}

template<class DataType>
bool DoubleLinkedList<DataType>::erase(const DataType &currentItem)
{
    ListNode<DataType> *current;
    ListNode<DataType> *trailCurrent;
    
    bool found;
    
    if(firstNode == nullptr)
    {
        found = false;  //cannot delete an item from an empty list
    }
    else if(firstNode->dataType == currentItem) //if the first node contains the item to be deleted.
    {
        current = firstNode;
        firstNode = firstNode->pNext;
        
        if(firstNode != nullptr)
        {
            firstNode->pPrevious = nullptr;
        }
        else
        {
            lastNode = nullptr;
        }
        
        numberNodes--;
        
        found = true;
        
        delete current;
        std::cout << "Item erased!"<<std::endl;
    }
    else
    {
        found = false;
        current = firstNode;
        
        while(current != nullptr && !found)
        {
            if(current->dataType == currentItem)
            {
                found = true;
            }
            else
            {
                current = current->pNext;
            }
        }
        
        if(current == nullptr)
        {
            found = false; //item to be deleted is not in the list
        }
        else if(current->dataType == currentItem)
        {
            trailCurrent = current->pPrevious;
            trailCurrent->pNext = current->pNext;
            
            if(current->pNext != nullptr)
            {
                current->pNext->pPrevious = trailCurrent;
            }
            if(current == lastNode)
            {
                lastNode = trailCurrent;
            }
            
            numberNodes--;
            delete current;
            
            
        }
    }//end else
    
    return found; //returns true if the value was found and false if not
    
    
}//end of function

template<class DataType>
bool DoubleLinkedList<DataType>::erase(ListNode<DataType> *existingNode)
{
    ListNode<DataType> *current;
    ListNode<DataType> *trailCurrent;
    
    bool found;
    
    if(firstNode == nullptr)
    {
        return false;  //cannot delete an item from an empty list
    }
    else if(firstNode == existingNode)
    {
        current = firstNode;
        firstNode = firstNode->pNext;
        
        if(firstNode != nullptr)
        {
            firstNode->pPrevious = nullptr;
        }
        else
        {
            lastNode = nullptr;
        }
        
        numberNodes--;
        
        delete current;
    }
    else
    {
        found = false;
        current = firstNode;
        
        while(current != nullptr && !found)
        {
            if(current == existingNode)
            {
                found = true;
            }
            else
            {
                current = current->pNext;
            }
        }
        
        if(current == nullptr)
        {
            return false;
        }
        else if(current == existingNode)
        {
            trailCurrent = current->pPrevious;
            trailCurrent->pNext = current->pNext;
            
            if(current->pNext != nullptr)
            {
                current->pNext->pPrevious = trailCurrent;
            }
            if(current == lastNode)
            {
                lastNode = trailCurrent;
            }
            
            numberNodes--;
            
            delete current;
        }
    }
    
    return found;
    
}

// note the code for the debug() function is included
// display a debug version of the list
template<class DataType>
void DoubleLinkedList<DataType>::debug(std::ostream &out) const
{
    const unsigned int ADDRWIDTH = 10;
    out << "START DEBUG" << std::endl;
    out << "first  =" << std::setw(ADDRWIDTH) << firstNode;
    out << ", last=" << std::setw(ADDRWIDTH) << lastNode;
    out << ", # nodes=" << size() << std::endl;
    unsigned int count = 1;
    
    for (auto current=firstNode; current!= nullptr; current=current->next())
    {
        out << "node " << std::setw(2) << count;
        out << "=" << std::setw(ADDRWIDTH) << current;
        out << ", next=" << std::setw(ADDRWIDTH)
        << current->next();
        out << ", previous=" << std::setw(ADDRWIDTH) 
        << current->previous();
        out << ", value=" << current->data() << std::endl;
        count++;
    }
    out << "END DEBUG" << std::endl;
}


#endif /* DoubleLinkedList_h */
