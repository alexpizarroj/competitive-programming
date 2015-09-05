import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;

class F {
  static ArrayList<Integer> getPrimesUnder(int n) {
    boolean[] is_prime = new boolean[n + 1];
    for (int i = 0; i <= n; ++i) {
      is_prime[i] = true;
    }
    
    for (int i = 2; i * i <= n; ++i) {
      if (!is_prime[i]) {
        continue;
      }
      for (int j = i * i; j <= n; j += i) {
        is_prime[j] = false;
      }
    }
    
    ArrayList<Integer> primes = new ArrayList<>();
    for (int i = 2; i <= n; ++i) {
      if (is_prime[i]) {
        primes.add(i);
      }
    }
    return primes;
  }
  
  static boolean isPrime(long n) {
    BigInteger x = BigInteger.valueOf(n);
    return x.isProbablePrime(100);
  }
  
  static boolean isSquare(long n) {
    long sqrt = (long)Math.floor(Math.sqrt((double)n));
    return (sqrt * sqrt == n);
  }
  
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    ArrayList<Integer> primes = getPrimesUnder(1000000);
    
    while (sc.hasNextLong()) {
      long n = sc.nextLong();
      int ans = 1;
    
      int cbrt = (int)Math.floor(Math.cbrt((double)n));
      for (int i = 0; i < primes.size() && primes.get(i) <= cbrt; ++i) {
        if (n % primes.get(i) == 0) {
          int cnt = 1;
          n /= primes.get(i);
          while (n % primes.get(i) == 0) {
            cnt += 1;
            n /= primes.get(i);
          }
          ans *= cnt + 1;
        }
      }
      
      if (n == 1) {
        // ans *= 1;
      } else if (isPrime(n)) {
        ans *= 2;
      } else if (isSquare(n)) {
        ans *= 3;
      } else {
        ans *= 4;
      }
      
      System.out.println(ans);
    }
  }
}