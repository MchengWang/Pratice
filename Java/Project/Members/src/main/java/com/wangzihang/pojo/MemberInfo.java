package com.wangzihang.pojo;

public class MemberInfo {
    private int id;
    private String memberNo;
    private String realName;
    private String tel;
    private String identityId;

    public MemberInfo() {
    }

    public MemberInfo(int id, String memberNo, String realName, String tel, String identityId) {
        this.id = id;
        this.memberNo = memberNo;
        this.realName = realName;
        this.tel = tel;
        this.identityId = identityId;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getMemberNo() {
        return memberNo;
    }

    public void setMemberNo(String memberNo) {
        this.memberNo = memberNo;
    }

    public String getRealName() {
        return realName;
    }

    public void setRealName(String realName) {
        this.realName = realName;
    }

    public String getTel() {
        return tel;
    }

    public void setTel(String tel) {
        this.tel = tel;
    }

    public String getIdentityId() {
        return identityId;
    }

    public void setIdentityId(String identityId) {
        this.identityId = identityId;
    }

    @Override
    public String toString() {
        return "MemberInfo{" +
                "id=" + id +
                ", memberNo='" + memberNo + '\'' +
                ", realName='" + realName + '\'' +
                ", tel='" + tel + '\'' +
                ", identityId='" + identityId + '\'' +
                '}';
    }
}
