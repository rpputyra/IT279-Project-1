/*
 * Assignment 1: Stacks & Queues
 * Queue.cpp
 * Created: 02/12/2018
 * Author: Christopher A Runyan
 */
#include <iostream> 

using namespace std;

class Queue{
   struct Node{
      public:int data;
      public:Node* next;

      public:Node(int data){
         this->data=data;
      }

      public:Node(int data, Node* next){
         this->data=data;
         this->next=next;
      }

      public:int getData(){
         return data;
      }

      public:void print(){
         cout<<"Data: "<<data<<"\n\n";
      }

      public:bool equals(Node* toTestEquals){
         if(toTestEquals->data==data){
            return true;
         }
         else{
            return false;
         }
      }
   };

private:
   Node* frontNode;
   int size;

public:
   //constructor
   Queue(){
      frontNode = NULL;
      size = 0;
   }

   //destructor
   ~Queue(){
      Node* next = frontNode;
      
      while(next){
         Node *deleteMe = next;
         next = next->next;
         delete deleteMe;
      }
   }

   void push(int data){
      Node* temp = frontNode;

      if(size == 0){
         frontNode = new Node(data);
      }
      else{
         for(int i=0; i<size-1; i++){
            temp = temp->next;
         }
         temp->next = new Node(data);
      }

      size++;
   }

   int front(){
      return frontNode->getData();
   }

   int back(){
      Node* toReturn = frontNode;
      int data;
      int i=0;

      while(i<size){
         toReturn = toReturn->next;
         i++;
      }
      data = toReturn->getData();
      delete toReturn;

      return data;
   }

   int pop(){
      if(size > 0){
         Node* frontNodeTemp = frontNode;
         frontNode = frontNode->next;
         size--;
      
         return frontNodeTemp->getData();
      }
      else{
         return 0;
      }
   }
 
   bool empty(){
      if(size == 0){
         return true;
      }
      else{
         return false;
      }
   }

   void print(){
      Node* toPrint = frontNode;
      int i=0;

      while(i<size){
         toPrint->print();
         toPrint = toPrint->next;
         i++;
      }
   }
};
