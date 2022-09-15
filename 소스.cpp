#include<iostream>
using namespace std;

typedef struct __point
{
	int xp;
	int yp;
}point;//실제 자료형은 뒤에 있는 것.

point& pntadder(const point& p1, const point& p2)//참조자를 썼을 때는 되는데, 포인터를 썼을 때는 안 된다.
{
	point* ptr = new point;//포인터 생성에 new를 쓸 수 있다.
	ptr->xp = p1.xp + p2.xp;//미정의된 포인터 정의 시, ->를 쓴다.
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

	point& pref = pntadder(*ptr1, *ptr2);//포인터의 참조자
	cout << "[" << pref.xp << ", " << pref.yp << "]" << endl;

	delete ptr1;
	delete ptr2;
	delete& pref;//참조한 구조체 역시 delete해야한다. &를 붙여야 한다.
	return 0;
}