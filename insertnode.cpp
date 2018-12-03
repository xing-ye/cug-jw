#include"标头.h"
bool Graphlnk::insertVertex()//插入一个结点 
{
	ifstream fin("duru1.txt", std::ios::in);
	char line[1024] = { 0 };
	numVertices = 0;
	string x = "";
	while (fin.getline(line, sizeof(line)))
	{
		stringstream word(line);
		word >> x;
		NodeTable[numVertices].start = x;
		numVertices++;
	}

	fin.clear();
	fin.close();
	cout << "插入结点成功" << endl;
	return true;
};