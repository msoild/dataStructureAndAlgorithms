//1. 快速排序模板
// 递归方法
// 1 5 3 6 4 (4 as pivot)
int partition(vector<int> &input, int l, int r) {
    int v = input[r];
    int i = l, j = r -1;
    while(i < j) {
        while(i < j && input[i] <= v) i ++;
        while(i < j && input[j] >= v) j --;
        if(i < j) swap(input[i], input[j]);
    } 
    swap(input[r], input[i]);
    return i;
}

void quickSort(vector<int>& input, int l, int r) {
    if(l >= r) return;
    int pivot = partition(intput, l , r);
    quickSort(input, l, pivot - 1);
    quickSort(input, pivot + 1, r);
}

#include <iostream>

using namespace std;

const int N = 1000010;

int q[N];

int partition(int q[], int l, int r) {
    int i = l, j = r;
    int v = q[r];
    while(i < j) {
        while(i < j && q[i] <= v) i ++;
        while(i < j && q[j] >= v) j --;
        if(i < j) swap(q[i], q[j]);
    }
    swap(q[i], q[r]);
    return i;
    
}
void quick_sort(int q[], int l, int r)
{
    if(l >= r) return;
    int pilot = partition(q, l, r);
    quick_sort(q, l, pilot -1);
    quick_sort(q, pilot +1, r);
   
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i ++ ) scanf("%d", &q[i]);

    quick_sort(q, 0, n - 1);

    for (int i = 0; i < n; i ++ ) printf("%d ", q[i]);

    return 0;
}
