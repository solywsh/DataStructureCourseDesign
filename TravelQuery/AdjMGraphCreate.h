#pragma once
#include "AdjMGraph.h"
typedef struct {
	int row;
	int col;
	int weight;
} RowColWeight;

void CreatGraph(AdjMGraph *G, DataType V[], int n, RowColWeight E[], int e)
//insert G with n vertexes information V and e sides information E
{
	int i, k;
	Initiate(G, n);
	for (i = 0; i < n; i++) {
		InsertVertex(G, V[i]);
	}
	for (k = 0; k < e; k++) {
		InsertEdge(G, E[k].row, E[k].col, E[k].weight);
	}
}