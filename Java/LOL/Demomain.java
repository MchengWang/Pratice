package Summarize.LOL;

public class Demomain {
    public static void main(String[] args) {
        //创建一个英雄角色
        Hero hero = new Hero();
        //给英雄起个名字，并设置年龄
        hero.setName("盖伦");
        hero.setAge(20);
        //创建一个武器对象
        weapon weapon = new weapon("多兰剑");
        //为英雄配备武器
        hero.setWeapon(weapon);
        //为英雄设置技能
        SkillImpl si = new SkillImpl();
        hero.setSkill(si);

        hero.attack();
    }
}
