package Summarize.Object;

public class DemoObjectCycle {
    public static void main(String[] args) {
        //for循环
        int a[] = {1,2,3,4,5};
        for (int i = 0; i < a.length; i++) {
            System.out.println(a[i]);
        }

        //do...while
        int b[] ={1,2,3,4,5,6,7,8,9};
        do{
            for (int i = 0; i < b.length; i++) {
                System.out.println(b[i]);
            }
        }while(b.length <9);

        //switch判断语句
        int d = 0;
        for (int i = 0; i < a.length; i++) {
            d = i;
        }
        switch (a[d]) {
            case 1:
                System.out.println("1");
                break;
            default:
                System.out.println("错误");
                break;
        }

        //break打断循环
        for (int i = 0; i < 5; i++) {
            System.out.println(i);
            break;
        }

        for (int i = 0; i < 4; i++) {
            if(i == 2){
                continue;
            }
            System.out.println(i);
        }

        //死循环
        /*while(true){
            System.out.println(0);

        }*/
    }
}
