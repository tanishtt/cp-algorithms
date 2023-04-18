#include<bits/stdc++.h>
using namespace std;
#define long long int int

int N=1e6+1;
vector<int>pw1(N);
vector<int>inv1(N);
//int pw2[N];
//int inv2[N];
vector<int>hash1(N);
//int hash2[N];

int p=31;
int md1=1e9+7;
//int md2=1e9+9;

int power(int a,int x,int md)
{
	//use mod if reuired..******int md=1e9+7**********;
	if(x==0)
	{
		return 1;
	}
	if(x==1)
	{
		return a;
	}
	int temp=power(a,x/2,md);
	if(x%2==0)
	{
		return temp*temp;
	}
	else
	{
		return a*temp*temp;
	}
}


void sh_precalc()
{
    pw1[0]=1;
    for(int i=1; i<N; i++)
    {
        pw1[i] =(pw1[i-1] * p) % md1;
    }
    // pw2[0]=1;
    // for(int i=1; i<N; i++)
    // {
    //     pw2[i] =(pw2[i-1] * p) % md2;
    // }

    int pw_inv1=power(p, md1-2 ,md1);
    inv1[0]=1;
    for(int i=1 ; i<N; i++)
    {
        inv1[i]=(inv1[i-1] * pw_inv1)%md1;
    }

    // int pw_inv2=power(p, md2-2 ,md2);
    // inv2[0]=1;
    // for(int i=1 ; i<N; i++)
    // {
    //     inv2[i]=(inv2[i-1] * pw_inv2)%md2;
    // }

}

void sh_build(string &s)
{
    int n=s.size();
    for( int i=0; i<n; i++)
    {
        hash1[i] = (((i==0)?0:hash1[i-1]) + (s[i]-'a'+1)*pw1[i])%md1;
    }

    // for( int i=0; i<n; i++)
    // {
    //     hash2[i] = ((i==0)?0:hash2[i-1] + (s[i]-'a'+1)*pw2[i])%md2;
    // }

}

int sh_gethash(int x,int y)
{
    int res=hash1[y]-((x==0)?0:hash1[x-1]);
    res=(res*inv1[x]) % md1;
    return res;
}


int32_t main()
{
    string s,t;
    cin>>s>>t;
    sh_precalc();
    sh_build(s);
    cout<<sh_gethash(1,4);
    

    return 0;
}
