import java.math.BigInteger;
import java.util.Scanner;

public class TimusDP {
    
    static final int maxn = 30;
    static final BigInteger MinusOne = BigInteger.ZERO.subtract(BigInteger.ONE);
    static BigInteger[][][] f = new BigInteger[maxn+1][maxn+1][maxn+1];
    static BigInteger[][][] g = new BigInteger[maxn+1][maxn+1][maxn+1];
    
    static BigInteger getF(int x, int y, int z) {
        if (f[x][y][z] == MinusOne) {
            BigInteger ans = BigInteger.ZERO;
            if (x >= 2 && y >= 2) {
                ans = BigInteger.valueOf((x-1)*(y-1))
                        .multiply(getF(x-1, y-1, z)).add(ans);
            }
            if (y >= 2 && z >= 1) {
                ans = BigInteger.valueOf((y-1)*z)
                        .multiply(getF(z, y-1, x-1)).add(ans);
            }       
            if (z >= 1) {
                ans = BigInteger.valueOf(z)
                        .multiply(getF(z, y, x-1)).add(ans);
            }
            f[x][y][z] = ans;
        }
		return f[x][y][z];
    }
    
    static BigInteger getG(int x, int y, int z) {
        if (g[x][y][z] == MinusOne) {
            BigInteger ans = BigInteger.ZERO;
            if (y >= 1 && z >= 1)
            {
                ans = getF(y, z, x-1).add(getF(z, y, x-1))
                        .multiply(BigInteger.valueOf(y * z)).add(ans);
            }   
            if (y >= 2) {
                ans = BigInteger.valueOf(y*(y-1))
                        .multiply(getG(y-1, z, x-1)).add(ans);
            }       
            if (z >= 2) {
                ans = BigInteger.valueOf(z*(z-1))
                        .multiply(getG(z-1, y, x-1)).add(ans);
            }
            g[x][y][z] = ans;
        }
		return g[x][y][z];
    }
    
    public static void main(String[] args) {
        
        for(int i = 0; i <= maxn; i++)
            for(int j = 0; j <= maxn; j++)
                for(int k = 0; k <= maxn; k++) {
                    f[i][j][k] = MinusOne;
                    g[i][j][k] = MinusOne;
                }
        
        for(int i = 0; i <= maxn; i++) {
            f[0][0][i] = f[0][i][0] = f[i][0][0] = BigInteger.ZERO;
        }
		f[0][1][1] = f[1][0][1] = BigInteger.ZERO;
		f[1][1][0] = BigInteger.ONE;

		g[0][0][0] = g[0][0][1] = BigInteger.ZERO;
        g[0][1][0] = g[0][1][1] = g[1][0][0] = BigInteger.ZERO;
 		g[1][0][1] = g[1][1][0] = BigInteger.ONE;
        
        final BigInteger Two = BigInteger.valueOf(2);
        Scanner sc = new Scanner(System.in);
        while (sc.hasNextInt())
        {
            int n = sc.nextInt();
            System.out.println(getG(n, n, n).divide(Two).toString());
        }
    }
    
}
