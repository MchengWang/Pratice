package Summarize.Test;

import java.io.*;
import java.sql.*;
import java.util.ArrayList;

public class Demo01 {
    private static final String MYSQL_DRIVER = "com.mysql.cj.jdbc.Driver";
    private static final String URL = "jdbc:mysql:///private";
    private static final String USER = "root";
    private static final String PASSWORD = "040820";
    private static Connection conn = null;
    private static PreparedStatement pstmt = null;
    private static ResultSet rs = null;

    static {
        try {
            Class.forName(Demo01.MYSQL_DRIVER);
            conn = DriverManager.getConnection(Demo01.URL , Demo01.USER , Demo01.PASSWORD);
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        }
    }

    public static void main(String[] args) {

    }

    public static boolean SavePicture(String url){
        FileInputStream fis = null;
        byte[] bytes = null;
        boolean b = false;
        try {
            fis = new FileInputStream(new File(url));
            bytes = new byte[fis.available()];
            fis.read(bytes);
            pstmt = conn.prepareStatement("insert into love (binary(bytes , 2) , current_timestamp)");
            b = pstmt.execute();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }

        return b;
    }

    public static void TakePicture(String url){
        FileOutputStream fos = null;
        ResultSet rs = null;
        ArrayList<Blob> list = new ArrayList<>();
        try {
            fos = new FileOutputStream(new File(url));
            pstmt = conn.prepareStatement("select * from love");
            rs = pstmt.executeQuery();

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        }
    }

}
