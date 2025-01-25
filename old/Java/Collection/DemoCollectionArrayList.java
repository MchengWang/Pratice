package Summarize.Collection;

import java.util.ArrayList;
import java.util.Random;

public class DemoCollectionArrayList {

    /*ArrayList此实现不可同步（多线程）
      底层是数组结构，查询快，增删慢*/
    public static void main(String[] args) {
        ArrayList<String> list = new ArrayList<>();
        //为集合添加元素
       /* boolean add(E e)将指定的元素添加到此列表的尾部。
        void add(int index, E element) 将指定的元素插入此列表中的指定位置。
        boolean addAll(Collection<? extends E> c) 按照指定 collection 的迭代器所返回的元素顺序，将该 collection 中的所有元素添加到此列表的尾部。
        boolean addAll(int index, Collection<? extends E> c) 从指定的位置开始，将指定 collection 中的所有元素插入到此列表中。*/
        list.add("赵丽颖");
        list.add("胡歌");
        list.add("古力娜扎");
        list.add("宋智孝");
        System.out.println(list);

        //获取指定索引的元素
        // E get(int index)  返回此列表中指定位置上的元素。
        System.out.println(list.get(2));

        //删除集合中的元素
        /*E remove(int index) 移除此列表中指定位置上的元素。
        boolean remove(Object o) 移除此列表中首次出现的指定元素（如果存在）。
        protected  void removeRange(int fromIndex, int toIndex) 移除列表中索引在 fromIndex（包括）和 toIndex（不包括）之间的所有元素。*/
        System.out.println(list.remove(0));

        //获取集合的长度
        // int size() 返回此列表中的元素数。
        System.out.println(list.size());

        //遍历集合
        for (String s : list) {
            System.out.println(s);
        }

        //把随机数添加到ArrayList集合中，并遍历显示出来
        ArrayList<Integer> list01 = new ArrayList<>();//创建ArrayList的集合对象
        for (int i = 0; i < 6; i++) { //往集合中添加6次元素
            list01.add(new Random().nextInt(33)+1);//往集合中添加随机数，范围在0-33之间
        }
        for (int s : list01) {//利用foreach循环遍历集合list01
            System.out.println(s);
        }

        //存储自定义对象到集合中
        Student one = new Student("洪七公",18);
        Student two = new Student("杨凌", 14);
        ArrayList<Student> list02 = new ArrayList<>();
        list02.add(one);
        list02.add(two);
        for (Student student : list02) {
            System.out.println(student);
        }

        //按照格式遍历集合字符串
        ArrayList<String> list03 = new ArrayList<>();
        list03.add("张三丰");
        list03.add("杨过");
        printArraylists(list03);

        //随机生成数字，并区分奇偶数，并输出数组和奇偶数的个数
        getshuzi();
    }

    //自定义Student学生类
    static class Student{
        private String name;
        private int age;

        public Student() {
        }

        public Student(String name, int age) {
            this.name = name;
            this.age = age;
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

        @Override
        public String toString() {
            return "Student{" +
                    "name='" + name + '\'' +
                    ", age=" + age +
                    '}';
        }
    }

    //按照格式遍历集合字符串
    public static void printArraylists(ArrayList<String> list){
        System.out.print("{");//先输入一个大括号
        for (int i = 0; i < list.size(); i++) {
            System.out.print(list.get(i));//获取集合中的元素
            if(i == list.size()-1){//如果i等于集合的长度-1就输入另外一半大括号
                System.out.println("}");
            }else{
                System.out.print("@");//反之输出@
            }
        }
    }

    //随机生成数字，并区分奇偶数，并输出数组和奇偶数的个数
    public static void getshuzi(){
        ArrayList<Integer> list01 = new ArrayList<>();
        for (int i = 0; i < 20; i++) {
            list01.add(new Random().nextInt(100)+1);//为集合随机添加1-100之间的数
        }
        ArrayList<Integer> list02 = new ArrayList<>();
        ArrayList<Integer> list03 = new ArrayList<>();
        for (Integer integer : list01) {
            System.out.print(integer+",");
            if(integer %2 == 0){
                list02.add(integer);
            }else{
                list03.add(integer);
            }
        }
        System.out.println();
        System.out.println("偶数的数量为："+list02.size());
        System.out.println("奇数的数量为"+list03.size());
    }
}
