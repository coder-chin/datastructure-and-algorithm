#include <iostream>
#include <string>
#include <iomanip>
using namespace std; 

struct Province{
	string name;
	double area;
	int pop;
} p[5];

int main()
{
	int n = 5;

	p[0].name = "Anhui";
	p[0].area = 139600.00;
	p[0].pop = 6461;

	p[1].name = "Beijing";
	p[1].area = 16410.54;
	p[1].pop = 1180;

	p[2].name = "Chongqing";
	p[2].area = 82400.00;
	p[2].pop = 3144;

	p[3].name = "Shanghai";
	p[3].area = 6340.50;
	p[3].pop = 1360;

	p[4].name = "Zhejiang";
	p[4].area = 101800.00;
	p[4].pop = 4894;
	for (int i = 0; i < n; ++i)
	{
		cout << p[i].name << " " << fixed << setprecision(2) << p[i].area << " " << p[i].pop << endl;
	}

	return 0;
}