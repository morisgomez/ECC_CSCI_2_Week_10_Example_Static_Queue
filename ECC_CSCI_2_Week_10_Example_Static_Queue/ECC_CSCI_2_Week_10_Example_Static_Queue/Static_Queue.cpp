/*
 Program Name: Static_Queue.cpp
 Programmer: Moris Gomez
 Date: Tuesday 04/14/2024
 Version Control: 1.0
 About: Week 10, CSCI 2, Example 1.
 Description:
    Intro to Static Queue using an array. Following along professor's example.
*/

#include <iostream>
using namespace std;

//create class IntQueue:
class IntQueue
{
private:
    int *qArray; //holds the address of the array //used to access it via pointer.
    int qSize; //holds size of the array //how many elements or indexes should it hold?
    int front; //holds the index of the front value in array.
    int rear; //holds the index of the rear value in array.
    int numItems; //holds the number values? # of indexes with an actual value.
    
public:
//FUNCTION 1. constructor:
    IntQueue(int size)
    {
        //creates an array "qArray" w/ data types of int & size of "size" DURING runtime.
        qArray = new int[size]; //dynamic memory allocation at runtime.
        
        //-1 = non-initialized array
        front = -1; //holds index not value. same as qArray[-1];
        rear = -1; //holds index not value. same as qArray[-1];
        numItems = 0; //num of indexes with actual values. array can be sized but have 0 items?
        qSize = size; //size of array.
    } //end constructor.
    
//FUNCTION 2. enqueue():
    void enqueue(int num)
    {
        if(isFull()) //if array is full, no space to insert a value at rear.
        {
            cout << "QUEUE IS FULL, NO SPACE TO ADD NEW VALUES!" << endl;
        }
        else //if not full, space to insert new value at rear.
        {
            rear = (rear + 1) % qSize; //determines new rear (where we insert new value).
            qArray[rear] = num; //the value located at qArray[rear] is assigned to num.
            //NOTE: cannot enqueue to to array w/ empty elemetns in the middle (cannot cut line).
            //NOTE: works only for array w/ empty values at left and right.
            numItems = numItems + 1;
        }
    } //end enqueue() function.

//FUNCTION 3. dequeue():
    void dequeue(int &num) //changes to num in local function scope appear in main.
    //num has the value we want to remove.
    {
        if(isEmpty()) //if array empty, nothing to remove.
        {
            cout << "QUEUE IS EMPTY, NOTHING TO REMOVE!" << endl;
        }
        else //if array has some values, return num from front which is removed.
        {
            //special case. one element in array:
            if(front == rear)
            {
                num = qArray[front]; //num gets value of only index bc the only we can delete.
                front = -1; //reset to array w/ no values so -1 is front & rear.
                rear = -1;
                numItems = 0; //reset num items to zero.
            }
            else //remove value stored in front element:
            {
                num = qArray[front];
                front = (front + 1) % qSize; //new front.
                numItems = numItems - 1;
            } //end inner else.
        } //end outer else.
    } //end dequeue() function.

//FUNCTION 4. isEmpty():
    bool isEmpty() const //const bc no need to change anything in func.
    {
        if(numItems == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    } //end isEmpty() function.

//FUNCTION 5. isFull():
    bool isFull() const
    {
        if(numItems < qSize)
        {
            return false;
        }
        else
        {
            return true;
        }
    } //end isFull() function.
    
//FUNCTION 6. clear():
    void clear()
    {
        front = qSize - 1; //will be at last index.
        rear = qSize -1; //will be at last index.
        numItems = 0;
    } //end clear() function.

//FUNCTION 7. display():
    void display()
    {
        if(numItems == 0)
        {
            cout << "The Queue is empty!" << endl;
        }
        else
        {
            cout << "------queue info so far:------" << endl;
            cout << "size of array: " << qSize <<endl;
            cout << "num of items: " << numItems << endl;
            cout << "front: " << front << endl;
            cout << "rear: " << rear << endl;
            
            for(int i = 0; i < qSize; i++)
            {
                cout << "index " << i << " has value of: " << qArray[i] << endl;
            } //end for loop.
            cout << "------------------------------" << endl;
        } //end else.
    } //end display() function.

}; //close IntQueue class.




int main()
{
    //1. create a static queue w/ size 5:
    IntQueue queueOne(5);
    //queueOne.display(); //empty.
    //2. enqueue 5 values to the queue:
    queueOne.enqueue(3);
    queueOne.enqueue(5);
    queueOne.enqueue(9);
    queueOne.enqueue(21);
    queueOne.enqueue(6);
    queueOne.display();
    //3. remove 2 values from the queue:
    int x = 3;
    queueOne.dequeue(x);
    queueOne.display();
    //front changes from -1 to 0.
    //items = 4.
    //every index still has the same value. front is just the next index. no values actually deleted.
    x = 6;
    queueOne.dequeue(x);
    queueOne.display();
    
    return 0;
}
