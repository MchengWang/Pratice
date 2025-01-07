package Summarize.USB;

public class mouse implements Usb {
    @Override
    public void open() {
        System.out.println("开机");
    }

    @Override
    public void close() {
        System.out.println("关机");
    }

    public void click(){
        System.out.println("点");
    }
}
