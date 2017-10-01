import java.math.BigInteger;
import java.util.Scanner;

public class TimusDP {

    static BigInteger[][] dp = new BigInteger[55][1005];
    
    public static void main(String[] args) {
        // Offline calculation
        for(int S = 1; S <= 1000; S++) {
            dp[0][S] = BigInteger.ZERO;
        }
        for(int N = 0; N <= 50; N++) {
            dp[N][0] = BigInteger.ONE;
        }
        for(int N = 1; N <= 50; N++) {
            for(int S = 1; S <= 1000; S++) {
                int lim = Math.min(S,9);
                dp[N][S] = BigInteger.ZERO;
                for(int i = 0; i <= lim; i++) {
                    dp[N][S] = dp[N][S].add(dp[N-1][S-i]);
                }
            }
       }

        // Query answering
        int n, s;
        Scanner sc = new Scanner(System.in);
        while ( sc.hasNextInt() ) {
            n = sc.nextInt();
            s = sc.nextInt();
            if( s%2 == 1 ) {
                System.out.println("0");
            }
            else {
                System.out.println(dp[n][s/2].pow(2).toString());
            }
        }
    }
}
