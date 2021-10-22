#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
	int num, dis, tmp;
 
	while(cin>>num && num) {
		vector<int> v, store;
 
		for (int i = 0; i < num; ++i)
		{
			cin >> tmp;
			v.push_back(tmp);
		}
 
		cin >> dis;
 
		for (int i = 0; i < dis; ++i)
		{
			// cout << "fornt: " << v[i] << endl;
			store.push_back(v[i]);
		}
 
		for (unsigned int i = dis; i < v.size(); ++i)
		{
			v[i-dis] = v[i];
			// cout << "new" << i-dis << ": " << v[i-dis] <<endl;
		}
 
		for (int i = 0; i < dis; ++i)
		{
			v[v.size()-dis+i] = store[i];
			// cout << "insert: " << dis+i << ": " << v[dis+i] << endl;
		}
 
		for (unsigned int i = 0; i < v.size()-1; ++i)
		{
			cout << v[i] << " ";
		}
 
		cout << v.back() << endl;
 
	}	
	return 0;
}
