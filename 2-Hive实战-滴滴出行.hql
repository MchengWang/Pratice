-- 一、数据仓库构建
--1：创建数据库 
    -- 1.1 创建ods库
    create database if not exists ods_didi;
    -- 1.2 创建dw库
    create database if not exists dw_didi;
    -- 1.3 创建app库
    create database if not exists app_didi;
--2：创建表
-- 2.1 创建订单表结构
    create table if not exists ods_didi.t_user_order(
        orderId string comment '订单id',
        telephone string comment '打车用户手机',
        lng string comment '用户发起打车的经度',
        lat string comment '用户发起打车的纬度',
        province string comment '所在省份',
        city string comment '所在城市',
        es_money double comment '预估打车费用',
        gender string comment '用户信息 - 性别',
        profession string comment '用户信息 - 行业',
        age_range string comment '年龄段（70后、80后、...）',
        tip double comment '小费',
        subscribe int comment '是否预约（0 - 非预约、1 - 预约）',
        sub_time string comment '预约时间',
        is_agent int comment '是否代叫（0 - 本人、1 - 代叫）',
        agent_telephone string comment '预约人手机',
        order_time string comment '预约时间'
    )
    partitioned by (dt string comment '时间分区') 
    ROW FORMAT DELIMITED FIELDS TERMINATED BY ',' ; 
--2.2 创建取消订单表
create table if not exists ods_didi.t_user_cancel_order(
    orderId string comment '订单ID',
    cstm_telephone string comment '客户联系电话',
    lng string comment '取消订单的经度',
    lat string comment '取消订单的纬度',
    province string comment '所在省份',
    city string comment '所在城市',
    es_distance double comment '预估距离',
    gender string comment '性别',
    profession string comment '行业',
    age_range string comment '年龄段',
    reason int comment '取消订单原因（1 - 选择了其他交通方式、2 - 与司机达成一致，取消订单、3 - 投诉司机没来接我、4 - 已不需要用车、5 - 无理由取消订单）',
    cancel_time string comment '取消时间'
)
partitioned by (dt string comment '时间分区') 
ROW FORMAT DELIMITED FIELDS TERMINATED BY ',' ; 
--2.3 创建订单支付表
create table if not exists ods_didi.t_user_pay_order(
    id string comment '支付订单ID',
    orderId string comment '订单ID',
    lng string comment '目的地的经度（支付地址）',
    lat string comment '目的地的纬度（支付地址）',
    province string comment '省份',
    city string comment '城市',
    total_money double comment '车费总价',
    real_pay_money double comment '实际支付总额',
    passenger_additional_money double comment '乘客额外加价',
    base_money double comment '车费合计',
    has_coupon int comment '是否使用优惠券（0 - 不使用、1 - 使用）',
    coupon_total double comment '优惠券合计',
    pay_way int comment '支付方式（0 - 微信支付、1 - 支付宝支付、3 - QQ钱包支付、4 - 一网通银行卡支付）',
    mileage double comment '里程（单位公里）',
    pay_time string comment '支付时间'
)
partitioned by (dt string comment '时间分区') 
ROW FORMAT DELIMITED FIELDS TERMINATED BY ',' ; 

--2.4创建用户评价表
create table if not exists ods_didi.t_user_evaluate(
    id string comment '评价日志唯一ID',
    orderId string comment '订单ID',
    passenger_telephone string comment '用户电话',
    passenger_province string comment '用户所在省份',
    passenger_city string comment '用户所在城市',
    eva_level int comment '评价等级（1 - 一颗星、... 5 - 五星）',
    eva_time string comment '评价时间'
)
partitioned by (dt string comment '时间分区') 
ROW FORMAT DELIMITED FIELDS TERMINATED BY ',' ; 


--3:给表加载数据
--3.1、创建本地路径，上传源日志文件
mkdir -p /export/data/didi

3.1.1 将本地笔记本的数据文件上传到Linux系统下的/export/data/didi目录下

