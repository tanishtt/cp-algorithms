//o(m + n)Knuth Morris Pratt Pattern Searching Algorithm.

#include<bits/stdc++.h>
using namespace std;

//o(m)
void fillLps( vector<int> &lps ,string &pat)
{
    int m=pat.size();
    int len = 0;
    int i = 1;
    lps[0] = 0;

    while( i<m )
    {
        if(pat[i] == pat[len])
        {
            lps[i] = len + 1;
            len = len + 1;
            i++; 
        }
        else
        {
            if(len == 0)
            {
                lps[i]=0;
                i++;
            }
            else
            {
                len = lps[len-1];
            }
        }
    }
}

//o(n + m)
void kmp(string &txt ,string &pat)
{
    int n=txt.size();
    int m=pat.size();

    vector<int> lps(m);
    fillLps(lps ,pat);
    
    int i = 0, j = 0;

    while(i < n)
    {
        if(pat[j] == txt[i])
        {
            i++;
            j++;
        }

        if(j == m)
        {
            //////occurencess.
            cout<<i-j<<" ";
            j = lps[j-1];
        }
        else if( i<n && pat[j]!=txt[i])
        {
            if(j == 0)
            {
                i++;
            }
            else
            {
                j=lps[j-1];
            }
        }
        
    }
}

int main()
{
    string txt,pat;
    cin>>txt>>pat;
    kmp(txt , pat);
    return 0;
}