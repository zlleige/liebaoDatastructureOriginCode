#include <iostream>
#include <map> //ӳ��(Ҳ���ֵ�)��������ӳ�䣬���ǹ�ϣӳ��
#include <hash_map>
#include <string>
#include "LinearMap.h"
#include "HashMap.h"

using namespace std;

int main()
{
	cout << "���������������ӳ��: " << endl;
	map<string,int> m;
	m["Bill"] = 98;
	m["Tom"] = 67;
	m["Mary"] = 100;
	//...�������棬�����˺ܶ�, 100�����1000���!

	cout << m["Tom"]  << endl;


	//������ŵ�
	cout << "������ŵ�: \n";
	int a[100000];
	for(int i=0; i<100000;++i)
		a[i] = i % 100;

	cout << a[8] << endl;
	cout << a[18] << endl;
	cout << a[98756] << endl;

	//һ��û�õģ�ֻ��ѧϰ������ӳ��
	LinearMap<string,int> lm;
	lm.Put("Bill",99);
	lm.Put("Tom",88);
	lm.Put("Mary",77);
	//����put�ܶ�����,100���
	cout << "LinearMap: " << lm.Get("Tom") << endl;

	//�ҵĹ�ϣӳ��
	cout << "�ҵĹ�ϣӳ��: " << endl;
	HashMap<string,int> myHMap;

	cout << myHMap.hash("Bill") << endl;
	cout << myHMap.myhash("Bill") << endl;
	myHMap.Put("Bill",999);
	myHMap.Put("Tom",888);
	myHMap.Put("Mary",777);
	cout << myHMap.Get("Tom") << endl;

	//cout << "ʹ��C++���õ�hash_map: " << endl;
	//hash_map<string,int> hm;
	//hm["Bill"] = 12;
	//hm["Tom"] = 22;
	//hm["Mary"] = 32;
	//cout << hm["Tom"] << endl;
	return 0;
}