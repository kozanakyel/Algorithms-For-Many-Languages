public class SpaceComp {
    public static void main(String[] args) {
        // SpaceComp spa = new SpaceComp();

        // int res = spa.sumItself(4);
        // System.out.println(res);

        int res2 = sum(5);
        System.out.println(res2);

    }

    static int sum(int n) {
        if (n <= 0)
            return 0;
        return n + sum(n - 1);
    }

    static int pairSumSequence(int n) {
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += (i + 1);
            System.out.println(sum);
        return sum;
    }

    static int pairSum(int a, int b) {
        return a + b;
    }

}