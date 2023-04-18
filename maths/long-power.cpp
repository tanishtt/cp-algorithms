long long int power(long long int a,long long int x)
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
	long long int temp=power(a,x/2);
	if(x%2==0)
	{
		return temp*temp;
	}
	else
	{
		return a*temp*temp;
	}
}