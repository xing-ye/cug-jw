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

	bool insertEdge(int v1, int v2, int cost, string v3);//����һ���� 

	int getnode(const string Node)
	{
		for (int i = 0; i<30; i++)
		{
			if (NodeTable[i].start == Node) return i;

		}	return -1;
	}
	Node *NodeTable;

};
