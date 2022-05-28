#include <iostream>

using namespace std;

class Stack
{


    int* stackArray;
    int Size;
    int TOS ;
public:
    Stack (int s)
    {
        TOS = 0;
        Size = s;
        stackArray = new int[Size];

    }

    ~Stack ()
    {
        delete [] stackArray;
    }

    bool isFull ()
    {
        return TOS == Size;
    }

    bool isEmpty()
    {
        return TOS == 0;
    }

    void push (int value)
    {
        if (!isFull())
        {

            stackArray[TOS++] = value;

        }
        else
        {
            cout << "Stack is Full ^_^ \n" ;
        }
    }

    Stack (const Stack& copiedArray)
    {

        TOS = copiedArray.TOS;
        Size = copiedArray.Size;
        stackArray = new int[Size];

        for (int i=0; i <TOS; i++)
        {
            stackArray[i] = copiedArray.stackArray[i];
        }


    }


    int pop ()
    {
        if(!isEmpty())
        {

            return stackArray[--TOS];
        }
        else
        {
            cout << "Stack is Empty T_T \n" ;
        }
    }

    void peek ()
    {

        if (!isEmpty())
        {
            cout << "The Peek Is : " << stackArray[TOS-1] <<endl;
        }
        else
        {
            cout << "Stack is Empty, There is no Peak \n";
        }


    }

    Stack Reverse ()
    {
        Stack Result(this->Size);

        for (int i =0; i <= TOS-1; i++)
        {
            Result.stackArray[i] = stackArray[(TOS-1)-i];

        }

        return Result;
    }

    Stack operator = (const Stack& rightSideObject)
    {

        delete [] stackArray;
        TOS = rightSideObject.TOS;
        Size = rightSideObject.Size;

        stackArray = new int[Size];

        for (int i =0 ; i<TOS; i++)
        {

            stackArray[i] = rightSideObject.stackArray[i];
        }

        return *this;

    }

    int operator[] (int index)
    {
        if (index >=TOS)
        {

            cout << "Invalid Index" <<endl;
            return 0;
        }
        return stackArray[index] ;

    }


    Stack operator+ (const Stack& rightSideObject)
    {
        Stack Result(*this);
        Result.Size = Size +rightSideObject.Size;
        Result.TOS= TOS + rightSideObject.TOS;

        int x = 0;
        for (int i =this->TOS ; i<Result.TOS; i++)
        {

            Result.stackArray[i]= rightSideObject.stackArray[x]  ;
            x++;


        }

        return Result;

    }

    void view ()
    {
        cout << "Items in Stacks are: ";
        for (int i=0; i < TOS ; i++)
        {
            cout << stackArray[i] << " , " ;
        }
        cout << endl;
    }
};


class LinearQueue
{
    int* Queue;
    int Size;
    int front ;
    int back ;

public:
    LinearQueue (int s)
    {
        front = 0;
        back = 0;
        Size = s;
        Queue = new int;
        cout << "Constructor" <<endl;

    }
    ///Copy Constructor
    LinearQueue (const LinearQueue& oldQueue)
    {
        front = oldQueue.front;
        back = oldQueue.back;
        Size = oldQueue.Size;
        Queue = new int [Size];
        for (int i =0; i <Size ; i++)
        {
            Queue[i] = oldQueue.Queue[i];

        }
        cout << "Copy Constructor" <<endl;

    }




    ~LinearQueue ()
    {
        delete[] Queue;
        cout << "Destructor" <<endl;
    }

    bool isFull ()
    {
        return back == Size;
    }

    bool isEmpty()
    {
        if (front >= back)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int enqueue (int value)
    {
        if (!isFull())
        {

            return Queue[back++] = value;

        }
        else
        {
            cout << "Queue is Full ^_^ \n" ;
        }
    }


    int dequeue ()
    {
        if(!isEmpty())
        {

            return Queue[front++];

        }
        else
        {
            cout << "Queue is Empty T_T \n" ;
        }
    }





};



class CircularQueue
{
    int* Queue;
    int Size;
    int front ;
    int back ;

public:
    CircularQueue (int s)
    {
        front = 0;
        back = 0;
        Size = s;
        Queue = new int[Size];

    }

    ~CircularQueue ()
    {
        delete[] Queue;
    }

    bool isFull ()
    {
        return back == Size;
    }

    bool isEmpty()
    {
        if ( front >= back)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue (int value)
    {
        if (!isFull())
        {

            Queue[back++] = value;
            cout << "Number Enqueued is: " <<  Queue[back-1] << endl;

        }
        else
        {
            cout << "Queue is Full ^_^ \n" ;
        }
    }


    void dequeue ()
    {
        if(!isEmpty())
        {

            if (back == 0)
            {
                cout << back ;

            }

            cout << "Number Dequeued is: " << Queue[front] << endl;

            for(int i = 0 ; i < back-1 ; i++)
            {
                Queue[i] = Queue[i+1];
            }

            back = back -1;









            //return Queue[front++];

        }
        else
        {
            cout << "Queue is Empty T_T \n" ;
        }
    }


};







int main()
{

    ///Dynamic Stack

    Stack c1(5);
    c1.push(5);
    c1.push(8);
    c1.push(9);
    c1.view();

    Stack c2(11);
    c2.push(3);
    c2.push(2);
    c2.push(10);
    c2.push(50);
    c2.view();

    Stack c3 = c1 + c2;
    cout << "Stack after adding first & second stack together  : ";
    c3.view();







    ///Linear Queue
    /*
        LinearQueue queue_1(5);
        cout << "Number Enqueued is: " << queue_1.enqueue(3) <<endl;;
        cout << "Number Enqueued is: " << queue_1.enqueue(2) <<endl;;
        cout << "Number Enqueued is: " << queue_1.enqueue(6) <<endl;;
        //ViewContent(queue_1);
        //LinearQueue queue_2(queue_1);
        queue_1.reverseStack();
    */

    /*
    cout << "Number Enqueued is: " << queue_1.enqueue(3) <<endl;;
    cout << "Number Enqueued is: " << queue_1.enqueue(2) <<endl;;
    cout << "Number Enqueued is: " << queue_1.enqueue(6) <<endl;;
    cout << "Number Dequeued is: " <<queue_1.dequeue() <<endl;
    cout << "Number Dequeued is: " <<queue_1.dequeue() <<endl;
    cout << "Number Enqueued is: " << queue_1.enqueue(5) <<endl;
    cout << "Number Dequeued is: " <<queue_1.dequeue() <<endl;
    cout << "Number Enqueued is: " << queue_1.enqueue(7) <<endl;
    cout << "Number Enqueued is: " << queue_1.enqueue(8) <<endl;
    */

    ///Circular Queue

    //CircularQueue cq(5);
    /*
    cout << "Number Enqueued is: " <<cq.enqueue(3) <<endl;
    cout << "Number Enqueued is: " <<cq.enqueue(7) <<endl;
    cout << "Number Enqueued is: " <<cq.enqueue(8) <<endl;
    */
    /*
        cq.enqueue(3);
        cq.enqueue(7);
        cq.enqueue(8);
        cq.dequeue() ;
        cq.dequeue() ;
        cq.dequeue() ;
        cq.dequeue() ;
        cq.enqueue(10) ;
        cq.dequeue() ;

    */
    return 0;
}
