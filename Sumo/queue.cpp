// #include<bits/stdc++.h>
#include <iostream>
using namespace std;

// structure to representt a queue
struct queue
{
    int size;
    int front;
    int rear;
    int element[100]; // you forgot to add this array
    int capacity;
};

// function to create a queue
void queueQ(queue &Q)
{
    Q.size = 0;
    Q.front = -1;
    Q.rear = -1;
    Q.capacity = 50;
}

// queue is full when the capacity of the queue is full
int isFull(queue &Q)
{
    return (Q.size == Q.capacity);
}
// queue is empty whenthe size is zero
int isEmpty(queue &Q)
{
    return (Q.size == 0); //`(Q.size == 0)` this evaluates to true or false
}

// function to add an item to the queue ,it changes rear ad size
void enqueue(queue &Q, int item)
{
    if(Q.front == (Q.rear+1)%Q.capacity){
        cout << "queue is full";
    }
    else{
        if(Q.front == -1) Q.front = 0;
        Q.rear = (Q.rear + 1) % Q.capacity;
        // Q.element[Q.rear] = x; // x is not defined u must use item
        Q.element[Q.rear] = item;
        cout << item << "inserted to queue";
    }
}

// function to delete an item, it changes the front and size
int dequeue(queue &Q)
{
    if (Q.front == -1)
    {
        cout << "queue is empty";
        // since in `int dequeue(queue &Q) int is its return data type
        // take care to return some integer value since queue is empty
        // we retur -1;
        return -1;
    }
    else
    {
        // y=Q.element[Q.front]; // this y is not declared so..
        int y = Q.element[Q.front];
        // add here the condition you always talked about if q.front == q.rear
        if(Q.front == Q.rear){
            Q.front = -1;
            Q.rear = -1;
        }
        else{
            Q.front = (Q.front + 1) % Q.capacity;
        }
        // cout<<item<<"deleted an item"; // dont cout here not requered send it to user
        return y;
    }
}
// void display(){ // Pass here the queue, display dont know what to display
void display(queue Q){ // PASS BY VALUE AS WE DONOT CHANGE ANYTHING
    // int i, // things end with `;` not with `,`
    // int temp;
    // if (front==rear)
    // cout<<"the queue is empty";
    // else
    // {
    // cout<<"element in the queue";
    // }
    // for(i=temp;i<rear;i++)
    // {
    // cout<<q[i]<<"";

    // }
    // You never see what is inside the queue you can just see the front element
    cout << Q.element[Q.front] << "\n";
}
int main()
{
    int choice;
    int num;
    queue Q;
    queueQ(Q);
    while (1)
    {
        cout << "\n 1. add element";
        cout << "\n 2. remove element";
        cout << "\n 3.display";
        cout << "\n enter your choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\n enter a number";
            cin >> num;
            enqueue(Q, num);
            break;
        case 2:
            num = dequeue(Q);    // this will return a number
            cout << num << "\n"; // giving user his number
            break;
        case 3:
            display(Q);
        // we have a default case
        default:
            cout << "\n invalid choice";
        }
    }
}