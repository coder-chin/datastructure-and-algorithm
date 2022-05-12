#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
int n;
long long a[100007];

bool judge(long long cost)
{
	long long pre = a[0] - cost;
	for (int i = 1; i < n; i++)
	{
		if (a[i] - cost > pre)
		{
			pre = a[i] - cost;
		}
		else
		{
			if (a[i] + cost <= pre)
			{
				return false;
			}
			pre++;
		}
	}
	return true;
}


int main()
{
	while (~scanf("%d", &n))
	{
		long long max = 0;
		long long min = 1000000;
		memset(a, 0, sizeof(a));
		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &a[i]);
			if (a[i] > max) max = a[i];
			if (a[i] < min) min = a[i];
		}
		long long le = 0;
		long long ri = max - min + n;
		while (le <= ri)
		{
			long long mid = le + (ri - le) / 2;
			if (judge(mid))
			{
				ri = mid - 1;
			}
			else
			{
				le = mid + 1;
			}
		}
		printf("%lld\n", le);
	}
	return 0;
}
