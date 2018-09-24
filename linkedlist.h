#ifndef LINKED_LIST
#define LINKED_LIST

#include <iostream>

using namespace std;


template <class T>
class ListNode
{
    template <class U> friend class LinkedList;

    public:
        ListNode(): next(nullptr), prev(nullptr) {}
        ListNode(T val): next(nullptr), prev(nullptr), data(val) {}
        ListNode(const ListNode<T>& rhs): next(nullptr), prev(nullptr), data(rhs.data) {}

        T& get()
        {   return data;    }

    private:
        ListNode<T>* next;
        ListNode<T>* prev;
        T data;
};


//Class ends up acting strange if it is divided between .h and .cpp, so I have to keep it in one file
template<class T>
class LinkedList
{
  private:
    ListNode<T>* front;
    ListNode<T>* end;
    ListNode<T>* iterator;
    int numElements;

    //reshapes the size of the List, should not be used by user
    void resize(int a)
    {
        //ensures that the list is physically possible
        if(a<0)
        {   a = 0;  }

        numElements = a;
    }


  public:

    //constructor
    LinkedList()
    {
        front = nullptr;
        end = nullptr;
        iterator = front;
        numElements = 0;
    }

    //copy constructor
    LinkedList(LinkedList<T>& rhs)
    {
        if(rhs.front==nullptr)
        {   return; }

        this->numElements = rhs.getSize();

        //sets iterator to begining and deep copies the first node
        rhs.setIterator(0);
        ListNode<T>* temp = new ListNode<T>(rhs.getData());
        this->addToFront(temp->get());

        for(int i=1; i<rhs.getSize(); i++)
        {
            rhs.iterateNext();
            ListNode<T>* temp = new ListNode<T>(rhs.getData());
            this->addToEnd(temp->get());
        }
    }


    //returns the size of the List
    int getSize()
    {
        return numElements;
    }

    //returns the data stored within the first node
    T& getFrontData()
    {
        return front->data;
    }

    //returns the data stored within the last node
    T& getEndData()
    {
        return end->data;
    }


    //returns the data stored within the node the iterator is pointing at
    T& getData()
    {
        if(iterator==nullptr)
        {   iterator = front;   }

        return iterator->data;
    }


    //returns the node the iterator is pointing at
    T& getIterator()
    {
        return iterator;
    }

    //increments the iterator to the next slot and returns if it has reached the end or not
    //True = Yes, it has another iteration in the list
    //False = No, it does not have another iteration in the list and is now at the front
    bool iterateNext()
    {
        //resets the iterator to the begining if it reaches the end of the list
        if(iterator->next == nullptr)
        {
            iterator = front;

            //tells the program it has reached the end of list
            return false;
        }

        //will move the iterator to the next node
        else
        {
            iterator = iterator->next;

            //tells the program that it has reached the next node
            return true;
        }
    }

    //specifically sets the iterator to a specific position
    void setIterator(int x)
    {
        //if the number is larger than the list, just point to the last node
        if(x>numElements)
        {   x = numElements;    }

        iterator = front;

        //iterates until it reaches the desired location
        for(int i=0; i<x; i++)
        {   iterateNext();  }

    }

    //adds a node at the front of the list
    void addToFront(T val)
    {
        if(front==nullptr)
        {
            front = new ListNode<T>(val);
            end = front;
        }

        else
        {
            ListNode<T>* temp = new  ListNode<T>(val);
            temp->next = front;
            front = temp;

            //links the next node back to the new node if it is not a trivial list
            if(temp->next != nullptr)
            {
                temp->next->prev = temp;
            }
        }

        resize(getSize()+1);
    }


    //adds a node to the end
    void addToEnd(T val)
    {
        //if the list is empty, add it to the beginning
        if(front==nullptr)
        {
            front = new ListNode<T>(val);
            end = front;
        }

        else
        {
            ListNode<T>* temp = new ListNode<T>(val);

            temp->prev = end;
            temp->prev->next = temp;
            end = temp;
        }

        resize(getSize()+1);
    }


    //removes the node at the front
    void removeFromFront()
    {
        //do nothing if the list is empty
        if(numElements==0)
        {
            cout << "Error: cannot delete an element of a blank list" <<endl;
            return;
        }

        ListNode<T>* temp = front;


        front = temp->next;
        iterator = temp->next;

        //if the list is not empty, adjust the next node
        if(temp->next != nullptr)
        {	temp->next->prev = temp->prev;	}

        delete temp;

        resize(getSize()-1);
    }

    //checks if the value is already inside the LinkedList
    //True = Yes, it is in the list
    //False = No, it is not in the list
    bool checkAll(T val)
    {
        this->setIterator(0);

        for(int i=0; i<this->getSize(); i++)
        {
            //if it finds a match, it is inside the list
            if(this->getData()==val)
            {   return true;   }

            this->iterateNext();
        }

        //if it never found a match, it is not inside the list
        return false;
    }

    //searches for the location of the passed value
    int find(T val)
    {
        this->setIterator(0);

        for(int i=0; i<this->getSize(); i++)
        {
            //if it finds a match, it is at location 'i'
            if(this->getData()==val)
            {   return i;   }

            this->iterateNext();
        }

        //if it never found a match, it is not inside the list
        return -1;
    }


    ~LinkedList()
    {

        ListNode<T>* temp = front;

        while(front != nullptr)
        {
            front = temp->next;
            delete temp;
            temp = front;
        }

    }


};

#endif
