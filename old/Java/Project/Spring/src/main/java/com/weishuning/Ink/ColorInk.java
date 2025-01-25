package com.weishuning.Ink;

public class ColorInk implements IInk{
    String color;
    public  void setColor(String color){
        this.color = color;
    }

    @Override
    public String getColor(){
        return color;
    }
}
