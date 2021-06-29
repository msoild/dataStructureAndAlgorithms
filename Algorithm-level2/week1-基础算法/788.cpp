/*
1. 找中间点
2. 归并
*/

#include <iostream>
#include <vector>

using namespace std;

const int N = 1000010;

int q[N];
int res;

int merge_sort(int q[], int l, int r, long long & revN)
{
   if (l >= r) return q[l];

    int mid = l + r >> 1;
    merge_sort(q, l, mid, revN);
    merge_sort(q, mid + 1, r, revN);
    
    std::vector<int> tmp;
    int i = l, j = mid + 1; 
    while(i <= mid && j <= r) {
        if(q[i] <= q[j]) tmp.push_back(q[i ++]);
        else  revN += (mid - i + 1), tmp.push_back(q[j ++]);
    }
    while(i <=mid) tmp.push_back(q[i ++]);
    while(j <= r) tmp.push_back(q[j ++]);
    int k = l;
    for(auto& x : tmp) {
        q[k ++] = x;
    }
    
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i ++ ) scanf("%d", &q[i]);
    long long revN = 0;
    merge_sort(q, 0, n -1, revN);
    printf("%lld", revN);
   
    return 0;
}

