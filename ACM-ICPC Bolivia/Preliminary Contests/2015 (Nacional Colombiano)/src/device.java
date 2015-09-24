// Solved by Alex Pizarro
import java.util.*;
import java.math.*;
import java.lang.*;
import java.io.*;

public class device {
  public static ArrayList<ArrayList<Decision>> vec; // options per device
  public static Fraction[][] dp; // memoization table
  public static int n; // nDevices

  public static Fraction solve(int cur, int mon) {
    if (cur == n) {
        return new Fraction();
    }
    if (dp[cur][mon] != null) {
        return dp[cur][mon];
    }

    Fraction res = new Fraction();
    res.a = 0;

    for (int i = 0; i < vec.get(cur).size(); ++i) {
        Decision dec = vec.get(cur).get(i);
        if (mon < dec.cost) {
            continue;
        }

        Fraction next = solve(cur + 1, mon - dec.cost);
        Fraction cand = next.multiply(dec.dontfail_odds);
        if (res.isLessThan(cand)) {
            res = cand;
        }
    }
    
    dp[cur][mon] = res;
    return res;
  }
  
  public static void main(String[] args) {
      //BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      Scanner sc = new Scanner(System.in);
      
      while (sc.hasNextInt()) {
          n = sc.nextInt();
          int money = sc.nextInt();
          
          int[] dec_size = new int[n];
          for (int i = 0; i < n; ++i) {
              dec_size[i] = sc.nextInt();
          }
          
          vec = new ArrayList<>();
          for (int i = 0; i < n; ++i) {
              vec.add(new ArrayList<Decision>());
              for (int k = 0; k < dec_size[i]; ++k) {
                  Decision dec = new Decision();
                  
                  long a = sc.nextInt(), b = sc.nextInt();
                  a = b - a;
                  dec.dontfail_odds = new Fraction(a, b);
                  dec.dontfail_odds.simplify();
                  
                  dec.cost = sc.nextInt();
                  
                  vec.get(i).add(dec);
              }
          }
          
          dp = new Fraction[20][1005];
          Fraction res = solve(0, money);
          res.a = res.b - res.a; // get the complement of the result
          res.simplify();
          
          System.out.printf("%d/%d\n", res.a, res.b);
      }
  }
}

class Decision {
  public Fraction dontfail_odds;
  public int cost;
}

class Fraction {
  public long a, b;

  public Fraction() {
    a = 1;
    b = 1;
  }

  public Fraction(long top, long bot) {
    a = top;
    b = bot;
  }

  public Fraction multiply(Fraction rhs) {
    return new Fraction(a * rhs.a, b * rhs.b);
  }

  public void simplify() {
    long ta = a, tb = b;
    while (tb != 0) {
        long tc = ta % tb;
        ta = tb;
        tb = tc;
    }
    final long gcd = ta;

    if (a == 0) {
        a = 0;
        b = 1;
    } else {
        a /= gcd;
        b /= gcd;
    }
  }

  public boolean isLessThan(Fraction rhs) {
    BigInteger t1 = BigInteger.valueOf(a);
    BigInteger t2 = BigInteger.valueOf(rhs.b);
    BigInteger t3 = BigInteger.valueOf(b);
    BigInteger t4 = BigInteger.valueOf(rhs.a);

    BigInteger le = t1.multiply(t2);
    BigInteger ri = t3.multiply(t4);

    return le.compareTo(ri) < 0;
  }

  public void show() {
    System.out.println("Fraction: " + Long.toString(a) + " " + Long.toString(b));
  }
}
