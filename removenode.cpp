#include"标头.h"
bool Graphcnt::removenode(int v)
{
	if (v<0 || v >= numnode)
	{
		return false;
	}
	Edge*p, *s, *t;
	int i, j;
	string k;
	while (NodeTable[v].adj != NULL)
	{
		p = NodeTable[v].adj;
		k = p->dest;
		j = getnode(k);
		s = NodeTable[j].adj;
		t = NULL;
		while (s != NULL &&s->dest != NodeTable[v].start)
		{
			t = s; s = s->link;
		}
		if (s != NULL)
		{
			if (t == NULL) NodeTable[j].adj = s->link;
			else t->link = s->link;
			delete s;
		}
		NodeTable[v].adj = p->link;
		delete p;
		numEdges--;
	}

	numnode--;
	NodeTable[v].start = NodeTable[numnode].start;
	p = NodeTable[v].adj = NodeTable[numnode].adj;
	if (p != NULL)
	{

		s = NodeTable[getnode(p->dest)].adj;
		while (s != NULL)

		if (getnode(s->dest) == numnode)
		{

			s->dest = NodeTable[v].start; break;
		}
		else s = s->link;

	}
	cout << "删除路由器成功" << endl;
	return true;
}