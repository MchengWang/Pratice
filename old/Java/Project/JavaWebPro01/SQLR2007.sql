--食品管理  创建数据库  foodDB
create database foodDB
go
use foodDB
go


--食品分类  创建表  foodType
-- id  类型名称  备注
create table foodType
(
	id int primary key identity(1,1), 
	typeName varchar(20),
	remark varchar(200)
)

insert into foodType values ('膨化零食','好吃')
select * from foodType

--食品明细   创建表   food
-- id    食品名称    所属分类    价格    库存  
create table food (
	id int primary key identity(1,1), 
	foodName varchar(20),
	foodTpyeId int ,
	price varchar(20),
	stock varchar(20)
)
insert into food values ('薯条',1,6,100)

select * from foodType
select * from food
