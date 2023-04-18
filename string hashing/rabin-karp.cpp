//for string matching.
//here we are find all the occurences.
//O( n + m).


vector<int> rabin_karp( string &s, string &t)
{
    int p=31;
    int m=1e9+9;
    int S=s.size(), T=t.size();
    //////////////////////////////////////////////
    vector<long long> poww(max(S , T)or 1e5+9);//see here
    //////////////////////////////////////////////


    
    poww[0]=1;
    for( int i=1 ; i < poww.size() ; i++)
    {
        poww[i]=(poww[i-1] * p)%m;
    }

    vector<long long> h(T + 1,0);

    for(int i=0; i<T ; i++)
    {
        h[i+1] = (h[i]+(t[i] - 'a' + 1)*poww[i] )%m;
    }//1 based index;

    long long h_s=0;

    for(int i=0; i<S ; i++)
    {
        h_s = (h_s + (s[i] - 'a' + 1)*poww[i])%m;
    }

    vector<int> occur;
    //1 based index;
    //n-m+1
    for(int i=0; i < T - S + 1 ;i++)
    {
        long long curr_h = (h[i+S] - h[i] + m)%m;
        if(curr_h == h_s*poww[i]%m)
        {
            occur.push_back(i);
        }
    }

    return occur;
}