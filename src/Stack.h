/*
 * Assignment 1: Stacks & Queues
 * Stack.h
 * Created: 02/04/2018
 * Author: Christopher A Runyan
 */

#ifndef STACK_H_
#define STACK_H_

class Stack {
struct Node{
   public:
      int operandInt1;
      int operantInt2;
      char operatorChar;
      Node* next;
      Node(int operatorInt1, int operatorInt2, char operatorChar);
      Node(int operatorInt1, int operatorInt2, char operatorChat, Node* next);
      int getOperatandInt1();
      int getOperantInt2();
      char getOperatorChar();
};

private: 
   Node* top;
   int size;

public:
   Stack();
   ~Stack();
   void push(int operandInt1, int operandInt2, char operatorChat);
   Node pop();
   Node peek();
   bool isEmpty();   
};

#endif /* STACK_H_ */