--3.2、通过load命令给表加载数据，并指定分区
load data local inpath '/export/data/didi/order.csv' into table t_user_order partition (dt='2020-04-12');
load data local inpath '/export/data/didi/cancel_order.csv' into table t_user_cancel_order partition (dt='2020-04-12');
load data local inpath '/export/data/didi/pay.csv' into table t_user_pay_order partition (dt='2020-04-12');
load data local inpath '/export/data/didi/evaluate.csv' into table t_user_evaluate partition (dt='2020-04-12');


--4:数据预处理
--建表
create table if not exists dw_didi.t_user_order_wide(
    orderId string comment '订单id',
    telephone string comment '打车用户手机',
    lng string comment '用户发起打车的经度',
    lat string comment '用户发起打车的纬度',
    province string comment '所在省份',
    city string comment '所在城市',
    es_money double comment '预估打车费用',
    gender string comment '用户信息 - 性别',
    profession string comment '用户信息 - 行业',
    age_range string comment '年龄段（70后、80后、...）',
    tip double comment '小费',
    subscribe int comment '是否预约（0 - 非预约、1 - 预约）',
    subscribe_name string comment '是否预约名称',
    sub_time string comment '预约时间',
    is_agent int comment '是否代叫（0 - 本人、1 - 代叫）',
    is_agent_name string comment '是否代叫名称',
    agent_telephone string comment '预约人手机',
    order_date string comment '预约时间，yyyy-MM-dd',
    order_year string comment '年',
    order_month string comment '月',
    order_day string comment '日',
    order_hour string comment '小时',
    order_time_range string comment '时间段',
    order_time string comment '预约时间'
)
partitioned by (dt string comment '时间分区') 
ROW FORMAT DELIMITED FIELDS TERMINATED BY ',' ; 

--转宽表HQL语句
--------------------------------------
--date_format将字符串转为日期
select date_format('2020-1-1', 'yyyy-MM-dd'); -- 2020-01-01
select date_format('2020-1-1 12:23', 'yyyy-MM-dd'); -- 2020-01-01
select date_format('2020-1-1 12:23:35', 'yyyy-MM-dd'); -- 2020-01-01

select date_format('2020-1-1 1:1:1', 'yyyy-MM-dd HH:mm:ss'); -- 2020-01-01 01:01:01

select hour(date_format('2020-1-1 1:1:00', 'yyyy-MM-dd HH:mm:ss')); --  01


