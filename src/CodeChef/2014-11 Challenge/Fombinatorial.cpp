#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

long long modexp(const int b, long long e, const int m)
{
	// Preconditions
	assert(b >= 0);
	assert(e >= 0);
	assert(m >= 1);
	// Iterative exponentiation
	long long ans = (1 % m), power = (b % m);
	while (e > 0)
	{
		if (e & 1)
			ans = (ans * power) % m;
		power = (power * power) % m;
		e >>= 1;
	}
	return ans;
}

void getPrimes(const int upto, vector<int> &primes)
{
	vector<bool> is_prime(upto+1, true);
	is_prime[0] = is_prime[1] = false;

	for(int i = 2; i*i <= upto; i++)
		if (is_prime[i])
			for(int j = i*i; j <= upto; j += i)
				is_prime[j] = false;

	primes.clear();
	for(int i = 2; i <= upto; i++)
		if (is_prime[i])
			primes.push_back(i);
}

void factorize(const vector<int> &primes, int n, vector<ii> &f)
{
	// Preconditions
	assert(n <= (long long)primes.back() * primes.back());
	// Prime factorization
	f.clear();
	for(int cur = 0; cur < (int)primes.size(); ++cur)
	{
		const int &p = primes[cur];

		if ((long long)p * p > n)
			break;
		if (n % p != 0)
			continue;

		int x = 0;
		while (n % p == 0)
		{
			x += 1;
			n /= p;
		}
		f.push_back(ii(p, x));
	}
	if (n != 1)
		f.push_back(ii(n, 1));
}

int getTotient(int n, const vector<ii> &primeFactorization)
{
	int top = 1, bot = 1;
	for(const ii &x : primeFactorization)
	{
		top *= (x.first - 1);
		bot *= (x.first);
	}
	int ans = ((long long)n * top) / bot;
	return ans;
}

int main()
{
	// Fast IO
	ios_base::sync_with_stdio(0); cin.tie(0);

	// Precalculations
	const int cstMaxN = 100000;
	vector<int> primes;
	vector< vector<ii> > factors(cstMaxN+1);;
	getPrimes(cstMaxN, primes);
	for(int i = 1; i <= cstMaxN; i++)
		factorize(primes, i, factors[i]);

	// Test case processing
	vector<int> isFactorOfM(cstMaxN+1, -1);
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, m, q;
		cin >> n >> m >> q;

		// Special case
		if (m == 1)
		{
			while (q--)
			{
				int r;
				cin >> r;
				cout << "0\n";
			}
			continue;
		}

		// M factorization
		vector<ii> mFactors;
		factorize(primes, m, mFactors);
		for(int i = 0; i < (int)mFactors.size(); i++)
		{
			const int p = mFactors[i].first;
			if (p <= cstMaxN)
				isFactorOfM[p] = i;
		}
		int mTotientValue = getTotient(m, mFactors);

		// g'(x) + highestPower precalculation
		vector< vector<long long> > highestPower(n+1);
		vector<int> g(n+1), ginv(n+1);
		highestPower[1] = vector<long long>(mFactors.size(), 0);
		g[1] = 1;
		ginv[1] = modexp(g[1], m-2, m);
		for(int x = 2; x <= n; ++x)
		{
			int base = 1;
			highestPower[x] = highestPower[x-1];
			for(const ii &y : factors[x])
				if (isFactorOfM[y.first] == -1)
				{
					for(int i = 0; i < y.second; ++i)
						base *= y.first;
				}
				else
				{
					int pos = isFactorOfM[y.first];
					highestPower[x][pos] += (y.second * x);
				}
			g[x] = ((long long)g[x-1] * modexp(base, x, m)) % m;
			ginv[x] = modexp(g[x], mTotientValue-1, m);
		}

		while (q--)
		{
			long long ans = 0;
			int r;
			cin >> r;
			
			ans = (long long)g[n] * ginv[r] % m;
			ans = ans * ginv[n-r] % m;
			
			for(int i = 0; i < (int)mFactors.size(); i++)
			{
				long long x = highestPower[n][i];
				x -= highestPower[r][i];
				x -= highestPower[n-r][i];
				ans = ans * modexp(mFactors[i].first, x, m) % m;
			}
			
			cout << ans << "\n";
		}

		for(const ii &x : mFactors)
			if (x.first <= cstMaxN)
				isFactorOfM[x.first] = -1;
	}

	return 0;
}
