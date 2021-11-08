#include <iostream>
using namespace std;

//证明C++中二维数组在空间上是连续的
void test_address() {
	int arr[2][3] = {
		{0, 1, 2},
		{3, 4, 5}
	};
	cout << &arr[0][0] << " " << &arr[0][1] << " " << &arr[0][2] << endl;
	cout << &arr[1][0] << " " << &arr[1][1] << " " << &arr[1][2] << endl;
}

int main()
{
	test_address();
	return 0;
}