--concat字符串的拼接
select concat('aaa','bbb','ccc');-- aaabbbccc
--length 获取字符串长度
select length('aaabbb'); -- 6
--------------------------------------
select 
    orderId,
    telephone,
    lng,
    lat,
    province,
    city,
    es_money,
    gender,
    profession,
    age_range,
    tip,
    subscribe,
    case when subscribe = 0 then '非预约'
         when subscribe = 1 then'预约'
    end as subscribe_name,
     date_format(concat(sub_time,':00'), 'yyyy-MM-dd HH:mm:ss') as sub_time,
    is_agent,
    case when is_agent = 0 then '本人'
         when is_agent = 1 then '代叫'
    end as is_agent_name,
    agent_telephone,
    date_format(order_time, 'yyyy-MM-dd') as order_date, -- 2020-1-1 --->2020-01-01
    year(date_format(order_time, 'yyyy-MM-dd')) as order_year, --2020
    month(date_format(order_time, 'yyyy-MM-dd')) as order_month, --12
    day(date_format(order_time, 'yyyy-MM-dd')) as order_day, --23
    hour(date_format(concat(order_time,':00'), 'yyyy-MM-dd HH:mm:ss')) as order_hour,
    case when hour(date_format(concat(order_time,':00'), 'yyyy-MM-dd HH:mm:ss')) > 1 and hour(date_format(concat(order_time,':00'), 'yyyy-MM-dd HH:mm:ss')) <= 5 then '凌晨'
         when hour(date_format(concat(order_time,':00'), 'yyyy-MM-dd HH:mm:ss')) > 5 and hour(date_format(concat(order_time,':00'), 'yyyy-MM-dd HH:mm:ss')) <= 8 then '早上'
         when hour(date_format(concat(order_time,':00'), 'yyyy-MM-dd HH:mm:ss')) > 8 and hour(date_format(concat(order_time,':00'), 'yyyy-MM-dd HH:mm:ss')) <= 11 then '上午'
         when hour(date_format(concat(order_time,':00'), 'yyyy-MM-dd HH:mm:ss')) > 11 and hour(date_format(concat(order_time,':00'), 'yyyy-MM-dd HH:mm:ss')) <= 13 then '中午'
         when hour(date_format(concat(order_time,':00'), 'yyyy-MM-dd HH:mm:ss')) > 13 and hour(date_format(concat(order_time,':00'), 'yyyy-MM-dd HH:mm:ss')) <= 17 then '下午'
         when hour(date_format(concat(order_time,':00'), 'yyyy-MM-dd HH:mm:ss')) > 17 and hour(date_format(concat(order_time,':00'), 'yyyy-MM-dd HH:mm:ss')) <= 19 then '晚上'
         when hour(date_format(concat(order_time,':00'), 'yyyy-MM-dd HH:mm:ss')) > 19 and hour(date_format(concat(order_time,':00'), 'yyyy-MM-dd HH:mm:ss')) <= 20 then '半夜'
         when hour(date_format(concat(order_time,':00'), 'yyyy-MM-dd HH:mm:ss')) > 20 and hour(date_format(concat(order_time,':00'), 'yyyy-MM-dd HH:mm:ss')) <= 24 then '深夜'
         when hour(date_format(concat(order_time,':00'), 'yyyy-MM-dd HH:mm:ss')) >= 0 and hour(date_format(concat(order_time,':00'), 'yyyy-MM-dd HH:mm:ss')) <= 1 then '深夜'
         else 'N/A'
    end as order_time_range,
    date_format(concat(order_time,':00'), 'yyyy-MM-dd HH:mm:ss') as order_time
from ods_didi.t_user_order where dt = '2020-04-12' and length(order_time) >= 8 ;



--7.3 	将数据加载到dw层宽表

------------------------------------

如何将一个表的查询结果保存到另外一张表:
insert overwrite table 表名1 select 字段 from 表名2


