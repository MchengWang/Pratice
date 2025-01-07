package com.shilinyu.paper;

import com.shilinyu.printer.Paper;

public class TextPaper implements Paper {
    //每行字符数
    private  int charPerLine =16;
    private int linePerPage =8;
    //纸张中的内容
    private String content="";
    //当前横向位置
    private int posX=0;
    //当前纵向位置
    private int posY=0;
    //当前页面数
    private int posP=1;
    //为了设值注入
    public  void setCharPerLine(int charPerLine){

        this.charPerLine = charPerLine;
    }
    public void setLinePerPage(int linePerPage){
        this.linePerPage = linePerPage;
    }

    @Override
    public void putInChar(char c) {
        content+=c;
        posX++;
        //判断是否换行
        if (posX==charPerLine)
        {
            content+=Paper.newline;
            posX=0;
            posY++;
        }
        //判断是否分页
        if (posY==linePerPage)
        {
            content+="==第"+posP+"页==";
            content+=Paper.newline;
            posX=0;
            posY=0;
            posP++;
        }
    }

    @Override
    public String getContent() {
        String ret =content;
        if (!(posX==0 && posY==0)){
            int count =linePerPage-posY;
            for(int i=0;i<count;i++)
                ret+=Paper.newline;
            ret+="==第"+ posP + "页==";
        }
        return ret;
    }
}
