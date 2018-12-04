#include"��ͷ.h"

int Graphcnt::getValue(int v1, int v2)
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
int Graphcnt::getnextnode(int v, int w)
{
	if (v != -1)
	{
		Edge*p = NodeTable[v].adj;
		while (p != NULL&&p->dest != NodeTable[w].start)
			p = p->link;
		if (p != NULL&&p->link != NULL)
			return getnode(p->link->dest);//����λ�� 
	}
	return -1;
};
//��ѯ��һ��� 
int Graphcnt::getfnode(int v)
{
	if (v != -1)//��v���վ�� 
	{
		Edge*p = NodeTable[v].adj;
		if (p != NULL) return getnode(p->dest);
	}
	return -1;
};
//������ʵ�� 
Graphcnt::Graphcnt(int sz)
{
	maxnode = sz;
	numnode = 0;
	numEdges = 0;
	NodeTable = new Node[sz];
	for (int i = 0; i<maxnode; i++)
		NodeTable[i].adj = NULL;

};