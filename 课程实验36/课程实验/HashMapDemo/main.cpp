#include <iostream>
#include <hash_map>
#include <string>

using namespace std;

int main()
{
	hash_map<string, int> hm;
	hm["Bill"] = 12;
	hm["Tom"] = 22;
	hm["Mary"] = 32;
	cout << hm["Tom"] << endl;
	system("pause");
	return 0;
}