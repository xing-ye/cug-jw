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
class Node//��ʾ�ڵ�������v��ʾ
{
public:
	string start;//·������ 
	Edge*adj;
};
class Graphcnt
{
public:
	int maxnode;  //ͼ�н������� 
	int numEdges;
	int numnode;
	Graphcnt();
	Graphcnt(int sz);
	int getValue(int v1, int v2);
	bool insertnode();//����һ����� 
	bool insertEdge(int v1, int v2, int cost, string v3, string v4);//����һ���� 
	int getfnode(int v);//v�ĵ�һ�����ڽ��
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