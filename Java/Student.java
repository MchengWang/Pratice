package mySet;

public class Student implements Comparable<Student>{
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
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + age;
		result = prime * result + ((name == null) ? 0 : name.hashCode());
		return result;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Student other = (Student) obj;
		if (age != other.age)
			return false;
		if (name == null) {
			if (other.name != null)
				return false;
		} else if (!name.equals(other.name))
			return false;
		return true;
	}
	public int compareTo(Student s) {
		// TODO Auto-generated method stub
		int num = this.age - s.age;//对年龄进行升序排列
//		int num = s.age - this.age;//对年龄进行降序排列
		int num2 = (num == 0 ? this.name.compareTo(s.name):num);
		return num2;
		
//		return 0;//代表的是目标s和本身相同，所以不添加
//		return 1;//代表的是进行升序排列，     默认的话就是存储的顺序
//		return -1;//代表的是进行降序排列
	}
    
}
