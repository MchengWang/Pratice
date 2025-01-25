package com.jsj.entries;

public class Course {
    int cid;
    String coursename;
    int hours;

    public int getCid() {
        return cid;
    }

    public void setCid(int cid) {
        this.cid = cid;
    }

    public String getCoursename() {
        return coursename;
    }

    public void setCoursename(String coursename) {
        this.coursename = coursename;
    }

    public int getHours() {
        return hours;
    }

    public void setHours(int hours) {
        this.hours = hours;
    }

    @Override
    public String toString() {
        return "Course{" +
                "cid=" + cid +
                ", coursename='" + coursename + '\'' +
                ", hours=" + hours +
                '}';
    }
}
