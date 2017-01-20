#include "lab7.h"

struct Node * insertBST(struct Node * r, struct Data d){
	if (r==NULL) {
		struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
		newNode->d = d;
		newNode->lChild = NULL;
		newNode->rChild = NULL;
		return newNode;	
	}

	else {
		if (r->d.data > d.data) {
			r->lChild = insertBST(r->lChild, d);
		}

		else if (r->d.data < d.data) {
			r->rChild = insertBST(r->rChild, d);
		}
	}
	return r;

}

void printInOrder(struct Node * r){
	if (r != NULL) {
		printInOrder(r->lChild);
		printf("%d ", r->d.data);
		printInOrder(r->rChild);		
	}


}

void deleteTree(struct Node * r){
	if (r == NULL) {
		return;
	}
	deleteTree(r->lChild);
	deleteTree(r->rChild);
	free(r);

}

void inOrder(struct Stack *s, struct Node *n) {
	if(n != NULL) {
		inOrder(s,n->lChild);
		push(s,n);
		inOrder(s,n->rChild);
	}
}

void printBSTs(struct Node * r1, struct Node * r2){
	struct Stack *s1 = initializeStack();
	struct Stack *s2 = initializeStack();

	inOrder(s1, r1);
	inOrder(s2, r2);

	struct Node * n1, * n2;
	int m1 = 0, m2 = 0;

	/*

	while(isEmpty(s1) != 1 && isEmpty(s2) != 1) {
		if(m1 == 0){
			n1 = pop(s1);
			m1 = 1;
		}
		if(m2 == 0) {
			n2 = pop(s2);
			m2 = 1;
		}
		if ((n2->d).data > (n1->d).data) {   //n2 > n1
			printf("%d ", (n2->d).data);
			n2 = NULL;
			m2 = 0;
		}
		else {17 13 3 2 20 15 10 1				// n1 >= n2
			printf("%d ", (n1->d).data);
			n1 = NULL;
			m1 = 0;
		}
	}
	while(isEmpty(s1) != 1) {
		n1 = pop(s1);
		if (n2 != NULL) {
			if (n2->d.data > n1->d.data) {
				printf("%d ", (n2->d).data);
				n2 == NULL;
	
		}
		}

		printf("%d ", (n1->d).data);
	}	
	while(isEmpty(s2) != 1) {
		n2 = pop(s2);
		if (n1 != NULL) {
			if (n1->d.data > n2->d.data) {
				printf("%d ", (n1->d).data);
				n1 == NULL;
			}
		}

		printf("%d ", (n2->d).data);
	}
	if (n1 != NULL) {
		printf("%d ", (n1->d).data);
	}
	if (n2 != NULL) {
		printf("%d ", (n2->d).data);
	}

	*/
	while(isEmpty(s1) != 1 && isEmpty(s2) != 1) {
		if(s1->top->n->d.data > s2->top->n->d.data) {
			n1 = pop(s1);
			printf("%d ", n1->d.data);
		}
		else {
			n2 = pop(s2);
			printf("%d ", n2->d.data);
		}
	}
	while(isEmpty(s1) != 1) {
		n1 = pop(s1);
		printf("%d ", (n1->d).data);
	}	
	while(isEmpty(s2) != 1) {
		n2 = pop(s2);
		printf("%d ", (n2->d).data);
	}


	freeStack(s1);
	freeStack(s2);

}
