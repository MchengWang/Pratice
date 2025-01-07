package Summarize.redbag;

public class user {
    private String name;//定义姓名
    private int money;//定义余额，当前用户的金额

    public user() {
    }

    public user(String name, int money) {
        this.name = name;
        this.money = money;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getMoney() {
        return money;
    }

    public void setMoney(int money) {
        this.money = money;
    }

    //展示用户有多少钱
    public void show(){
        System.out.println("我叫"+ name +",有"+money+"元");
    }
}
