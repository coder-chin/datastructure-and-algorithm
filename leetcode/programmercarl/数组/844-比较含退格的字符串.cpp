//栈
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1, s2;
        int m = s.size(), n = t.size();

        for(int i = 0; i < m; i++) {
            if(s[i]=='#') {
                if(!s1.empty()) s1.pop();
            }    
            else s1.push(s[i]);
        } 

         for(int i = 0; i < n; i++) {
            if(t[i]=='#') {
                if(!s2.empty()) s2.pop();
            }

            else s2.push(t[i]);
        } 

        return s1 == s2;
    }
};


//双指针
class Solution {
public:
    void changeString(string &s) {
        int n = s.size();
        int slowIndex = 0, fastIndex = 0;

        for(; fastIndex < n; fastIndex++) {
            if(s[fastIndex] != '#') {
                s[slowIndex++] = s[fastIndex];
            } else if(slowIndex != 0) {
                slowIndex--;
            }
        }

        s.resize(slowIndex);  //参数是个数
    }

    bool backspaceCompare(string s, string t) {
        changeString(s);
        changeString(t);

        return s == t;
    }
};