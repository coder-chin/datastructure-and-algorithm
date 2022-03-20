#include<iostream> 
#include <string>
using namespace std; 
int main()
{
    string str;
    cin >> str;

    string s(str.rbegin(),str.rend());

    if(str==s)
        cout << "yes" << endl;

    else 
        cout << "no" << endl;

    return 0;
}