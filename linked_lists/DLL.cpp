/*
 * DLL.cpp
 *
 *  Created on: Sep 28, 2016
 *      Author: Debra
 */

#include "DLL.hpp"
#include "DNode.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

DLL::DLL(){
	first = NULL;
	last = NULL;
	size = 0;
}
DLL::~DLL(){
	DNode *tmp = first;
	while (first != NULL) {
		tmp = first->next;
		delete first;
		first = tmp;
		size --;
	}
	first = NULL;
	last = NULL;
}
void DLL::printDLL() {
	DNode *tmp = first;
	while (tmp != NULL) {
		cout << tmp->data << "->";
		tmp = tmp->next;
	}
	cout << endl;
}
void DLL::printRevDLL() {
	DNode *tmp = last;
	while (tmp != NULL) {
		cout << tmp->data << "->";
		tmp = tmp->prev;
	}
	cout << endl;
}

void DLL::addFirst(int x) { //2 pts
	//add very first element to list
	first = new DNode (x);
	last = first;
	size++;
}
void DLL::addAtFront(int x) { //2 pts
	//	add a new node to the beginning of the list
	if(first == NULL)
	{
		addFirst(x);
	}
	else
	{
		DNode *n = new DNode(x);
		n->next = first;
		first->prev=n;
		//first = first->prev; //TODO
		size++;
	}
}

void DLL::push(int x) { //2 pts
	// add a new node to the end of the list
	DNode *n = new DNode(x);
	last->next = n;
	n->prev = last;
	last = last->next;
	size ++;
}
void DLL::addAtK(int x, int k){ //4 pts

	DNode* ptr = first;
	if(k == 0) //Add at the beginning
	{
		addAtFront(x);
	}
	else if(k == size) //Add at the end
	{
		push(x);
	}
	else
	{	//Traverse
		for(int i = 0; i < k-1; i++)
		{
			ptr = ptr->next;
		}

		DNode* ptrNxt = ptr->next;
		DNode* toAdd = new DNode(x);

		//Swap pointers
		ptr->next = toAdd;
		toAdd->prev = ptr;
		toAdd->next = ptrNxt;
		ptrNxt->prev = toAdd;
		size++;

	}
}

void DLL::join(DLL *list2){ //2 pts
	// join list 2 to the end of the list, modifying the size of the list
	last->next=list2->first;
	list2->first->prev = last;
	last = NULL;
	size += list2->size;
}

int DLL::pop() { //5 pts
	//popping the last node off the end of the list and returning that data
	if (size > 0){
		int x = last->data;
		last = last->prev;
		delete last->next;

		last->next = NULL;
		return x;
	}else{
		return -1;
	}

}
DNode *DLL::findKth(int k) {
	//find the element at the kth position and returning a pointer to that node
	DNode* ptr = first;
	if(k > size)
	{
		cout << "Out of bounds, returning last element" << endl;
		return last;
	}
	else
	{
		for(int i = 0; i < k; i++)
		{
			ptr = ptr->next;
		}
		return ptr;
	}
}
int DLL::findK(int k) {
	DNode *tmp = first;
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


int DLL::remFirst() { //2 pts
	//remove the first node from the list, returning its data
	int data = first->data;
	DNode *second = first->next;
	second->prev = NULL;	 // TODO

	cout << "First's Data: " << data << endl;
	delete first;

	first = second;
	size --;
	return data;
}

int DLL::remKth(int k) { //4 pts
	//remove the kth element of the list, returning its data
	if (k < size && k > 0) {
		DNode *tmp = first;
		for (int i = 0; i < k -1; i++) {  //TODO
			tmp = tmp->next;
		}// for
		int x = tmp->next->data;
		DNode *tmp2= tmp->next;
		tmp->next = tmp->next->next;
		delete tmp2;
		return x;
	}// if
	else
	{
		return 0;
	}
}
void DLL::RecursiveReverse(DLL *l2){ //TODO
	//If there's only 1 node...
	if(l2->size <2){
		return;
	}
	else{
		DNode* p1 = l2->first;
		DNode* p2 = l2->first->next;
		DNode* p3 = p2->next;

		l2->first = l2->last;
		l2->last = p1;
		p1->prev = p2;
		p1->next = NULL;
		reverse(p1, p2, p3);}
}

void DLL::reverse(DNode* p1, DNode* p2, DNode* p3)
{
	if(p3 == NULL)
	{
		p2->next = p1;
		p2->prev = p3;
		return;
	}
	else
	{
		p2->next = p1;
		p2->prev = p3;
		reverse(p2,p3,p3->next);
	}
}

void DLL::sortDLL() { //TODO
	DLL* list2 = new DLL();
	DNode* sortedFirst = list2->first;
	DNode* ptr = first;
	DNode* ptr2;

	for (; ptr->next != NULL; ptr = ptr->next)
	{
		if (ptr == NULL)
		{
			list2->push(ptr->data);
		}
		else
		{
			int index = 0;
			for (; ptr->data < ptr2->data || ptr->next == NULL; ptr2 = ptr2->next)
			{
				ptr2 = list2->first;
				list2->addAtK(ptr->data, index);
				remKth(index);
				index++;
			}
		}
	}
	for(ptr2 = list2->first; ptr2->next != NULL; ptr2 = ptr->next)
		last = ptr2;
	first = sortedFirst;
}

void DLL::Merge2(DLL *l2) { //10 pts //TODO
	//sortDLL();
	//l2->sortDLL();

	//Merge two sorted lists into one longer sorted list, and setting
	//the current list to the longer sorted list
	// Note that I sorted both lists before I called this.
	//also note that joining the two lists and then sorting is NOT what I want
	//here - I want this function to start at the beginning of each list,
	//and pull the smallest of the 2 values into the new list, then move up
	//one in that particular list.
	// e.g.,
	// l1 = 3,7,12,15,22,23,24,29    l2=4,8,12,13,27
	// n=3
	// l1 = 7,12,15,22,23,24,29    l2=4,8,12,13,27
	// n=3,4
	// l1 = 7,12,15,22,23,24,29    l2=8,12,13,27
	// n=3,4,7
	// l1 = 12,15,22,23,24,29    l2=8,12,13,27
	// n=3,4,7,8
	// l1 = 12,15,22,23,24,29    l2=12,13,27
	// n=3,4,7,8,12
	// l1 = 15,22,23,24,29    l2=12,13,27
	// n=3,4,7,8,12,12
	// l1 = 15,22,23,24,29    l2=13,27
	// n=3,4,7,8,12,12,13
	// l1 = 15,22,23,24,29    l2=27
	// n=3,4,7,8,12,12,13
	// l1 = 15,22,23,24,29    l2=27
	// n=3,4,7,8,12,12,13,15
	// l1 = 22,23,24,29    l2=27
	// n=3,4,7,8,12,12,13,15,22
	// l1 = 23,24,29    l2=27
	// n=3,4,7,8,12,12,13,15,22,23
	// l1 = 24,29    l2=27
	// n=3,4,7,8,12,12,13,15,22,23,24
	// l1 = 29    l2=27
	// n=3,4,7,8,12,12,13,15,22,23,24,27
	// l1 = 29    l2
	// n=3,4,7,8,12,12,13,15,22,23,24,27,29
//
}
void DLL::RemoveDuplicates() { //12pts
	// assumes the list is unsorted, removes all duplicates from the list
	//Note how massively easier this would be if we just sorted the list first...
	// Note also that you can use a helper function if you like
	//TODO

}




