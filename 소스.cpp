#include<iostream>
using namespace std;

typedef struct __point
{
	int xp;
	int yp;
}point;//���� �ڷ����� �ڿ� �ִ� ��.

point& pntadder(const point& p1, const point& p2)//�����ڸ� ���� ���� �Ǵµ�, �����͸� ���� ���� �� �ȴ�.
{
	point* ptr = new point;//������ ������ new�� �� �� �ִ�.
	ptr->xp = p1.xp + p2.xp;//�����ǵ� ������ ���� ��, ->�� ����.
	ptr->yp = p1.yp + p2.yp;
	return*ptr;
}

int main()
{
	point* ptr1 = new point;
	ptr1->xp = 3;
	ptr1->yp = 30;

	point* ptr2 = new point;
	ptr2->xp = 70;
	ptr2->yp = 7;

	point& pref = pntadder(*ptr1, *ptr2);//�������� ������
	cout << "[" << pref.xp << ", " << pref.yp << "]" << endl;

	delete ptr1;
	delete ptr2;
	delete& pref;//������ ����ü ���� delete�ؾ��Ѵ�. &�� �ٿ��� �Ѵ�.
	return 0;
}