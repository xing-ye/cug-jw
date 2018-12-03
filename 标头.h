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
	string dest;//路由器终点号 
	string netnumber;
	string yanma;
	int cost;
	Edge*link;
};
class Vertex//表示节点以下用v表示
{
public:
	string start;//路由器号 
	Edge*adj;
};
class Graphlnk
{
public:
	int maxVertices;  //图中结点最大数 
	int numEdges;
	int numVertices;
	Graphlnk();
	Graphlnk(int sz);
	int getWeight(int v1, int v2);
	bool insertVertex();//插入一个结点 
	bool insertEdge(int v1, int v2, int cost, string v3, string v4);//插入一条边 
	int getFirstNeighbor(int v);//v的第一个相邻结点
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