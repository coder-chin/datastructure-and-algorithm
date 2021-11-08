//移除办法：覆盖策略

//我的代码
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        if(n==0) return 0;  //空数组

        int left = 0, right = n-1;
        while(right>=0 && nums[right] == val) right--;

        while(left < right) {
            if(nums[left] == val) {
                swap(nums[left], nums[right]);
                left++, right--;
                while(nums[right] == val && right) right--; //右边一定不等于目标值
            } else {
                left++;
            }
        }

        return right+1;    //下标+1
    }
};


//大佬的代码
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();

        int slowIndex = 0, fastIndex = 0;

        for(int fastIndex = 0; fastIndex < n; fastIndex++) {
            if(nums[fastIndex] != val) {
                nums[slowIndex] = nums[fastIndex];
                slowIndex++;
            }
        }

        return slowIndex;
    }
};