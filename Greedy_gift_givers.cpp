#include<iostream>
#include<string>
#include<map>
#include<fstream>
/*
ID: tejasan1
LANG: C++
TASK: gift1
*/
using namespace std;
int main(){
  ofstream fout ("gift1.out");
  ifstream fin ("gift1.in");
  int NP;
  fin >> NP;
  string names[NP];
  map <string, int> amount;
  for(int i = 0; i < NP; i++) 
  {
    string s;
    fin >> s;
    names[i] = s;
    amount[s] = 0; 
  }
  for(int i = 0; i < NP; i++) 
  {
    string person;
    int tot;
    int k;
    fin >> person >> tot >> k;
    amount[person] -= (k > 0 ? (k*(tot/k)) : 0);
    for(int j = 0 ; j < k; j++)
    {
      string person;
      fin >> person;
      amount[person] += (tot/k);
    }
  }
  for(int i = 0; i < NP; i++)
  {
    fout << names[i] << " " << amount[names[i]] << "\n";
  }
  return 0;
}
