#include"��ͷ.h"
bool Graphlnk::insertVertex()//����һ����� 
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
	cout << "������ɹ�" << endl;
	return true;
};