//假设在一轮匹配中：从s串i开始，t[1,j]完成了匹配，t[j+1]未匹配，我们将t的前缀t[1,j]
//视为一个独立的字符串p
//在p中，我们计算它的最长公共前后缀，长度为k (保证k<p串长度)
//可知p.prefix(k) = p.suffix(k) 即t(1,k) = t(j-k+1,j)
//下一轮匹配时，s串的下标可以从i+j-k开始

//KMP核心数据结构：next数组
//对每个p串计算最长公共前后缀长度(要小于P串长度，并保存到next数组中)

//数组next[i]的含义： next[i]表示t串的前缀t[1,i]中，最长公共前后缀长度
//不能过分跳跃，否则不能会跳过正确答案。因此找公共最长前后缀


// 构造next数组

class Solution {
public:
    int strStr(string s, string t) {
        int m = t.length();
        int n = s.length();

        s = '0' + s;
        t = '0' + t;

        vector<int> next(m+1, 0);
        next[0] = -1;  //起始next[0]==-1  next[1] = 0

        int j = 2, i = next[1];   //j是游标，不断往后移动  i是长度为j的字符串匹配前后匹配的最大长度 始终等于next[j]

        while(j <= m) {  //abcabx
            while(i!=-1 && t[i+1]!=t[j])  i = next[i];  //匹配不到就一直回退, 直到i为0

            if(i==-1) i = 0, j++;  //i回退到0的话，i=next[0]=-1, i要恢复到0，j继续往后扫描

            else {    //next[j] = t[i+1]
                next[j] = i+1;
                i = next[j];
                j++;
            }
        }

        i = 1, j = 1;

        while(i<=n && j<=m) {
            while(j>=1 && t[j]!=s[i])  j = next[j-1]+1;  //不匹配的话子串游标后移，父串游标不变

            if(!j) j = 1, i++;
            else i++, j++;
        }

        if(j<m) return -1;  //j没走到最后，说明i走完了，j没走完 为匹配成功

        else return i-m-1;
    }
};