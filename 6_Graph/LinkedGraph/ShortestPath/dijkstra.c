#include "shortestPath.h"
#include <stdlib.h>
#include <stdio.h>

int shortestDistanceVertex(int *visited, int *distance, int size)
{
	int min = INF;
	int select = -1;
	
	for (int i = 0 ; i < size ; i++)
	{
		if (visited[i] != 1)
			if (distance[i] < min)
			{
				min = distance[i];
				select = i;
			}		
	}
	return select;
}
/*
 * 1. 거리 정보dist를 저장 할 배열 초기화
 * 2. 방문 여부visit 저장 할 배열 초기화
 * 3. 모든 거리는 처음에 INF로 초기화
 * 4. dist[V] = 0;
 * 5. 반복
 *		방문하지 않은 vertex 중에 가장 비용이 적은 (dist 배열 참고)
 *		선택 된 vertex가 없다면 loop 탈출 
 *		선택 된 vertex(v)로부터 갈 수 있는 vertex(w)들에 대한 거리정보 갱신
 *		dist[w] > dist[v] + graph->ppList[v]->head->plink->plink...
		case 1) 선택 된 vertex (v)가 1.
			1-1) v로 부터 갈 수 있는 vertex (w) 가 0
				dist[0] > dist[1] + 1에서 0으로 가는 edge의 weight 0 > 2 (x) 갱신하지 않음
			1-2) v로 부터 갈 수 있는 vertex (w) 가 2
				dist[2] > dist[1] + 1에서 2로 가는 edge 의 weight 4 > 1 + 2 (o) dist[2] <- 3
			dist : 0, 1, 3 , inf, inf. inf .......
			vist : 1, 1, 0, 0, 0 .................
 *  	라면 dist[w] = dist[v] + graph->ppList[v]->head->plink->plink..
*/
int	*dijkstra(LinkedGraph *pGraph, int startVertex)
{
	int size;
	int	*visited;
	int	*distance;

	if (!pGraph)
		return (NULL);
	size = pGraph->maxVertexCount;
	if (startVertex < 0 || startVertex >= size)
		return (NULL);
	visited = calloc(size, sizeof(int));
	distance = calloc(size, sizeof(int));
	for (int i = 0 ; i < size ; i++)
		distance[i] = INF;
	distance[startVertex] = 0;
	while(1)
	{
		int selVertexID;
		ListNode *curr;
		/*distance가 가장 작은 vertex 선택(방문 하지 않은 것 중)*/
		selVertexID = shortestDistanceVertex(visited, distance, size);
		if (selVertexID == -1)
			break;
		/*선택 된 vertex 방문 여부 갱신*/
		visited[selVertexID] = 1;

		/*선택 된 vertex로 부터 갈 수 있는 모든 vertex 거리 정보 갱신*/
		curr = pGraph->ppAdjEdge[selVertexID]->headerNode.pLink;
		while (curr)
		{
			long long infCheck = distance[selVertexID] + curr->weight;
			if (infCheck >= INF)
				continue ;
			if (distance[curr->ID] > distance[selVertexID] + curr->weight)
				distance[curr->ID] = distance[selVertexID] + curr->weight;
			curr = curr->pLink;
		}
	}
	free(visited);
	return (distance);
}

void printIntArray(int *arr, int size)
{
	printf("idx | data \n");
	for (int i = 0 ; i < size ; i++)
	{
		printf("%3d | ", i);
		if (arr[i] == INF)
			printf("inf\n");
		else
			printf("%-2d\n", arr[i]);
	}
}