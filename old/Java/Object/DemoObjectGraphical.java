package Summarize.Object;

import java.util.GregorianCalendar;

public class DemoObjectGraphical {
    final static double PI = 3.1415926;
}
class Circalar{
    double radius;//定义圆的半径
    double area;//定义圆的面积
    public Circalar(double radius){
        this.radius = radius;
        area = DemoObjectGraphical.PI *radius * radius;//圆的面积计算公式
        System.out.println("圆的面积是："+area);
    }
}
class Spherical{
    double radius;// 定义球体的半径
    double volume;//定义球体的面积
    public Spherical(double radius){
        this.radius = radius;
        volume = 4/3 * DemoObjectGraphical.PI *radius *radius*radius;//球体面积的计算公式
        System.out.println("球体的体积是："+volume+"半径是:"+radius);
    }

    public static void main(String[] args) {
        Circalar c = new Circalar(4.5);
        Spherical s = new Spherical(5.9);
    }
}

