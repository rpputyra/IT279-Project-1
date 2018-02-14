/*
 * Assignment 1: Stacks & Queues
 * StackTest.cpp
 * Created: 02/04/2018
 * Author: Christopher A Runyan
 */
#include <iostream>
#include "Stack.cpp"

using namespace std;

int main(){
   Stack* stack=new Stack();
   cout<<"New stack created.\n";

   stack->push(1, 2, '+');
   cout<<"Push method tested OK.\n";
   cout<<"Stack after push method:\n"; 
   stack->print();

   stack->pop();
   cout<<"\nPop method tested OK.\n";
   cout<<"Stack after pop method:\n\n";
   stack->print();

   stack->push(1, 2, '+');
   stack->push(3, 4, '*');
   stack->push(5, 6, '-');
   cout<<"\nStack after 3 push methods:\n"; 
   stack->print();

   stack->pop();
   cout<<"\nStack after pop method:\n";
   stack->print();

   stack->push(3, 4, '*');
   cout<<"\nStack after adding duplicate:\n";
   stack->print();

   cout<<"\ntop & top->next equals: "<<stack->peek()->equals(stack->peek()->next)<<"\n\n";

   return 0;
} 
