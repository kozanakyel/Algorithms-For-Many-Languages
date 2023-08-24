import java.util.ArrayList;

public class SpaceComp {

    static int counter = 0;   // Counter for recursive stack
    public static void main(String[] args) {
        // SpaceComp spa = new SpaceComp();

        // int res = spa.sumItself(4);
        // System.out.println(res);

        // int res2 = pairSumSequence(5);
        // System.out.println(res2);

        // ArrayList<Integer> arr = new ArrayList<>(2000);

        // int k = f(4);

        permutation("a");
        System.out.println(counter);

    }

    static int sum(int n) {
        if (n <= 0)
            return 0;
        return n + sum(n - 1);
    }

    static int pairSumSequence(int n) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (i + 1);
            System.out.println(sum);
        }
        return sum;
    }

    static int pairSum(int a, int b) {
        return a + b;
    }

    static int f(int n){
        counter++;
        System.out.println("Call numbers: "+counter);
        if (n<=1) {
            return 1;
        }
        return f(n-1)+f(n-1);
    }

    static boolean isPrime(int n){
        // O(sqrt(n))  Big O, time complexity
        for(int x=2; x*x<=n; x++){
            if(n%x==0){
                return false;
            }
        }
        return true;
    }

    static void permutation(String str){
        permutation(str, "");
    }


    static void permutation(String str, String prefix){
        if(str.length()==0){
            System.out.println(prefix);
            counter++;
        }else{
            for(int i=0; i<str.length();i++){
                String rem = str.substring(0, i) + str.substring(i+1);
                permutation(rem, prefix+str.charAt(i));
                counter++;
            }
        }
    }

    

}