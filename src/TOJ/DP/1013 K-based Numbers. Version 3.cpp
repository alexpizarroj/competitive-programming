#include <bits\stdc++.h>
using namespace std;

struct Matrix
{
	static const unsigned n = 2;
	const static Matrix Identity;

	long long val[n][n];

	Matrix() {}

	Matrix(long long a, long long b, long long c, long long d)
	{
		val[0][0] = a, val[0][1] = b;
		val[1][0] = c, val[1][1] = d;
	}
};
const Matrix Matrix::Identity(1, 0, 0, 1);

long long multiply(long long a, long long b, long long m)
{
	unsigned long long x = 0, y = a % m;
	while (b > 0)
	{
		if (b & 1)
			x = (x + y) % m;
		y = (2 * y) % m;
		b >>= 1;
	}
	return x;
}

Matrix multiply(const Matrix &A, const Matrix &B, long long m)
{
	Matrix ret;
	for(unsigned i = 0; i < A.n; i++)
		for(unsigned j = 0; j < A.n; j++)
		{
			unsigned long long tmp = 0;
			for(unsigned k = 0; k < A.n; k++)
				tmp = (tmp + multiply(A.val[i][k], B.val[k][j], m)) % m;
			ret.val[i][j] = tmp;
		}
	return ret;
}

Matrix power(const Matrix &A, long long e, long long m)
{
	Matrix ret = Matrix::Identity, B = A;
	while (e > 0)
	{
		if (e & 1)
			ret = multiply(ret, B, m);
		B = multiply(B, B, m);
		e >>= 1;
	}
	return ret;
}

int main()
{   
	// Fast IO
	ios_base::sync_with_stdio(0); cin.tie(0);

	long long n, k, m;
	while (cin >> n >> k >> m)
	{
		// cout << "=== " << n << " " << k << " " << m << '\n';

		Matrix base;
		base.val[1][1] = (k - 1) % m;
		base.val[0][1] = base.val[1][0] = multiply(k, k - 1, m);
		base.val[0][0] = ((unsigned long long)base.val[0][1] + base.val[1][1]) % m;
		base.val[0][0] = multiply(k - 1, base.val[0][0], m);

		if (n == 2)
			cout << base.val[0][1] << "\n";
		else if (n == 3)
			cout << base.val[0][0] << "\n";
		else
		{
			Matrix tmp = power(Matrix(k - 1, 1, k - 1, 0), n - 3, m);
			base = multiply(base, tmp, m);
			// cout << base.val[0][0] << " " << base.val[0][1] << "\n";
			// cout << base.val[1][0] << " " << base.val[1][1] << "\n";
			cout << base.val[0][0] << "\n";
		}
	}
	return 0;
}
