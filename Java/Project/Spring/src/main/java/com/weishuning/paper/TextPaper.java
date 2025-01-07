package com.weishuning.paper;

public class TextPaper implements IPaper{
    private int charPerLine = 16;
    private int LinePerPage = 8;
    //相当于纸张的空白区域
    private String content ="";
    //当前列
    private int posx = 0;//0~charPerLine - 1;
    //当前行
    private int posy = 0;//0~LinePerPage - 1;
    //当前页
    private int posPage = 0;

    public int getCharPerLine() {
        return charPerLine;
    }

    public void setCharPerLine(int charPerLine) {
        this.charPerLine = charPerLine;
    }

    public int getLinePerPage() {
        return LinePerPage;
    }

    public void setLinePerPage(int linePerPage) {
        LinePerPage = linePerPage;
    }

    @Override
    public void putInChar(char c) {
        content += c;
        posx++;
        if(posx==charPerLine)
        {
            content += IPaper.newLine;
            posx = 0;
            posy++;
        }
        if(posy == LinePerPage)
        {
            content += "==第" + posPage + "页==";
            content += IPaper.newLine;
            posx = 0;
            posy = 0;
            posPage++;
        }

    }

    @Override
    public String getContent() {
        String ret = content;

        //最后一页是否打印满，如果没有满，加空白行和页码
        if(!( posx == 0 && posy ==0))
        {
            int count = LinePerPage - posy;
            for(int i = 0; i < count;i++)
                ret += "==第" + posPage + "页==";
        }

        return ret;
    }
}
