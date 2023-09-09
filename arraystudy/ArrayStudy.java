package arraystudy;

import java.util.ArrayList;

public class ArrayStudy {
    public static void main(String[] args) {

        ArrayStudy test = new ArrayStudy();

        String temp = "new stul";
        boolean r = test.isUniqueChars(temp);
        System.out.println(r);

    }

    public static ArrayList<String> merge(String[] words, String[] more) {
        ArrayList<String> sentence = new ArrayList<>();
        for(String w : words) sentence.add(w);
        for(String w : more) sentence.add(w);
        return sentence;
    }

    public boolean isUniqueChars(String str){
        if(str.length() > 128) return false;

        boolean[] charSet = new boolean[128];
        for (int i = 0; i < str.length(); i++) {
            int val = str.charAt(i);
            if(charSet[val]){
                return false;
            }
            charSet[val] = true;
        }
        return true;
    }
}
