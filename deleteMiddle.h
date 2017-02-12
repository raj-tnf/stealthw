/*
 * deleteMiddle.h
 *
 */

typedef struct node
{
	int item;
	struct node *next;
}link;


void printList(link *list);

link *createList(int size);

int removeMidElement(link *list);
