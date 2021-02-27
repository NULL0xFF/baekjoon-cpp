package nonclass;

import java.util.Scanner;

public class P15829 {
    public static void main(String[] args) {
        final int mod = 1234567891;
        final int mul = 31;
        Scanner inputStreamScanner = new Scanner(System.in);
        String inputString = "";
        int length = 0;

        // Input
        length = inputStreamScanner.nextInt();
        inputString = inputStreamScanner.next();
        inputStreamScanner.close();

        // Hashing
        long hash = 0;
        long r = 1;
        for (int loop = 0; loop < length; loop++) {
            hash = (hash + (((inputString.charAt(loop) - 'a') + 1) * r)) % mod;
            r = (r * mul) % mod;
        }
        System.out.println(hash);

        // Finalize
        return;
    }
}