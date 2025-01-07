package Summarize.Lambda;

public class DemoLambdaStandardformat {
    /*lambda标准格式
      匿名内部类的好处与弊端，一方面省去实现类的定义，另一方面语法太复杂
    语义分析 Runnable接口只有run方法的定义
        public abstract void run();
    即制定一件做事情的方案（其实就是一个函数）
        无参数：不需要任何条件即可执行该方法
        无返回值：该方案不产生任何结果
        代码块（方法体）：该方法的具体执步骤
    同样的语义体现在lambda语法中更加简单
        ()->Systm.out.println("多线程任务执行");
        前面的括号即run方法的参数（无），代表不需任何条件
        中间的一个箭头指的是，将前面的参数床底到后面的代码
        后面的输出语句即业务逻辑代码
    lambda标准格式
    lambda省去面向对象的条件框框，格式有三个部分组成
        一些参数
        一个箭头
        一段代码
    lambda标准格式
    （参数类型 参数名称）->{代码语句}
    格式说明
        小括号的语句与传统方法参数列表一样：无参即空；多个参数用逗号分隔
        ->是新引入的语法格式，代表指向动作
        大括号的语法与传统方法体要求基本一致
     */
    public static void main(String[] args) {
        //使用匿名内部类
        Cookinvoke(new Cook() {
            @Override
            public void makeCook() {
                System.out.println("吃饭了");
            }
        });

        //使用lambda表达式简化匿名内部类的书写
        Cookinvoke(()->{
            System.out.println("吃饭了");
        });

        //使用lambda进行最优化简化
        Cookinvoke(()-> System.out.println("吃饭了"));

    }

    //定义一个方法
    public static void Cookinvoke(Cook cook){
        cook.makeCook();
    }

}

interface Cook{
    public abstract void makeCook();
}
