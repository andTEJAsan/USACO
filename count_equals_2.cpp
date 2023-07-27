#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for(int i = 0 ; i < n; i++) cin >> a[i];
    for(int i = 0 ; i < m; i++) cin >> b[i];
    vector<int> c(m);
    int i=0;
    int count = 0;
    int element = b[0];
    while(i < n && a[i]<b[0]) i++;
    while(i < n && a[i]==b[0]){
        count++;
        i++;
    }
    c[0] = count;
    for(int j = 1; j < m ; j++)
    {
        if(b[j] != element){
            count = 0;
            element =  b[j];
            while(i < n && a[i]<b[j]) i++;
            while(i < n && a[i]==b[j]){
                count++;
                i++;
            }
        }
        c[j] = count;

    }
    long long sum=0;
    for(auto x : c) sum+=x;
    cout << sum << "\n";

    return 0;
}