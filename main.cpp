#include <stdlib.h>
#include<string>
#include<fstream>
#include"��ͷ.h"
int DefaultVertices = 30;
using namespace std;
int main()
{
	Graphlnk G(30);
	cout << "��ȡ�ļ�����վ��" << endl;
	G.insertVertex();
	cout << "��վ����Ϊ" << G.numVertices << endl;
	int i, j, weight;
	ifstream fin("duru2.txt", std::ios::in);
	char line[1024] = { 0 };
	string x = "";
	string y = "";
	string m = "";
	string n = "";
	int z;
	while (fin.getline(line, sizeof(line)))
	{
		stringstream word(line);
		word >> x;//·����� 
		word >> y;//·���յ� 
		word >> z;//Ȩֵ 
		word >> m;//����� 
		word >> n;//�������� 
		i = G.getVertexPos(x);
		j = G.getVertexPos(y);
		weight = z;
		G.insertEdge(i, j, weight, m, n);
	}

	fin.clear();
	fin.close();
	cout << "�ܱ�����Ϊ" << G.numEdges << endl;
	int h;
	int r;
	int *dist = new int[G.numVertices];
	int *path = new int[G.numEdges];
	string v, u; int a = 1, b;
	//���·�ɱ� 

	while (a)
	{
		cout << "1.����·�ɺ���ʾ·�ɱ�  2.ɾ��һ��·�ɱ�  3.ɾ��һ���� 4.�˳�" << endl;
		cin >> b;
		if (b == 1)
		{
			cout << "����·�ɺ�" << endl;
			cin >> v;
			r = G.getVertexPos(v);
			while (r == -1)
			{
				cout << "û�и�·��" << endl;
				cout << "����·����" << endl;
				cin >> v;
				r = G.getVertexPos(v);
			}

			ShortestPath(G, r, dist, path);
		}
		if (b == 2)
		{

			//ɾ��һ��·���� 
			cout << "ɾ��·����" << endl;
			cin >> v;
			int w = G.getVertexPos(v);
			while (!G.removeVertex(w))
			{
				cout << "û�и�·��" << endl;
				cout << "ɾ��·����" << endl;
				cin >> v;
				w = G.getVertexPos(v);
			}
			cout << "�������µ�·�ɱ�" << " " << "����·�����鿴·�ɱ�" << endl;
			cin >> v;
			r = G.getVertexPos(v);
			if (r == -1)
			{
				cout << "û�и�·��" << endl;
			}
			else
			{
				ShortestPath(G, r, dist, path);
			}
		}
		if (b == 3)
		{
			//ɾ��һ���� 
			cout << "ɾ��һ����" << endl;
			cin >> v;
			cin >> u;
			r = G.getVertexPos(v);
			h = G.getVertexPos(u);
			while (!G.removeEdge(r, h))
			{
				cout << "ɾ��һ����" << endl;
				cin >> v;
				cin >> u;
				r = G.getVertexPos(v);
				h = G.getVertexPos(u);
			}

		}
		if (b == 4)
		{
			a = 0;
			cout << "���˳�" << endl;
		}

	}

}