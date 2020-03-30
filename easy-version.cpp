#include <iostream>

using namespace std;

int main()
{
	int n;
	long long t, max = 0, min;
	int a[1000];
	int b[1000];
	int result[1000];

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 0; i < n; i++)
	{
		t = a[i]; b[i] = a[i];
		
		min = a[i];
		for (int j = i - 1; j >= 0; j--)
		{
			if (a[j] < min) min = a[j];
			t += min;
			b[j] = min;
		}

		min = a[i];

		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < min) min = a[j];
			t += min;
			b[j] = min;
		}

		if (t > max)
		{
			max = t;
			for (int j = 0; j < n; j++) result[j] = b[j];
		}
	}

	for (int i = 0; i < n; i++) cout << result[i] << " ";
	
	//system("pause");
	return 0;
}
