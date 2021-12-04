class Solution {
public:
    int maximumProduct(vector<int> nums) {
        int min1 = INT_MAX, min2 = INT_MAX;     //分别是最小的两个数，按照在数轴上的顺序依次增大
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN; //分别是最大的三个数, 依次增大

        for(int i: nums) {
            if(i < min1) {
                // i比最小的都小
                min2 = min1;
                min1 = i;
            } else if(i < min2){
                // i 介于最下的两个数之间
                min2 = i;
            }

            if(i > max3) {
                max1 = max2;
                max2 = max3;
                max3 = i;
            } else if(i > max2) {
                max1 = max2;
                max2 = i;
            } else if(i > max1){
                max1 = i;
            }
        }

        return max(min1 * min2 * max3, max1 * max2 * max3);
    };
};