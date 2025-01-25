package com.jsj.entries;

import java.util.List;

public class StudentInfo {
    int sid;
    String name;
    String gender;
    String address;
    int cid;

    public List<Course> getCouseList() {
        return courseList;
    }

    public void setCourseList(List<Course> couseList) {
        this.courseList = couseList;
    }

    List<Course> courseList;
   // String banjiName;
   // ClassInfo classInfo;

    public int getSid() {
        return sid;
    }

    public void setSid(int sid) {
        this.sid = sid;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getGender() {
        return gender;
    }

    public void setGender(String gender) {
        this.gender = gender;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public int getCid() {
        return cid;
    }

    public void setCid(int cid) {
        this.cid = cid;
    }

    @Override
    public String toString() {
        return "StudentInfo{" +
                "sid=" + sid +
                ", name='" + name + '\'' +
                ", gender='" + gender + '\'' +
                ", address='" + address + '\'' +
                ", cid=" + cid +
                '}';
    }
    //    public int getCid() {
//        return cid;
//    }
//
//    public void setCid(int cid) {
//        this.cid = cid;
//    }

//    @Override
//    public String toString() {
//        return "StudentInfo{" +
//                "sid=" + sid +
//                ", name='" + name + '\'' +
//                ", gender='" + gender + '\'' +
//                ", address='" + address + '\'' +
//                ", cid=" + cid +
//                ", banjiName='" + banjiName + '\'' +
//                '}';
//    }



}
