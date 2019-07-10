#include "queue.h"
#include<iostream>

using namespace std;

int main()
{
    queue<int> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    //q.enqueue(60);

    cout<<q.front()<<endl;
    q.dequeue();
    cout<<q.front()<<endl;
}