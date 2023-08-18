#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream fin("stacking.in");
    ofstream fout("stacking.out");
    int n, k;
    fin >> n >> k;
    vector<int> s(n+1);
    for(int i = 0 ; i < k ; i++)
    {
        int x,y;
        fin >> x >> y;
        s[x]++;
        if(y < n) s[y+1]--;
    }
    for(int i =1 ; i < n+2; i++ )
    {
        s[i] +=s[i-1];
    }
    sort(++s.begin(),s.end());
    fout << s[(n+1)/2];
    return 0;
}