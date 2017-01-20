#include "lab5.h"

void insertNode(int d, struct Node ** lPtr)
{
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = d;
	
	struct Node *currNode = *lPtr;
	
	if (*lPtr == NULL) {
		*lPtr = newNode;
		newNode->next = NULL;
		return;
	}
	if ((*lPtr)->data >= d) {
		newNode->next = *lPtr;
		*lPtr = newNode;
		return;
	}
	
	
	else {
		
		while (((currNode)->data <d) && (currNode!=NULL)) {
		
			//
			if ((currNode)->next == NULL) {
				(currNode)->next = newNode;
				newNode->next = NULL;
				return;
				
			}
		
		
			//
			if ((currNode)->next->data >= d) {
				newNode->next = (currNode)->next;
				(currNode)->next = newNode;
				return;
			}
			
			
			(currNode) = (currNode)->next;
		}
	
	}


}
void deleteNode(int d, struct Node ** lPtr)
{

	struct Node *cNode = *lPtr;
	struct Node *pNode = NULL;
	while (cNode != NULL) {
		if (cNode->data == d) {
		
			if (pNode == NULL) {
			*lPtr = cNode->next;
			}
			
			else {
			pNode->next = cNode->next;
			}
			
		free(cNode);
		return;
		}
		
		pNode = cNode;
		cNode = cNode-> next;

	}
	

}

void printList(struct Node * L)
{
	struct Node *temp = L;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");	
}

struct Node ** createTable(int buckets)
{
	struct Node **table = (struct Node **)malloc(sizeof(struct Node *) * buckets);
	int i;
	for (i=0; i< buckets; i++) {
		table[i] = NULL;
	}
	
	return table;
}

int findHash(int key, int buckets)
{
	return (key % buckets);
}

void insertTable(int key, int buckets, struct Node ** tablePtr)
{
	insertNode(key, &tablePtr[findHash(key, buckets)]);

}

void freeTable(struct Node ** tablePtr, int buckets)
{
	int i = 0;
	for (i; i < buckets; i++) {
		struct Node *temp = tablePtr[i];
		struct Node *head = tablePtr[i];
		
		
		
		while (temp != NULL) {
			temp = head->next;
			free(head);
			head = temp;
		}
		free(head);
		free(temp);
	
	}
	free(tablePtr);



}


