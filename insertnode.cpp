#include"insertnode.h"
bool Graphcnt::insertnode()//����һ����� 
{
	ifstream fin("duru1.txt", std::ios::in);
	char line[1024] = { 0 };
	numnode = 0;
	string x = "";
	while (fin.getline(line, sizeof(line)))
	{
		stringstream word(line);
		word >> x;
		NodeTable[numnode].start = x;
		numnode++;
	}

	fin.clear();
	fin.close();
	cout << "������ɹ�" << endl;
	return true;
};