/*
SQLyog Ultimate v8.32 
MySQL - 5.5.27 : Database - db20211213
*********************************************************************
*/

/*!40101 SET NAMES utf8 */;

/*!40101 SET SQL_MODE=''*/;

/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;
CREATE DATABASE /*!32312 IF NOT EXISTS*/`db20211213` /*!40100 DEFAULT CHARACTER SET utf8 */;

USE `db20211213`;

/*Table structure for table `t_customer` */

DROP TABLE IF EXISTS `t_customer`;

CREATE TABLE `t_customer` (
  `id` int(11) NOT NULL AUTO_INCREMENT COMMENT '编号',
  `username` varchar(20) COLLATE utf8_unicode_ci DEFAULT NULL COMMENT '用户名',
  `jobs` varchar(30) COLLATE utf8_unicode_ci DEFAULT NULL COMMENT '工作',
  `phone` varchar(11) COLLATE utf8_unicode_ci DEFAULT NULL COMMENT '电话',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

/*Data for the table `t_customer` */

insert  into `t_customer`(`id`,`username`,`jobs`,`phone`) values (1,'张三','教师','111');
insert  into `t_customer`(`id`,`username`,`jobs`,`phone`) values (2,'张力','学生','222');
insert  into `t_customer`(`id`,`username`,`jobs`,`phone`) values (3,'李四','学生','223');
insert  into `t_customer`(`id`,`username`,`jobs`,`phone`) values (4,'李兰兰','学生',NULL);

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
