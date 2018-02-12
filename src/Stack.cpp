/*
 * Assignment 1: Stacks & Queues
 * Stack.cpp
 * Created: 02/04/2018
 * Author: Christopher A Runyan
 */
#include <iostream>

using namespace std;

class Stack{
   //Node for Stack, contains two ints and one char
   struct Node{
      public:int operandInt1;
      public:int operandInt2;
      public:char operatorChar;
      public:Node* next;

      public:Node(int operandInt1, int operandInt2, char operatorChar){
         this->operandInt1 = operandInt1;
         this->operandInt2 = operandInt2;
         this->operatorChar = operatorChar;
         this->next = NULL;
      }

      public:Node(int operandInt1, int operandInt2, char operatorChar, Node* next){
         this->operandInt1 = operandInt1;
         this->operandInt2 = operandInt2;
         this->operatorChar = operatorChar;
         this->next = next;
      }

      public:int getOperandInt1(){
         return operandInt1;
      }
   
      public:int getOperandInt2(){
         return operandInt2;
      }
  
      public:char getOperatorChar(){
         return operatorChar;
      }

      public:void print(){
         cout<<"Operand 1: "<<operandInt1<<"\n";
         cout<<"Operand 2: "<<operandInt2<<"\n";
         cout<<"Operator: "<<operatorChar<<"\n\n";
      }
   };

private:
   Node* top;
   int size;

public:
   //constructor
   Stack(){
      top = NULL;
      size = 0;
   }

   //destructor
   ~Stack(){
      Node* next = top;
      
      while(next){
         Node *deleteMe = next;
         next = next->next;
         delete deleteMe;
      }
   }
  
   //pushes new Node onto top of Stack
   void push(int operandInt1, int operandInt2, char operatorChar){
      if(size == 0){
         top = new Node(operandInt1, operandInt2, operatorChar);
      }
      else{
         top = new Node(operandInt1, operandInt2, operatorChar, top);
      }
      size++;
   }
 
   //returns the Node at the top of the Stack and then removes it
   Node* pop(){
      Node* topTemp = top;
      top = top->next;
      size--;
      
      return topTemp;
   }

   //returns the Node at the top of the Stack
   Node* peek(){
      return top;
   }

   //returns the int value of operandInt1 in Node at the top of the Stack
   int peekFirstOperand(){
      return top->operandInt1;
   }

   //returns true of Stack is empty, false if Stack has items inside of it
   bool isEmpty(){
      if(size == 0){
         return true;
      }
      else{
         return false;
      }
   }

   //returns size of Stack
   int getSize(){
      return size;
   }

   //prints each Node inside of the Stack in a clean format
   void print(){
      Node* toPrint = top;
      int i=0;

      while(i<size){
         toPrint->print();
         toPrint = toPrint->next;
         i++;
      }
   }
};
 
