/*
 * findtarget.c
 */

#include <stdio.h>
#include <stdlib.h>
#include"findTarget.h"


/* Find the target node that contains the int.
 * Assumption is to return only the first
 * occurrance of the int is returned.
 */
int* findTarget(struct node root, int target){
	struct node *ptr = &root;
	while (ptr != NULL){
		int *elements = ptr->elements;
		for (int i=0; i<MAX_ELEMENT_SIZE; i++){
			int element = elements[i];
			if (element == target){
				return elements;
			}
		}
		ptr = ptr->next;
	}
	return NULL;
}


int matchArrays(int expected[], int result[]){
	if (expected == NULL || result == NULL){
		return -1;
	}

	int* one = expected;
	int* two = result;

	while (*one && *two){
		if (*one != *two){
			return -1;
		}
		//printf("ExpectedArray=%d, ResultArray=%d\n", *one, *two);
		one++;
		two++;
	}

	return 0;
}


/*
 * TESTS
 */

int test_findTarget_matchFound(){
	struct node four = {{1,2,3,4},NULL};
	struct node three = {{5,6,7,8},&four};
	struct node two = {{9,10,11,12},&three};
	struct node root = {{13,14,15,16},&two};

	int *result = findTarget(root, 7);
	int *expected = three.elements;

	return matchArrays(result,expected);
}


int test_findTarget_matchNotFound(){
	struct node four = {{1,2,3,4},NULL};
	struct node three = {{5,6,17,8},&four};
	struct node two = {{9,10,11,12},&three};
	struct node root = {{13,14,15,16},&two};

	int *result = findTarget(root, 7);
	if (result == NULL)
		return 0;

	return -1;
}


int test_findTarget_matchWith_multipleEntries(){
	struct node four = {{1,2,3,4},NULL};
	struct node three = {{5,6,5,8},&four};
	struct node two = {{9,10,11,12},&three};
	struct node root = {{13,14,15,16},&two};

	int *result = findTarget(root, 5);
	int *expected = three.elements;

	return matchArrays(result,expected);
}


int main(){
	printf("Starting the find!!!\n");

	printf("Match Found: %d\n" , test_findTarget_matchFound());
	printf("Match Not Found: %d\n" , test_findTarget_matchNotFound());
	printf("Match Not Found: %d\n" , test_findTarget_matchWith_multipleEntries());
}
