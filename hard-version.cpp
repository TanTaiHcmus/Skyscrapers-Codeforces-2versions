#include <iostream>
#include <ctime>

using namespace std;

int *a;
int *b;
long long *c;
long long *d;
int *arr;
long long *ip;
int *vt;
int n, positionNearby, maxLong = 500000;

int max(int x, int y)
{
	if (x >= y) return x;
	else return y;
}

int min(int x, int y)
{
	if (x <= y) return x;
	else return y;
}

void qsort(int l, int r)
{
	int i, j, x;
	i = l;
	j = r;
	x = arr[(l + r) / 2];
	do
	{
		while (arr[i] < x) i++;
		while (arr[j] > x) j--;
		if (i <= j)
		{
			swap(arr[i], arr[j]);
			swap(vt[i], vt[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (l < j) qsort(l, j);
	if (i < r) qsort(i, r);
}

int findPositionNearby(int x)
{
	int maxPosition = 0;
	while (x > 0)
	{
		maxPosition = max(maxPosition, b[x]);
		x -= x & (-x);
	}

	return maxPosition;
}

void updateTree(int i, int x)
{
	while (x <= maxLong)
	{
		b[x] = i;
		x += x & (-x);
	}
}

int findPositionNearby1(int x)
{
	int minPosition = n + 1;
	while (x > 0)
	{
		minPosition = min(minPosition, b[x]);
		x -= x & (-x);
	}

	return minPosition;
}

void updateTree1(int i, int x)
{
	while (x <= maxLong)
	{
		b[x] = i;
		x += x & (-x);
	}
}

int main()
{
	int vtri = 0;
	int *arrResult;

	cin >> n;

	a = new int[n + 2];
	b = new int[maxLong + 2];
	c = new long long[n + 2];
	d = new long long[n + 2];
	vt = new int[n + 2];
	arr = new int[n + 2];
	ip = new long long[n + 2];
	arrResult = new int[n + 2];
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		ip[i] = arr[i];
		vt[i] = i;
	}

	qsort(1, n);

	int dem = 1;
	a[vt[1]] = 1;

	for (int i = 2; i <= n; i++)
	{
		if (arr[i] != arr[i - 1]) dem++;
		a[vt[i]] = dem;
	}

	for (int i = 0; i <= maxLong; i++)
	{
		b[i] = 0;
	}

	c[0] = 0;

	for (int i = 1; i <= n; i++)
	{
		positionNearby = findPositionNearby(a[i]);
		c[i] = c[positionNearby] + ip[i] * (i - positionNearby);
		updateTree(i, a[i]);
	}

	for (int i = 0; i <= maxLong; i++) b[i] = n + 1;

	d[n + 1] = 0;
	
	for (int i = n; i >= 1; i--)
	{
		positionNearby = findPositionNearby1(a[i]);
		d[i] = d[positionNearby] + ip[i] * (positionNearby - i);
		updateTree1(i, a[i]);
	}

	long long result = 0;

	for (int i = 1; i <= n; i++) if (c[i] + d[i] - ip[i] > result)
	{
		result = c[i] + d[i] - ip[i];
		vtri = i;
	}

	arrResult[vtri] = ip[vtri];

	for (int i = vtri - 1; i >= 1; i--) arrResult[i] = min(arrResult[i + 1], ip[i]);
	for (int i = vtri + 1; i <= n; i++) arrResult[i] = min(arrResult[i - 1], ip[i]);

	for (int i = 1; i <= n; i++) cout << arrResult[i] << " ";

	delete[]a; delete[]b; delete[]c; delete[]d; delete[]vt; delete[]arr; delete[]arrResult; delete[]ip;
	//system("pause");
	return 0;
}