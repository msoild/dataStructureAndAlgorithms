//r 不用mid mid = r + l +1 >>1
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,q,a[N];
void Up(int x)
{
    int l=0,r=n-1;
    while (l<r) 
    {
        int mid=l+r>>1;
        if (a[mid]>=x)
            r=mid;
        else
            l=mid+1;
    }
    if (a[l]!=x)
        l=-1;
    cout<<l<<' ';
    return;
}

void Down(int x)
{
    int l=0,r=n-1;
    while (l<r) 
    {
        int mid =l+r+1>>1;
        if (a[mid]<=x)
            l=mid;
        else
            r=mid-1;
    }
    if (a[l]!=x)
        l=-1;
    cout<<l<<endl;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>q;
    for (int i=0; i<n; i++)
        cin>>a[i];
    while (q--) 
    {
        int x;
        cin>>x;
        Up(x);
        Down(x);
    }
    return 0;
}