-------------------------------------
insert overwrite table dw_didi.t_user_order_wide partition(dt='2020-04-12')
select 
    orderId,
    telephone,
    lng,
    lat,
    province,
    city,
    es_money,
    gender,
    profession,
    age_range,
    tip,
    subscribe,
    case when subscribe = 0 then '非预约'
         when subscribe = 1 then'预约'
    end as subscribe_name,
     date_format(concat(sub_time,':00'), 'yyyy-MM-dd HH:mm:ss') as sub_time,
    is_agent,
    case when is_agent = 0 then '本人'
         when is_agent = 1 then '代叫'
    end as is_agent_name,
    agent_telephone,
    date_format(order_time, 'yyyy-MM-dd') as order_date, -- 2020-1-1 --->2020-01-01
    year(date_format(order_time, 'yyyy-MM-dd')) as order_year, --2020
    month(date_format(order_time, 'yyyy-MM-dd')) as order_month, --12
    day(date_format(order_time, 'yyyy-MM-dd')) as order_day, --23
    hour(date_format(concat(order_time,':00'), 'yyyy-MM-dd HH:mm:ss')) as order_hour,
    case when hour(date_format(concat(order_time,':00'), 'yyyy-MM-dd HH:mm:ss')) > 1 and hour(date_format(concat(order_time,':00'), 'yyyy-MM-dd HH:mm:ss')) <= 5 then '凌晨'
         when hour(date_format(concat(order_time,':00'), 'yyyy-MM-dd HH:mm:ss')) > 5 and hour(date_format(concat(order_time,':00'), 'yyyy-MM-dd HH:mm:ss')) <= 8 then '早上'
         when hour(date_format(concat(order_time,':00'), 'yyyy-MM-dd HH:mm:ss')) > 8 and hour(date_format(concat(order_time,':00'), 'yyyy-MM-dd HH:mm:ss')) <= 11 then '上午'
         when hour(date_format(concat(order_time,':00'), 'yyyy-MM-dd HH:mm:ss')) > 11 and hour(date_format(concat(order_time,':00'), 'yyyy-MM-dd HH:mm:ss')) <= 13 then '中午'
         when hour(date_format(concat(order_time,':00'), 'yyyy-MM-dd HH:mm:ss')) > 13 and hour(date_format(concat(order_time,':00'), 'yyyy-MM-dd HH:mm:ss')) <= 17 then '下午'
         when hour(date_format(concat(order_time,':00'), 'yyyy-MM-dd HH:mm:ss')) > 17 and hour(date_format(concat(order_time,':00'), 'yyyy-MM-dd HH:mm:ss')) <= 19 then '晚上'
         when hour(date_format(concat(order_time,':00'), 'yyyy-MM-dd HH:mm:ss')) > 19 and hour(date_format(concat(order_time,':00'), 'yyyy-MM-dd HH:mm:ss')) <= 20 then '半夜'
         when hour(date_format(concat(order_time,':00'), 'yyyy-MM-dd HH:mm:ss')) > 20 and hour(date_format(concat(order_time,':00'), 'yyyy-MM-dd HH:mm:ss')) <= 24 then '深夜'
         when hour(date_format(concat(order_time,':00'), 'yyyy-MM-dd HH:mm:ss')) >= 0 and hour(date_format(concat(order_time,':00'), 'yyyy-MM-dd HH:mm:ss')) <= 1 then '深夜'
         else 'N/A'
    end as order_time_range,
    date_format(concat(order_time,':00'), 'yyyy-MM-dd HH:mm:ss') as order_time
from ods_didi.t_user_order where dt = '2020-04-12' and length(order_time) >= 8;





--5:指标分析
---------------------1 总订单笔数----------------------------


select 
    count(orderid) as total_cnt
from
    dw_didi.t_user_order_wide
where
    dt = '2020-04-12'
;

-- 创建保存日期对应订单笔数的app表
create table if not exists app_didi.t_order_total(
    date_val string comment '日期（年月日)',
    count int comment '订单笔数'
)
partitioned by (month string comment '年月，yyyy-MM')
row format delimited fields terminated by ','
;

--加载数据到app表
insert overwrite table app_didi.t_order_total partition(month='2020-04')
select 
    '2020-04-12',
    count(orderid) as total_cnt
from
    dw_didi.t_user_order_wide
where
    dt = '2020-04-12'
;
---------------------2. 预约和非预约用户占比----------------------------

需求:
  求出预约用户订单所占的百分比:
   
select 预约订单总数 / 总订单数 from 预约统计订单数表,总订单数表 
union all
select 非预约订单总数 / 总订单数 from 非预约统计订单数表,总订单数表 


   
select 
   '2020-04-12',
    '预约',
    concat(round(t1.total_cnt /t2.total_cnt *100,2),'%') as subscribe 
from 
   (
      select 
            count(orderid) as total_cnt
        from
            dw_didi.t_user_order_wide
        where
            subscribe = 1 and dt = '2020-04-12' 
    )t1,
    (
        select 
            count(orderid) as total_cnt
        from
            dw_didi.t_user_order_wide
        where
            dt = '2020-04-12'
    )t2

union all --将上边的查询结果和下边的查询结果进行合并

select 
   '2020-04-12',
    '非预约',
    concat(round(t1.total_cnt /t2.total_cnt *100,2),'%') as nosubscribe 
