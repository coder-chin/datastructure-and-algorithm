#include <iostream>

int ack(int m, int n)
{
	if(m==0)
		return n+1;
	else if(n==0)
		return ack(m-1, 1);
	else 
		return ack(m-1, ack(m, n-1));
}

int main()
{
	
	int m, n;
	while(std::cin>>m>>n)
	{
		if(!m && !n)
			break;

		std::cout << ack(m, n) << std::endl;
	}
	return 0;
}