struct query 
{
	long long int l;
	long long int r;
	long long int in;
} q[200005];

bool compare(query x, query y) 
{
	if (x.l / BLOCK != y.l / BLOCK) 
	{
		// different blocks, so sort by block.
		return x.l / BLOCK < y.l / BLOCK;
	}
	// same block, so sort by R value
	return x.r < y.r;
}

void add(long long int cur) 
{
	cnt[arr[cur]]++;
	if (cnt[arr[cur]] == 1) 
	{
		tans++;
	}
}

void remove(long long int cur) 
{
	cnt[arr[cur]]--;
	if (cnt[arr[cur]] == 0) 
	{
		tans--;
	}
}


int main() 
{

	fastRead_int(n);
	loop(i, 0, n) 
	{
		fastRead_int(arr[i]);
	}

	fastRead_int(t);
	loop(i, 0, t) 
	{
		fastRead_int(a);
		fastRead_int(b);
		a--, b--;
		q[i].l = a, q[i].r = b, q[i].in = i;
	}
	sort(q, q + t, compare);
	int curL = 0, curR = 0;
	loop(i, 0, t) 
	{

		while (curL < q[i].l) 
		{
			remove(curL);
			curL++;
		}
		while (curL > q[i].l) 
		{
			add(curL - 1);
			curL--;
		}
		while (curR <= q[i].r) 
		{
			add(curR);
			curR++;
		}
		while (curR > q[i].r + 1) 
		{
			remove(curR - 1);
			curR--;
		}
		ans[q[i].in] = tans;

	}
	for (int i = 0; i < t; ++i) 
	{
		printf("%d\n", ans[i]);
	}		
	return 0;
}