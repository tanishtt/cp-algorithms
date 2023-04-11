#include<bits/stdc++.h>
//#include<string.h>
using namespace std;
const int mod=1e9+7;

long long get_hash(string &s)
{//s/&s
    long long h=0;
    for(char c : s)
    {
        h = ( h*31 + (c-'a'+1)) % mod;
    }
    return h;
}


int main()
{
    string s="tanish";
    cout<<get_hash(s);
}