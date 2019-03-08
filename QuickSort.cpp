#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <algorithm>


#include <time.h>

using namespace std;

void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

void pri(int a[],int s,int e)
{
    for (int i = s; i <= e; ++i)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}


void quick_sort_recursive(int a[], int left, int right) {
	
    if (left >= right)
        return;
    int pivot=rand()%(right-left+1)+left;
    int val = a[pivot];
    int sidx= left;
    swap(a[pivot],a[right]);
    for (int i = left; i <= right-1; ++i)
    {
    	if(a[i]<val){
    		swap(a[i],a[sidx]);
    		sidx++;
    	}
    }
    swap(a[sidx],a[right]);

    // pri(a,0,9);

    quick_sort_recursive(a, left, sidx-1);
    quick_sort_recursive(a, sidx + 1, right);
}


int main(int argc, char const *argv[])
{
	srand( 1 );
	int tot=500;
	cin>>tot;
	int a[tot];
	
	for (int i = 0; i < tot; ++i)
	{
		cin>>a[i];
	}
	cout<<endl;
	clock_t t1 = clock();
	quick_sort_recursive(a,0,tot-1);	
	int time=(clock() - t1) * 1.0 / CLOCKS_PER_SEC * 1000 ;
	
	cout<<endl;
	cout<<"time:"<<time;
	return 0;
}