/**
 * CS180 - Euler: SmallestMultiple
 * Find the smallest
 * @author Joseph Marshall, marsha87@purdue.edu, 804
 */

public class SmallestMultiple {
    public static void main(String[] args) {
        int sm = 1;
        boolean smallestMultiple = false;
        while (!smallestMultiple) {
            sm++;
            smallestMultiple = true;
            for (int i = 1; i <= 20; i++) {
                if (sm % i != 0)
                    smallestMultiple = false;
            }
        }
        System.out.println(sm);
    }
}
