 /*
 * Assignment 1: Stacks & Queues
 * QueueTest.cpp
 * Created: 02/12/2018
 * Author: Christopher A Runyan
 */
#include <iostream>
#include "Queue.cpp"

using namespace std;

int main(){
   Queue* queue=new Queue();
   cout<<"New queue created.\n";

   cout<<"About to test push method.\n";
   queue->push(1);
   cout<<"Push method tested OK.\n";
   cout<<"Queue after push method:\n"; 
   queue->print();

   queue->pop();
   cout<<"\nPop method tested OK.\n";
   cout<<"Queue after pop method:\n\n";
   queue->print();

   queue->pop();
   cout<<"\nPop method tested OK.\n";
   cout<<"Queue after pop method:\n\n";
   queue->print();

   queue->push(1);
   queue->push(3);
   queue->push(5);
   cout<<"\nQueue after 3 push methods:\n"; 
   queue->print();

   queue->pop();
   cout<<"\nQueue after pop method:\n";
   queue->print();

   queue->push(7);
   cout<<"\nQueue after adding:\n";
   queue->print();
   
   cout<<"Node at front: "<<queue->front()<<"\n";

   return 0;
}