from 
   (
      select 
            count(orderid) as total_cnt
        from
            dw_didi.t_user_order_wide
        where
            subscribe = 0 and dt = '2020-04-12' 
    )t1,
    (
        select 
            count(orderid) as total_cnt
        from
            dw_didi.t_user_order_wide
        where
            dt = '2020-04-12'
    )t2


-- 创建保存日期对应订单笔数的app表
create table if not exists app_didi.t_order_subscribe_percent(
    date_val string comment '日期',
    subscribe_name string comment '是否预约',
    percent_val string comment '百分比'
)partitioned by (month string comment '年月yyyy-MM') 
row format delimited fields terminated by ','

--加载数据到app表
insert overwrite table  app_didi.t_order_subscribe_percent partition(month='2020-04')
select 
   '2020-04-12',
    '预约',
    concat(round(t1.total_cnt /t2.total_cnt *100,2),'%') as subscribe 
from 
   (
      select 
            count(orderid) as total_cnt
        from
            dw_didi.t_user_order_wide
        where
            subscribe = 1 and dt = '2020-04-12' 
    )t1,
    (
        select 
            count(orderid) as total_cnt
        from
            dw_didi.t_user_order_wide
        where
            dt = '2020-04-12'
    )t2

union all
select 
   '2020-04-12',
    '非预约',
    concat(round(t1.total_cnt /t2.total_cnt *100,2),'%') as nosubscribe 
from 
   (
      select 
            count(orderid) as total_cnt
        from
            dw_didi.t_user_order_wide
        where
            subscribe = 0 and dt = '2020-04-12' 
    )t1,
    (
        select 
            count(orderid) as total_cnt
        from
            dw_didi.t_user_order_wide
        where
            dt = '2020-04-12'
    )t2


---------------------3 不同时段的订单个数----------------------------
--编写HQL语句
select
    order_time_range,
    count(*) as order_cnt
from
    dw_didi.t_user_order_wide
where
    dt = '2020-04-12'
group by
    order_time_range
--创建APP层表
create table if not exists app_didi.t_order_timerange_total(
    date_val string comment '日期',
    timerange string comment '时间段',
    count int comment '订单数量'
)
partitioned by (month string comment '年月，yyyy-MM')
row format delimited fields terminated by ','
;

--加载数据到APP表
insert overwrite table app_didi.t_order_timerange_total partition(month = '2020-04')
select
    '2020-04-12',
    order_time_range,
    count(*) as order_cnt
from
    dw_didi.t_user_order_wide
where
    dt = '2020-04-12'
group by
    order_time_range
;

--------------不同年龄段、时段订单个数-----
---创建表---
create table if not exists app_didi.t_order_agerange_timerange(
    date_val string comment '日期',
	agerange string ,
    timerange string comment '时间段',
    count int comment '订单数量'
)
partitioned by (month string comment '年月，yyyy-MM')
row format delimited fields terminated by ','
;

insert overwrite table app_didi.t_order_agerange_timerange partition(month='2020-04')
select '2020-04-12',  age_range,order_time_range,count(1)  
from dw_didi.t_user_order_wide 
group by 
age_range,order_time_range




--------4. 不同地域订单占比--------------------
--编写HQL ---方式1
select
    province,
    count(*) as order_cnt
from
    dw_didi.t_user_order_wide
where
    dt = '2020-04-12'
group by
    province
;




--创建APP表
create table if not exists app_didi.t_order_province_total(
    date_val string comment '日期',
    province string comment '省份',
    count int comment '订单数量'
)
partitioned by (month string comment '年月，yyyy-MM')
row format delimited fields terminated by ','
;

--数据加载到APP表
insert overwrite table app_didi.t_order_province_total partition(month = '2020-04')
select
    '2020-04-12',
    province,
    count(*) as order_cnt
from
    dw_didi.t_user_order_wide
where
    dt = '2020-04-12'
group by
    province
order by order_cnt desc
;


--------5 不同年龄段，不同时段订单占比--------------------

