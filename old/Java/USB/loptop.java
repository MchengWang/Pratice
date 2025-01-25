package Summarize.USB;

public class loptop {
    public void powerOn(){
        System.out.println("开机");
    }

    public void powerOff(){
        System.out.println("关机");
    }

    //使用usb的方法，使用接口作为方法的参数
    public void usbDecive (Usb usb){
        usb.open();
        if(usb instanceof mouse){
            mouse m = (mouse) usb;
            m.click();
        }else if(usb instanceof keyboard){
            keyboard k = (keyboard) usb;
            k.type();
        }
        usb.close();
    }
}
