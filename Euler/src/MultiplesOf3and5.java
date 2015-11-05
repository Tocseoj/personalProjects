/**
 * CS180 - Euler: MultiplesOf3and5
 * Sum all multiples of 3 and 5 below 1000
 *
 * @author Joseph Marshall, marsha87@purdue.edu, 804
 */

public class MultiplesOf3and5 implements Runnable {
    private static int sum = 0;
    private int start;
    private int end;
    private static Object sync = new Object();

    public MultiplesOf3and5(int start, int end) {
        this.start = start;
        this.end = end;
    }

    @Override
    public void run() {
        for (int i = start; i <= end; i++) {
            if (i % 3 == 0 || i % 5 == 0) {
                synchronized (sync) {
                    sum += i;
                }
            }
        }
    }

    public static void main(String[] args) {
        MultiplesOf3and5 mul3 = new MultiplesOf3and5(0, 499);
        MultiplesOf3and5 mul5 = new MultiplesOf3and5(500, 999);
        Thread t1 = new Thread(mul3);
        Thread t2 = new Thread(mul5);
        t1.start();
        t2.start();
        try {
            t1.join();
            t2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println(sum);
    }
}
