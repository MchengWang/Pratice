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

insert  into `book`(`bid`,`bname`,`btype`,`price`,`bdesc`) values (1,'java',1,33.2,'java primer');
insert  into `book`(`bid`,`bname`,`btype`,`price`,`bdesc`) values (2,'基础java教程',1,23.6,'c++ 入门教程');
insert  into `book`(`bid`,`bname`,`btype`,`price`,`bdesc`) values (3,'邓小平理论',4,300,'将价了，都买吧！');
insert  into `book`(`bid`,`bname`,`btype`,`price`,`bdesc`) values (4,'马克思主义',2,100,'思想教育');

/*Table structure for table `classinfo` */

DROP TABLE IF EXISTS `classinfo`;

CREATE TABLE `classinfo` (
  `cid` int(11) NOT NULL AUTO_INCREMENT,
  `cname` varchar(200) NOT NULL,
  PRIMARY KEY (`cid`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

/*Data for the table `classinfo` */

insert  into `classinfo`(`cid`,`cname`) values (1,'软件工程1班');
insert  into `classinfo`(`cid`,`cname`) values (2,'软件工程2班');

/*Table structure for table `course` */

DROP TABLE IF EXISTS `course`;

CREATE TABLE `course` (
  `cid` int(11) NOT NULL AUTO_INCREMENT,
  `coursename` varchar(30) NOT NULL,
  `hours` int(11) NOT NULL DEFAULT '10',
  PRIMARY KEY (`cid`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;

/*Data for the table `course` */

insert  into `course`(`cid`,`coursename`,`hours`) values (1,'Java',10);
insert  into `course`(`cid`,`coursename`,`hours`) values (2,'C++',10);
insert  into `course`(`cid`,`coursename`,`hours`) values (3,'思想政治',10);
insert  into `course`(`cid`,`coursename`,`hours`) values (4,'高等数学',10);

/*Table structure for table `logininfo` */

DROP TABLE IF EXISTS `logininfo`;

CREATE TABLE `logininfo` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `username` varchar(50) NOT NULL,
  `password` varchar(50) NOT NULL,
  `uid` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8;

/*Data for the table `logininfo` */

insert  into `logininfo`(`id`,`username`,`password`,`uid`) values (1,'zsf','11111',1);
insert  into `logininfo`(`id`,`username`,`password`,`uid`) values (2,'ls','22222',2);
insert  into `logininfo`(`id`,`username`,`password`,`uid`) values (3,'wzt','33333',3);

/*Table structure for table `stu_course` */

DROP TABLE IF EXISTS `stu_course`;

CREATE TABLE `stu_course` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `sid` int(11) NOT NULL,
  `cid` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8;

/*Data for the table `stu_course` */

insert  into `stu_course`(`id`,`sid`,`cid`) values (1,1,1);
insert  into `stu_course`(`id`,`sid`,`cid`) values (2,1,2);
insert  into `stu_course`(`id`,`sid`,`cid`) values (3,1,4);
insert  into `stu_course`(`id`,`sid`,`cid`) values (4,2,1);
insert  into `stu_course`(`id`,`sid`,`cid`) values (5,2,3);
insert  into `stu_course`(`id`,`sid`,`cid`) values (6,2,4);
insert  into `stu_course`(`id`,`sid`,`cid`) values (7,3,4);
insert  into `stu_course`(`id`,`sid`,`cid`) values (8,3,1);

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

insert  into `studentinfo`(`sid`,`name`,`gender`,`address`,`cid`) values (1,'张三','男','河南',1);
insert  into `studentinfo`(`sid`,`name`,`gender`,`address`,`cid`) values (2,'李四','男','河北',1);
insert  into `studentinfo`(`sid`,`name`,`gender`,`address`,`cid`) values (3,'王五','女','上海',2);
insert  into `studentinfo`(`sid`,`name`,`gender`,`address`,`cid`) values (4,'赵四','女','北京',2);
insert  into `studentinfo`(`sid`,`name`,`gender`,`address`,`cid`) values (5,'周六','男','天津',1);

/*Table structure for table `userinfo` */

DROP TABLE IF EXISTS `userinfo`;

CREATE TABLE `userinfo` (
  `uid` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(50) NOT NULL,
  `gender` varchar(10) NOT NULL,
  `address` varchar(200) DEFAULT NULL,
  `tel` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`uid`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8;

/*Data for the table `userinfo` */

insert  into `userinfo`(`uid`,`name`,`gender`,`address`,`tel`) values (1,'张三丰','男','武当山','188888888');
insert  into `userinfo`(`uid`,`name`,`gender`,`address`,`tel`) values (2,'李斯','男','长安','199999999');
insert  into `userinfo`(`uid`,`name`,`gender`,`address`,`tel`) values (3,'武则天','女','洛阳','166666666');

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
