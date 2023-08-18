#include<iostream>
#include<vector>

typedef long long ll;
using namespace std;

int main() {
    ll n, s;
    cin >> n >> s;
    vector<ll> a(n);
    for(ll i = 0 ; i < n; i++)
    {
        cin >> a[i];
    }
    ll i = 0;
    ll j = 0;
    ll sum = 0;
    ll len = 0;
    while(sum < s && j < n) sum+=a[j++]; // compute the good subarray with the least value of j 
    if(sum < s) cout << -1 << "\n";
    else 
    {
        if(j == n) cout << n << "\n";
        else {
            j--;
            ll res = j-i+1;
            for(j=j+1; j < n; j++)
            {
                sum+=a[j];
                while(sum >= s)
                {
                    sum-=a[i];
                    i++;
                }
                i--;
                sum+=a[i];
                // compute the max i such that a[i..j] is good

                res = min(res,j-i+1);
            }
            cout << res << "\n";
        }
    }
    
    
    return 0;
}
