package Summarize.Generics;

public class DemoGenericsinterfaceimpl implements DemoGenericsInterface<String>{

    @Override
    public void method(String s) {
        System.out.println(s);
    }


}

class demomain{
    public static void main(String[] args) {
        //使用DemoGenericsinterfaceImpl对象
        DemoGenericsinterfaceimpl dgii = new DemoGenericsinterfaceimpl();
        dgii.method("Hello World");
    }
}
