#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        deque<int> p;
        vector<int> ret;
        for(int i = 1; i <= m; i++) p.push_back(i);

        int num = queries.size();
        int tmp;

        for(int i=0; i<num; i++) {
            auto it = p.begin();
            for(int j=0; j<m; j++) {
                if(queries[i]==p[j]) {
                    ret.push_back(j);
                    tmp = p[j];
                    p.erase(it+j);
                    p.push_front(tmp);
                }
            }
        }
        
        return ret;
    }
};

int main()
{
    vector<int> qs= {4,1,2,2};
    int m = 4;
    Solution solution;

    vector<int> q = solution.processQueries(qs, m);

    cout << q[0] << endl;

    return 0;
}