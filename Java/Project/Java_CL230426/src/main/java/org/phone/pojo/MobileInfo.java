package org.phone.pojo;

public class MobileInfo {
    private int id;
    private String phoneNo;
    private String ownerName;
    private String color;
    private String brand;

    public MobileInfo() {
    }

    public MobileInfo(int id, String phoneNo, String ownerName, String color, String brand) {
        this.id = id;
        this.phoneNo = phoneNo;
        this.ownerName = ownerName;
        this.color = color;
        this.brand = brand;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getPhoneNo() {
        return phoneNo;
    }

    public void setPhoneNo(String phoneNo) {
        this.phoneNo = phoneNo;
    }

    public String getOwnerName() {
        return ownerName;
    }

    public void setOwnerName(String ownerName) {
        this.ownerName = ownerName;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public String getBrand() {
        return brand;
    }

    public void setBrand(String brand) {
        this.brand = brand;
    }

    @Override
    public String toString() {
        return "MobileInfo{" +
                "id=" + id +
                ", phoneNo='" + phoneNo + '\'' +
                ", ownerName='" + ownerName + '\'' +
                ", color='" + color + '\'' +
                ", brand='" + brand + '\'' +
                '}';
    }
}
