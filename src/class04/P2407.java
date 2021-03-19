package class04;

import java.math.BigInteger;
import java.util.Scanner;

public class P2407 {
    private static BigInteger cache[][];

    private static BigInteger combination(int n, int r) {
        if (cache[n][r] != BigInteger.ZERO)
            return cache[n][r];
        BigInteger ret = BigInteger.ONE;
        if (n != r && r != 0)
            ret = combination(n - 1, r - 1).add(combination(n - 1, r));
        cache[n][r] = ret;
        return ret;
    }

    public static void main(String[] args) {
        Scanner inputStreamScanner = new Scanner(System.in);
        int n, m;
        n = inputStreamScanner.nextInt();
        m = inputStreamScanner.nextInt();
        cache = new BigInteger[n + 1][m + 1];
        for (int a = 0; a <= n; a++)
            for(int b = 0; b <= m; b++)
                cache[a][b] = BigInteger.ZERO;
        BigInteger com = combination(n, m);
        System.out.printf("%s\n", com.toString());
        return;
    }
}