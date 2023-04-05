#include <bits/stdc++.h>
using namespace std;

double func(double x,double b, double c)
{
    return (x*x+b*x+c)/sin(x);
}
double diff=0.000001;      //1e-7/1e-6
//check for double and int
//for graph opening upward. "U"
double ternarysearch(double l,double r,double b,double c)
{
    while (r-l>diff)
    {
        double m1=l+(r-l)/3;
        double m2=r-(r-l)/3;

        double fm1=func(m1,b,c);
        double fm2=func(m2,b,c);

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
    double d=func(l,b,c);
    return d;
    
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    double b,c;
	    cin>>b>>c;
	    cout<<fixed<<setprecision(12)<<ternarysearch(0,M_PI_2,b,c)<<endl;
	    //cout<<ternarysearch(0,M_PI_2,b,c)<<"\n";
	}
	return 0;
}