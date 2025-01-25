package mySet;

import java.util.TreeSet;


/*
    存储学生对象并遍历，创建集合使用无参构造方法
    要求：按照年龄从小到大排序，年龄相同时，按照姓名的字母顺序排序
 */
public class TreeSetDemo02 {
    public static void main(String[] args) {
        //创建集合对象
       TreeSet<Student> ts = new TreeSet<Student>();

        //创建学生对象
		Student s1 = new Student("zhoujielun",33);
		Student s2 = new Student("chenyixun",32);
		Student s3 = new Student("zhangxueyou",41);
		Student s4 = new Student("caixukun",32);

        //把学生添加到集合
        ts.add(s1);
        ts.add(s2);
        ts.add(s3);
        ts.add(s4);

        //遍历集合
        for(Student stu : ts){
        	System.out.println(stu.getName() + ", " + stu.getAge());//java.lang.ClassCastException
        }
    }
}
