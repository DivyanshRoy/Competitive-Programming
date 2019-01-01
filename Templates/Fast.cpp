

long long int matrix1[3][3],matrix2[3][3],result[3][3],init_matrix[3][3];

void matrix_multiply()
{
	long long int i,j,k;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			result[i][j]=0;
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			for(k=0;k<3;k++)
			{
				result[i][j]+=matrix1[i][k]*matrix2[k][j];
			}
		}
	}
}

void matrix_pow(long long int p)
{
	long long int i,j;
	if(p==1)
	{
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				result[i][j]=init_matrix[i][j];
			}
		}
		return;
	}

	matrix_pow(p/2);
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			matrix1[i][j]=matrix2[i][j]=result[i][j];
		}
	}
	matrix_multiply();
	if(p%2==1)
	{
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				matrix1[i][j]=result[i][j];
				matrix2[i][j]=init_matrix[i][j];
			}
		}	
		matrix_multiply();
	}
}

void matrix_pow(long long int arr[3][3],long long int p)
{
	long long int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			init_matrix[i][j]=arr[i][j];
		}
	}
	matrix_pow(p);
}	


long long int fast_pow(long long int a,long long int p,long long int m)
{
	if(p==0)
		return 1;
	if(p==1)
		return a;
	long long int ans=1,sq=fast_pow(p/2);
	ans=(sq*sq)%m;
	if(p&1)
		ans=(ans*a)%m;
	return ans;
}
