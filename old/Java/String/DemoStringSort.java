package Summarize.String;

import java.util.Arrays;

public class DemoStringSort {
    public static void main(String[] args) {
        String a = "acdi24BADEF";
        char[] c = a.toCharArray();
        Arrays.sort(c);//对str进行升序排列
        for (char c1 : c) {
            System.out.print(c1+",");
        }
    }
}
