#include"��ͷ.h"
bool Graphlnk::removeEdge(int v1, int v2)//ͼ��ɾһ���� 
{
	if (v1 != -1 && v2 != -1)
	{
		Edge*p = NodeTable[v1].adj, *q = NULL, *s = p;
		while (p != NULL&&p->dest != NodeTable[v2].start)
		{
			q = p; p = p->link;
		}
		if (p != NULL){ //�ҵ���ɾ���
			if (p == s) NodeTable[v1].adj = p->link;
			else q->link = p->link;
			delete p;
		}
		else
		{
			cout << "�����û�б�" << endl;
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
		cout << "ɾ���ɹ�" << endl;
		return true;
	}
	else
	{
		cout << "������ɾ��ʧ��" << endl;
		return false;
	}
}