class Solution {
public:
    string longestPrefix(string s) {
        int m = s.length();
        int max = 0;

        s = '0' + s;

        vector<int> next(m+1, 0);
        next[0] = -1;  //起始next[0]==-1  next[1] = 0

        int j = 2, i = next[1];   //j是游标，不断往后移动  i是长度为j的字符串匹配前后匹配的最大长度 始终等于next[j]

        while(j <= m) {  //abcabx
            while(i!=-1 && s[i+1]!=s[j])  i = next[i];  //匹配不到就一直回退, 直到i为0

            if(i==-1) i = 0, j++;  //i回退到0的话，i=next[0]=-1, i要恢复到0，j继续往后扫描

            else {    //next[j] = t[i+1]
                next[j] = i+1;
                max = next[j] > max ? next[j] : max;
                i = next[j];
                j++;
            }
        }
        return s.substr(1, next[m]);
    }
};