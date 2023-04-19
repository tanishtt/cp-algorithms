#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007


ll power(ll a , ll b)
{
    ll ans = 1;
    while(b)
    {
        if(b&1) ans = (ans%mod * a%mod)%mod;
        a=(a%mod * a%mod)%mod;
        b=b>>1;
    }
    return ans;
}


int main()
{
        string s,t;
        cin>>s>>t;
        int n=s.size();
        int m=t.size();
        //n>=m finding t in s;

        vector<pair<ll,ll>> hash(n);

        ll p1=31 , p2=37 , m1=1 , m2=1;
        vector<ll> pow_p1(n) , pow_p2(n);

        for(int i=0 ; i<n ; i++)
        {
            pow_p1[i] = m1;
            pow_p2[i] = m2;
            ll hash1 = ((s[i] - 'a' + 1)*m1 )%mod;
            ll hash2 = ((s[i] - 'a' + 1)*m2 )%mod;
            m1 = (m1*p1)%mod;
            m2 = (m2*p2)%mod;

            if(i)
            {
                hash1 = (hash1 + hash[i-1].first) % mod;
                hash2 = (hash2 + hash[i-1].second) % mod;
            }
            hash[i] = {hash1 , hash2};
        }

        //for t->m
        ll t_hsh1=0 ,t_hsh2=0;
        for(int i=0 ; i<m ; i++)
        {
            t_hsh1 = (t_hsh1 + (t[i] - 'a' + 1)*pow_p1[i] )%mod;
            t_hsh2 = (t_hsh2 + (t[i] - 'a' + 1)*pow_p2[i] )%mod;
            

        }
        //cout<<t_hsh1<<" "<<t_hsh2;
        //for t->{thsh1,thsh2}

        vector<ll> inv_p1(n) , inv_p2(n);

        // for(int i=0 ; i<n ; i++)
        // {
        //     inv_p1[i] = power(pow_p1[i] , mod-2);
        //     inv_p2[i] = power(pow_p2[i] , mod-2);
        // }

        ll pw_inv1=power(p1, mod-2 );
        ll pw_inv2=power(p2, mod-2 );
        inv_p1[0]=1;
        inv_p2[0]=1;
        for(int i=1 ; i<n; i++)
        {
            inv_p1[i]=(inv_p1[i-1] * pw_inv1)% mod;
            inv_p2[i]=(inv_p2[i-1] * pw_inv2)% mod;
        }

        auto getHash = [&](ll l ,ll r){
                ll hash1 = hash[r].first , hash2 = hash[r].second;
                if(l){
                    hash1 = (hash1 - hash[l-1].first + mod)%mod;
                    hash2 = (hash2 - hash[l-1].second + mod)%mod;
                    hash1 = (hash1 * inv_p1[l])%mod;
                    hash2 = (hash2 * inv_p2[l])%mod;
                }
                return make_pair(hash1 , hash2);
            };


        vector<ll> occur;
        //let n=6 m=3;
        //i<6-3+1=4 , 0123
        for(int i=0 ; i<n-m+1 ; i++)
        {
            //[0..i-1]
            //[0..j]
            ll ii=i;
            ll jj=i+m-1;
            // ll hsi_1_1=0, hsi_1_2=0;
            // if(ii)
            // {
            //     hsi_1_1= hash[ii-1].first;
            //     hsi_1_2= hash[ii-1].second;
            // }
            

            // ll hsj_1= hash[jj].first;
            // ll hsj_2= hash[jj].second;

            // ll h1,h2;
            // //[0..j]-[0..i-1]
            // h1= hsj_1 - hsi_1_1 + mod;
            // h2= hsj_2 - hsi_1_2 + mod;
            
            // h1= (h1 * inv_p1[ii])% mod;
            // h2= (h2 * inv_p2[ii])% mod;
            
            auto h=getHash(ii,jj);
            if(t_hsh1 ==  h.first && t_hsh2 == h.second)
            {
                occur.push_back(i);
            }
        }

        for( int i=0; i<occur.size() ;i++)
        {
            cout<<occur[i]<<" ";
        }
            // auto pp=getHash(1 , 4);
            // cout<<pp.first<<" "<<pp.second;


        return 0;
    }