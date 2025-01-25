package Summarize.Generics;

public class DemoGenericsInterfaceImpll<T> implements DemoGenericsInterface<T> {
    @Override
    public void method(T t) {
        System.out.println(t);
    }
}

class democlassmain{
    public static void main(String[] args) {
        //创建GenericsInterfaceImpll对象并使用
        DemoGenericsInterfaceImpll dgii = new DemoGenericsInterfaceImpll();
        dgii.method("abjafgha");
        dgii.method(155);
    }
}
