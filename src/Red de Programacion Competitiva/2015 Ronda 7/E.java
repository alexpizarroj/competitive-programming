import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class catalan {
	
	static final ArrayList<BigInteger> facts = new ArrayList<BigInteger>();
	
	private static BigInteger big(int x) {
		return new BigInteger(Integer.toString(x));
	}
	
	private static BigInteger fact(int x) {
		final int sz = facts.size();
		if (x < sz) {
			return facts.get(x);
		}
		for (int i = Math.max(1, sz); i <= x; ++i) {
			BigInteger t = big(i);
			facts.add(facts.get(i-1).multiply(t));
		}
		return facts.get(x);
	}
	
	private static BigInteger cat(int n) {
		BigInteger t1 = fact(2 * n);
		BigInteger t2 = fact(n);
		BigInteger t3 = big(n + 1);
		BigInteger t4 = t1.divide(t2).divide(t2).divide(t3);
		return t4;
	}
	
	public static void main(String[] args) {
		facts.add(BigInteger.ONE);
		
		final Scanner sc = new Scanner(System.in);
		final int N = sc.nextInt();
		System.out.println(cat(N + 1));
	}
}
