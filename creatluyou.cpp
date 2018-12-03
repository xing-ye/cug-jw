#include"标头.h"

int Graphlnk::getWeight(int v1, int v2)
{
	if (v1 != -1 && v2 != -1)
	{
		Edge *p = NodeTable[v1].adj;
		while (p != NULL && p->dest != NodeTable[v2].start)
		{
			p = p->link;
		}
		if (p != NULL)
			return p->cost;
		else return 100;
	}
}
int Graphlnk::getNextNeighbor(int v, int w)
{
	if (v != -1)
	{
		Edge*p = NodeTable[v].adj;
		while (p != NULL&&p->dest != NodeTable[w].start)
			p = p->link;
		if (p != NULL&&p->link != NULL)
			return getVertexPos(p->link->dest);//返回位置 
	}
	return -1;
};
//查询第一结点 
int Graphlnk::getFirstNeighbor(int v)
{
	if (v != -1)//有v这个站点 
	{
		Edge*p = NodeTable[v].adj;
		if (p != NULL) return getVertexPos(p->dest);
	}
	return -1;
};
//函数的实现 
Graphlnk::Graphlnk(int sz)
{
	maxVertices = sz;
	numVertices = 0;
	numEdges = 0;
	NodeTable = new Vertex[sz];
	for (int i = 0; i<maxVertices; i++)
		NodeTable[i].adj = NULL;

};