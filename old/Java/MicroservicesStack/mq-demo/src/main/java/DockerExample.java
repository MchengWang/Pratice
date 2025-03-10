/**
 *  此类只用于解释相关技术的类
 */

public class DockerExample {
    /*Docker是一个快速交付应用，运行应用的技术：
    *   1、可以将程序及其依赖，运行环境一起打包为一个镜像，可以迁移到任意Linux操作系统
    *   2、运行时利用沙箱机制形成隔离容器，各个应用互不打扰
    *   3、启动、移除都可以通过一行命令完成，方便快捷*/

    /*Docker和虚拟机的差异
    *   docker是一个系统进程，虚拟机是在操作系统中的操作系统
    *   docker体积小，启动速度快、性能好；虚拟机体积大、启动速度慢，性能一般*/

    /*镜像：
    *   将应用及其依赖、环境、配置打包到一起
    *容器：
    *   镜像运行起来就是容器，一个镜像可以运行多个容器
    *Docker架构：
    *   服务端：接受命令或远程请求，操作镜像或容器
    *   客户端：发送命令或者请求到Docker服务端
    *DockerHub：
    *   一个镜像托管的服务器，类似的还有阿里云镜像服务，统称为DockerRegistry*/

    /*镜像是分层结构，每一层称为一个Layer
     *   BaseImage层：包含基本的系统函数库，环境变量，文件系统
     *   EntryPoint：入口，是镜像中应用启动的命令
     *   其他：在BaseImage基础上添加依赖，安装程序，完成整个应用的安装和配置*/

    /*什么是DockerCompose
    *   Docker Compose可以基于Compose文件帮我们快速的部署分布式应用，而无需手动一个个创建和运行容器
    *   Compose文件是一个文本文件，通过指令定义集群中的每个容器如何运行*/

    /*什么是Dockerfile
    *   Dockerfile是一个文本文件，其中包含一个个的指令（Instruction），用指令来说明要执行什么操作来构建镜像。每一个指令都会形成一层Layer
    *   FROM 指定基础镜像 FROM centos:6
    *   ENV 设置环境变量，可在后面指令使用 ENV key value
    *   COPY 拷贝本地文件到镜像的指定目录 COPY ./mysql-5.7rpm /tmp
    *   RUN 执行Linux的shell命令，一般是安装过程的命令 RUN yum install gcc
    *   EXPOSE 指定容器运行时坚挺的端口，是给镜像使用者看的 EXPOSE 8080
    *   ENTRYPOINT 镜像中应用的启动命令，容器运行时调用 ENTRYPOINT java -jar  xx.jar
    *DockerCompose的详细语法参考官网：https://docs.docker.com/compose/compose-file/*/

    /*如何将镜像推送到私有仓库中
    *   1、推送本地镜像到仓库前都必须重命名（docker tag）镜像，以镜像仓库地址为前缀
    *   2、镜像仓库推送前需要把仓库地址配置到docker服务的daemon.json文件中，被docker信任
    *   3、推送使用docker push命令
    *   4、拉去使用docker pull命令*/

}
