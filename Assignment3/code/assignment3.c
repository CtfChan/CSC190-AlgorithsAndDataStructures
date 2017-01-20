#include "assignment3.h"

struct flowNetwork * initFlowNetwork(){
	struct flowNetwork *network;
	network = (struct flowNetwork *)malloc(sizeof(struct flowNetwork));
	network->adjMatrix = initAdjMatrix();
	int i;
	for (i=0;i<NODES;i++) {
		network->visitedNodes[i] = 0;
		network->parent[i] = -1;
	}
	return network;
}

void deleteFlowNetwork(struct flowNetwork * fN){
	deleteAdjMatrix((fN->adjMatrix));
	free(fN);
	fN=NULL;
	
}

int breadthFirstPathSearch(struct flowNetwork * fN, int s, int t){
	 int i;
	 for (i=0;i<NODES;i++) {
		fN->visitedNodes[i] = 0;
		fN->parent[i] = -1;
	 }




	struct Queue *q;
	initQueue(&q);

	struct Data d1;
	d1.vertex = s;

	enqueue(q, d1);


	
	while(isQueueEmpty(q) != 1) {
		struct Data dt;
		dequeue(q, &dt);
		for (i=0; i<NODES;i++) {
			if ((fN->adjMatrix[dt.vertex][i]).flowCap - (fN->adjMatrix[dt.vertex][i]).flow > 0) {
				if (fN->visitedNodes[i] == 0) {
					fN->visitedNodes[i] = 1;
					fN->parent[i] = dt.vertex;
					struct Data d2;
					d2.vertex = i;
					enqueue(q, d2);
				}		

			}


		}


	}
	free(q);
	if (fN->visitedNodes[t] == 1) {
		return 1;
	}
	return 0;


}


void maximizeFlowNetwork(struct flowNetwork * fN, int s, int t){



	/*
  	int i = 0;
	while (breadthFirstPathSearch(fN, s, t) == 1){
	

	    // COMPUTE MAX FLOW
	    int increment = 0, poss = 0;
	    int cNode = t;
	    int pNode = fN->parent[cNode];
	    increment = fN->adjMatrix[pNode][cNode].flowCap - fN->adjMatrix[pNode][cNode].flow;

	
	    while (pNode != s) {
		cNode = pNode;
		pNode = fN->parent[cNode];
		poss = fN->adjMatrix[pNode][cNode].flowCap - fN->adjMatrix[pNode][cNode].flow;
 		printf("%d", poss);	

	
            	if (poss < increment) {
	  		increment = poss;
	
		}
	    }


	    // INPUT THE FLOW
	    cNode = t;
            pNode = fN->parent[NODES];
	    fN->adjMatrix[pNode][cNode].flow += increment;
		
	//	rewrite this
	    int j;
 	    printf("increment: %d\n", increment);
	    printf("flow: %d\n", fN->adjMatrix[pNode][cNode].flow);
            printf("flowCap: %d\n", fN->adjMatrix[pNode][cNode].flowCap);
	    for (i=0;i<NODES;i++) {
			 for (j=0;j<NODES;j++) {
		 	printf("%d", fN->adjMatrix[i][j].flowCap -fN->adjMatrix[i][j].flow);
	    	 }
  	    }
	//

     	    while (pNode != s) {
		cNode = pNode;
		pNode = fN->parent[pNode];
		fN->adjMatrix[pNode][cNode].flow += increment;
	    }
         	
		
	}

*/

	
 	while(breadthFirstPathSearch(fN, s, t) == 1){
		int i, flowmin, ind, poss;
		flowmin = fN->adjMatrix[fN->parent[t]][t].flowCap -  fN->adjMatrix[fN->parent[t]][t].flow;
		ind = t;
	
		while (ind != s) {
			poss =fN->adjMatrix[fN->parent[ind]][ind].flowCap -  fN->adjMatrix[fN->parent[ind]][ind].flow;
			if (poss < flowmin) {
				flowmin = poss;
			}
			ind = fN->parent[ind];
		}

		ind = t;
		while (ind != s) {
			fN->adjMatrix[fN->parent[ind]][ind].flow += flowmin;
			//fN->adjMatrix[ind][fN->parent[ind]].flow -= flowmin;
			ind = fN->parent[ind];

		}
	




	}




	








}





