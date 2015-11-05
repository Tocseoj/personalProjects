/**
 * CS180 - Euler: LargestPrimeFactor
 * Explain:
 *
 * @author Joseph Marshall, marsha87@purdue.edu, 804
 */
public class LargestPrimeFactor {

    public static long calcLargestPrimeFactor(long number) throws IllegalArgumentException {
        if (number <= 1)
            throw new IllegalArgumentException();
        int lpf;
        for (lpf = 2; lpf <= number; lpf++) {
            if (number % lpf == 0) {
                number /= lpf;
                lpf--;
            }
        }
        return lpf;
    }

    public static void main(String[] args) {
        System.out.println(calcLargestPrimeFactor(600851475143L));
    }
}
