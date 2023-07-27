#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    ll s;
    cin >> n >> s;
    vector<int> a(n);
    vector<int> l {};
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int i , j = 0;
    ll sum = a[0];
    while(j < n){
        while(sum <= s)
        {
           sum+=a[++j];
        }
        sum-=a[i];
        if(i==j) j++;
        i++;
    }
    cout << i << " " << j-1 << "\n";
    return 0;
}