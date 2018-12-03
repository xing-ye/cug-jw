#pragma once
#include<string>
#include<fstream>
#include <stdlib.h>
#include <sstream>
#include <iostream>
using namespace std;
class Edge
{
public:
	string dest;//·�����յ�� 
	string netnumber;
	string yanma;
	int cost;
	Edge*link;
};
class Vertex//��ʾ�ڵ�������v��ʾ
{
public:
	string start;//·������ 
	Edge*adj;
};
class Graphlnk
{
public:
	int maxVertices;  //ͼ�н������� 
	int numEdges;
	int numVertices;
	Graphlnk();
	Graphlnk(int sz);
	int getWeight(int v1, int v2);
	bool insertVertex();//����һ����� 
	bool insertEdge(int v1, int v2, int cost, string v3, string v4);//����һ���� 
	int getFirstNeighbor(int v);//v�ĵ�һ�����ڽ��
	int getNextNeighbor(int v, int w);
	bool removeVertex(int v);
	bool removeEdge(int v1, int v2);
	int getVertexPos(const string vertex)
	{
		for (int i = 0; i<30; i++)
		{
			if (NodeTable[i].start == vertex) return i;

		}	return -1;
	}
	Vertex *NodeTable;

};
void ShortestPath(Graphlnk& G, int v, int dist[], int path[]);
void printPath(Graphlnk& G, int v, int dist[], int path[]);