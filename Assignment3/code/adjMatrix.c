#include "assignment3.h"

struct Edge ** initAdjMatrix(){
	struct Edge **matrix;
	matrix = (struct Edge **)malloc(NODES * sizeof(struct Edge));
	
	int i, j;
	for (i=0;i<NODES;i++) {
		matrix[i] = (struct Edge *)malloc(NODES * sizeof(struct Edge));

		for (j=0;j<NODES;j++) {
			
			matrix[i][j].flow = 0;
			matrix[i][j].flowCap = 0;
		}
	}
	return matrix;
}

void insertAdjMatrix(struct Edge ** aM, int vi, int vj, int flow, int flowCap){
	aM[vi][vj].flow = flow;
	aM[vi][vj].flowCap = flowCap;
}

void deleteAdjMatrix(struct Edge ** aM){
	int i;
	for (i=0;i<NODES;i++) {
		free(aM[i]);
		aM[i] = NULL;
	}
	free(aM);

}

void printAdjMat(struct Edge ** aM){
	int i, j;
	for (i=0;i<NODES;i++) {
		for (j=0;j<NODES;j++) {
			if (aM[i][j].flowCap > 0) {
				printf("Edge: (%d, %d) Flow: %d Max Cap: %d\n",i,j,aM[i][j].flow,aM[i][j].flowCap);
			}
		}
	}

}
