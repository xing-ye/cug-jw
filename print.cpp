#include"标头.h"
void Print(Graphcnt& G, int v, int dist[], int path[])
{
	//输出path数组中存储的图G从顶点v到其余各顶点的路径和距离
	cout << G.NodeTable[v].start << "的路由表为" << endl;
	int i, j, k, n = G.numnode;
	int * d = new int[n];
	for (i = 0; i<n; i++)
	{
		if (i != v)
		{
			j = i;
			k = 0;
			while (j != v)
			{
				d[k++] = j;
				j = path[j];
			}
			//	cout << "顶点" << G.NodeTable[i].start << "的最短路径为：" << G.NodeTable[v].start << " ";


			if (k == 1)
			{
				cout << "目的网络" << G.NodeTable[d[0]].start << " ";
				cout << "直接交付" << " ";
			}
			else
			{
				cout << "目的网络" << G.NodeTable[d[0]].start << " ";
				cout << "下一跳" << G.NodeTable[d[k - 1]].start << " ";
			}
			cout << "最短路径长度为：" << dist[i] << endl;
		}
	}
	delete[] d;
}