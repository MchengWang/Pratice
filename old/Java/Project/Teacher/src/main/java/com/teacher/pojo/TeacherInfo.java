package com.teacher.pojo;

public class TeacherInfo {
    private int id;
    private String teacherNo;
    private String teacherName;
    private String tel;
    private String email;

    public TeacherInfo() {
    }

    public TeacherInfo(int id, String teacherNo, String teacherName, String tel, String email) {
        this.id = id;
        this.teacherNo = teacherNo;
        this.teacherName = teacherName;
        this.tel = tel;
        this.email = email;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getTeacherNo() {
        return teacherNo;
    }

    public void setTeacherNo(String teacherNo) {
        this.teacherNo = teacherNo;
    }

    public String getTeacherName() {
        return teacherName;
    }

    public void setTeacherName(String teacherName) {
        this.teacherName = teacherName;
    }

    public String getTel() {
        return tel;
    }

    public void setTel(String tel) {
        this.tel = tel;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    @Override
    public String toString() {
        return "TeacherInfo{" +
                "id=" + id +
                ", teacherNo='" + teacherNo + '\'' +
                ", teacherName='" + teacherName + '\'' +
                ", tel='" + tel + '\'' +
                ", email='" + email + '\'' +
                '}';
    }
}
