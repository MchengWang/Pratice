import com.jsj.dao.ClassInfoService;
import com.jsj.dao.StudentInfoService;
import com.jsj.entries.ClassInfo;
import com.jsj.entries.Course;
import com.jsj.entries.StudentInfo;
import com.jsj.uitils.MybaitsFactory;
import org.apache.ibatis.session.SqlSession;
import org.junit.Test;

import java.util.List;

public class StudentInfoTest {

    @Test
    public  void  selectStudentByCidTest()
    {
        SqlSession session= MybaitsFactory.getSqlSession();
        StudentInfoService studentInfoService=session.getMapper(StudentInfoService.class);

        List<StudentInfo> list=studentInfoService.selectStudentByCid(1);

        for (StudentInfo s:list)
        {
            System.out.println(s);
            System.out.println("选课信息:");
            for (Course c:s.getCouseList())
                System.out.println(c);
            System.out.println("-----------------------------");
        }
    }

    @Test
    public  void selectInfoWithClassTest()
    {
        SqlSession session= MybaitsFactory.getSqlSession();
        StudentInfoService studentInfoService=session.getMapper(StudentInfoService.class);

        List<StudentInfo> list=studentInfoService.selectInfoWithClass(1);

        for (StudentInfo s:list)
            System.out.println(s);
    }

    @Test
    public  void selectAllInfoWithStudent()
    {
        SqlSession session= MybaitsFactory.getSqlSession();
        ClassInfoService classInfoService=session.getMapper(ClassInfoService.class);

        List<ClassInfo> list=classInfoService.selectAllInfoWithStudent();

        for(ClassInfo c:list)
        {
            System.out.println(c);
            System.out.println("学生列表:");
            for (StudentInfo s:c.getStudentInfoList())
                System.out.println(s);

        }

    }

}
