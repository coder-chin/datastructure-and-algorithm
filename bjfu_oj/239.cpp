#include <iostream>
using namespace std;

typedef struct Monkey
{
	int num;
	struct Monkey *next;
} Monkey, *MonkeyList;

void init(MonkeyList &M, int m)
{
	MonkeyList ptr = M;

	for (int i = 0; i < m;)
	{
		Monkey *monkey = new Monkey;
		monkey->num = ++i;
		monkey->next = NULL;
		ptr->next = monkey;
		ptr = ptr->next;
		//cout << "num: " << ptr->num << endl;
	}
	//cout << ptr->num << endl;
	ptr->next = M->next;
	M = ptr;

	//cout << M->next->num << endl;
	//cout << ptr->next->num << endl;
}

void print(MonkeyList &M)
{
	MonkeyList ptr = M->next; //first
	while(ptr->next!=M->next)
	{
		cout << "num: " << ptr->num << endl;
		ptr = ptr->next;
	}
}

void circle(MonkeyList M, int n)
{
	MonkeyList ptr = M;

	while (ptr->next != ptr)
	{
		for (int i = 1; i < n; i++)
		{
			ptr = ptr->next;
		}
		MonkeyList tmp = ptr->next; //待删除节点

		cout << tmp->num << " ";
		ptr->next = tmp->next;
		delete tmp;
		//cout << "delete" << endl;
	}
	cout << ptr->num;
	delete ptr;
	//cout << "delete" << endl;
	cout << endl;
}

int main()
{
	int m, n;

	while (cin >> m && cin >> n)
	{
		if (!m && !n)
			break;

		MonkeyList M = new Monkey;
		init(M, m);
		circle(M, n);
		//print(M);
	}

	return 0;
}