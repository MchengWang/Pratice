package com.household.pojo;

public class HouseHoldInfo {
    private int id;
    private String householdNo;
    private String householdName;
    private String tel;
    private String location;

    public HouseHoldInfo() {
    }

    public HouseHoldInfo(int id, String householdNo, String householdName, String tel, String location) {
        this.id = id;
        this.householdNo = householdNo;
        this.householdName = householdName;
        this.tel = tel;
        this.location = location;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getHouseholdNo() {
        return householdNo;
    }

    public void setHouseholdNo(String householdNo) {
        this.householdNo = householdNo;
    }

    public String getHouseholdName() {
        return householdName;
    }

    public void setHouseholdName(String householdName) {
        this.householdName = householdName;
    }

    public String getTel() {
        return tel;
    }

    public void setTel(String tel) {
        this.tel = tel;
    }

    public String getLocation() {
        return location;
    }

    public void setLocation(String location) {
        this.location = location;
    }

    @Override
    public String toString() {
        return "HouseHoldInfo{" +
                "id=" + id +
                ", householdNo='" + householdNo + '\'' +
                ", householdName='" + householdName + '\'' +
                ", tel='" + tel + '\'' +
                ", location='" + location + '\'' +
                '}';
    }
}
