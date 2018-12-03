#include"标头.h"
bool Graphlnk::removeEdge(int v1, int v2)//图上删一条边 
{
	if (v1 != -1 && v2 != -1)
	{
		Edge*p = NodeTable[v1].adj, *q = NULL, *s = p;
		while (p != NULL&&p->dest != NodeTable[v2].start)
		{
			q = p; p = p->link;
		}
		if (p != NULL){ //找到被删结点
			if (p == s) NodeTable[v1].adj = p->link;
			else q->link = p->link;
			delete p;
		}
		else
		{
			cout << "两点间没有边" << endl;
			return false;
		}
		p = NodeTable[v2].adj; q = NULL; s = p;
		while (p->dest != NodeTable[v1].start)
		{
			q = p; p = p->link;
		}
		if (p == s) NodeTable[v2].adj = p->link;
		else q->link = p->link;
		delete p;
		cout << "删除成功" << endl;
		return true;
	}
	else
	{
		cout << "结点错误，删边失败" << endl;
		return false;
	}
}