/*
 * Assignment 1: Stacks & Queues
 * Stack.cpp
 * Created: 02/04/2018
 * Author: Christopher A Runyan
 */

#include "Stack.h"

class Stack{
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

      public:Node(int operatorInt1, int operatorInt2, char operatorChar, Node* next){
         this->operandInt1 = operandInt1;
         this->operandInt2 = operandInt2;
         this->operatorChar = operatorChar;
         this->next = next;
      }

      public int getOperandInt1(){
         return operandInt1;
      }
   
      public int getOperandInt2(){
         return operandInt2;
      }
  
      public char getOperatorChar(){
         return operatorChar;
      }
   };

public:
   //constructor
   Stack(){
      top = NULL;
      size = 0;
   }

   //destructor
   ~Stack(){
      Node* next = head;
      
      while(next){
         Node *deleteMe = next;
         next = next->next;
         delete deleteMe;
      }
   }

   void push(int operandInt1, int operandInt2, char operatorChar){
      head = new Node(operandInt1, operandInt2, operatorChar, head);
      size++;
   }

   Node pop(){
      Node* headTemp = head;
      head = head->next;
      size--;
      
      return headTemp;
   }

   Node peek(){
      return head;
   }

   bool isEmpty(){
      if(size == 0){
         return true;
      }
      else{
         return false;
      }
   }

private:
   Node* top;
   int size;
};
 
