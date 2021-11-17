#include <iostream>
#include <vector>
using namespace std;
//只会这种方法了，对不起！！

int main()
{
	vector<int> arr = {1, -2, 0, 3};
	int sum = 0, part = 0;
	int n = arr.size();
	int min = 0;

	for(int i = 0; i < n; i++) {   							 //确定起始位置
        for(int length = 1; i + length <= n; length += 1) {  //确定数组长度
            part = 0, min = 0;   //每次都置0
            for(int begin = i; begin < i + length; begin++) {
                part += arr[begin];
               	min = min > arr[begin] ? arr[begin] : min;
            }
            // cout << part << " | " << min << endl;
            // 如果在这个区间最小的数是负数而且长度不为1(即排除子数组只有一个负数的情况)，就减掉它
            if(min<0 && length!=1) part -= min;
            sum = sum < part ? part : sum;
        }
    }

	cout << sum << endl;  //结果

	return 0;
}