--不同年龄段的订单统计
select 
'2020-04-12',
 age_range,
 count(*)
from dw_didi.t_user_order_wide
where dt='2020-04-12'
group by age_range

--不同时段的订单统计
select 
'2020-04-12',
 order_time_range,
 count(*)
from dw_didi.t_user_order_wide
where dt='2020-04-12'
group by order_time_range


--不同年龄段，不同时段的订单统计
select
   '2020-04-12',
    age_range,
    order_time_range,
    count(*) as order_cnt
from
    dw_didi.t_user_order_wide
where
    dt = '2020-04-12'
group by
    age_range,
    order_time_range
;

--创建APP表
create table if not exists app_didi.t_order_age_and_time_range_total(
    date_val string comment '日期',
    age_range string comment '年龄段',
    order_time_range string comment '时段',
    count int comment '订单数量'
)
partitioned by (month string comment '年月，yyyy-MM')
row format delimited fields terminated by ','
;

--加载数据到APP表
insert overwrite table app_didi.t_order_age_and_time_range_total partition(month = '2020-04')
select
      '2020-04-12',
      age_range,
     order_time_range,
    count(*) as order_cnt
from
    dw_didi.t_user_order_wide
where
    dt = '2020-04-12'
group by
    age_range,
    order_time_range
;



-------------6 不同职业订单统计top5-方式1
select

'2020-04-12',
 profession,
 count(orderid) as total_cnt
from 
dw_didi.t_user_order_wide
group by profession
order by total_cnt desc
limit 5

--不同职业订单统计top5-方式2
select * from
(
    select 
    *,
    dense_rank() over(order by total_cnt desc) as rk
    from 
    (
        select
        '2020-04-12',
        profession,
        count(orderid) as total_cnt
        from 
        dw_didi.t_user_order_wide
        group by profession
    )t
)tt
where rk <=5


--创建app表
create table if not exists app_didi.t_order_profession_total_topn( 
date_val string comment '日期', 
profession string comment '职业', 
Order_cnt int comment '订单数量', 
rk int comment '排名' 
) 
partitioned by (month string comment '年月，yyyy-MM') 
row format delimited fields terminated by ',' 

--给表加载数据
insert overwrite table app_didi.t_order_profession_total_topn partition(month = '2020-04')
select * from
(
    select 
    *,
    dense_rank() over(order by total_cnt desc) as rk
    from 
    (
        select
        '2020-04-12',
        profession,
        count(orderid) as total_cnt
        from 
        dw_didi.t_user_order_wide
        group by profession
    )t
)tt
where rk <=5



--------------7 求取消订单百分比
select
'2020-04-12' date_val
,
concat(round(t1.total_cnt/t2.total_cnt * 100,2),'%') as percent_val
from 
(select count(*) total_cnt from ods_didi.t_user_cancel_order where dt='2020-04-12')t1
,
(select count(*) total_cnt from dw_didi.t_user_order_wide where dt='2020-04-12')t2

--创建app表
create table if not exists app_didi.t_order_cancel_order_percent( 
date_val string comment '日期', 
cancel_order_percent string comment '百分比'
) 
partitioned by (month string comment '年月，yyyy-MM') 
row format delimited fields terminated by ',' 

--插入数据

insert overwrite table app_didi.t_order_cancel_order_percent partition(month = '2020-04')
select
'2020-04-12' date_val
,
concat(round(t1.total_cnt/t2.total_cnt * 100,2),'%') as percent_val
from 
(select count(*) total_cnt from ods_didi.t_user_cancel_order where dt='2020-04-12')t1
,
(select count(*) total_cnt from dw_didi.t_user_order_wide where dt='2020-04-12')t2




--6:Sqoop安装 
-- 准备工作

#验证sqoop是否工作
/export/server/sqoop-1.4.7/bin/sqoop list-databases \
--connect jdbc:mysql://192.168.88.100:3306/ \
--username root \
--password 123456 

