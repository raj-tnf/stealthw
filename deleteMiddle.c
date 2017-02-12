/*
 * removeMiddle.c
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include"deleteMiddle.h"

// Prints the node value of linked list.
void printList(link *list){
	link *curr = list;
	while (curr != NULL){
		printf("\t%d\n", curr->item);
		curr = curr->next;
	}
}


/*
 * if node size is < 1
 * list is not created.
 */
link *createList(int size){
	link *list = NULL;
	if (size < 1){
		//printf("Linked list should atleast have 1 element.\n");
		return list;
	}
	//printf("Creating linked list whose item values are from 0 - %d\n", size - 1);
	for (int i = 0; i < size; i++){
		link *head = malloc(sizeof(link));
		if (head == NULL){
			fprintf(stderr, "%s", "Could not allocate memory. Exiting\n");
			exit(1);
		}
		head->item = i;
		head->next = list;
		list = head;
	}
	return list;
}


/*
 * if node size is 0, 1, 2
 * no processing is done.
 */
int removeMidElement(link *list){
	link *curr = list;
	int midElement;

	link *i = curr;
	link *ii = curr;
	link *prevnode;

	if (curr== NULL){
		//printf("Empty list. Exiting\n");
		return -1;
	}
	if (curr->next == NULL){
		//printf("Only Single Element in list.\n");
		return -1;
	}

	if (curr->next->next == NULL){
		//printf("Only Two elements in list.\n");
		return -1;
	}

	while(ii && ii->next){
		i = i->next;
		ii = ii->next->next;
		if (i == ii){
			//printf("Loop Detected.\n");
			return -1;
		}
	}

	i = curr;
	ii = curr;
	while(i && ii  && ii->next){
		ii = ii->next->next;
		prevnode = i;
		i  = i->next;
	}
	prevnode->next = i->next;
	midElement = i->item;
	//i->next = NULL;
	//printf("Removing node with value = %d\n",midElement);
	return midElement;
}


/* TESTS */

/* Find middle element in linked list with odd
 * number of nodes. Ex: 0->1->2->Null
 */
int test_odd_list(){
	printf("Running test test_odd_list()\n");
	link *origList;
	int listSize = 3;
	int expectedVal = 1;
	int result;
	int retVal = 0;
	origList = createList(listSize);
	printList(origList);
	result = removeMidElement(origList);
	if (expectedVal != result){
		retVal = 1;
	}
	return retVal;
}


/* Find middle element in linked list with even
 * number of nodes. Ex: 0->1->2->3->Null
 */
int test_even_list(){
	printf("Running test test_even_list()\n");
	link *origList;
	int listSize = 6;
	int expectedVal = 2;
	int result;
	int retVal = 0;
	origList = createList(listSize);
	printList(origList);
	result = removeMidElement(origList);
	if (expectedVal != result){
		retVal = 1;
	}
	return retVal;
}


/* Find middle element in linked list
 * with 1 node. Ex: 0->Null.
 * Don't process if only 1 element is present.
 */
int test_single_node(){
	printf("Running test test_singlelist()\n");
	link *origList;
	int listSize = 1;
	int expectedVal =-1;
	int result;
	int retVal = 0;
	origList = createList(listSize);
	printList(origList);
	result = removeMidElement(origList);
	if (expectedVal != result){
		retVal = 1;
	}
	return retVal;
}


/*
 * Pass empty list to
 * removeMidElement()
 */
int test_empty_list(){
	printf("Running test test_empty_list()\n");
	link *origList = NULL;
	int listSize = 1;
	int expectedVal =-1;
	int result;
	int retVal = 0;
	result = removeMidElement(origList);
	if (expectedVal != result){
		retVal = 1;
	}
	return retVal;
}


/*
 * Test createList() with
 * int size = 0;
 */
int test_zero_list_size(){
	printf("Running test test_zero_list()\n");
	link *origList;
	int listSize = 0;
	int *expectedVal = NULL;
	int result;
	int retVal = 0;
	origList = createList(listSize);
	if (origList != NULL){
		retVal = 1;
	}
	return retVal;
}


int main(){
	int total_tests = 5;
	int pass = 0;
	int result;

	result = test_odd_list();
	if (result == 0)
		pass++;

	result = test_even_list();
	if (result == 0)
		pass++;

	result = test_single_node();
	if (result == 0)
		pass++;

	result = test_empty_list();
	if (result == 0)
		pass++;

	result = test_zero_list_size();
	if (result == 0)
		pass++;
	printf("Number of tests passed is %d, out of total tests = %d\n", pass, total_tests);
}
