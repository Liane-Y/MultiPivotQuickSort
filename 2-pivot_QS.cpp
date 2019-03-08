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
    int pivot1=rand()%(right-left+1)+left;
    int pivot2=rand()%(right-left+1)+left;
    if(a[pivot1]>a[pivot2])
        swap(a[pivot1],a[pivot2]);
    
    int val1 = a[pivot1];
    int val2 = a[pivot2];

    swap(a[pivot1],a[left]);swap(a[pivot2],a[right]);
    int sidx1= left+1; int sidx2 = right-1;
    // cout<<val<<endl;
    for (int i = left+1; i <= right-1; ++i)
    {
        if(a[i]<val1){
            swap(a[i],a[sidx1]);
            sidx1++;
            continue;
        }
        if(a[i]>val2){
            swap(a[i],a[sidx2]);
            sidx2--;
            continue;
        }
    }
    swap(a[sidx1],a[left]);
    swap(a[sidx2],a[right]);

    // pri(a,0,9);

    quick_sort_recursive(a, left, sidx1-1);
    quick_sort_recursive(a, sidx1 + 1, sidx2-1);
    quick_sort_recursive(a, sidx2+1, right);
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
    clock_t t1 = clock();
    quick_sort_recursive(a,0,tot-1);    
    int time=(clock() - t1) * 1.0 / CLOCKS_PER_SEC * 1000 ;
    
    cout<<"time:"<<time<<"ms"<<endl;
    
    printf("\n");
    
    return 0;
}