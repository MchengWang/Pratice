package com.jsj.entries;

import java.util.List;

public class ClassInfo {
    int cid;
    String cname;
    List<StudentInfo> studentInfoList;

    public List<StudentInfo> getStudentInfoList() {
        return studentInfoList;
    }

    public void setStudentInfoList(List<StudentInfo> studentInfoList) {
        this.studentInfoList = studentInfoList;
    }




    public int getCid() {
        return cid;
    }

    public void setCid(int cid) {
        this.cid = cid;
    }

    public String getCname() {
        return cname;
    }

    public void setCname(String cname) {
        this.cname = cname;
    }

    @Override
    public String toString() {
        return "ClassInfo{" +
                "cid=" + cid +
                ", cname='" + cname + '\'' +
                ", studentInfoList=" + studentInfoList +
                '}';
    }
}
