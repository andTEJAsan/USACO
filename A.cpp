#include<vector>
#include<iostream>
typedef long long ll;
using namespace std;

ll sqrt(ll n){
    ll l = 1;
    ll r = n;
    bool found = false;
    while(l < r)
{
    ll mid = l +(r-l+1)/2;
    if(mid*mid <= n && (mid+1)*(mid+1)> n) {l = r = mid;}
    else if (mid*mid <=n) l= mid+2;
    else r = mid -1;
}
return l;
}
inline void solve()
{
    ll n;
    cin >> n;
    // to find the largest interval [l,r] such that for all i , l<= i <= r i divides n;
    vector<bool> a(n+1,false); 
    for(int i = 2; i <n; i++)
    {
        if (!a[i] && n%i != 0)
        {
                for(ll j = i ; j < n; j+=i) a[j] = true;
        }
    }
    ll max_size = 1;
    ll present_count = 1;
    for(int i= 2; i <= n; i++)
    {
        if(!(a[i])) present_count++;
        else {
            max_size = max(max_size, present_count);
            present_count = 0;
        }

    }
    cout << max_size << "\n";
}
int main() {
    ll t;
    cin >> t;
    while(t--){
    solve();
    }
    return 0;
}