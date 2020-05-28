#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define lld long double
#define F first
#define S second
#define f(i,a,b) for(int i=a;i<=b;i++)
#define g(i,a,b) for(int i=a;i>=b;i--)
#define mp make_pair
#define pb push_back
#define mh make_heap
#define ph push_heap
#define pq priority_queue
#define bits(x) __builtin_popcountll(x)
#define op(x) cout<<"Case #"<<x<<": "
#define op1(x) cout<<"Case "<<x<<": "
using namespace std;
const ll mod = 1000000007;
const ll INF = 1e18;
const int N = 21;

void solve(int t)
{
	ll a, b;
	long double d;
	cin >> a >> b >> d;

	ll ans = 2;
	long double diff = abs(((a + b) * 1.0) / (2.0) - d);

	ll lo = 1;
	ll hi = 1000000;
	ll mid;


	while (lo <= hi)
	{
		mid = (lo + hi) / 2;
		long double avg = ((mid * a) * 1.0 + (mid - 1) * b * 1.0) / ((2 * mid - 1) * 1.0);

        cout<<mid<<" "<<avg<<" "<<endl;
		if (avg <= d)
		{
			hi = mid - 1;
			if (abs(avg - d) < diff)
			{
				ans = 2 * mid - 1;
				diff = abs(avg - d);
			}

			if (abs(avg - d) == diff)
			{
				ans = min(ans, 2 * mid - 1);
				diff = abs(avg - d);
			}

		}
		else
		{
			lo = mid + 1;
			if (abs(avg - d) < diff)
			{
				ans = 2 * mid - 1;
				diff = abs(avg - d);
			}
			if (abs(avg - d) == diff)
			{
				ans = min(ans, 2 * mid - 1);
				diff = abs(avg - d);
			}
		}
	}

	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    long double xl = 10.23;
    cout<<xl<<endl;
	int t = 1;
	cin >> t;

	for (int i = 1; i <= t; i++)
	{
		solve(i);

	}
}