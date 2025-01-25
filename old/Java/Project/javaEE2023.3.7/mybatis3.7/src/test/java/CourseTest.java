import com.jsj.dao.CourseService;
import com.jsj.entries.Course;
import com.jsj.uitils.MybaitsFactory;
import org.apache.ibatis.session.SqlSession;
import org.junit.Test;

import java.util.List;

public class CourseTest {

    @Test
    public  void selectCourseBySidTest()
    {
        SqlSession session= MybaitsFactory.getSqlSession();
        CourseService courseService=session.getMapper(CourseService.class);
        List<Course> list=courseService.selectCourseBySid(1);
        for (Course c:list)
            System.out.println(c);
    }
}
