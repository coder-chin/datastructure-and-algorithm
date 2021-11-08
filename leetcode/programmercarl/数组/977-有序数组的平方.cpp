class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n, 0);
        int left = 0, right = n-1, index = n-1;

        while(left <= right) {
            if(nums[left]*nums[left] < nums[right]*nums[right]) {
                ret[index--] = nums[right]*nums[right];
                right--;
            } else {
                ret[index--] = nums[left]*nums[left];
                left++;
            }
        }

        return ret;
    }
};