/**
 * CS180 - Euler: SumSquareDifference
 * difference between the square of sum, and sum of squares of natural numbers
 * @author Joseph Marshall, marsha87@purdue.edu, 804
 */

public class SumSquareDifference {
    private int sumSquared = 0;
    private int squaredSum = 0;

    public static void main(String[] args) {
        System.out.println(new SumSquareDifference().ssd(100));
    }

    public int ssd(int n) {
        int sumSquared = 0;
        int squaredSum = 0;
        for (int i = 1; i <= n; i++) {
            squaredSum += Math.pow(i, 2);
            sumSquared += i;
        }
        sumSquared = (int) Math.pow(sumSquared, 2);
        return sumSquared - squaredSum;
    }
}
