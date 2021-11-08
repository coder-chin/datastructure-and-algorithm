704. 二分查找 https://leetcode-cn.com/problems/binary-search/

//版本一：左闭右闭
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int slow = 0, high = n-1, mid = 0;

        while(slow <= high) {
            mid = (slow + high)/2;
            if(nums[mid] > target) {
                high = mid-1;
            } else if(nums[mid] < target){
                slow = mid+1;
            } else {
                return mid;
            }
        }

        return -1;
    }
};

//版本二：左闭右开
class Solution {
public:
    //左闭右开
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int slow = 0, high = n, mid = 0;

        while(slow < high) {
            mid = (slow + high)/2;
            if(nums[mid] > target) {
                high = mid;
            } else if(nums[mid] < target){
                slow = mid+1;
            } else {
                return mid;
            }
        }

        return -1;
    }
};