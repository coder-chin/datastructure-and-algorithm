class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return n; //一个直接结束

        int slowIndex = 0, fastIndex = 1;

        for(; fastIndex < n; fastIndex++) {
            if(nums[fastIndex] != nums[slowIndex]) {
                slowIndex++;
                nums[slowIndex] = nums[fastIndex];
            }
        }

        return slowIndex+1;
    }
};