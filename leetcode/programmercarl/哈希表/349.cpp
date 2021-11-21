#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set;
        unordered_set<int> nums_set(nums1.begin(), nums1.end());

        for(int num: nums2) {
        	// != 最后一个说明找到了，就加入set中。  迭代器本质是遍历
        	if(nums_set.find(num) != nums_set.end()) {
        		result_set.insert(num);
        	}
        }

        return vector<int>(result_set.begin(), result_set.end());
    }
};

int main()
{
	int nums1[] = {4, 9, 5}, nums2[] = {9,4,9,8,4};
	vector<int> n1(nums1, nums1 + sizeof(nums1) / sizeof(int));
	vector<int> n2(nums2, nums2 + sizeof(nums2) / sizeof(int));

	Solution solution;

	vector<int> ret = solution.intersection(n1, n2);

	for (unsigned int i = 0; i < ret.size(); ++i)
	{
		cout << ret[i];
	}

	return 0;
}
