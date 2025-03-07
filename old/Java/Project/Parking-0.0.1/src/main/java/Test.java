import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.text.DecimalFormat;

public class Test {
    public static void main(String[] args) {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            String url = "jdbc:mysql://localhost:3306/dh?useUnicode=true&characterEncoding=utf8";
            String Name = "root";
            String cord = "27341906";
            Connection conn = DriverManager.getConnection(url , Name , cord);
            PreparedStatement pstmt = conn.prepareStatement("insert into ParkingSpaces (parkingSpaces_type , parkingSpaces_state , parkingSpaces_local) values (?, ? ,?)");
            DecimalFormat df = new DecimalFormat("00");
            char[] chars = "ABCDE".toCharArray();
            for (int i = 0; i < chars.length; i++) {
                for (int j = 1; j <= 50; j++) {
                    pstmt.setString(2 , "未停车");
                    pstmt.setString(3 , chars[i] + df.format(j));
                    if(i <= 2){
                        pstmt.setString(1 , "小型车位");
                    }else if(i < 4){
                        pstmt.setString(1 , "中型车位");
                    }else{
                        pstmt.setString(1 , "大型车位");
                    }

                    pstmt.addBatch();
                }
                pstmt.executeBatch();
            }
        } catch (ClassNotFoundException | SQLException e) {
            e.printStackTrace();
        }
    }
}
