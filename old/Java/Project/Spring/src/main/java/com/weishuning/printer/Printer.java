package com.weishuning.printer;

import com.weishuning.Ink.IInk;
import com.weishuning.paper.IPaper;

public class Printer {
    private IInk ink = null;
    private IPaper paper = null;

    public IInk getInk() {
        return ink;
    }

    public void setInk(IInk ink) {
        this.ink = ink;
    }

    public IPaper getPaper() {
        return paper;
    }

    public void setPaper(IPaper paper) {
        this.paper = paper;
    }

    public void print(String  str){
        System.out.println("打印颜色是：" + ink.getColor());
        for(int i=0;i<str.length();i++)
            paper.putInChar(str.charAt(i));

        System.out.println(paper.getContent());
    }
}
