import java.math.BigInteger;
import java.util.Scanner;

public class TimusDP {

    static BigInteger[] dp = new BigInteger[10005];
    
    public static void main(String[] args) {
        int N, K;
        Scanner sc = new Scanner(System.in);
        BigInteger TWO = new BigInteger("2");
        
        while ( sc.hasNextInt() ) {
            N = sc.nextInt();
            K = sc.nextInt();
            dp[0] = BigInteger.ONE;
            for(int n = 1; n <= N; n++) {
                if ( n <= K ) {
                    dp[n] = dp[n-1].add(dp[n-1]);
                } else if ( n == K+1 ) {
                    dp[n] = dp[n-1].add(dp[n-1]).subtract(BigInteger.ONE);
                } else {
                    dp[n] = dp[n-1].add(dp[n-1]).subtract(dp[n-K-2]);
                }
            }
            System.out.println(dp[N].toString());
        }
    }
}
