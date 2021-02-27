package nonclass;

import java.math.BigInteger;
import java.util.Scanner;

public class P15829 {
    public static void main(String[] args) {
        Scanner inputStreamScanner = new Scanner(System.in);
        String inputString = "";
        int length = 0;

        // Input
        length = inputStreamScanner.nextInt();
        inputString = inputStreamScanner.next();
        inputStreamScanner.close();

        // Hashing
        // if (length <= 5) {
        //     long hash = 0;
        //     for (int loop = 0; loop < length; loop++)
        //         hash = hash + (((inputString.charAt(loop) - 'a') + 1) * (long) Math.pow(31, loop));
        //     System.out.println(hash);
        // } else {
            BigInteger hash = BigInteger.ZERO;
            for (int loop = 0; loop < length; loop++)
                hash = hash.add(BigInteger.valueOf(31).pow(loop).multiply(BigInteger.valueOf((inputString.charAt(loop) - 'a') + 1)));
            hash = hash.mod(BigInteger.valueOf(1234567891));
            System.out.println(hash.toString());
        // }

        // Finalize
        return;
    }
}