package mySet1;

import java.util.Comparator;
import java.util.TreeSet;

import mySet.Student;

/*
    存储学生对象并遍历，创建TreeSet集合使用带参构造方法
    TreeSet(Comparator comparator) ：根据指定的比较器进行排序
    要求：按照年龄从小到大排序，年龄相同时，按照姓名的字母顺序排序
    
    new TreeSet<Student>(arg0): arg0 可以使用一个匿名内部类的方式新建一个Comparator接口的实现类
 */
public class TreeSetDemo03 {
    public static void main(String[] args) {
      //创建集合对象
        TreeSet<Student> ts = new TreeSet<Student>(new Comparator<Student>() {
        	//在匿名内部类中，重写compare方法
        	public int compare(Student s1, Student s2) {
        		// TODO Auto-generated method stub
        		//按照年龄从小到大排序（升序排列）
        		//this   -   s
        		// s1    -   s2
        		int num = s1.getAge() - s2.getAge();
        		//年龄相同时，按照姓名的字母顺序排序
        		int num2 = num == 0 ? s1.getName().compareTo(s2.getName()):num;
        		return num2;
        	}
		});
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
