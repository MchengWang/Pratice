package Summarize.LOL;

public class Hero {
    private String name;//英雄的名字
    private int age;//英雄的年龄
    private weapon weapon;//英雄的武器
    private Skill skill;//设置英雄技能

    public Hero() {
    }

    public Hero(String name, int age  , weapon weapon , Skill skill) {
        this.name = name;
        this.age = age;
        this.weapon = weapon;
        this.skill = skill;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public weapon getWeapon() {
        return weapon;
    }

    public void setWeapon(weapon weapon){
        this.weapon = weapon;
    }

    public void setSkill(Skill skill){
        this.skill = skill;
    }

    public Skill getSkill(){
        return skill;
    }

    public void attack(){
        System.out.println("年龄为"+age+"的"+name+"用"+weapon+"释放技能"+skill+"，攻击敌方");
    }
}
