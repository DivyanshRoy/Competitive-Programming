bool prime[1000005];

long long int i,j,n=1000000;

void sieve()
{
	for(i=0;i<=n;i++)
		prime[i]=1;
	prime[0]=prime[1]=0;
	for(i=2;i<=n;i++)
	{
		if(!prime[i])
			continue;
		for(j=i*i;j<=n;j+=i)
		{
			prime[j]=0;
		}
	}	
}