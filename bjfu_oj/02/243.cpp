#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int length, num;
	
	while(cin>>length && length)
	{
		stack<int> sta;

		while(length--)
		{
			cin >> num;
			if(num==-1)
			{
				if(sta.empty()){
					cout << "POP ERROR" << endl;
					while(length--)
						cin >> num;

					break;
				}
				else {
					cout << sta.top() <<  endl;
					sta.pop();
				}
			}
			else 
				sta.push(num);
		}
	}

	return 0;
}