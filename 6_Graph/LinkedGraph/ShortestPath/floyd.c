#include "shortestPath.h"
#include <stdio.h>
#include <stdlib.h>

/* 
 * 1. 노드 별 거리 정보가 저장 될 배열을 초기화 한다.
 *
*/
int **initMatrix(int sizeOfVertex)
{
	int **distMatrix;

	distMatrix = malloc(sizeof(int *) * sizeOfVertex);
	if (!distMatrix)	return (NULL);
	for (int i = 0 ; i < sizeOfVertex ; i++)
	{
		distMatrix[i] = malloc(sizeof(int) * sizeOfVertex);
		if (!distMatrix[i])
		{
			while (i >= 0)
			{
				free(distMatrix[i]);
				i--;
			}
			free(distMatrix);
			return (NULL);
		}
		for (int j = 0 ; j < sizeOfVertex ; j++)
		{
			if (i == j)
				distMatrix[i][j] = 0;
			else
				distMatrix[i][j] = INF;
		}
	}
	return (distMatrix);
}

void    initWeightMatix(LinkedGraph *pGraph, int **distMatrix)
{
	for (int i = 0 ; i < pGraph->maxVertexCount ; i++)
	{
		ListNode *curr = pGraph->ppAdjEdge[i]->headerNode.pLink;
		while (curr)
		{
			distMatrix[i][curr->ID] = curr->weight;
			curr = curr->pLink;
		}
	}
}

int	**floyd(LinkedGraph *pGraph)
{
	int **distMatrix;
	
	distMatrix = initMatrix(pGraph->maxVertexCount);
	initWeightMatix(pGraph, distMatrix);
	/*
	 * distMatrix[row][col]의 value는 거리.
	 * vertex From에서  To로 가는 경로와 From에서 K를 거쳐 To로 가는 경로의 크기를 비교
	 * 거쳐가게 되는 노드인 K에 대해서 반복.
	 * 우선 pGraph의 모든 vertex에 대해서 탐색해야 하므로 for문 하나. (K = 0 ~ max)
	 * -> From에서 To로 가는 weight 는 distMatirx[from][to] --1)
	 * -> From에서 K를 거쳐 To로 가는 경로는 distMatirx[from][k] + distMatirx[k][to] --2)
	 * 1)과 2)를 비교해서 2)가 더 작으면 1)을 2)로 갱신
	*/
	for (int k = 0 ; k < pGraph->maxVertexCount ; k++)
	{
		// printIntMatrix(distMatrix,6,6);
		for (int from = 0 ; from < pGraph->maxVertexCount ; from++)
			for (int to = 0 ; to < pGraph->maxVertexCount ; to++)
			{
				long long infCheck = (long long)distMatrix[from][k] + (long long)distMatrix[k][to];
				if (infCheck >= INF)
					continue ;
				if (distMatrix[from][to] > distMatrix[from][k] + distMatrix[k][to])
					distMatrix[from][to] = distMatrix[from][k] + distMatrix[k][to];
			}
	}
	return (distMatrix);
}

void printIntMatrix(int **Matrix, int rows, int cols)
{
	printf("\n");
	for(int i = 0 ; i < rows ; i ++)
	{
		for(int j = 0 ; j < cols ; j ++)
		{
			if (Matrix[i][j] == INF) printf("[INF]");
			else	printf("[%3d]", Matrix[i][j]);
		}
		printf("\n");
	}
}

void deleteIntMatrix(int **Matrix, int rows)
{
	for(int i = 0 ; i < rows ; i ++)
		free(Matrix[i]);
	free(Matrix);
}