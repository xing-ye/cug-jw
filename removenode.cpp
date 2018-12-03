#include"标头.h"
bool Graphlnk::removeVertex(int v)
{
	if (v<0 || v >= numVertices)
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
		j = getVertexPos(k);
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

	numVertices--;
	NodeTable[v].start = NodeTable[numVertices].start;
	p = NodeTable[v].adj = NodeTable[numVertices].adj;
	if (p != NULL)
	{

		s = NodeTable[getVertexPos(p->dest)].adj;
		while (s != NULL)

		if (getVertexPos(s->dest) == numVertices)
		{

			s->dest = NodeTable[v].start; break;
		}
		else s = s->link;

	}
	cout << "删除路由器成功" << endl;
	return true;
}