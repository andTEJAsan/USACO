#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m; 
    vector<int> a(n);
    vector<int> b(m);
    vector<int> c(m);
    for(int i = 0 ; i < n; i ++ ) cin >> a[i];
    for(int i = 0 ; i < m; i ++ ) cin >> b[i];
    {
        int i = 0; 
    for(int j = 0 ; j < m ; j++ )
    {
        while(i<n && a[i] < b[j]){
            i++;
        }
        c[j] = i;
    }
    for(auto x : c) cout << x << " ";
    }

    return 0;
}