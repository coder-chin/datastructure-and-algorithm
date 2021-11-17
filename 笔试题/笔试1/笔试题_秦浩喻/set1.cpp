#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// 这学期刚接触数据结构和算法，尽力吧！
// 暂时还不会哈希表，只能先暴力了~

vector<vector<int>> solution(vector<int> arr, int target) {
	vector<vector<int>> ret;  			//结果
	int left = 0, right = arr.size()-1; //左右指针
	sort(arr.begin(), arr.end()); 		// [-2, 0, 1, 1, 3, 4]

	while(left < right) {
		if(arr[left]+arr[right] == target) {
			ret.push_back({arr[left++], arr[right++]});
		} else if(arr[left]+arr[right] < target) {
			left++;
		} else {
			right--;
		}
	}

	return ret; 	//返回结果
}

int main()
{
	vector<int> arr = {1, 4, -2, 3, 0, 1};
	int target = 1;  			  //目标值
	sort(arr.begin(), arr.end()); //sort

	vector<vector<int>> ret = solution(arr, target); 

	return 0;
}
