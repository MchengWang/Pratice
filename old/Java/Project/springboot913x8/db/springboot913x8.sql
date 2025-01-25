-- MySQL dump 10.13  Distrib 5.7.31, for Linux (x86_64)
--
-- Host: localhost    Database: springboot913x8
-- ------------------------------------------------------
-- Server version	5.7.31

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Current Database: `springboot913x8`
--

/*!40000 DROP DATABASE IF EXISTS `springboot913x8`*/;

CREATE DATABASE /*!32312 IF NOT EXISTS*/ `springboot913x8` /*!40100 DEFAULT CHARACTER SET utf8mb4 */;

USE `springboot913x8`;

--
-- Table structure for table `config`
--

DROP TABLE IF EXISTS `config`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `config` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '主键',
  `name` varchar(100) NOT NULL COMMENT '配置参数名称',
  `value` varchar(100) DEFAULT NULL COMMENT '配置参数值',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8 COMMENT='配置文件';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `config`
--

LOCK TABLES `config` WRITE;
/*!40000 ALTER TABLE `config` DISABLE KEYS */;
INSERT INTO `config` VALUES (1,'picture1','upload/picture1.jpg'),(2,'picture2','upload/picture2.jpg'),(3,'picture3','upload/picture3.jpg');
/*!40000 ALTER TABLE `config` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `dianfei`
--

DROP TABLE IF EXISTS `dianfei`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `dianfei` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '主键',
  `addtime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT '创建时间',
  `xuehao` varchar(200) DEFAULT NULL COMMENT '学号',
  `xueshengxingming` varchar(200) DEFAULT NULL COMMENT '学生姓名',
  `sushehao` varchar(200) DEFAULT NULL COMMENT '宿舍号',
  `suguanzhanghao` varchar(200) DEFAULT NULL COMMENT '宿管账号',
  `suguanxingming` varchar(200) DEFAULT NULL COMMENT '宿管姓名',
  `yongdianliang` int(11) DEFAULT NULL COMMENT '用电量',
  `danjia` double DEFAULT NULL COMMENT '单价',
  `feiyong` double DEFAULT NULL COMMENT '费用',
  `dengjiriqi` date DEFAULT NULL COMMENT '登记日期',
  `ispay` varchar(200) DEFAULT '未支付' COMMENT '是否支付',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=99 DEFAULT CHARSET=utf8 COMMENT='电费';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `dianfei`
--

LOCK TABLES `dianfei` WRITE;
/*!40000 ALTER TABLE `dianfei` DISABLE KEYS */;
INSERT INTO `dianfei` VALUES (91,'2030-05-30 12:23:59','学号1','学生姓名1','宿舍号1','宿管账号1','宿管姓名1',1,1,1,'2030-05-30','未支付'),(92,'2030-05-30 12:23:59','学号2','学生姓名2','宿舍号2','宿管账号2','宿管姓名2',2,2,2,'2030-05-30','未支付'),(93,'2030-05-30 12:23:59','学号3','学生姓名3','宿舍号3','宿管账号3','宿管姓名3',3,3,3,'2030-05-30','未支付'),(94,'2030-05-30 12:23:59','学号4','学生姓名4','宿舍号4','宿管账号4','宿管姓名4',4,4,4,'2030-05-30','未支付'),(95,'2030-05-30 12:23:59','学号5','学生姓名5','宿舍号5','宿管账号5','宿管姓名5',5,5,5,'2030-05-30','未支付'),(96,'2030-05-30 12:23:59','学号6','学生姓名6','宿舍号6','宿管账号6','宿管姓名6',6,6,6,'2030-05-30','未支付'),(97,'2030-05-30 12:23:59','学号7','学生姓名7','宿舍号7','宿管账号7','宿管姓名7',7,7,7,'2030-05-30','未支付'),(98,'2030-05-30 12:23:59','学号8','学生姓名8','宿舍号8','宿管账号8','宿管姓名8',8,8,8,'2030-05-30','未支付');
/*!40000 ALTER TABLE `dianfei` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `menjinxinxi`
--

DROP TABLE IF EXISTS `menjinxinxi`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `menjinxinxi` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '主键',
  `addtime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT '创建时间',
  `xuehao` varchar(200) DEFAULT NULL COMMENT '学号',
  `xueshengxingming` varchar(200) DEFAULT NULL COMMENT '学生姓名',
  `menjinkahao` varchar(200) DEFAULT NULL COMMENT '门禁卡号',
  `tongjileixing` varchar(200) DEFAULT NULL COMMENT '统计类型',
  `yuefen` varchar(200) DEFAULT NULL COMMENT '月份',
  `xueqi` varchar(200) DEFAULT NULL COMMENT '学期',
  `jinchucishu` varchar(200) DEFAULT NULL COMMENT '进出次数',
  `beizhu` varchar(200) DEFAULT NULL COMMENT '备注',
  `suguanzhanghao` varchar(200) DEFAULT NULL COMMENT '宿管账号',
  `suguanxingming` varchar(200) DEFAULT NULL COMMENT '宿管姓名',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=79 DEFAULT CHARSET=utf8 COMMENT='门禁信息';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `menjinxinxi`
--

LOCK TABLES `menjinxinxi` WRITE;
/*!40000 ALTER TABLE `menjinxinxi` DISABLE KEYS */;
INSERT INTO `menjinxinxi` VALUES (71,'2030-05-30 12:23:59','学号1','学生姓名1','门禁卡号1','月份','月份1','学期1','进出次数1','备注1','宿舍管理员','宿管姓名1'),(72,'2030-05-30 12:23:59','学号2','学生姓名2','门禁卡号2','月份','月份2','学期2','进出次数2','备注2','宿舍管理员','宿管姓名2'),(73,'2030-05-30 12:23:59','学号3','学生姓名3','门禁卡号3','月份','月份3','学期3','进出次数3','备注3','宿舍管理员','宿管姓名3'),(74,'2030-05-30 12:23:59','学号4','学生姓名4','门禁卡号4','月份','月份4','学期4','进出次数4','备注4','宿舍管理员','宿管姓名4'),(75,'2030-05-30 12:23:59','学号5','学生姓名5','门禁卡号5','月份','月份5','学期5','进出次数5','备注5','宿舍管理员','宿管姓名5'),(76,'2030-05-30 12:23:59','学号6','学生姓名6','门禁卡号6','月份','月份6','学期6','进出次数6','备注6','宿舍管理员','宿管姓名6'),(77,'2030-05-30 12:23:59','学号7','学生姓名7','门禁卡号7','月份','月份7','学期7','进出次数7','备注7','宿舍管理员','宿管姓名7'),(78,'2030-05-30 12:23:59','学号8','学生姓名8','门禁卡号8','月份','月份8','学期8','进出次数8','备注8','宿舍管理员','宿管姓名8');
/*!40000 ALTER TABLE `menjinxinxi` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `shuifei`
--

DROP TABLE IF EXISTS `shuifei`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `shuifei` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '主键',
  `addtime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT '创建时间',
  `xuehao` varchar(200) DEFAULT NULL COMMENT '学号',
  `xueshengxingming` varchar(200) DEFAULT NULL COMMENT '学生姓名',
  `sushehao` varchar(200) DEFAULT NULL COMMENT '宿舍号',
  `suguanzhanghao` varchar(200) DEFAULT NULL COMMENT '宿管账号',
  `suguanxingming` varchar(200) DEFAULT NULL COMMENT '宿管姓名',
  `yongshuiliang` int(11) DEFAULT NULL COMMENT '用水量',
  `danjia` double DEFAULT NULL COMMENT '单价',
  `feiyong` double DEFAULT NULL COMMENT '费用',
  `dengjiriqi` date DEFAULT NULL COMMENT '登记日期',
  `ispay` varchar(200) DEFAULT '未支付' COMMENT '是否支付',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=89 DEFAULT CHARSET=utf8 COMMENT='水费';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `shuifei`
--

LOCK TABLES `shuifei` WRITE;
/*!40000 ALTER TABLE `shuifei` DISABLE KEYS */;
INSERT INTO `shuifei` VALUES (81,'2030-05-30 12:23:59','学号1','学生姓名1','宿舍号1','宿管账号1','宿管姓名1',1,1,1,'2030-05-30','未支付'),(82,'2030-05-30 12:23:59','学号2','学生姓名2','宿舍号2','宿管账号2','宿管姓名2',2,2,2,'2030-05-30','未支付'),(83,'2030-05-30 12:23:59','学号3','学生姓名3','宿舍号3','宿管账号3','宿管姓名3',3,3,3,'2030-05-30','未支付'),(84,'2030-05-30 12:23:59','学号4','学生姓名4','宿舍号4','宿管账号4','宿管姓名4',4,4,4,'2030-05-30','未支付'),(85,'2030-05-30 12:23:59','学号5','学生姓名5','宿舍号5','宿管账号5','宿管姓名5',5,5,5,'2030-05-30','未支付'),(86,'2030-05-30 12:23:59','学号6','学生姓名6','宿舍号6','宿管账号6','宿管姓名6',6,6,6,'2030-05-30','未支付'),(87,'2030-05-30 12:23:59','学号7','学生姓名7','宿舍号7','宿管账号7','宿管姓名7',7,7,7,'2030-05-30','未支付'),(88,'2030-05-30 12:23:59','学号8','学生姓名8','宿舍号8','宿管账号8','宿管姓名8',8,8,8,'2030-05-30','未支付');
/*!40000 ALTER TABLE `shuifei` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `susheanpai`
--

DROP TABLE IF EXISTS `susheanpai`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `susheanpai` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '主键',
  `addtime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT '创建时间',
  `xuehao` varchar(200) NOT NULL COMMENT '学号',
  `xueshengxingming` varchar(200) DEFAULT NULL COMMENT '学生姓名',
  `zhuanye` varchar(200) DEFAULT NULL COMMENT '专业',
  `menjinkahao` varchar(200) DEFAULT NULL COMMENT '门禁卡号',
  `sushehao` varchar(200) DEFAULT NULL COMMENT '宿舍号',
  `susheleixing` varchar(200) DEFAULT NULL COMMENT '宿舍类型',
  `louceng` varchar(200) DEFAULT NULL COMMENT '楼层',
  `weizhi` varchar(200) DEFAULT NULL COMMENT '位置',
  `chuangwei` varchar(200) DEFAULT NULL COMMENT '床位',
  `suguanzhanghao` varchar(200) DEFAULT NULL COMMENT '宿管账号',
  `suguanxingming` varchar(200) DEFAULT NULL COMMENT '宿管姓名',
  PRIMARY KEY (`id`),
  UNIQUE KEY `xuehao` (`xuehao`)
) ENGINE=InnoDB AUTO_INCREMENT=49 DEFAULT CHARSET=utf8 COMMENT='宿舍安排';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `susheanpai`
--

LOCK TABLES `susheanpai` WRITE;
/*!40000 ALTER TABLE `susheanpai` DISABLE KEYS */;
INSERT INTO `susheanpai` VALUES (41,'2030-05-30 12:23:59','学号1','学生姓名1','专业1','门禁卡号1','宿舍号1','宿舍类型1','楼层1','位置1','床位1','宿管账号1','宿管姓名1'),(42,'2030-05-30 12:23:59','学号2','学生姓名2','专业2','门禁卡号2','宿舍号2','宿舍类型2','楼层2','位置2','床位2','宿管账号2','宿管姓名2'),(43,'2030-05-30 12:23:59','学号3','学生姓名3','专业3','门禁卡号3','宿舍号3','宿舍类型3','楼层3','位置3','床位3','宿管账号3','宿管姓名3'),(44,'2030-05-30 12:23:59','学号4','学生姓名4','专业4','门禁卡号4','宿舍号4','宿舍类型4','楼层4','位置4','床位4','宿管账号4','宿管姓名4'),(45,'2030-05-30 12:23:59','学号5','学生姓名5','专业5','门禁卡号5','宿舍号5','宿舍类型5','楼层5','位置5','床位5','宿管账号5','宿管姓名5'),(46,'2030-05-30 12:23:59','学号6','学生姓名6','专业6','门禁卡号6','宿舍号6','宿舍类型6','楼层6','位置6','床位6','宿管账号6','宿管姓名6'),(47,'2030-05-30 12:23:59','学号7','学生姓名7','专业7','门禁卡号7','宿舍号7','宿舍类型7','楼层7','位置7','床位7','宿管账号7','宿管姓名7'),(48,'2030-05-30 12:23:59','学号8','学生姓名8','专业8','门禁卡号8','宿舍号8','宿舍类型8','楼层8','位置8','床位8','宿管账号8','宿管姓名8');
/*!40000 ALTER TABLE `susheanpai` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `susheguanliyuan`
--

DROP TABLE IF EXISTS `susheguanliyuan`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `susheguanliyuan` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '主键',
  `addtime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT '创建时间',
  `suguanzhanghao` varchar(200) NOT NULL COMMENT '宿管账号',
  `mima` varchar(200) NOT NULL COMMENT '密码',
  `suguanxingming` varchar(200) DEFAULT NULL COMMENT '宿管姓名',
  `xingbie` varchar(200) DEFAULT NULL COMMENT '性别',
  `suguanshouji` varchar(200) DEFAULT NULL COMMENT '宿管手机',
  `zhaopian` longtext COMMENT '照片',
  `shenfenzheng` varchar(200) DEFAULT NULL COMMENT '身份证',
  PRIMARY KEY (`id`),
  UNIQUE KEY `suguanzhanghao` (`suguanzhanghao`)
) ENGINE=InnoDB AUTO_INCREMENT=29 DEFAULT CHARSET=utf8 COMMENT='宿舍管理员';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `susheguanliyuan`
--

LOCK TABLES `susheguanliyuan` WRITE;
/*!40000 ALTER TABLE `susheguanliyuan` DISABLE KEYS */;
INSERT INTO `susheguanliyuan` VALUES (21,'2030-05-30 12:23:59','宿管账号1','123456','宿管姓名1','男','13823888881','upload/susheguanliyuan_zhaopian1.jpg','440300199101010001'),(22,'2030-05-30 12:23:59','宿管账号2','123456','宿管姓名2','男','13823888882','upload/susheguanliyuan_zhaopian2.jpg','440300199202020002'),(23,'2030-05-30 12:23:59','宿管账号3','123456','宿管姓名3','男','13823888883','upload/susheguanliyuan_zhaopian3.jpg','440300199303030003'),(24,'2030-05-30 12:23:59','宿管账号4','123456','宿管姓名4','男','13823888884','upload/susheguanliyuan_zhaopian4.jpg','440300199404040004'),(25,'2030-05-30 12:23:59','宿管账号5','123456','宿管姓名5','男','13823888885','upload/susheguanliyuan_zhaopian5.jpg','440300199505050005'),(26,'2030-05-30 12:23:59','宿管账号6','123456','宿管姓名6','男','13823888886','upload/susheguanliyuan_zhaopian6.jpg','440300199606060006'),(27,'2030-05-30 12:23:59','宿管账号7','123456','宿管姓名7','男','13823888887','upload/susheguanliyuan_zhaopian7.jpg','440300199707070007'),(28,'2030-05-30 12:23:59','宿管账号8','123456','宿管姓名8','男','13823888888','upload/susheguanliyuan_zhaopian8.jpg','440300199808080008');
/*!40000 ALTER TABLE `susheguanliyuan` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `sushexinxi`
--

DROP TABLE IF EXISTS `sushexinxi`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `sushexinxi` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '主键',
  `addtime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT '创建时间',
  `sushehao` varchar(200) DEFAULT NULL COMMENT '宿舍号',
  `susheleixing` varchar(200) DEFAULT NULL COMMENT '宿舍类型',
  `tupian` longtext COMMENT '图片',
  `louceng` varchar(200) DEFAULT NULL COMMENT '楼层',
  `weizhi` varchar(200) DEFAULT NULL COMMENT '位置',
  `kezhurenshu` varchar(200) DEFAULT NULL COMMENT '可住人数',
  `beizhu` varchar(200) DEFAULT NULL COMMENT '备注',
  `suguanzhanghao` varchar(200) DEFAULT NULL COMMENT '宿管账号',
  `suguanxingming` varchar(200) DEFAULT NULL COMMENT '宿管姓名',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=39 DEFAULT CHARSET=utf8 COMMENT='宿舍信息';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `sushexinxi`
--

LOCK TABLES `sushexinxi` WRITE;
/*!40000 ALTER TABLE `sushexinxi` DISABLE KEYS */;
INSERT INTO `sushexinxi` VALUES (31,'2030-05-30 12:23:59','宿舍号1','六人间','upload/sushexinxi_tupian1.jpg,upload/sushexinxi_tupian2.jpg,upload/sushexinxi_tupian3.jpg','10','A公寓','10','备注1','宿管账号1','宿管姓名1'),(32,'2030-05-30 12:23:59','宿舍号2','六人间','upload/sushexinxi_tupian2.jpg,upload/sushexinxi_tupian3.jpg,upload/sushexinxi_tupian4.jpg','10','A公寓','10','备注2','宿管账号2','宿管姓名2'),(33,'2030-05-30 12:23:59','宿舍号3','六人间','upload/sushexinxi_tupian3.jpg,upload/sushexinxi_tupian4.jpg,upload/sushexinxi_tupian5.jpg','10','A公寓','10','备注3','宿管账号3','宿管姓名3'),(34,'2030-05-30 12:23:59','宿舍号4','六人间','upload/sushexinxi_tupian4.jpg,upload/sushexinxi_tupian5.jpg,upload/sushexinxi_tupian6.jpg','10','A公寓','10','备注4','宿管账号4','宿管姓名4'),(35,'2030-05-30 12:23:59','宿舍号5','六人间','upload/sushexinxi_tupian5.jpg,upload/sushexinxi_tupian6.jpg,upload/sushexinxi_tupian7.jpg','10','A公寓','10','备注5','宿管账号5','宿管姓名5'),(36,'2030-05-30 12:23:59','宿舍号6','六人间','upload/sushexinxi_tupian6.jpg,upload/sushexinxi_tupian7.jpg,upload/sushexinxi_tupian8.jpg','10','A公寓','10','备注6','宿管账号6','宿管姓名6'),(37,'2030-05-30 12:23:59','宿舍号7','六人间','upload/sushexinxi_tupian7.jpg,upload/sushexinxi_tupian8.jpg,upload/sushexinxi_tupian9.jpg','10','A公寓','10','备注7','宿管账号7','宿管姓名7'),(38,'2030-05-30 12:23:59','宿舍号8','六人间','upload/sushexinxi_tupian8.jpg,upload/sushexinxi_tupian9.jpg,upload/sushexinxi_tupian10.jpg','10','A公寓','10','备注8','宿管账号8','宿管姓名8');
/*!40000 ALTER TABLE `sushexinxi` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `token`
--

DROP TABLE IF EXISTS `token`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `token` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '主键',
  `userid` bigint(20) NOT NULL COMMENT '用户id',
  `username` varchar(100) NOT NULL COMMENT '用户名',
  `tablename` varchar(100) DEFAULT NULL COMMENT '表名',
  `role` varchar(100) DEFAULT NULL COMMENT '角色',
  `token` varchar(200) NOT NULL COMMENT '密码',
  `addtime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT '新增时间',
  `expiratedtime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT '过期时间',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8 COMMENT='token表';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `token`
--

LOCK TABLES `token` WRITE;
/*!40000 ALTER TABLE `token` DISABLE KEYS */;
INSERT INTO `token` VALUES (1,1,'admin','users','管理员','y8b9ys799vg9d7l1aqm8qhec9wmixyyn','2030-05-30 12:26:43','2030-05-30 13:26:43'),(2,28,'宿管账号8','susheguanliyuan','宿舍管理员','tnchx35bqz3pcjqsbdavs3fzdd2ropvs','2030-05-30 12:26:46','2030-05-30 13:26:47');
/*!40000 ALTER TABLE `token` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `users`
--

DROP TABLE IF EXISTS `users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `users` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '主键',
  `username` varchar(100) NOT NULL COMMENT '用户名',
  `password` varchar(100) NOT NULL COMMENT '密码',
  `role` varchar(100) DEFAULT '管理员' COMMENT '角色',
  `addtime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT '新增时间',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 COMMENT='用户表';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `users`
--

LOCK TABLES `users` WRITE;
/*!40000 ALTER TABLE `users` DISABLE KEYS */;
INSERT INTO `users` VALUES (1,'admin','admin','管理员','2030-05-30 12:24:00');
/*!40000 ALTER TABLE `users` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `weishengtongji`
--

DROP TABLE IF EXISTS `weishengtongji`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `weishengtongji` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '主键',
  `addtime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT '创建时间',
  `tongjibianhao` varchar(200) DEFAULT NULL COMMENT '统计编号',
  `tongjileixing` varchar(200) DEFAULT NULL COMMENT '统计类型',
  `xueqi` varchar(200) DEFAULT NULL COMMENT '学期',
  `yuefen` varchar(200) DEFAULT NULL COMMENT '月份',
  `sushehao` varchar(200) DEFAULT NULL COMMENT '宿舍号',
  `susheleixing` varchar(200) DEFAULT NULL COMMENT '宿舍类型',
  `qingsaocishu` varchar(200) DEFAULT NULL COMMENT '清扫次数',
  `sushepaiming` varchar(200) DEFAULT NULL COMMENT '宿舍排名',
  `dengjiriqi` date DEFAULT NULL COMMENT '登记日期',
  `suguanzhanghao` varchar(200) DEFAULT NULL COMMENT '宿管账号',
  `suguanxingming` varchar(200) DEFAULT NULL COMMENT '宿管姓名',
  PRIMARY KEY (`id`),
  UNIQUE KEY `tongjibianhao` (`tongjibianhao`)
) ENGINE=InnoDB AUTO_INCREMENT=69 DEFAULT CHARSET=utf8 COMMENT='卫生统计';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `weishengtongji`
--

LOCK TABLES `weishengtongji` WRITE;
/*!40000 ALTER TABLE `weishengtongji` DISABLE KEYS */;
INSERT INTO `weishengtongji` VALUES (61,'2030-05-30 12:23:59','1111111111','学期','学期1','月份1','宿舍号1','宿舍类型1','清扫次数1','宿舍排名1','2030-05-30','宿管账号1','宿管姓名1'),(62,'2030-05-30 12:23:59','2222222222','学期','学期2','月份2','宿舍号2','宿舍类型2','清扫次数2','宿舍排名2','2030-05-30','宿管账号2','宿管姓名2'),(63,'2030-05-30 12:23:59','3333333333','学期','学期3','月份3','宿舍号3','宿舍类型3','清扫次数3','宿舍排名3','2030-05-30','宿管账号3','宿管姓名3'),(64,'2030-05-30 12:23:59','4444444444','学期','学期4','月份4','宿舍号4','宿舍类型4','清扫次数4','宿舍排名4','2030-05-30','宿管账号4','宿管姓名4'),(65,'2030-05-30 12:23:59','5555555555','学期','学期5','月份5','宿舍号5','宿舍类型5','清扫次数5','宿舍排名5','2030-05-30','宿管账号5','宿管姓名5'),(66,'2030-05-30 12:23:59','6666666666','学期','学期6','月份6','宿舍号6','宿舍类型6','清扫次数6','宿舍排名6','2030-05-30','宿管账号6','宿管姓名6'),(67,'2030-05-30 12:23:59','7777777777','学期','学期7','月份7','宿舍号7','宿舍类型7','清扫次数7','宿舍排名7','2030-05-30','宿管账号7','宿管姓名7'),(68,'2030-05-30 12:23:59','8888888888','学期','学期8','月份8','宿舍号8','宿舍类型8','清扫次数8','宿舍排名8','2030-05-30','宿管账号8','宿管姓名8');
/*!40000 ALTER TABLE `weishengtongji` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `weishengxinxi`
--

DROP TABLE IF EXISTS `weishengxinxi`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `weishengxinxi` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '主键',
  `addtime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT '创建时间',
  `xuehao` varchar(200) DEFAULT NULL COMMENT '学号',
  `xueshengxingming` varchar(200) DEFAULT NULL COMMENT '学生姓名',
  `sushehao` varchar(200) DEFAULT NULL COMMENT '宿舍号',
  `susheleixing` varchar(200) DEFAULT NULL COMMENT '宿舍类型',
  `zhuangtai` varchar(200) DEFAULT NULL COMMENT '状态',
  `qingsaoshijian` datetime DEFAULT NULL COMMENT '清扫时间',
  `dengjishijian` datetime DEFAULT NULL COMMENT '登记时间',
  `suguanzhanghao` varchar(200) DEFAULT NULL COMMENT '宿管账号',
  `suguanxingming` varchar(200) DEFAULT NULL COMMENT '宿管姓名',
  `beizhu` varchar(200) DEFAULT NULL COMMENT '备注',
  `sfsh` varchar(200) DEFAULT '待审核' COMMENT '是否审核',
  `shhf` longtext COMMENT '审核回复',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=59 DEFAULT CHARSET=utf8 COMMENT='卫生信息';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `weishengxinxi`
--

LOCK TABLES `weishengxinxi` WRITE;
/*!40000 ALTER TABLE `weishengxinxi` DISABLE KEYS */;
INSERT INTO `weishengxinxi` VALUES (51,'2030-05-30 12:23:59','学号1','学生姓名1','宿舍号1','宿舍类型1','状态1','2030-05-30 20:23:59','2030-05-30 20:23:59','宿管账号1','宿管姓名1','备注1','是',''),(52,'2030-05-30 12:23:59','学号2','学生姓名2','宿舍号2','宿舍类型2','状态2','2030-05-30 20:23:59','2030-05-30 20:23:59','宿管账号2','宿管姓名2','备注2','是',''),(53,'2030-05-30 12:23:59','学号3','学生姓名3','宿舍号3','宿舍类型3','状态3','2030-05-30 20:23:59','2030-05-30 20:23:59','宿管账号3','宿管姓名3','备注3','是',''),(54,'2030-05-30 12:23:59','学号4','学生姓名4','宿舍号4','宿舍类型4','状态4','2030-05-30 20:23:59','2030-05-30 20:23:59','宿管账号4','宿管姓名4','备注4','是',''),(55,'2030-05-30 12:23:59','学号5','学生姓名5','宿舍号5','宿舍类型5','状态5','2030-05-30 20:23:59','2030-05-30 20:23:59','宿管账号5','宿管姓名5','备注5','是',''),(56,'2030-05-30 12:23:59','学号6','学生姓名6','宿舍号6','宿舍类型6','状态6','2030-05-30 20:23:59','2030-05-30 20:23:59','宿管账号6','宿管姓名6','备注6','是',''),(57,'2030-05-30 12:23:59','学号7','学生姓名7','宿舍号7','宿舍类型7','状态7','2030-05-30 20:23:59','2030-05-30 20:23:59','宿管账号7','宿管姓名7','备注7','是',''),(58,'2030-05-30 12:23:59','学号8','学生姓名8','宿舍号8','宿舍类型8','状态8','2030-05-30 20:23:59','2030-05-30 20:23:59','宿管账号8','宿管姓名8','备注8','是','');
/*!40000 ALTER TABLE `weishengxinxi` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `weixiu`
--

DROP TABLE IF EXISTS `weixiu`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `weixiu` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '主键',
  `addtime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT '创建时间',
  `xueshengxingming` varchar(200) DEFAULT NULL COMMENT '学生姓名',
  `xuehao` varchar(200) DEFAULT NULL COMMENT '学号',
  `sushehao` varchar(200) DEFAULT NULL COMMENT '宿舍号',
  `suguanzhanghao` varchar(200) DEFAULT NULL COMMENT '宿管账号',
  `suguanxingming` varchar(200) DEFAULT NULL COMMENT '宿管姓名',
  `weixiuxuqiu` varchar(200) DEFAULT NULL COMMENT '维修需求',
  `sheshitupian` longtext COMMENT '设施图片',
  `sheshiweixiuyuanyin` longtext COMMENT '设施维修原因',
  `shenqingweixiushijian` datetime DEFAULT NULL COMMENT '申请维修时间',
  `weixiuzhuangtai` varchar(200) NOT NULL COMMENT '维修状态',
  `sfsh` varchar(200) DEFAULT '待审核' COMMENT '是否审核',
  `shhf` longtext COMMENT '审核回复',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=109 DEFAULT CHARSET=utf8 COMMENT='维修';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `weixiu`
--

LOCK TABLES `weixiu` WRITE;
/*!40000 ALTER TABLE `weixiu` DISABLE KEYS */;
INSERT INTO `weixiu` VALUES (101,'2030-05-30 12:23:59','学生姓名1','学号1','宿舍号1','宿管账号1','宿管姓名1','维修需求1','upload/weixiu_sheshitupian1.jpg,upload/weixiu_sheshitupian2.jpg,upload/weixiu_sheshitupian3.jpg','设施维修原因1','2030-05-30 20:23:59','已维修','是',''),(102,'2030-05-30 12:23:59','学生姓名2','学号2','宿舍号2','宿管账号2','宿管姓名2','维修需求2','upload/weixiu_sheshitupian2.jpg,upload/weixiu_sheshitupian3.jpg,upload/weixiu_sheshitupian4.jpg','设施维修原因2','2030-05-30 20:23:59','已维修','是',''),(103,'2030-05-30 12:23:59','学生姓名3','学号3','宿舍号3','宿管账号3','宿管姓名3','维修需求3','upload/weixiu_sheshitupian3.jpg,upload/weixiu_sheshitupian4.jpg,upload/weixiu_sheshitupian5.jpg','设施维修原因3','2030-05-30 20:23:59','已维修','是',''),(104,'2030-05-30 12:23:59','学生姓名4','学号4','宿舍号4','宿管账号4','宿管姓名4','维修需求4','upload/weixiu_sheshitupian4.jpg,upload/weixiu_sheshitupian5.jpg,upload/weixiu_sheshitupian6.jpg','设施维修原因4','2030-05-30 20:23:59','已维修','是',''),(105,'2030-05-30 12:23:59','学生姓名5','学号5','宿舍号5','宿管账号5','宿管姓名5','维修需求5','upload/weixiu_sheshitupian5.jpg,upload/weixiu_sheshitupian6.jpg,upload/weixiu_sheshitupian7.jpg','设施维修原因5','2030-05-30 20:23:59','已维修','是',''),(106,'2030-05-30 12:23:59','学生姓名6','学号6','宿舍号6','宿管账号6','宿管姓名6','维修需求6','upload/weixiu_sheshitupian6.jpg,upload/weixiu_sheshitupian7.jpg,upload/weixiu_sheshitupian8.jpg','设施维修原因6','2030-05-30 20:23:59','已维修','是',''),(107,'2030-05-30 12:23:59','学生姓名7','学号7','宿舍号7','宿管账号7','宿管姓名7','维修需求7','upload/weixiu_sheshitupian7.jpg,upload/weixiu_sheshitupian8.jpg,upload/weixiu_sheshitupian9.jpg','设施维修原因7','2030-05-30 20:23:59','已维修','是',''),(108,'2030-05-30 12:23:59','学生姓名8','学号8','宿舍号8','宿管账号8','宿管姓名8','维修需求8','upload/weixiu_sheshitupian8.jpg,upload/weixiu_sheshitupian9.jpg,upload/weixiu_sheshitupian10.jpg','设施维修原因8','2030-05-30 20:23:59','已维修','是','');
/*!40000 ALTER TABLE `weixiu` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `xuesheng`
--

DROP TABLE IF EXISTS `xuesheng`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `xuesheng` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '主键',
  `addtime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT '创建时间',
  `xuehao` varchar(200) NOT NULL COMMENT '学号',
  `mima` varchar(200) NOT NULL COMMENT '密码',
  `xueshengxingming` varchar(200) DEFAULT NULL COMMENT '学生姓名',
  `xingbie` varchar(200) DEFAULT NULL COMMENT '性别',
  `touxiang` longtext COMMENT '头像',
  `xueshengshouji` varchar(200) DEFAULT NULL COMMENT '学生手机',
  `zhuanye` varchar(200) DEFAULT NULL COMMENT '专业',
  `nianling` int(11) DEFAULT NULL COMMENT '年龄',
  `menjinkahao` varchar(200) DEFAULT NULL COMMENT '门禁卡号',
  PRIMARY KEY (`id`),
  UNIQUE KEY `xuehao` (`xuehao`)
) ENGINE=InnoDB AUTO_INCREMENT=19 DEFAULT CHARSET=utf8 COMMENT='学生';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `xuesheng`
--

LOCK TABLES `xuesheng` WRITE;
/*!40000 ALTER TABLE `xuesheng` DISABLE KEYS */;
INSERT INTO `xuesheng` VALUES (11,'2030-05-30 12:23:59','学号1','123456','学生姓名1','男','upload/xuesheng_touxiang1.jpg','13823888881','专业1',1,'门禁卡号1'),(12,'2030-05-30 12:23:59','学号2','123456','学生姓名2','男','upload/xuesheng_touxiang2.jpg','13823888882','专业2',2,'门禁卡号2'),(13,'2030-05-30 12:23:59','学号3','123456','学生姓名3','男','upload/xuesheng_touxiang3.jpg','13823888883','专业3',3,'门禁卡号3'),(14,'2030-05-30 12:23:59','学号4','123456','学生姓名4','男','upload/xuesheng_touxiang4.jpg','13823888884','专业4',4,'门禁卡号4'),(15,'2030-05-30 12:23:59','学号5','123456','学生姓名5','男','upload/xuesheng_touxiang5.jpg','13823888885','专业5',5,'门禁卡号5'),(16,'2030-05-30 12:23:59','学号6','123456','学生姓名6','男','upload/xuesheng_touxiang6.jpg','13823888886','专业6',6,'门禁卡号6'),(17,'2030-05-30 12:23:59','学号7','123456','学生姓名7','男','upload/xuesheng_touxiang7.jpg','13823888887','专业7',7,'门禁卡号7'),(18,'2030-05-30 12:23:59','学号8','123456','学生姓名8','男','upload/xuesheng_touxiang8.jpg','13823888888','专业8',8,'门禁卡号8');
/*!40000 ALTER TABLE `xuesheng` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2030-05-31 13:03:55
