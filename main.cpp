#include"main.h"
int DefaultVertices = 30;
using namespace std;
int main()
{
	Graphcnt G(30);
	cout << "��ȡ�ļ�����վ��" << endl;
	G.insertnode();
	cout << "��վ����Ϊ" << G.numnode << endl;
	int i, j, weight;
	ifstream fin("duru2.txt", std::ios::in);
	char line[1024] = { 0 };
	string x = "";
	string y = "";
	string m = "";
	int z;
	while (fin.getline(line, sizeof(line)))
	{
		stringstream word(line);
		word >> x;//·����� 
		word >> y;//·���յ� 
		word >> z;//Ȩֵ 
		word >> m;//����� 
		i = G.getnode(x);
		j = G.getnode(y);
		weight = z;
		G.insertEdge(i, j, weight, m);
	}

	fin.clear();
	fin.close();
	cout << "�ܱ�����Ϊ" << G.numEdges << endl;
	int h;
	int r;
	int *dist = new int[G.numnode];
	int *path = new int[G.numEdges];
	string v, u; int a = 1, b;
	//���·�ɱ� 

	while (a)
	{
		cout << "    1.����·�ɺ���ʾ·�ɱ�\n    2.ɾ��һ�����\n    3.ɾ��һ����\n    4.����һ����\n    5.����һ���ڵ�\n    6.�˳�" << endl;
		cin >> b;
		if (b == 1)
		{
			cout << "����·�ɺ�" << endl;
			cin >> v;
			r = G.getnode(v);
			while (r == -1)
			{
				cout << "û�и�·��" << endl;
				cout << "����·����" << endl;
				cin >> v;
				r = G.getnode(v);
			}

			shortestway(G, r, dist, path);
		}
		if (b == 2)
		{

			//ɾ��һ��·���� 
			cout << "ɾ�����" << endl;
			cin >> v;
			int w = G.getnode(v);
			while (!G.removenode(w))
			{
				cout << "û�иõ�" << endl;
				cout << "ɾ�����" << endl;
				cin >> v;
				w = G.getnode(v);
			}
			cout << "�������µ�·�ɱ�" << " " << "����·�����鿴·�ɱ�" << endl;
			cin >> v;
			r = G.getnode(v);
			if (r == -1)
			{
				cout << "û�и�·��" << endl;
			}
			else
			{
				shortestway(G, r, dist, path);
			}
		}
		if (b == 3)
		{
			//ɾ��һ���� 
			cout << "ɾ��һ����" << endl;
			cin >> v;
			cin >> u;
			r = G.getnode(v);
			h = G.getnode(u);
			while (!G.removeEdge(r, h))
			{
				cout << "ɾ��һ����" << endl;
				cin >> v;
				cin >> u;
				r = G.getnode(v);
				h = G.getnode(u);
			}

		}
		if (b == 4)
		{
			cout << "������ǰ���㣬Ȩֵ������ţ�\n";
			ofstream fout("duru2.txt", ofstream::app);
			char str[1024];
			//cin.ignore();
			if (cin >> str)
			{
				gets_s(str);
				fout << str << endl;
			}
			fout.close();
			ifstream fin("duru2.txt", ios::in);
			char line[1024] = { 0 };
			string x = "";
			string y = "";
			string m = "";
			string n = "";
			int z;
			while (fin.getline(line, sizeof(line)))
			{
				stringstream word(line);
				word >> x;//·����� 
				word >> y;//·���յ� 
				word >> z;//Ȩֵ 
				word >> m;//����� 
				i = G.getnode(x);
				j = G.getnode(y);
				weight = z;
				G.insertEdge(i, j, weight, m);
			}
			fin.clear();
			fin.close();
			cout << "�ܱ�����Ϊ" << G.numEdges << endl;
			int h;
			int r;
			int *dist = new int[G.numnode];
			int *path = new int[G.numEdges];
		}
		if (b == 5)
		{
			cout << "����Ҫ��ӵĽ��ţ�\n";
			ofstream out("duru1.txt", ofstream::app);
			char ch[10];
			cin.ignore();
			if (cin >> ch)
			{
				out << ch << endl;
			}
			out.close();
			ifstream fin("duru1.txt", std::ios::in);
			char line[1024] = { 0 };
			G.numnode = 0;
			string x = "";
			while (fin.getline(line, sizeof(line)))
			{
				stringstream word(line);
				word >> x;
				G.NodeTable[G.numnode].start = x;
				G.numnode++;
			}
			fin.clear();
			fin.close();
			cout << "������ɹ�" << endl;
		}

		if (b == 6)
		{
			a = 0;
			cout << "���˳�" << endl;
		}

	}

}