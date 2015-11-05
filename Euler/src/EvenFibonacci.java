/**
 * CS180 - Euler: EvenFibonacci
 * Sum of even valued terms in fibonacci sequence under (<=) 4,000,000
 * @author Joseph Marshall, marsha87@purdue.edu, 804
 */
public class EvenFibonacci {
    private int term1;
    private int term2;
    private int sum;

    public EvenFibonacci(int term1, int term2) {
        this.term1 = term1;
        this.term2 = term2;
        sum = 0;
    }

    public int calc() {
        while (term2 <= 4000000) {
            if (term1 % 2 == 0)
                sum += term1;
            if (term2 % 2 == 0)
                sum += term2;
            int tempTerm1 = term1 + term2;
            int tempTerm2 = term2 + tempTerm1;
            term1 = tempTerm1;
            term2 = tempTerm2;
        }
        if (term1 <= 4000000 && term1 % 2 == 0)
            sum += term1;
        return sum;
    }

    public static void main(String[] args) {
        System.out.println(new EvenFibonacci(1, 2).calc());
        System.out.println();
    }
}
