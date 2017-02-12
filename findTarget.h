/*
 * findtarget.h
 */


#define MAX_ELEMENT_SIZE 4

struct node{
  int elements[4];
  struct node *next;
};

int* findTarget(struct node root, int target);
int matchArrays(int expected[], int result[]);
