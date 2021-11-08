class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int slowIndex = 0, fastIndex = 0;
        int tmp;
        //相对顺序不变

        for(; fastIndex < n; fastIndex++) {
            if(nums[fastIndex] != 0) {
                swap(nums[slowIndex++], nums[fastIndex]);
            }
        }
    }
};