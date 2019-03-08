//
//  main.cpp
//  multi qs
//
//  Created by Yuan Yiliang on 8/3/19.
//  Copyright © 2019 Yuan Yiliang. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int num_cmp=0;

int cmp ( const void *a , const void *b )
{
    return *(int *)a - *(int *)b;
}

int findidx(int val, int p[],int k)
{
    num_cmp++;
    for (int i = 0; i < k; ++i)
    {
        if(val<=p[i])
            return i;
    }
    return k;
}

void reverce(int a[],int p1,int p2)
{
    int tmp = a[p1];
    a[p1]=a[p2];
    a[p2]=tmp;
}

void pri(int a[],int s,int e)
{
    for (int i = s; i <= e; ++i)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int pivot(int a[],int s,int e,int k)
{
    if(s>=e)
        return 0;
    int *val;
    val = new int[k];
    int *num;
    num = new int[k+2];
    int *b;
    b = new int[e-s+1];
    int *c;
    c = new int[e-s+1];

    memset(num,0,sizeof(int)*(k+2));    
    int pos;
    
    //find k pivot
    for (int i = 0; i < k; ++i)
    {
        pos = rand()%(e-s+1)+s;
        val[i]=a[pos];
    }
    qsort(val, k, sizeof(int), cmp);
    // cout<<"val: ";
    // pri(val,0,k-1);
    int ind;
    int i_b;
    // cout<<"start count\n";
    for (int i = s; i <= e ; ++i)
    {
        i_b = i-s;
        ind=findidx(a[i],val,k);//0 - k
        b[i_b]=ind;
        num[ind]++;
    }
    // pri(num,0,k+1);
    
    
    int p2[k+2];
    p2[0]=0;
    for (int i = 0; i < k+1; ++i)
    {
        num[i+1]+=num[i];
        p2[i+1]=num[i];
    }
    // pri(p2,0,k+1);
    memcpy(num,p2,sizeof(int)*(k+2));
    
    // cout<<"start put into new\n";
    for (int i = s; i <= e ; ++i)
    {
        i_b = i-s;
        ind=b[i_b];
        if( ind==k || a[i]<val[ind]){
            c[ num[ind] ] = a[i];
            num[ind]++;
            num_cmp++;
        }
        
    }// put into the right place
    
    // cout<<"ending num[]=";pri(num,0,k+1);
    // cout<<"ending p2[]=";pri(p2,0,k+1);

    for (int i = 0; i<k; i++)
    {
        for (int j=num[i]; j<p2[i+1];j++){
            c[j]=val[i];
            num_cmp++;
        }
    }
    // cout<<"ending\n";
    // c-> a
    //!!!!
    memcpy(a+s, c, sizeof(int)*(e-s+1));
    
    // cout<<"a[]=";
    // pri(a, 0, 9);
    
    delete []val;
    delete []num;
    delete []b;
    delete []c;
    for (int i = 0; i < k; ++i)
    {
        //p2[i+1]: next start
        //p2[i+1]-1: this end
        //p2[i+1]-2: this end - val
        if(p2[i+1]-2-p2[i]>=1)
            pivot(a,p2[i]+s,p2[i+1]+s-2,k);
    }
    //last partion
    if(p2[k+1]-1-p2[k]>=1)
        pivot(a,p2[k]+s,p2[k+1]+s-1,k);
    return 0;
}


int main(int argc, char const *argv[])
{
    //srand( (unsigned)time( NULL ) );
    srand(1);
    int tot=500000;
    // cin>>tot;

    int a[tot+5];
    int b[tot+5];

    for (int i = 0; i < tot; ++i)
    {
        // a[i]=0;
        // cin>>a[i];
        // b[i]=a[i];
        b[i] = a[i] = i;

    }
    vector<int> nv;
    for (int kkk = 1; kkk <= 30; ++kkk)
    {
        memcpy(a,b,sizeof(int)*tot);
        num_cmp=0;
        clock_t t1 = clock();  
        pivot(a,0,tot-1,kkk);
        int time=(clock() - t1) * 1.0 / CLOCKS_PER_SEC * 1000 ;
        cout<<time<<",";
        nv.push_back(num_cmp);

    }

    for (int i = 0; i < tot-1; ++i){
        if(a[i]>a[i+1]){
            cout<<"ERROR";
            return -1;
        }
    }
    
    
    return 0;
}

