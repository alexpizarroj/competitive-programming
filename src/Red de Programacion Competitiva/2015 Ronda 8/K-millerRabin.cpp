#include <bits/stdc++.h>
using namespace std;

long long modprod(long long A, long long B, long long MOD)
{
  long long P = 0;
  while(B)
  {
    if(B & 1) P = (P + A) % MOD;
    
    B >>= 1;
    A = (A << 1) % MOD;
  }
  return P;
}

long long modpow(long long x, long long n, long long MOD) 
{ 
    long long P = 1;
    while(n) 
    { 
        if(n & 1) P = modprod(P, x, MOD); 
        
        n >>= 1; 
        x = modprod(x, x, MOD); 
    }
    return P; 
} 

bool isProbablePrime(long long n)
{
  if (n <= 1 || (n != 2 && n % 2 == 0)) return 0;
  if (n == 2) return 1;
  
  long long m = n - 1; int k = 0;
  while((m & 1) == 0) k++, m >>= 1;
  
  for(int it=0; it<5; it++)
  {
    long long a = 2 + rand() % (n - 3), x = modpow(a, m, n);
    if(x != 1 && x != n-1)
    {
      bool probablePrime = 0;
      
      for(int r=1; r<k && !probablePrime; r++)
      {
        x = modprod(x, x, n);
        if(x == 1) return 0;
        if(x == n - 1) probablePrime = 1;
      }
      
      if(!probablePrime) return 0;
    }
  }
  
  return 1;
}

bool tryRev(string &s)
{
  for (int i = 0; i < (int)s.size() / 2; ++i)
  {
    if (s[i] == '6') s[i] = '9';
    else if (s[i] == '9') s[i] = '6';
    else if (s[i] == '3' || s[i] == '4' || s[i] == '7') return false;
    
    swap(s[i], s[(int)s.size() - i - 1]);

    if (s[i] == '6') s[i] = '9';
    else if (s[i] == '9') s[i] = '6';
    else if (s[i] == '3' || s[i] == '4' || s[i] == '7') return false;
  }

  int n = (int)s.size();

  if (n % 2 != 0)
  {
    if (s[n/2] == '6') s[n/2] = '9';
    else if (s[n/2] == '9') s[n/2] = '6';
    else if (s[n/2] == '3' || s[n/2] == '4' || s[n/2] == '7') return false;
  }

  return true;
}


int main()
{
  string s;
  while(cin >> s)
  {
    string srev = s;
    long long a = stoll(s);
    if (tryRev(s))
    { 
      long long b = stoll(s);
      if (isProbablePrime(a) && isProbablePrime(b)) cout << "yes" << endl;
      else cout << "no" << endl;
    }
    else cout << "no" << endl;
  }
    return 0;
}
