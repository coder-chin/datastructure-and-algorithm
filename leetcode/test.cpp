#include <iostream>
#include <vector>
using namespace std;
int main() 
{
	vector<int> a(10);
	a.push_back(1);
	cout << a.capacity();
	return 0;
}