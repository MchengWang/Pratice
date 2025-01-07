package Summarize.USB;

public class Demomain {
    public static void main(String[] args) {
        //首先创建一个笔记本电脑
        loptop lt = new loptop();
        lt.powerOn();
        //准备一个鼠标，准备向上转型
        Usb m = new mouse();
        //参数是Usb类型，我正好传递进去的就是Usb鼠标
        lt.usbDecive(m);
        //创建一个Usb键盘
        keyboard k = new keyboard(); //没有使用多态写法
        //方法参数是Usb类型，传递进去的就是实现类对象
        lt.usbDecive(k);//正确写法
        //使用子类对象，匿名对象也可以
        lt.usbDecive(new keyboard());
        lt.powerOff();
        System.out.println("============================");

    }
}
