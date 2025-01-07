--创建数据库
create database R2007_01;
go
--使用数据库
use R2007_01;
go
--创建表
create table users(
	id int primary key identity(1,1),
	userName varchar(20),
	userPwd varchar(20),
	nickName varchar(20),
	age int
)
--向表中插入数据
insert into users values ('wpf','wpf123','王鹏飞',18);
--查询表的全内容
select * from users



