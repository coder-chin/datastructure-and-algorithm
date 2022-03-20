#include <iostream>
using namespace std;
void partition(int a[], int n) {
	int low = 0, high = n - 1; // 分别指向表的下界和上界
	int low0 = 0, high0 = n - 1; // 分别指向新表的下界和上界
	int flag = 1; // 标记是否划分成功，0为成功
	int k = n / 2; // 表的中间位置

	while (flag) {
		// 快速排序思想
		int pivot = a[low];
		while (low < high) {
			while (low < high && a[high] >= pivot) {
				high--;
			}
			if (low != high) {
				a[low] = a[high];
			}
			while (low < high && a[low] <= pivot) {
				low++;
			}
			if (low != high) {
				a[high] = a[low];
			}
		}
		a[low] = pivot;
		// 如果枢轴的位置是中间位置
		if (low == k - 1) {
			flag = 0;
		} else {
			// 如果枢轴在中间前面的位置，那么0~low的元素属于A1，从low+1后面继续查找
			if (low < k - 1) {
				low0 = ++low;
				high = high0;
			} else {
				// 如果枢轴在中间后面的位置，那么在high~n-1的元素属于A2,从high-1之前查找
				high0 = --high;
				low = low0;
			}
		}
	}
	// 计算A1
	for (int i = 0; i < k-1; ++i) {
		cout << a[i] << " ";
	}
	cout << a[k-1] << endl;
	// 计算A2
	for (int i = k; i < n-1; ++i) {
		cout << a[i] << " ";
	}
	cout << a[n-1] << endl;

}
int main() {
	int a[100];
	int n;
	while(cin>>n && n) {
		for (int i = 0; i < n; ++i) {
		cin >> a[i];
		}
	partition(a, n);

	}
	
	return 0;
}