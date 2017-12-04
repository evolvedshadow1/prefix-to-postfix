#include <string>
#include <iostream>
#include <iomanip>
#pragma once
using namespace std;
template<class ElementType>
class Node {
public:
    Node();
    ~Node();
    void setValue(int val);
    Node<ElementType>* next;
    ElementType data;
};

template<class ElementType>
Node<ElementType>::Node(){
  next = NULL;
}
template<class ElementType>
Node<ElementType>::~Node(){
}
template<class ElementType>
void Node<ElementType>::setValue(int d){
  data = d;
}

template <class ElementType>
class StackLL{
public:
  StackLL();
  void push(ElementType val);
  void pop();
  ElementType peek();
  //void append();
  void print();
  bool isEmpty();
  //StackLL<ElementType>& operator=(const StackLL& rhs);
  //ElementType operator[](const size_t pos);
private:
  Node<ElementType>* head;
  int elementCount;
  int max;
};


template<class ElementType>
StackLL<ElementType>::StackLL(){
  head = NULL;
  elementCount = 0;
  max = 1000;
}
template<class ElementType>
void StackLL<ElementType>::push(ElementType val){
  Node<ElementType>* newNode = new Node<ElementType>;
  newNode->data = val;
  if(head == NULL){
    head = newNode;
  }else{
    newNode->next = head;
    head = newNode;
  }
  elementCount++;
}
template<class ElementType>
void StackLL<ElementType>::pop(){
  Node<ElementType>* tmpNode = head;
  if(tmpNode != NULL){
    head = head->next;
    tmpNode->next = NULL;
    delete tmpNode;
    elementCount--;
  }
}
template<class ElementType>
ElementType StackLL<ElementType>::peek(){
  if(head != NULL){
    return head->data;
  }else{
    cout << "No elements in linked list!" << endl;
    return 0;
  }
}
/*
template<class ElementType>
void StackLL<ElementType>::append(ElementType val){
  Node<ElementType>* newNode = new Node<ElementType>;
  newNode->data = val;
  Node<ElementType>* tmpNode = head;
  if(head == NULL){
    head = newNode;
  }else{
    if(tmpNode->next != NULL){
      tmpNode = tmpNode->next;
    }else if(tmpNode->next == NULL){

    }
  }
}
*/
template<class ElementType>
void StackLL<ElementType>::print(){
  Node<ElementType>* count = head;
  while(count != NULL){
      cout << count->data << endl;
      count = count->next;
  }
  cout << "elementCount is: " << elementCount << endl;
}

template<class ElementType>
bool StackLL<ElementType>::isEmpty(){
  if(head == NULL && elementCount == 0){
    return true;
  }
}
