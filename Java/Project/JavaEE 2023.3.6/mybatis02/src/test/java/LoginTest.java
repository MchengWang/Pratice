import com.jsj.dao.LoginInfoService;
import com.jsj.dao.UserInfoService;
import com.jsj.entries.LoginInfo;
import com.jsj.entries.UserInfo;
import com.jsj.uitils.MybaitsFactory;
import org.apache.ibatis.session.SqlSession;
import org.junit.Test;

import java.util.List;

public class LoginTest {


    @Test
    public void selectAllInfoTest()
    {
        SqlSession sqlSession= MybaitsFactory.getSqlSession();
        LoginInfoService loginInfoService=sqlSession.getMapper(LoginInfoService.class);

        List<LoginInfo> users=loginInfoService.selectAllInfo();
        for(LoginInfo u:users)
            System.out.println(u);
    }
}
