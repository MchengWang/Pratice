package hnzj.edu.pojo;

public class CityPojo {
	private String city;
	private int count;

	public String getCity() {
		return city;
	}

	public void setCity(String city) {
		this.city = city;
	}

	public int getCount() {
		return count;
	}

	public void setCount(int count) {
		this.count = count;
	}

	@Override
	public String toString() {
		return "{\"name\":\"" + city + "\",\"value\":" + String.valueOf(count) + "}";
	}

}
