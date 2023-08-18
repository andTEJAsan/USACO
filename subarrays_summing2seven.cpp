#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

int main(){
    ifstream fin("div7.in");
    ofstream fout("div7.out");
    int n;
    fin >> n;
    vector<int> c(n+1);
    c[0]=0;
    for(int i = 1; i <= n; i++) 
    {
        int x; fin >> x;
        c[i] = (x + c[i-1])%7;
    }
    int msz = 0;
    vector<int> right(7);
    for(int i = 1; i <= n; i++)
    {
        right[c[i]] = i;
    }
    vector<int> left(7);
    for(int i = n; i > 0; i--)
    {
        left[c[i]] = i;
    }
    int ans = 0;
    for(int i = 0; i < 7; i++)
    {
        ans = max(ans, right[i] - left[i] );
    }
    fout << ans << "\n";
    return 0;
}
