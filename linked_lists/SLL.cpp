/*
 * SLL.cpp
 *
 *  Created on: Sep 26, 2016
 *      Author: Debra
 */

#include "SLL.hpp"
#include "SNode.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;


/*
 * Olivia Liepa
 * Viroon Yong
 * Stephen Lu
 * Ryan Boederev
 * Yuchen Tang
 * Kyle Wang
 *
 */

SLL::SLL(){
	first = NULL;
	last = NULL;
	size = 0;
}
SLL::~SLL(){
	SNode *tmp = first;
	while (first != NULL) {
		tmp = first->next;
		delete first;
		first = tmp;
		size --;
	}
	first = NULL;
	last = NULL;
}
void SLL::printSLL() {
	SNode *tmp = first;
	while (tmp != NULL) {
		cout << tmp->data << "->";
		tmp = tmp->next;
	}
	cout << endl;
}

void SLL::addFirst(int x) { // 3 pts
	first = new SNode (x);
	//todo
	last = first;
	size++;
	//make a new list of only one node, data is x
}
void SLL::addAtFront(int x) {  //3 pts
	if(first == NULL)
	{
		addFirst(x);
	}
	else
	{
		SNode *n = new SNode(x);
		n->next = first;
		first = n;
		size++;
	}

	//add a new node to the front of the list with data being x
}

void SLL::push(int x) { //6 pts
	//add a new node to the end of the list, with data x
	//last might be the problem here

	last->next = new SNode(x);
	last = last -> next;

	size ++;

}

void SLL::addAtK(int x, int k){
	SNode *tmp = first;
	if (k==0) {
		addAtFront(x);

	}
	if (k < size  && k >= 0) {
		for (int i = 0; i < k-1; i++) {
			tmp = tmp->next;
		}
		SNode *tmp2 = tmp->next;
		tmp->next = new SNode(x);
		tmp->next->next = tmp2;
		size++;
	}
}
void SLL::join(SLL *list2){ //3 pts
	//join the list with list2, making the current list one longer list
	last->next=list2->first;
	last = list2->last;
	size = size + list2->size;

}

int SLL::pop() {
	if (size > 0) {
		int x = last->data;
		if (first != last ){
			SNode *tmp = first;
			for (int i = 0; i < size-1;i++) {
				tmp = tmp->next;
			}
			delete last;
			last = tmp;
			last->next = NULL;
		}
		else {
			delete last;
			first = NULL;
			last = NULL;
		}
		size --;
		return x;
	}
	else {
		return -1;
	}
}
SNode *SLL::findKth(int k) { //4 pts
	// find the node at the kth location and return it
	SNode *tmp = first;
	for (int i=0; i<k+1; i++){
		tmp = tmp->next;
	}//for

	return tmp;
}
int SLL::findK(int k) {
	SNode *tmp = first;
	int ind = 0;
	while (tmp != NULL && tmp->data != k) {
		tmp = tmp->next;
		ind++;
	}
	if (ind < size) {
		return ind;
	}
	else {
		return -1;
	}
}
int SLL::remFirst() { //3 pts
	//remove the first node from the list, returning its data
	int data = first->data;
	SNode *second = first->next;
	delete first;
	first = second;
	size --;
	return data;
}
int SLL::remKth(int k) {
	if (k < size && k > 0) {
		SNode *tmp = first;
		for (int i = 0; i < k -1; i++) {
			tmp = tmp->next;
		}// for
		int x = tmp->next->data;
		SNode *tmp2= tmp->next;
		tmp->next = tmp->next->next;
		delete tmp2;
		return x;
	}// if
}
//void SLL::reverseList(){ //10 pts
//	//Reverses the list, after completed, the last should be the first
//	//in the list and the first should be the last
//	//Challenge - I did this with one pass across the list
//
//	SNode *temphead = first;
//	SNode *tempRest = NULL;
//	SNode *tempNext = first->next;
//
//
//	if (first == NULL){
//	        return;}
//
//	last = first;
//
//	while (tempRest != NULL) {
//	         // Step1: Take out the next node
//	   	tempNext = tempRest;
//	        //Step2: Update the pointer of rest nodes after taking out the first
//	   	tempRest = tempRest->next;
//	        //Step3: Add the taken out node to the new list
//	    tempNext->next = temphead;
//	      //Step4: Update the new temp head node
//	    temphead = tempNext;
//	        // Repeat Step 1-4
//	    }
//	 first = temphead;
//	 last->next = NULL;
//
//}


void SLL::reverseList(){ //10 pts
	//Reverses the list, after completed, the last should be the first
	//in the list and the first should be the last
	//Challenge - I did this with one pass across the list
	if(size < 2)
	{
		return;
	}
	else
	{
		SNode* p1 = first;
		SNode* p2 = first->next;
		SNode* p3 = first->next->next;
		reverse(p1,p2,p3);
	}
}

void SLL::reverse(SNode* p1, SNode* p2, SNode* p3)
{
	if(p3 == NULL)

	{
		p2->next = p1;
		return;
	}
	else
	{
		p2->next = p1;
		reverse(p2,p3,p3->next);
	}
}
