#include <iostream>
#include"QueueLinkedList.h"


using namespace std;

class Stack
{
private:

    //write your code here. Add additional private variables if necessary
    Queue list;

public:
    // Constructor
    Stack()
    {
        //write your code here. Initialize additional private variables if necessary
    }
    Stack(int initialCapacity)
    {
       
        //write your code here. Initialize additional private variables if necessary
    }

    // Destructor
    ~Stack()
    {
        clear();
        
    }

    
    // Push an element onto the stack
    void push(int x)
    {
        //write your code here.
        //push the element onto the stack
        list.enqueue(x);

    }

    // Remove and return the top element
    int pop()
    {
       //write your code here. Check if the stack is empty and return -1 if it is.
       //pop the top element and return it
       if (list.length() == 0)
       {
        /* code */
        return -1;

       }

       int size = list.length();
       for (int i = 1; i < size; i++)
       {
        /* code */
        int a = list.dequeue();
        list.enqueue(a);
       }
       return list.dequeue();

       

       
    }

    // Return the top element without removing it
    int top()
    {
        //write your code here. Check if the stack is empty and return -1 if it is.
        //return the top element
        if (list.length() == 0)
        {
            /* code */
            return -1;

        }
        int size = list.length();
         for (int i = 1; i < size; i++)
       {
        /* code */
        int a = list.dequeue();
        list.enqueue(a);
       }

       int val = list.dequeue();
       list.enqueue(val);
       return val;

        


    }

    // Return the number of elements in the stack
    int length()
    {
        //write your code here. Return the number of elements in the stack
        return list.length();

    }

    // Check if the stack is empty
    bool isEmpty()
    {
        //write your code here. Return true if the stack is empty, false otherwise
        return list.isEmpty();

    }

    // Clear the stack
    void clear()
    {
        //write your code here. Clear the stack.
        list.clear();

    }
};