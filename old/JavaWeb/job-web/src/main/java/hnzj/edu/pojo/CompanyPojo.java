package hnzj.edu.pojo;

public class CompanyPojo {
	private String company;
	private int count;

	public String getCompany() {
		return company;
	}

	public void setCompany(String company) {
		this.company = company;
	}

	public int getCount() {
		return count;
	}

	public void setCount(int count) {
		this.count = count;
	}

	@Override
	public String toString() {
		return "{\"name\":\""+company+"\",\"value\":"+String.valueOf(count)+"}";
	}
}
