#include<iostream>
#include<vector>
using namespace std;

int binary_upper(const vector<int>& a , int x){
// to find the smallest index such that x < a[i]
    if (x < a[0]) return 0;
    else if (x >= a[a.size()-1]) return a.size();
    int n = a.size();
    int r = n-1;
    int l = 0;
    // now we have a[0] <= x < a[N-1];
    while(l < r){
        int mid = l + (r-l+1)/2;
        if(a[mid] >= x) l = mid+1;
        else {
            if(x < a[mid-1]) return mid-1;
            r = mid;
        }
    }
    return r;
}


int binary_lower(const vector<int>& a , int x){
// to find the largest index such that x > a[i]
    if (x > a[a.size()-1]) return a.size()-1;
    else if (x <= a[0]) return -1;
    int n = a.size();
    int r = n-1;
    int l = 0;
    // now we have a[0] <= x < a[N-1];
    while(l < r){
        int mid = l + (r-l+1)/2;
        if(a[mid] >= x) r = mid-1;
        else {
            l = mid;
        }
    }
    return r;
}






int main() {
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);

    for(int i = 0 ; i < n; i++) cin >> a[i];
    for(int i = 0 ; i < m; i++) cin >> b[i];
    vector<int> c(m);
    for(int i = 0 ; i < m; i++)
    {
        c[i] = binary_upper(a,b[i]) - binary_lower(a,b[i]) -1;
    }
    long long sum = 0;
    for(auto x : c) sum+=x;
    cout << sum <<"\n";


    return 0;
}