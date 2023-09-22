import java.util.LinkedHashSet;
import java.util.Set;

public class Matrix {
    public static void main(String[] args) {

        String str = "address@domain.com";
        System.out.println(str.split("@")[1].split("\\.")[0]); 

        Set s = new LinkedHashSet();
        s.add("1");
        s.add(1);
        s.add(1);
        s.add(2);
        System.out.println(s.size());

        // double[][] a = {
        //         { 2, 3 },
        //         { 4, 5 }
        // };

        // double[][] b = {
        //         { 6, 7 },
        //         { 8, 9 }
        // };

        // double[][] result = matrixMultiplication(a, b);

        // // Print the result matrix
        // for (int i = 0; i < result.length; i++) {
        //     for (int j = 0; j < result[0].length; j++) {
        //         System.out.print(result[i][j] + " ");
        //     }
        //     System.out.println();
        // }
    }

    static double[][] matrixMultiplication(double[][] a, double[][] b) {
        int n = a.length;
        int m = b[0].length;
        int x = a[0].length;
        double[][] c = new double[n][m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < x; j++)
                for (int k = 0; k < n; k++)
                    c[i][j] += a[i][k] * b[k][j];
        return c;
    }
}

class Price{
    static double getPrice(){
        return 100;
    }

    double getGrossPrice(){
        return getPrice() * 1.18;
    }
}