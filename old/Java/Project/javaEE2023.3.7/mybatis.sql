/*
SQLyog Ultimate v8.32 
MySQL - 5.5.27 : Database - mytest1
*********************************************************************
*/

/*!40101 SET NAMES utf8 */;

/*!40101 SET SQL_MODE=''*/;

/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;
CREATE DATABASE /*!32312 IF NOT EXISTS*/`mytest1` /*!40100 DEFAULT CHARACTER SET utf8 */;

USE `mytest1`;

/*Table structure for table `book` */

DROP TABLE IF EXISTS `book`;

CREATE TABLE `book` (
  `bid` int(11) NOT NULL AUTO_INCREMENT,
  `bname` varchar(50) NOT NULL,
  `btype` int(11) DEFAULT NULL,
  `price` double DEFAULT '0',
  `bdesc` varchar(200) DEFAULT NULL,
  PRIMARY KEY (`bid`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;

/*Data for the table `book` */

insert  into `book`(`bid`,`bname`,`btype`,`price`,`bdesc`) values (1,'java',1,33.2,'java primer'),(2,'基础java教程',1,23.6,'c++ 入门教程'),(3,'邓小平理论',4,300,'将价了，都买吧！'),(4,'马克思主义',2,100,'思想教育');

/*Table structure for table `classinfo` */

DROP TABLE IF EXISTS `classinfo`;

CREATE TABLE `classinfo` (
  `cid` int(11) NOT NULL AUTO_INCREMENT,
  `cname` varchar(200) NOT NULL,
  PRIMARY KEY (`cid`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

/*Data for the table `classinfo` */

insert  into `classinfo`(`cid`,`cname`) values (1,'软件工程1班'),(2,'软件工程2班');

/*Table structure for table `studentinfo` */

DROP TABLE IF EXISTS `studentinfo`;

CREATE TABLE `studentinfo` (
  `sid` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(200) NOT NULL,
  `gender` varchar(10) DEFAULT NULL,
  `address` varchar(200) DEFAULT NULL,
  `cid` int(11) NOT NULL,
  PRIMARY KEY (`sid`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8;

/*Data for the table `studentinfo` */

insert  into `studentinfo`(`sid`,`name`,`gender`,`address`,`cid`) values (1,'张三','男','河南',1),(2,'李四','男','河北',1),(3,'王五','女','上海',2),(4,'赵四','女','北京',2),(5,'周六','男','天津',1);

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
