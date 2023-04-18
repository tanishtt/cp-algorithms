// \    /    /\
//  \  /    /  \
//   \/    /    \
//ex-f(x)=x2+4x+7;
//unimodel
//min-max

#include<bits/stdc++.h>
double func(double x)
{
    return powd(x*2)+4*x+7;
}

double diff=0.0000001;      //1e-7/1e-6
//*******check for double and int**************
//*******for graph opening upward. "U"******* or 4 3 2 1 2 3 4
double ternarysearch(int l,int r)
{
    while (r-l>diff)
    {
        double m1=l+(r-l)/3;
        double m2=r-(r-l)/3;

        double fm1=func(m1);
        double fm2=func(m2);

        if(fm1>fm2)
        {
            l=m1;
        }
        else if(fm1<fm2)
        {
            r=m2;
        }
        else
        {
            l=m1;
            r=m2;
        }
    }
    return l;
    
}
int main()
{
    // given range of x
    // given function.
    //use ternary search get x;


    //if(round off required ,do it.)
    return 0;
}