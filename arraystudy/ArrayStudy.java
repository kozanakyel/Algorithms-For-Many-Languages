package arraystudy;

import java.util.ArrayList;

public class ArrayStudy {
    public static void main(String[] args) {

        ArrayStudy test = new ArrayStudy();

        String temp = "new stul";
        boolean r = test.isUniqueChars(temp);
        System.out.println(r);

        RunnableDemo r1 = new RunnableDemo("thr-1");
        r1.start();

        RunnableDemo r2 = new RunnableDemo("thr-2");
        r2.start();

    }

    public static ArrayList<String> merge(String[] words, String[] more) {
        ArrayList<String> sentence = new ArrayList<>();
        for (String w : words)
            sentence.add(w);
        for (String w : more)
            sentence.add(w);
        return sentence;
    }

    public boolean isUniqueChars(String str) {
        if (str.length() > 128)
            return false;

        boolean[] charSet = new boolean[128];
        for (int i = 0; i < str.length(); i++) {
            int val = str.charAt(i);
            if (charSet[val]) {
                return false;
            }
            charSet[val] = true;
        }
        return true;
    }
}

class RunnableDemo implements Runnable {
    private Thread t;
    private String threadName;

    RunnableDemo(String name) {
        threadName = name;
        System.out.println("Creating " + threadName);
    }

    public void run() {
        System.out.println("Running " + threadName);
        try {
            for (int i = 4; i > 0; i--) {
                System.out.println("Thread: " + threadName + ", " + i);
                // Let the thread sleep for a while.
                Thread.sleep(50);
            }
        } catch (InterruptedException e) {
            System.out.println("Thread " + threadName + " interrupted.");
        }
        System.out.println("Thread " + threadName + " exiting.");
    }

    public void start() {
        System.out.println("Starting " + threadName);
        if (t == null) {
            t = new Thread(this, threadName);
            t.start();
        }
    }
}
