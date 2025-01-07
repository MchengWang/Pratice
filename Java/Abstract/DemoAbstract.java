package Summarize.Abstract;

public class DemoAbstract {
    public static void main(String[] args) {
        zi ZI = new zi();//初始化子类对象
        ZI.xs();//调用方法
    }
}

//创建继承抽象父类的子类
class zi extends fu{

    @Override
    public void xs() {
        System.out.println("Hello world");
    }
}
