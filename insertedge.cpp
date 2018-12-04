#include"标头.h"
bool Graphcnt::insertEdge(int v1, int v2, int cost, string v3)
{

	if (v1 >= 0 && v1 <= numnode&&v2 >= 0 && v2 <= numnode)//v1,v2合法 
	{
		string a;
		int b, c;
		Edge*q, *p;
		p = NodeTable[v1].adj;
		while (p != NULL&&p->dest != NodeTable[v2].start)
			p = p->link;
		if (p != NULL)
		{
			return false;
		} //找到此边不插入
		p = new Edge(); q = new Edge();
		p->dest = NodeTable[v2].start;    p->cost = cost;
		p->netnumber = v3; 
		p->link = NodeTable[v1].adj;
		NodeTable[v1].adj = p;//链入v1表 
		q->dest = NodeTable[v1].start;    q->cost = cost;
		q->netnumber = v3; 
		q->link = NodeTable[v2].adj;
		NodeTable[v2].adj = q;
		numEdges++;
		return true;
	}
	return false;

};