--1:mysql创建目标数据库和目标表
    #创建目标数据库
    create database if not exists app_didi;
     
    #创建订单总笔数目标表
    create table if not exists app_didi.t_order_total(
        order_date date,
        count int
    );

 --2:导出订单总笔数表数据
    /export/server/sqoop-1.4.7/bin/sqoop export \
    --connect jdbc:mysql://192.168.88.100:3306/app_didi \
    --username root \
    --password 123456 \
    --table t_order_total \
    --export-dir /user/hive/warehouse/app_didi.db/t_order_total/month=2020-04

    ----------------------Hive指标分析操作-------------------
        select 
        '2020-04-12',
        subscribe_name,
        count(orderid)
        from dw_didi.t_user_order_wide
        group by  subscribe_name

    create table if not exists app_didi.t_order_subscribe_name_count( 
        date_val string comment '日期', 
        subscribe_name string comment '预约和非预约名字',
        total_cnt int comment '订单数'
    ) 
    partitioned by (month string comment '年月，yyyy-MM') 
    row format delimited fields terminated by ',' ;

    insert overwrite table app_didi.t_order_subscribe_name_count partition(month = '2020-04')
    select 
    '2020-04-12',
    subscribe_name,
    count(orderid)
    from dw_didi.t_user_order_wide
    group by  subscribe_name;

-----------------------MySQL数据库---------------
创建数据库：
create database app_didi


   --在mysql中创建目标表

    create table if not exists app_didi.t_order_subscribe_name_count( 
        date_val date comment '日期', 
        subscribe_name varchar(20) comment '预约和非预约名字',
        total_cnt varchar(20) comment '订单数'
    ) ;

   --sqoop导出
    /export/server/sqoop-1.4.7/bin/sqoop export \
    --connect jdbc:mysql://192.168.88.100:3306/app_didi \
    --username root \
    --password 123456 \
    --table t_order_subscribe_name_count \
    --export-dir /user/hive/warehouse/app_didi.db/t_order_subscribe_percent/month=2020-04


    #创建不同时段订单统计目标表
    --1:在mysql创建目标表
    create table if not exists app_didi.t_order_timerange_total(
        order_date date ,
        timerange varchar(20) ,
        count int 
    );


   --2：sqoop导出
    /export/server/sqoop-1.4.7/bin/sqoop export \
    --connect jdbc:mysql://192.168.88.100:3306/app_didi \
    --username root \
    --password 123456 \
    --table t_order_timerange_total \
    --export-dir /user/hive/warehouse/app_didi.db/t_order_timerange_total/month=2020-04




    #创建不同地域订单统计目标表
    --1:在mysql创建目标表
    create table if not exists app_didi.t_order_province_total(
     order_date date ,
     province varchar(20) ,
     city varchar(20),
     count int 
   );

   --2：sqoop导出
    /export/server/sqoop-1.4.7/bin/sqoop export \
    --connect jdbc:mysql://192.168.88.100:3306/app_didi \
    --username root \
    --password 123456 \
    --table t_order_province_total \
    --export-dir /user/hive/warehouse/app_didi.db/t_order_province_total/month=2020-04


   #创建不同年龄段，不同时段订单目标表
   --1: 在mysql创建目标表
    create table if not exists app_didi.t_order_age_and_time_range_total(
        order_date date ,
        age_range varchar(20) ,
        order_time_range varchar(20) ,
        count int 
    );
    --2:sqoop导出

    /export/server/sqoop-1.4.7/bin/sqoop export \
    --connect jdbc:mysql://192.168.88.100:3306/app_didi \
    --username root \
    --password 123456 \
    --table t_order_age_and_time_range_total \
    --export-dir /user/hive/warehouse/app_didi.db/t_order_agerange_timerange/month=2020-04



--Superset可视化

superset run -h 192.168.88.100 -p 8099 --with-threads --reload --debugger

mysql+pymysql://root:123456@192.168.88.100/app_didi?charset=utf8
