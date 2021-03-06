package nonclass;

import java.math.BigInteger;
import java.util.Scanner;

public class P10826 {
    private static BigInteger fibonacci(BigInteger[] cache, int n) {
        if (n == 0)
            return BigInteger.ZERO;
        if (n == 1 || n == 2)
            return BigInteger.ONE;
        if (cache[n].compareTo(BigInteger.ZERO) == 0)
            cache[n] = fibonacci(cache, n - 1).add(fibonacci(cache, n - 2));
        return cache[n];
    }

    public static void main(String[] args) {
        Scanner inputStreamScanner = new Scanner(System.in);
        int n = inputStreamScanner.nextInt();
        inputStreamScanner.close();
        BigInteger[] cache = new BigInteger[n + 1];
        for (int index = 0; index <= n; index++)
            cache[index] = BigInteger.ZERO;
        System.out.println(fibonacci(cache, n));
        return;
    }
}