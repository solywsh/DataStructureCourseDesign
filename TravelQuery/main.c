#include <stdio.h>
#include <malloc.h>

typedef char DataType;
#define MaxSize 10
#define MaxVertices 10
#define MaxWeight 10000

#include "AdjMGraph.h"
#include "AdjMGraphCreate.h"
#include "Dijkstra.h"

int main(void) {
	AdjMGraph g;
	//CREAT 10 PLACE
	char a[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

	RowColWeight rcw[] = {
			{0,1,2},
			{0,2,3},
			{1,2,5},
			{1,4,7},
			{2,5,6},
			{2,6,4},
			{3,5,3},
			{3,7,2},
			{3,8,7},
			{4,3,4},
			{5,8,8},
			{6,7,10},
			{6,9,10},
			{8,9,20},
	};
	int i, n = 10, e = 14;
	int distance[10], path[10];
	CreatGraph(&g, a, n, rcw, e);
	Dijkstra(g, 0, distance, path);

	printf("The shortest path from vertex %c to other places is :\n", g.Vertices.list[0]);
	for (i = 0; i < n; ++i) {
		printf("    The shortest path to vertex %c is %d.\n", g.Vertices.list[i], distance[i]);
	}

	printf("The first vertex of the shortest path from vertex %c to other vertices is:\n",
	       g.Vertices.list[0]);
	for (i = 0; i < n; ++i) {
		if (path[i] != -1) {
			printf("    The first vertex to vertex %c is %c.\n",
			       g.Vertices.list[i], g.Vertices.list[path[i]]);
		}
	}
}