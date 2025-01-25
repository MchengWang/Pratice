package Summarize.Junit;

public class JunitConcepts {
    /*Junit使用：白盒测试
    *   1.定义一个测试类（测试用例） 建议 测试类名：被测试的类名加Test 包名：xxx.xxx.xx.test
    *   2.定义测试方法：可以独立执行 建议：方法名：test加测试的方法名 返回值：void参数列表：空参
    *   3.给方法加@Test
    *   4.导入junit依赖环境
    * 判定结果：红色：失败    一般我们会使用断言操作来处理
    *         绿色：成功    Assert.assertEquals(期望的结果，运算的结果)
    * 补充：
    *   @Before 初始化方法，用于资源申请，所有测试方法在执行之前都会先执行该方法
    *   @After 释放资源方法，在所有测试方法执行完成，都会自动执行该方法*/
}
