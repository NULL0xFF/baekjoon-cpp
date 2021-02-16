import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner inputStreamScanner = new Scanner(System.in);
        int l = 0;
        String input = "";

        l = inputStreamScanner.nextInt();
        input = inputStreamScanner.next();
        inputStreamScanner.close();

        if (l <= 5) {
            int hash = 0;
            for (int loop = 0; loop < l; loop++)
                hash = hash + ((input.charAt(loop) - 'a') + 1) * (int) Math.pow(31, loop);
            System.out.println(hash);
        } else {
            BigInteger hash = new BigInteger("0");
            for (int loop = 0; loop < l; loop++)
                hash = hash.add((new BigInteger("31")).pow(loop)
                        .multiply(new BigInteger(String.valueOf(input.charAt(loop) - 'a' + 1))));
            System.out.println(hash);
        }

    }
}