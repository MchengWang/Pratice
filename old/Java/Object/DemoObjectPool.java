package Summarize.Object;

public class DemoObjectPool {
    static public int water = 0;
    public void output(){
    }
    public void inle(){
        water = water +3;
    }

    public static void main(String[] args) {
        DemoObjectPool in = new DemoObjectPool();
        DemoObjectPool out = new DemoObjectPool();
        System.out.println("游泳池中的水量"+ DemoObjectPool.water);
        System.out.println("向水池中加两次水");
        in.inle();
        in.inle();
        System.out.println("游泳池中的水量"+DemoObjectPool.water);
    }
}
