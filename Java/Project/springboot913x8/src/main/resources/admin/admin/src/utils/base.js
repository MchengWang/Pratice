const base = {
    get() {
        return {
            url : "http://localhost:8080/springboot913x8/",
            name: "springboot913x8",
            // 退出到首页链接
            indexUrl: ''
        };
    },
    getProjectName(){
        return {
            projectName: "学生宿舍管理系统"
        } 
    }
}
export default base
