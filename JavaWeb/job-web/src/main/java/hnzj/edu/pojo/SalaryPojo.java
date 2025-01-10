package hnzj.edu.pojo;

public class SalaryPojo {
	private String salary;
	private int count;

	public String getSalary() {
		return salary;
	}

	public void setSalary(String salary) {
		this.salary = salary;
	}

	public int getCount() {
		return count;
	}

	public void setCount(int count) {
		this.count = count;
	}

	@Override
	public String toString() {
		return "{\"name\":\"" + salary + "\",\"value\":" + String.valueOf(count) + "}";
	}

}
