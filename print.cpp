#include"��ͷ.h"
void Print(Graphcnt& G, int v, int dist[], int path[])
{
	//���path�����д洢��ͼG�Ӷ���v������������·���;���
	cout << G.NodeTable[v].start << "��·�ɱ�Ϊ" << endl;
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
			//	cout << "����" << G.NodeTable[i].start << "�����·��Ϊ��" << G.NodeTable[v].start << " ";


			if (k == 1)
			{
				cout << "Ŀ������" << G.NodeTable[d[0]].start << " ";
				cout << "ֱ�ӽ���" << " ";
			}
			else
			{
				cout << "Ŀ������" << G.NodeTable[d[0]].start << " ";
				cout << "��һ��" << G.NodeTable[d[k - 1]].start << " ";
			}
			cout << "���·������Ϊ��" << dist[i] << endl;
		}
	}
	delete[] d;
}