const base = {
    get() {
        return {
            url : "http://localhost:8080/springboot18499/",
            name: "springboot18499",
            // 退出到首页链接
            indexUrl: 'http://localhost:8080/springboot18499/front/dist/index.html'
        };
    },
    getProjectName(){
        return {
            projectName: "扶孤助贫平台"
        } 
    }
}
export default base
