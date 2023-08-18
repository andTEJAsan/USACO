#include<iostream>
#include<vector>
typedef long long ll;
using namespace std;

int main() {
    ll n ,s ;
    cin >> n >> s;
    vector<ll> a(n);
    for(int i = 0; i < n;  i ++) cin >> a[i];
    ll i = 0;
    ll j = 0;
    ll sum = 0; 
    ll count = 0;
    for(; j < n; j++)
    {
       sum+=a[j]; 
       while(sum > s)
       {
            sum-=a[i];
            i++;
       }
       count+= j-i+1;
    }
    cout << count << "\n";
    return 0;
}