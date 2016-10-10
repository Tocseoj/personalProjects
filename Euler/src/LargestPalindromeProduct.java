/**
 * CS180 - Euler: LargestPalindromeProduct
 * Explain:
 *
 * @author Joseph Marshall, marsha87@purdue.edu, 804
 */
public class LargestPalindromeProduct implements Runnable {
    private static int largest;
    private int start;
    private int end;
    private static int n1;
    private static int n2;
    private static Object sync = new Object();

    public LargestPalindromeProduct(int start, int end) {
        this.start = start;
        this.end = end;
    }

    @Override
    public void run() {
        for (int i = 100; i <= 999; i++) {
            for (int j = start; j <= end; j++) {
                if (isPalindrome(new Integer(i * j).toString())) {
                    synchronized (sync) {
                        if (i * j > largest) {
                            largest = i * j;
                            n1 = i;
                            n2 = j;
                        }
                    }
                }
            }
        }
    }

    public boolean isPalindrome(String s) {
        for (int i = 0; i < s.length() / 2; i++) {
            if (s.charAt(i) != s.charAt(s.length() - i - 1)) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        long time = System.currentTimeMillis();
        Thread t1 = new Thread(new LargestPalindromeProduct(100, 499));
        Thread t2 = new Thread(new LargestPalindromeProduct(500, 999));
        t1.start();
        t2.start();
        try {
            t1.join();
            t2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println(largest);
        System.out.println(n1);
        System.out.println(n2);
        System.out.println(System.currentTimeMillis() - time);
    }
}
