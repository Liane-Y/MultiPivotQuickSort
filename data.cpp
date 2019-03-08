#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <algorithm>
using namespace std;
int tot = 500000;

int cmp ( const void *a , const void *b )
{
    return *(int *)a - *(int *)b;
}


int main(int argc, char const *argv[])
{
	int k;
	cin>>k;
	cout<<tot<<endl;
	int num[tot];
	int sorted=tot/100*k;
	int unsorted = tot - sorted;
	for (int i = 0; i < tot; ++i)
	{
		num[i]=random();
	}

	qsort(num, sorted, sizeof(int), cmp);

	for (int i = 0; i <sorted; ++i)
	{
		if(unsorted){
		int i1=rand()%unsorted+sorted;
		
		swap(num[i],num[i1]);
		}		
	}

	for (int i = 0; i < tot; ++i)
	{
		cout<<num[i]<<" ";
	}

	return 0;
}