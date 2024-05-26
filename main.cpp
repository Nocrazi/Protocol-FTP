
#include "main.h"

#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	auto conductor = Conductor::getInstance();
	vector<string> names = conductor->getFileNames("C:\\Users\\Admin\\Documents\\au*",10);
	for (size_t i = 0; i < names.size(); ++i)
		cout << names[i] << endl;


}

