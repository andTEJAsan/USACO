#include<iostream>
#include<string>
#include<map>
#include<fstream>
/*
ID: tejasan1
LANG: C++
TASK: friday
*/
using namespace std;
int main(){
  ofstream fout ("friday.out");
  ifstream fin ("friday.in");
int N;
fin >> N;
int frequency[7]= {0,0,0,0,0,0,0};
/*
Starting from 1st Jan 1900 ending on 31 Dec 1900 + N - 1 N <= 400;
if an year is not a leap year then Feb has 28 days
1 Jan was a Monday
Weeks : 0 1 2 3 4 5 6 

There are 12 13ths in an year
if the starting day is day i, then the first 13th is i + 5 mod 7
                              2nd one is going to be i + 1 mod 7
                              3rd one is going to be i + 1 mod 7
                              4 th one is going to be i + 3 mod 7
                              5   i + 6
                               6 i + 1
                               7 



*/


return 0;
}
