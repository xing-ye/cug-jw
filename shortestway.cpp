#include"shortestway.h"
void shortestway(Graphcnt& G, int v, int dist[], int path[])
{//Graph是一个带权有向图，本算法建立一个数组，dist[j],0<=j<n;是当前求到的从顶点v到顶点j的最短路径长度，同时用数组path存放求到的最短路径
	int n = G.numnode;
	bool *S = new bool[n];
	int i, j, k;
	int w, min;
	for (i = 0; i<n; i++)
	{
		dist[i] = G.getValue(v, i);
		S[i] = false;

		if (i != v && dist[i] <100)
			path[i] = v;
		else
		{
			path[i] = -1;
		}
	}
	S[v] = true;
	dist[v] = 0;
	for (i = 0; i<n - 1; i++)
	{
		min = 100;
		int u = v;
		for (j = 0; j<n; j++)
		{
			if (S[j] == false && dist[j] < min)
			{
				u = j;
				min = dist[j];
			}
		}
		S[u] = true;
		for (k = 0; k<n; k++)
		{
			w = G.getValue(u, k);
			if (S[k] == false && w <100 && dist[u] + w<dist[k])
			{
				dist[k] = dist[u] + w;
				path[k] = u;
			}
		}
	}
	Print(G, v, dist, path);
}
