/*
 * lab3main.cpp
 *
 *  Created on: Feb 26, 2015
 *      Author: Debra
 */

//#include <iostream>
//#include <stdlib.h>

#include "SLL.hpp"
#include "SNode.hpp"
#include "DLL.hpp"
#include "DNode.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
	srand(time(NULL));
	cout << "SLL" << endl;

	// Testing SLL
	SLL *list = new SLL;
	list->addFirst(rand()%50);
	list->printSLL();

	cout << "push" << endl;
	for (int i = 0; i < 10; i++) {
		if (i == 5) {
			list->push(42);
			i++;
		}
		else {
			list->push(rand()%50);
		}
		list->printSLL();
	}

	cout << "\nFind Kth" << endl;
	SNode *s = list->findKth(6);
	int y = s->getData();
	cout << y << endl;
	int x = list->findK(42);

	cout << "\nAdd at K" << endl;
	cout << x << endl;
	list->addAtK(55,4);
	list->printSLL();

	cout << "\nAdd at K again" << endl;
	list->addAtK(60,0);
	list->printSLL();

	cout << "\nPop" << endl;
	x = list->pop();
	cout << x << endl;
	list->printSLL();

	cout << "\nPop" << endl;
	x = list->pop();
	cout << x << endl;
	list->printSLL();

	cout << "\nRemove First" << endl;
	x = list->remFirst();
	cout << x << endl;
	list->printSLL();

	cout << "\nRemove First" << endl;
	x = list->remFirst();
	cout << x << endl;
	list->printSLL();

	cout << "\nRemove kth (3rd Element)" << endl;
	x = list->remKth(3);
	cout << x << endl;
	list->printSLL();

	cout << "\nRemove kth (4th Element)" << endl;
	x = list->remKth(4);
	cout << x << endl;
	list->printSLL();

	cout << "\nAdd First (To a new list)" << endl;
	SLL *l2 = new SLL;
	l2->addFirst(rand()%50);
	for (int i = 0; i < 10; i++) {
		l2->push(rand()%50);
	}
	l2->printSLL();

	cout << "\nJoin" << endl;
	list->join(l2);
	list->printSLL();


	cout << "\nReverse" << endl;
	list->reverseList();
	list->printSLL();


	//Testing DLL
	cout << "\n\n============================\n\nDLL\n" << endl;

	//Generate new list
	cout << "\nGenerate a new list" << endl;
	DLL *listd = new DLL;
	listd->addFirst(rand()%50);
	listd->printDLL();
	for (int i = 0; i < 8; i++) {
		if (i == 4) {
			listd->push(42);
			i++;
		}
		else {
			listd->push(rand()%50);
		}
		listd->printDLL();
	}

	cout << "\nFind kth(6)" << endl;
	DNode *s2 = listd->findKth(6);
	int y2 = s2->getData();
	cout << y2 << endl;


	cout << "\nFind kth(42)" << endl;
	int x2 = listd->findK(42);
	cout << x2 << endl;

	cout << "\nAdd at k" << endl;
	listd->addAtK(55,4);
	listd->printDLL();

	cout << "\nAdd at k again" << endl;
	listd->addAtK(60,0);
	listd->printDLL();

	cout << "\nPop" << endl;
	x2 = listd->pop();
	cout << x2 << endl;
	listd->printDLL();

	cout << "\nPop again" << endl;
	x2 = listd->pop();
	cout << x2 << endl;
	listd->printDLL();

	cout << "\nRemove First" << endl;
	x2 = listd->remFirst();
	cout << x2 << endl;
	listd->printDLL();

	cout << "\nRemove First again" << endl;
	x2 = listd->remFirst();
	cout << x2 << endl;
	listd->printDLL();

	cout << "\nRemove kth(3)" << endl;
	x2 = listd->remKth(3);
	cout << x2 << endl;
	listd->printDLL();

	cout << "\nMake a new list" << endl;
	DLL *ld2 = new DLL;
	ld2->addFirst(rand()%50);
	for (int i = 0; i < 8; i++) {
		ld2->push(rand()%50);
	}
	ld2->printDLL();

	cout << "\nJoin" << endl;
	cout << endl;
	listd->join(ld2);
	listd->printDLL();
	listd->printRevDLL();

	cout << "\nReverse" << endl;

	listd->RecursiveReverse(listd);   //TODO
	listd->printDLL();
	listd->printRevDLL();


	cout << "\nNew list and Add First" << endl;
	DLL *list1 = new DLL;
	list1->addFirst(rand()%50);
	list1->printDLL();

	cout << "\n" << endl;
	for (int i = 0; i < 8; i++) {
		if (i == 4) {
			list1->push(42);
			i++;
		}
		else {
			list1->push(rand()%50);
		}
	}
	list1->printDLL();

//	list1->sortDLL();
//	list1->printDLL();

//	cout << "\nGenerate another new list (push * 42)" << endl;
//	DLL *list2 = new DLL;
//	list2->addFirst(rand()%50);
//	list2->printDLL();
//	for (int i = 0; i < 8; i++) {
//		if (i == 4) {
//			list2->push(42);
//			i++;
//		}
//		else {
//			list2->push(rand()%50);
//		}
//	}
//
//
//	list2->printDLL();
//
//	cout << "\nSort" << endl;
//	list2->sortDLL();
//	list2->printDLL();
//
//	cout << "\nMerge" << endl;
//	list1->Merge2(list2);
//	list1->printDLL();
}

