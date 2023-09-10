import java.io.*;
import java.util.*;

public class CamelCaseProblem {

    public static void main(String[] args) {
        /*
         * Enter your code here. Read input from STDIN. Print output to STDOUT. Your
         * class should be named Solution.
         */
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextLine()) {
            String input = scanner.nextLine();
            String[] parts = input.split(";");
            String operation = parts[0];
            String type = parts[1];
            String string = parts[2];

            if (operation.equals("S")) {
                String[] words = splitCamelCase(string, type);
                System.out.println(String.join(" ", words));
            } else if (operation.equals("C")) {
                String camelCaseString = combineCamelCase(string, type);
                System.out.println(camelCaseString);
            }
        }
        scanner.close();
    }

    private static String[] splitCamelCase(String s, String type) {
        String[] temp = s.split("(?<=[a-z])(?=[A-Z])|(?<=[A-Z])(?=[A-Z][a-z])");
        int lastIndex = temp.length - 1;
        for (int i = 0; i < temp.length; i++) {
            temp[i] = temp[i].toLowerCase();
        }

        if (type.equals("M")) {

            temp[lastIndex] = temp[lastIndex].substring(0, temp[lastIndex].length() - 2);
            return temp;
        }
        return temp;
    }

    private static String combineCamelCase(String s, String type) {
        String[] words = s.split("\\s+");
        StringBuilder sb = new StringBuilder();
        boolean firstWord = true;
        for (String word : words) {
            if (firstWord) {
                sb.append(word.toLowerCase());
                firstWord = false;
            } else {
                sb.append(Character.toUpperCase(word.charAt(0)));
                sb.append(word.substring(1).toLowerCase());
            }
        }
        if (type.equals("M")) {
            sb.append("()");
        }
        if (type.equals("C")) {
            sb.setCharAt(0, Character.toUpperCase(sb.charAt(0)));
        }
        return sb.toString();
    }
}