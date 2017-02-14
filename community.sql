/*
Navicat MySQL Data Transfer

Source Server         : ssh
Source Server Version : 50621
Source Host           : localhost:3306
Source Database       : community

Target Server Type    : MYSQL
Target Server Version : 50621
File Encoding         : 65001

Date: 2015-05-17 10:24:51
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for `activity_info`
-- ----------------------------
DROP TABLE IF EXISTS `activity_info`;
CREATE TABLE `activity_info` (
  `a_id` int(11) NOT NULL AUTO_INCREMENT,
  `a_name` char(40) NOT NULL,
  `a_address` char(100) DEFAULT NULL,
  `a_date` date DEFAULT NULL,
  `a_time` float DEFAULT NULL,
  `a_state` int(11) NOT NULL DEFAULT '0',
  `a_baoliu` char(255) DEFAULT NULL,
  PRIMARY KEY (`a_id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of activity_info
-- ----------------------------
INSERT INTO `activity_info` VALUES ('1', '天使之心', '湖北中医药大学南区', '2015-05-15', '3', '0', null);
INSERT INTO `activity_info` VALUES ('2', '心理健康', '操场', '2015-05-17', '3', '0', null);

-- ----------------------------
-- Table structure for `activity_list`
-- ----------------------------
DROP TABLE IF EXISTS `activity_list`;
CREATE TABLE `activity_list` (
  `a_id` int(11) NOT NULL,
  `c_id` int(11) NOT NULL,
  `m_id` int(11) NOT NULL,
  `al_baoliu` char(255) DEFAULT NULL,
  PRIMARY KEY (`a_id`,`c_id`,`m_id`),
  KEY `a_id` (`a_id`),
  KEY `cc_id` (`c_id`),
  KEY `mm_id` (`m_id`),
  CONSTRAINT `a_id` FOREIGN KEY (`a_id`) REFERENCES `activity_info` (`a_id`) ON UPDATE CASCADE,
  CONSTRAINT `cc_id` FOREIGN KEY (`c_id`) REFERENCES `community_info` (`c_id`) ON UPDATE CASCADE,
  CONSTRAINT `mm_id` FOREIGN KEY (`m_id`) REFERENCES `member_info` (`m_id`) ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of activity_list
-- ----------------------------
INSERT INTO `activity_list` VALUES ('1', '1', '1', null);
INSERT INTO `activity_list` VALUES ('1', '1', '2', null);
INSERT INTO `activity_list` VALUES ('2', '2', '2', null);

-- ----------------------------
-- Table structure for `community_info`
-- ----------------------------
DROP TABLE IF EXISTS `community_info`;
CREATE TABLE `community_info` (
  `c_id` int(11) NOT NULL AUTO_INCREMENT COMMENT '社团编号',
  `c_name` char(40) NOT NULL COMMENT '社团名称',
  `c_data` date DEFAULT NULL,
  `c_phone` char(15) DEFAULT NULL COMMENT '电话',
  `master_no` int(11) NOT NULL COMMENT '部长编号',
  `c_infomation` text,
  `c_baoliu` char(255) DEFAULT NULL,
  PRIMARY KEY (`c_id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of community_info
-- ----------------------------
INSERT INTO `community_info` VALUES ('1', '心理协会', '2015-01-01', '1234', '1', '健康心理', null);
INSERT INTO `community_info` VALUES ('2', '瑜伽协会', '2015-05-03', '98765', '2', '瑜伽', null);

-- ----------------------------
-- Table structure for `info_diffusion`
-- ----------------------------
DROP TABLE IF EXISTS `info_diffusion`;
CREATE TABLE `info_diffusion` (
  `i_id` int(11) NOT NULL AUTO_INCREMENT,
  `m_id` int(11) NOT NULL DEFAULT '0',
  `c_id` int(11) NOT NULL DEFAULT '0',
  `i_text` text,
  `i_date` date DEFAULT NULL,
  `i_baoliu` char(255) DEFAULT NULL,
  PRIMARY KEY (`i_id`),
  KEY `im_id` (`m_id`),
  KEY `ic_id` (`c_id`),
  CONSTRAINT `ic_id` FOREIGN KEY (`c_id`) REFERENCES `community_info` (`c_id`) ON UPDATE CASCADE,
  CONSTRAINT `im_id` FOREIGN KEY (`m_id`) REFERENCES `member_info` (`m_id`) ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of info_diffusion
-- ----------------------------
INSERT INTO `info_diffusion` VALUES ('1', '1', '1', '心理社长发布消息', '2015-05-15', null);
INSERT INTO `info_diffusion` VALUES ('2', '2', '2', '瑜伽协会发布消息', '2015-05-17', null);

-- ----------------------------
-- Table structure for `member_admin`
-- ----------------------------
DROP TABLE IF EXISTS `member_admin`;
CREATE TABLE `member_admin` (
  `m_id` int(11) NOT NULL COMMENT '会员编号',
  `c_id` int(11) NOT NULL COMMENT '社团编号',
  `mc_grant` int(11) NOT NULL DEFAULT '3' COMMENT '权限',
  `ma_baoliu` char(255) DEFAULT NULL,
  PRIMARY KEY (`m_id`,`c_id`),
  KEY `c_id` (`c_id`),
  CONSTRAINT `c_id` FOREIGN KEY (`c_id`) REFERENCES `community_info` (`c_id`) ON UPDATE CASCADE,
  CONSTRAINT `m_id` FOREIGN KEY (`m_id`) REFERENCES `member_info` (`m_id`) ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of member_admin
-- ----------------------------
INSERT INTO `member_admin` VALUES ('1', '1', '1', null);
INSERT INTO `member_admin` VALUES ('2', '2', '1', null);

-- ----------------------------
-- Table structure for `member_info`
-- ----------------------------
DROP TABLE IF EXISTS `member_info`;
CREATE TABLE `member_info` (
  `m_id` int(11) NOT NULL AUTO_INCREMENT COMMENT '会员编号',
  `m_name` char(40) DEFAULT NULL COMMENT '姓名',
  `m_sno` char(20) DEFAULT NULL COMMENT '学号',
  `m_sex` char(4) DEFAULT NULL COMMENT '性别',
  `m_phone` char(15) DEFAULT NULL COMMENT '电话',
  `password` char(20) NOT NULL,
  `state` int(11) NOT NULL DEFAULT '0' COMMENT '是否已登录',
  `m_baoliu` char(255) DEFAULT NULL,
  PRIMARY KEY (`m_id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of member_info
-- ----------------------------
INSERT INTO `member_info` VALUES ('1', '袁满', '20120702030', '女', '15972926714', '123456', '0', null);
INSERT INTO `member_info` VALUES ('2', '孙露婷', '20120702055', '女', '18064117322', '8907', '0', null);
