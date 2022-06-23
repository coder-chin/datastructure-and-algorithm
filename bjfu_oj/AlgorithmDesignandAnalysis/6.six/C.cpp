#include <bits/stdc++.h>
using namespace std;


    bool startswith(const std::string&str, const std::string&suffix, int start = 0, int end = MAX_32BIT_INT)
    {
    //调用＿string＿tailmatch函数，参数-1表示字符串头部匹配
        int result = _string_tailmatch(str, suffix, start, end, -1);
        return static_cast<bool>(result);
    }


int main()
{
    vector<string> words;
    string str;

    while(getline(str, cin)){
        if(str.length==0)//则为空行
        break;
        words.push_back(str);
    }

    while(cin >> str) {
        for(int i = 0; i < words.size; i++) {
            if(startswith(words[i], str)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}
