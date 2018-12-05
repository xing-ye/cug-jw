#include"main.h"
int DefaultVertices = 30;
using namespace std;
int main()
{
	Graphcnt G(30);
	cout << "读取文件插入站点" << endl;
	G.insertnode();
	cout << "总站点数为" << G.numnode << endl;
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
		word >> x;//路由起点 
		word >> y;//路由终点 
		word >> z;//权值 
		word >> m;//网络号 
		i = G.getnode(x);
		j = G.getnode(y);
		weight = z;
		G.insertEdge(i, j, weight, m);
	}

	fin.clear();
	fin.close();
	cout << "总边数数为" << G.numEdges << endl;
	int h;
	int r;
	int *dist = new int[G.numnode];
	int *path = new int[G.numEdges];
	string v, u; int a = 1, b;
	//输出路由表 

	while (a)
	{
		cout << "    1.输入路由号显示路由表\n    2.删除一个结点\n    3.删除一条边\n    4.插入一条边\n    5.插入一个节点\n    6.退出" << endl;
		cin >> b;
		if (b == 1)
		{
			cout << "输入路由号" << endl;
			cin >> v;
			r = G.getnode(v);
			while (r == -1)
			{
				cout << "没有该路由" << endl;
				cout << "输入路由器" << endl;
				cin >> v;
				r = G.getnode(v);
			}

			shortestway(G, r, dist, path);
		}
		if (b == 2)
		{

			//删除一个路由器 
			cout << "删除结点" << endl;
			cin >> v;
			int w = G.getnode(v);
			while (!G.removenode(w))
			{
				cout << "没有该点" << endl;
				cout << "删除结点" << endl;
				cin >> v;
				w = G.getnode(v);
			}
			cout << "已生成新的路由表" << " " << "输入路由器查看路由表" << endl;
			cin >> v;
			r = G.getnode(v);
			if (r == -1)
			{
				cout << "没有该路由" << endl;
			}
			else
			{
				shortestway(G, r, dist, path);
			}
		}
		if (b == 3)
		{
			//删除一条边 
			cout << "删除一条边" << endl;
			cin >> v;
			cin >> u;
			r = G.getnode(v);
			h = G.getnode(u);
			while (!G.removeEdge(r, h))
			{
				cout << "删除一条边" << endl;
				cin >> v;
				cin >> u;
				r = G.getnode(v);
				h = G.getnode(u);
			}

		}
		if (b == 4)
		{
			cout << "请输入前后结点，权值，网络号：\n";
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
				word >> x;//路由起点 
				word >> y;//路由终点 
				word >> z;//权值 
				word >> m;//网络号 
				i = G.getnode(x);
				j = G.getnode(y);
				weight = z;
				G.insertEdge(i, j, weight, m);
			}
			fin.clear();
			fin.close();
			cout << "总边数数为" << G.numEdges << endl;
			int h;
			int r;
			int *dist = new int[G.numnode];
			int *path = new int[G.numEdges];
		}
		if (b == 5)
		{
			cout << "输入要添加的结点号：\n";
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
			cout << "插入结点成功" << endl;
		}

		if (b == 6)
		{
			a = 0;
			cout << "已退出" << endl;
		}

	}

}