class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = 0;
        int part = 0;
        int n = arr.size();

        for(int i = 0; i < n; i++) {
            for(int length = 1; i + length <= n; length += 2) {
                part = 0;
                for(int begin = i; begin < i + length; begin++) {
                    part += arr[begin];
                }
                sum += part;
            }
        }

        return sum;
    }
};