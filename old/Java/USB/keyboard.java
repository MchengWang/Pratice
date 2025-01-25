package Summarize.USB;

public class keyboard implements Usb {
    @Override
    public void open() {
        System.out.println("开机");
    }

    @Override
    public void close() {
        System.out.println("关机");
    }

    public void type(){
        System.out.println("敲");
    }
}
