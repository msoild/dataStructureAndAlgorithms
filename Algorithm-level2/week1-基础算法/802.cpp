#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int>PII;

int find(vector<int>& nums, int x) {
    int l = 0, r = nums.size() - 1;
    while(l < r) {
        int mid = l + r >> 1;
        if(nums[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l + 1;
}


int main() {
    int n, m;
    //所有数的下标
    vector<int> alls;
    vector<int> a;
    vector<int> aPreSum;
    vector<PII> add, query;
  
    cin >> n >> m;
    while(n --) {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
        alls.push_back(x);
    }
    
    while(m --) {
        int l , r;
        cin >> l >> r;
        query.push_back({l, r});
        alls.push_back(l);
        alls.push_back(r);
        
    }
    
    //order and erase the same   
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    
    int allsSize = alls.size();
    a.resize(allsSize + 1);
    aPreSum.resize(allsSize + 1);
    
    for(auto&& item: add) {
        int index = find(alls, item.first);
        a[index] += item.second;
    }
    
    for(int i = 1; i <= allsSize; i ++) aPreSum[i] = aPreSum[i -1] + a[i];
    
    for(auto&& item : query) {
        int l = find(alls, item.first);
        int r = find(alls, item.second);
        cout << aPreSum[r] - aPreSum[l - 1] << std::endl;
    }
    
    return 0;
}