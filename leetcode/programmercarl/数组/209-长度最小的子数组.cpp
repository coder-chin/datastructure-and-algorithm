//BF
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minLength = INT_MAX;
        int length = 0, sum = 0;

        for(int i=0; i<n; i++) {
            sum = 0;
            for(int j=i; j<n; j++) {
                sum += nums[j];
                if(sum >= target) {
                    length = j-i+1;
                    minLength = length < minLength ? length : minLength;
                    break;
                }
            }    
        }

        return minLength == INT_MAX ? 0 : minLength;
    }
};

// 滑动窗口
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minLength = INT_MAX;
        int sum = 0, subLength = 0;
        int i = 0; //起始位置

        for(int j=0; j<n; j++) {
            sum += nums[j];
            while(sum >= target) {
                subLength = j - i + 1;
                minLength = subLength < minLength ? subLength : minLength;
                sum -= nums[i++];
            }
        }

        return minLength == INT_MAX ? 0 : minLength;
    }
};

