package hnzj.edu.pojo;

public class Test {

	public static void main(String[] args) {
		String city="±±¾©";
		int count=150;
		String jsonS="{\"name\":\""+city+"\",\"value\":"+String.valueOf(count)+"}";
		System.out.println(jsonS);
	}

}
