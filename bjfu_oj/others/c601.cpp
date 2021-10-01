#include <iostream>
#include <vector>
using namespace std;
// 京东秋招真题

int main()
{
	int m, n;
	int tmp;

	while(cin >> m >> n) 
	{
		vector<int> a, b, c;
		//a
		for (int i = 0; i < m; ++i)
		{
			cin >> tmp;
			a.push_back(tmp);
		}
		//b
		for (int i = 0; i < n; ++i)
		{
			cin >> tmp;
			b.push_back(tmp);
		}
		//a插入
		for (int i = 0; i < m; ++i)
		{
			tmp = a[i];
			c.push_back(tmp);
		}
		//b插入
		for (int i = 0; i < n; ++i)
		{
			tmp = b[i];
			c.push_back(tmp);
		}

		sort(c.begin(), c.end());

		for (unsigned int i = 0; i < c.size()-1; i++)
			for (unsigned int j = i+1; j < c.size(); j++)
			{
				if(c[i]==c[j])
				{
					c.erase(c.begin()+j);
					// 删除以后先--再++ 比较的还是删除的这个位置
					j--;
				}
			}

		for (unsigned int i = 0; i < c.size()-1; ++i)
		{
			cout << c[i] << " ";
		}

		cout << c.back() << endl;
	}
	
	return 0;
}