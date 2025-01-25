package com.shilinyu.ink;

import com.shilinyu.printer.Ink;

import java.awt.*;

public class GeryInk implements Ink {
    @Override
    public String getColor(int r,int g,int b){
        int c=(r+g+b)/3;
        Color color =new Color(c,c,c);
        return "#"+Integer.toHexString(color.getRGB()).substring(2);
    }

}
