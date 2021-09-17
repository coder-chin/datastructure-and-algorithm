//寻找数组的中心索引
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int index=-1; //默认为-1
        if(nums.empty()) return index;
        int sum = 0;
        for(int i=0; i<nums.size();i++)
        {
            sum += nums[i];
        }
        int left_sum = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(left_sum*2+nums[i]==sum)
            {
                index = i;
                break;
            }
            left_sum+=nums[i];
        }
        return index;
    }
};

//搜索插入位置
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) { 
        int start = 0, end = nums.size()-1;
        int mid;
        int index=0;
        while(start<=end) {
            mid = (start+end)/2;
            if(nums[mid]==target) {
                index = mid;
                break;
            } else if(target>nums[mid]) {
                start = mid+1;
            } else if(target<nums[mid]) {
                end = mid-1;
            }
        }
        //没有找到的时候
        if(start>end) {
            if(start == mid+1) {
                //比mid大
                index = mid+1;
            }
            else {
                //比mid小，就把Mid的位置占了
                index = mid;
            }
        }
        return index;
    }
};

//合并区间
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        int num = intervals.size();
        sort(intervals.begin(), intervals.end());
        merged.push_back(intervals[0]);
        for(int i=1; i<num; i++) {
            int index = merged.size()-1;
            if(intervals[i][0]>merged[index][1]) {
                merged.push_back(intervals[i]);
            }
            else {
                merged[index][1] = max(intervals[i][1], merged[index][1]);
            }
        }
        return merged;
    }
};

//旋转矩阵
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        //不占用额外内存
        for(int row=0; row<size; row++) {
            for(int column=0; column<row; column++) {
                swap(matrix[row][column], matrix[column][row]);
            }
        }
        for(int row=0; row<size; row++) {
            for(int column=0; column<size/2; column++) {
                swap(matrix[row][column], matrix[row][size-column-1]);
            }
        }
    }
};

//零矩阵
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    vector<vector<int>> m;
    int xsize = matrix.size();
    int ysize = matrix[0].size();
    for(int row=0; row<xsize; row++) {
        for(int column=0; column<ysize; column++) {
            if(matrix[row][column]==0) {
                m.push_back({row,column});
            }
        }
    }
    int msize = m.size();
    for(int i=0; i<msize; i++) {
        int k = m[i][0]; //行数
        int n = m[i][1]; //列数
        for(int i=0;i<ysize;i++) {
            matrix[k][i]=0;
        }
        for(int i=0;i<xsize;i++) {
        	matrix[i][n]=0;
		}
    }
    }
};