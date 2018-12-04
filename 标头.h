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
class Node//表示节点以下用v表示
{
public:
	string start;//路由器号 
	Edge*adj;
};
class Graphcnt
{
public:
	int maxnode;  //图中结点最大数 
	int numEdges;
	int numnode;
	Graphcnt();
	Graphcnt(int sz);
	int getValue(int v1, int v2);
	bool insertnode();//插入一个结点 
	bool insertEdge(int v1, int v2, int cost, string v3, string v4);//插入一条边 
	int getfnode(int v);//v的第一个相邻结点
	int getnextnode(int v, int w);
	bool removenode(int v);
	bool removeEdge(int v1, int v2);
	int getnode(const string Node)
	{
		for (int i = 0; i<30; i++)
		{
			if (NodeTable[i].start == Node) return i;

		}	return -1;
	}
	Node *NodeTable;

};
void shortestway(Graphcnt& G, int v, int dist[], int path[]);
void Print(Graphcnt& G, int v, int dist[], int path[]);