/*
 Navicat Premium Data Transfer

 Source Server         : sqlserver
 Source Server Type    : SQL Server
 Source Server Version : 10001600
 Source Host           : localhost:1433
 Source Catalog        : test
 Source Schema         : dbo

 Target Server Type    : SQL Server
 Target Server Version : 10001600
 File Encoding         : 65001

 Date: 17/12/2020 23:14:43
*/


-- ----------------------------
-- Table structure for category
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[category]') AND type IN ('U'))
	DROP TABLE [dbo].[category]
GO

CREATE TABLE [dbo].[category] (
  [cateid] int  NOT NULL,
  [category] varchar(255) COLLATE Chinese_PRC_CI_AS  NOT NULL
)
GO

ALTER TABLE [dbo].[category] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Records of category
-- ----------------------------
INSERT INTO [dbo].[category] VALUES (N'1', N'学习用品')
GO

INSERT INTO [dbo].[category] VALUES (N'2', N'生活用品')
GO

INSERT INTO [dbo].[category] VALUES (N'3', N'零食')
GO

INSERT INTO [dbo].[category] VALUES (N'4', N'水果')
GO

INSERT INTO [dbo].[category] VALUES (N'5', N'饮料')
GO

INSERT INTO [dbo].[category] VALUES (N'6', N'日用百货')
GO

INSERT INTO [dbo].[category] VALUES (N'7', N'酒水饮料')
GO

INSERT INTO [dbo].[category] VALUES (N'8', N'洗漱用品')
GO


-- ----------------------------
-- Table structure for commodity
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[commodity]') AND type IN ('U'))
	DROP TABLE [dbo].[commodity]
GO

CREATE TABLE [dbo].[commodity] (
  [cid] int  IDENTITY(1,1) NOT NULL,
  [cname] varchar(50) COLLATE Chinese_PRC_CI_AS  NULL,
  [sid] int  NULL,
  [category] varchar(50) COLLATE Chinese_PRC_CI_AS  NULL,
  [minnum] int  NULL,
  [maxmun] int  NULL
)
GO

ALTER TABLE [dbo].[commodity] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Records of commodity
-- ----------------------------
SET IDENTITY_INSERT [dbo].[commodity] ON
GO

INSERT INTO [dbo].[commodity] ([cid], [cname], [sid], [category], [minnum], [maxmun]) VALUES (N'1', N'自动铅笔', N'3', N'学习用品', N'60', N'500')
GO

INSERT INTO [dbo].[commodity] ([cid], [cname], [sid], [category], [minnum], [maxmun]) VALUES (N'2', N'钢笔', N'3', N'学习用品', N'40', N'1000')
GO

INSERT INTO [dbo].[commodity] ([cid], [cname], [sid], [category], [minnum], [maxmun]) VALUES (N'3', N'作业本', N'3', N'学习用品', N'100', N'2000')
GO

INSERT INTO [dbo].[commodity] ([cid], [cname], [sid], [category], [minnum], [maxmun]) VALUES (N'4', N'尺子', N'3', N'学习用品', N'50', N'500')
GO

INSERT INTO [dbo].[commodity] ([cid], [cname], [sid], [category], [minnum], [maxmun]) VALUES (N'5', N'苹果', N'1', N'水果', N'10', N'50')
GO

INSERT INTO [dbo].[commodity] ([cid], [cname], [sid], [category], [minnum], [maxmun]) VALUES (N'6', N'香蕉', N'1', N'水果', N'10', N'50')
GO

INSERT INTO [dbo].[commodity] ([cid], [cname], [sid], [category], [minnum], [maxmun]) VALUES (N'7', N'橘子', N'1', N'水果', N'10', N'50')
GO

INSERT INTO [dbo].[commodity] ([cid], [cname], [sid], [category], [minnum], [maxmun]) VALUES (N'8', N'5号电池', N'2', N'日用百货', N'10', N'40')
GO

INSERT INTO [dbo].[commodity] ([cid], [cname], [sid], [category], [minnum], [maxmun]) VALUES (N'9', N'卫生纸', N'2', N'日用百货', N'10', N'1000')
GO

INSERT INTO [dbo].[commodity] ([cid], [cname], [sid], [category], [minnum], [maxmun]) VALUES (N'10', N'洗发水', N'2', N'日用百货', N'10', N'1000')
GO

INSERT INTO [dbo].[commodity] ([cid], [cname], [sid], [category], [minnum], [maxmun]) VALUES (N'11', N'康师傅', N'4', N'零食', N'10', N'1000')
GO

INSERT INTO [dbo].[commodity] ([cid], [cname], [sid], [category], [minnum], [maxmun]) VALUES (N'12', N'火腿', N'4', N'零食', N'5', N'1000')
GO

INSERT INTO [dbo].[commodity] ([cid], [cname], [sid], [category], [minnum], [maxmun]) VALUES (N'13', N'面包', N'4', N'零食', N'5', N'100')
GO

INSERT INTO [dbo].[commodity] ([cid], [cname], [sid], [category], [minnum], [maxmun]) VALUES (N'14', N'江小白', N'8', N'酒水饮料', N'20', N'1000')
GO

INSERT INTO [dbo].[commodity] ([cid], [cname], [sid], [category], [minnum], [maxmun]) VALUES (N'20', N'笔记本', N'7', N'学习用品', N'100', N'500')
GO

INSERT INTO [dbo].[commodity] ([cid], [cname], [sid], [category], [minnum], [maxmun]) VALUES (N'21', N'直尺', N'7', N'学习用品', N'10', N'1000')
GO

INSERT INTO [dbo].[commodity] ([cid], [cname], [sid], [category], [minnum], [maxmun]) VALUES (N'22', N'毛巾', N'5', N'洗漱用品', N'10', N'500')
GO

INSERT INTO [dbo].[commodity] ([cid], [cname], [sid], [category], [minnum], [maxmun]) VALUES (N'23', N'钢笔', N'2', N'学习用品', N'1000', N'50000')
GO

INSERT INTO [dbo].[commodity] ([cid], [cname], [sid], [category], [minnum], [maxmun]) VALUES (N'24', N'小刀', N'2', N'学习用品', N'100', N'5000')
GO

INSERT INTO [dbo].[commodity] ([cid], [cname], [sid], [category], [minnum], [maxmun]) VALUES (N'25', N'康师傅', N'7', N'零食', N'100', N'5000')
GO

INSERT INTO [dbo].[commodity] ([cid], [cname], [sid], [category], [minnum], [maxmun]) VALUES (N'26', N'泡面', N'5', N'零食', N'100', N'5000')
GO

INSERT INTO [dbo].[commodity] ([cid], [cname], [sid], [category], [minnum], [maxmun]) VALUES (N'27', N'柚子', N'1', N'水果', N'10', N'422')
GO

INSERT INTO [dbo].[commodity] ([cid], [cname], [sid], [category], [minnum], [maxmun]) VALUES (N'28', N'铅笔', N'3', N'学习用品', N'100', N'500')
GO

INSERT INTO [dbo].[commodity] ([cid], [cname], [sid], [category], [minnum], [maxmun]) VALUES (N'29', N'方便面', N'4', N'零食', N'100', N'500')
GO

INSERT INTO [dbo].[commodity] ([cid], [cname], [sid], [category], [minnum], [maxmun]) VALUES (N'30', N'方便面', N'8', N'零食', N'100', N'500')
GO

SET IDENTITY_INSERT [dbo].[commodity] OFF
GO


-- ----------------------------
-- Table structure for in
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[in]') AND type IN ('U'))
	DROP TABLE [dbo].[in]
GO

CREATE TABLE [dbo].[in] (
  [iid] int  IDENTITY(1,1) NOT NULL,
  [cid] int  NULL,
  [price] float(53)  NULL,
  [time] datetime  NULL,
  [shelftime] datetime  NULL,
  [num] int  NULL,
  [uid] int  NULL,
  [weight] float(53)  NULL
)
GO

ALTER TABLE [dbo].[in] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Records of in
-- ----------------------------
SET IDENTITY_INSERT [dbo].[in] ON
GO

INSERT INTO [dbo].[in] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'154', N'1', N'5', N'2020-11-21 18:09:10.000', N'2021-01-01 18:09:45.000', N'60', N'1', NULL)
GO

INSERT INTO [dbo].[in] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'155', N'2', N'50', N'2020-11-21 18:09:13.000', N'2022-03-21 18:09:51.000', N'70', N'1', NULL)
GO

INSERT INTO [dbo].[in] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'156', N'6', N'2', N'2020-11-21 18:09:16.000', N'2021-01-01 18:09:45.000', N'100', N'2', NULL)
GO

INSERT INTO [dbo].[in] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'157', N'4', N'2', N'2020-11-21 18:09:21.000', N'2021-01-01 18:09:45.000', N'10', N'1', NULL)
GO

INSERT INTO [dbo].[in] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'158', N'1', N'5.5', N'2020-11-21 18:09:18.000', N'2021-01-01 18:09:45.000', N'10', N'2', N'500')
GO

INSERT INTO [dbo].[in] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'159', N'6', N'2', N'2020-11-21 18:09:28.000', N'2021-01-01 18:09:45.000', N'10', N'1', N'500')
GO

INSERT INTO [dbo].[in] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'160', N'7', N'1', N'2020-11-21 18:09:25.000', N'2021-01-01 18:09:45.000', N'10', N'1', NULL)
GO

INSERT INTO [dbo].[in] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'161', N'9', N'5', N'2020-11-21 18:09:31.000', N'2021-01-01 18:09:45.000', N'20', N'1', NULL)
GO

INSERT INTO [dbo].[in] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'162', N'10', N'10', N'2020-11-21 18:09:34.000', N'2021-01-01 18:09:45.000', N'10', N'1', NULL)
GO

INSERT INTO [dbo].[in] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'163', N'5', N'5.5', N'2020-11-21 18:09:37.000', N'2021-01-01 18:09:45.000', N'20', N'1', NULL)
GO

INSERT INTO [dbo].[in] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'164', N'12', N'1', N'2020-11-21 18:09:39.000', N'2021-01-01 18:09:45.000', N'20', N'1', NULL)
GO

INSERT INTO [dbo].[in] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'165', N'1', N'6', N'2020-11-29 13:02:42.000', N'2023-03-01 13:02:46.000', N'50', N'2', N'20')
GO

INSERT INTO [dbo].[in] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'166', N'1', N'6', N'2020-11-29 14:02:42.000', N'2023-03-01 13:02:46.000', N'50', N'2', N'20')
GO

INSERT INTO [dbo].[in] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'167', N'6', N'9', N'2020-11-29 17:24:56.580', N'2022-12-05 05:22:00.000', N'7', N'1', N'8')
GO

INSERT INTO [dbo].[in] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'170', N'6', N'15', N'2020-11-29 17:42:14.243', N'2022-02-22 22:22:00.000', N'15', N'1', N'15')
GO

INSERT INTO [dbo].[in] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'171', N'14', N'21', N'2020-11-29 21:38:20.777', N'2023-12-12 12:12:00.000', N'15', N'1', N'10')
GO

INSERT INTO [dbo].[in] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'172', N'20', N'7', N'2020-11-29 21:42:34.903', N'2222-02-22 22:22:00.000', N'5', N'1', N'5')
GO

INSERT INTO [dbo].[in] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'173', N'20', N'7', N'2020-11-29 21:42:34.903', N'2222-02-22 22:22:00.000', N'44', N'1', N'5')
GO

INSERT INTO [dbo].[in] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'174', N'21', N'5', N'2020-11-30 13:06:31.420', N'2222-02-22 22:22:00.000', N'83', N'3', N'6')
GO

INSERT INTO [dbo].[in] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'175', N'22', N'10', N'2020-12-06 13:17:01.690', N'2022-02-22 22:22:00.000', N'180', N'3', N'10')
GO

INSERT INTO [dbo].[in] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'176', N'23', N'10', N'2020-12-06 15:04:49.533', N'2022-02-22 22:22:00.000', N'10', N'3', N'10')
GO

INSERT INTO [dbo].[in] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'180', N'25', N'6', N'2020-12-14 21:30:24.570', N'2022-09-20 21:31:38.000', N'400', N'3', N'200')
GO

INSERT INTO [dbo].[in] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'181', N'26', N'15', N'2020-12-14 21:47:16.000', N'2022-12-15 23:42:35.000', N'50', N'3', N'7')
GO

INSERT INTO [dbo].[in] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'182', N'27', N'25', N'2020-12-14 22:11:00.737', N'2021-12-15 22:06:16.000', N'20', N'3', N'45')
GO

INSERT INTO [dbo].[in] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'183', N'5', N'7', N'2020-12-15 09:54:35.293', N'2021-10-16 09:54:11.000', N'12', N'3', N'8')
GO

INSERT INTO [dbo].[in] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'184', N'28', N'6', N'2020-12-16 14:38:08.997', N'2024-12-17 14:35:15.000', N'50', N'3', N'8')
GO

INSERT INTO [dbo].[in] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'185', N'29', N'10', N'2020-12-16 14:41:46.113', N'2024-09-17 14:35:15.000', N'54', N'3', N'13')
GO

INSERT INTO [dbo].[in] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'186', N'29', N'10', N'2020-12-16 14:41:52.740', N'2024-09-17 14:35:15.000', N'54', N'3', N'13')
GO

INSERT INTO [dbo].[in] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'188', N'29', N'10', N'2020-12-16 14:48:27.040', N'2034-09-17 14:35:15.000', N'46', N'3', N'13')
GO

SET IDENTITY_INSERT [dbo].[in] OFF
GO


-- ----------------------------
-- Table structure for in_copy
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[in_copy]') AND type IN ('U'))
	DROP TABLE [dbo].[in_copy]
GO

CREATE TABLE [dbo].[in_copy] (
  [iid] int  IDENTITY(1,1) NOT NULL,
  [cid] int  NULL,
  [price] float(53)  NULL,
  [time] datetime  NULL,
  [shelftime] datetime  NULL,
  [num] int  NULL,
  [uid] int  NULL,
  [weight] float(53)  NULL
)
GO

ALTER TABLE [dbo].[in_copy] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Records of in_copy
-- ----------------------------
SET IDENTITY_INSERT [dbo].[in_copy] ON
GO

INSERT INTO [dbo].[in_copy] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'1', N'1', N'5', N'2020-11-21 18:09:10.000', N'2021-01-01 18:09:45.000', N'60', N'1', NULL)
GO

INSERT INTO [dbo].[in_copy] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'2', N'2', N'50', N'2020-11-21 18:09:13.000', N'2022-03-21 18:09:51.000', N'70', N'1', NULL)
GO

INSERT INTO [dbo].[in_copy] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'3', N'6', N'2', N'2020-11-21 18:09:16.000', N'2021-01-01 18:09:45.000', N'100', N'2', NULL)
GO

INSERT INTO [dbo].[in_copy] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'4', N'4', N'2', N'2020-11-21 18:09:21.000', N'2021-01-01 18:09:45.000', N'10', N'1', NULL)
GO

INSERT INTO [dbo].[in_copy] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'5', N'1', N'5.5', N'2020-11-21 18:09:18.000', N'2021-01-01 18:09:45.000', N'10', N'2', N'500')
GO

INSERT INTO [dbo].[in_copy] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'6', N'6', N'2', N'2020-11-21 18:09:28.000', N'2021-01-01 18:09:45.000', N'10', N'1', N'500')
GO

INSERT INTO [dbo].[in_copy] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'8', N'7', N'1', N'2020-11-21 18:09:25.000', N'2021-01-01 18:09:45.000', N'10', N'1', NULL)
GO

INSERT INTO [dbo].[in_copy] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'9', N'9', N'5', N'2020-11-21 18:09:31.000', N'2021-01-01 18:09:45.000', N'20', N'1', NULL)
GO

INSERT INTO [dbo].[in_copy] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'10', N'10', N'10', N'2020-11-21 18:09:34.000', N'2021-01-01 18:09:45.000', N'10', N'1', NULL)
GO

INSERT INTO [dbo].[in_copy] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'11', N'5', N'5.5', N'2020-11-21 18:09:37.000', N'2021-01-01 18:09:45.000', N'20', N'1', NULL)
GO

INSERT INTO [dbo].[in_copy] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'12', N'12', N'1', N'2020-11-21 18:09:39.000', N'2021-01-01 18:09:45.000', N'20', N'1', NULL)
GO

INSERT INTO [dbo].[in_copy] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'13', N'1', N'6', N'2020-11-29 13:02:42.000', N'2023-03-01 13:02:46.000', N'50', N'2', N'20')
GO

INSERT INTO [dbo].[in_copy] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'14', N'1', N'6', N'2020-11-29 14:02:42.000', N'2023-03-01 13:02:46.000', N'50', N'2', N'20')
GO

INSERT INTO [dbo].[in_copy] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'15', N'6', N'9', N'2020-11-29 17:24:56.580', N'2022-12-05 05:22:00.000', N'7', N'1', N'8')
GO

INSERT INTO [dbo].[in_copy] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'16', N'6', N'5', N'2020-11-29 17:39:54.897', N'2000-01-01 00:00:00.000', N'10', N'1', N'0')
GO

INSERT INTO [dbo].[in_copy] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'18', N'6', N'77.55', N'2020-11-29 17:40:50.943', N'2000-01-01 00:00:00.000', N'255', N'1', N'45')
GO

INSERT INTO [dbo].[in_copy] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'19', N'6', N'15', N'2020-11-29 17:42:14.243', N'2022-02-22 22:22:00.000', N'15', N'1', N'15')
GO

INSERT INTO [dbo].[in_copy] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'20', N'14', N'21', N'2020-11-29 21:38:20.777', N'2023-12-12 12:12:00.000', N'15', N'1', N'10')
GO

INSERT INTO [dbo].[in_copy] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'23', N'20', N'7', N'2020-11-29 21:42:34.903', N'2222-02-22 22:22:00.000', N'5', N'1', N'5')
GO

INSERT INTO [dbo].[in_copy] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'24', N'20', N'7', N'2020-11-29 21:42:34.903', N'2222-02-22 22:22:00.000', N'44', N'1', N'5')
GO

INSERT INTO [dbo].[in_copy] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'28', N'21', N'5', N'2020-11-30 13:06:31.420', N'2222-02-22 22:22:00.000', N'83', N'3', N'6')
GO

INSERT INTO [dbo].[in_copy] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'29', N'22', N'10', N'2020-12-06 13:17:01.690', N'2022-02-22 22:22:00.000', N'180', N'3', N'10')
GO

INSERT INTO [dbo].[in_copy] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'30', N'23', N'10', N'2020-12-06 15:04:49.533', N'2022-02-22 22:22:00.000', N'10', N'3', N'10')
GO

INSERT INTO [dbo].[in_copy] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'31', N'24', N'11', N'2020-12-06 16:05:22.723', N'2000-01-01 00:00:00.000', N'555', N'3', N'5')
GO

INSERT INTO [dbo].[in_copy] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'32', N'5', N'8', N'2020-12-14 09:02:53.443', N'2000-01-01 00:00:00.000', N'11', N'3', N'9')
GO

INSERT INTO [dbo].[in_copy] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'33', N'5', N'11', N'2020-12-14 09:13:58.630', N'2005-01-01 00:00:00.000', N'15', N'3', N'14')
GO

INSERT INTO [dbo].[in_copy] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'34', N'25', N'6', N'2020-12-14 21:30:24.570', N'2022-09-20 21:31:38.000', N'400', N'3', N'200')
GO

INSERT INTO [dbo].[in_copy] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'35', N'26', N'15', N'2020-12-14 21:47:16.000', N'2022-12-15 23:42:35.000', N'50', N'3', N'7')
GO

INSERT INTO [dbo].[in_copy] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'36', N'27', N'25', N'2020-12-14 22:11:00.737', N'2021-12-15 22:06:16.000', N'20', N'3', N'45')
GO

INSERT INTO [dbo].[in_copy] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'37', N'5', N'7', N'2020-12-15 09:54:35.293', N'2021-10-16 09:54:11.000', N'12', N'3', N'8')
GO

INSERT INTO [dbo].[in_copy] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'38', N'28', N'6', N'2020-12-16 14:38:08.997', N'2024-12-17 14:35:15.000', N'50', N'3', N'8')
GO

INSERT INTO [dbo].[in_copy] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'39', N'29', N'10', N'2020-12-16 14:41:46.130', N'2024-09-17 14:35:15.000', N'54', N'3', N'13')
GO

INSERT INTO [dbo].[in_copy] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'40', N'29', N'10', N'2020-12-16 14:41:52.757', N'2024-09-17 14:35:15.000', N'54', N'3', N'13')
GO

INSERT INTO [dbo].[in_copy] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'41', N'30', N'10', N'2020-12-16 14:42:42.880', N'2022-09-17 14:35:15.000', N'46', N'3', N'13')
GO

INSERT INTO [dbo].[in_copy] ([iid], [cid], [price], [time], [shelftime], [num], [uid], [weight]) VALUES (N'42', N'29', N'10', N'2020-12-16 14:48:27.053', N'2034-09-17 14:35:15.000', N'46', N'3', N'13')
GO

SET IDENTITY_INSERT [dbo].[in_copy] OFF
GO


-- ----------------------------
-- Table structure for out
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[out]') AND type IN ('U'))
	DROP TABLE [dbo].[out]
GO

CREATE TABLE [dbo].[out] (
  [oid] int  IDENTITY(1,1) NOT NULL,
  [cid] int  NOT NULL,
  [price] float(53)  NOT NULL,
  [time] datetime  NOT NULL,
  [num] int  NOT NULL,
  [uid] int  NOT NULL,
  [weight] float(53)  NOT NULL
)
GO

ALTER TABLE [dbo].[out] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Records of out
-- ----------------------------
SET IDENTITY_INSERT [dbo].[out] ON
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'1', N'1', N'5', N'2020-11-21 18:17:49.000', N'200', N'1', N'52')
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'2', N'4', N'5', N'2020-11-21 18:17:49.000', N'55', N'1', N'52')
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'3', N'5', N'5', N'2020-11-21 18:17:49.000', N'22', N'1', N'52')
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'4', N'1', N'5', N'2020-11-29 13:35:21.000', N'20', N'1', N'50')
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'5', N'6', N'77.55', N'2020-11-30 00:26:12.430', N'100', N'1', N'0')
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'6', N'6', N'77.55', N'2020-11-30 10:12:47.860', N'100', N'1', N'0')
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'7', N'6', N'77.55', N'2020-11-30 10:38:20.957', N'100', N'1', N'0')
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'8', N'22', N'10', N'2020-12-06 15:05:40.123', N'20', N'3', N'0')
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'9', N'6', N'15', N'2020-12-10 20:08:39.003', N'16', N'3', N'0')
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'10', N'6', N'15', N'2020-12-10 20:08:54.950', N'16', N'3', N'0')
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'11', N'6', N'15', N'2020-12-10 20:09:08.040', N'16', N'3', N'0')
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'12', N'7', N'6', N'2020-12-11 11:21:00.420', N'10', N'3', N'0')
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'13', N'25', N'6', N'2020-12-14 21:31:03.833', N'100', N'3', N'0')
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'14', N'26', N'15', N'2020-12-14 21:47:48.967', N'50', N'3', N'0')
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'15', N'27', N'25', N'2020-12-14 22:11:49.917', N'100', N'3', N'0')
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'16', N'5', N'7', N'2020-12-15 09:55:17.483', N'12', N'3', N'0')
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'17', N'6', N'5', N'2020-12-15 10:45:36.240', N'10', N'1', N'0')
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'18', N'6', N'77.55', N'2020-12-15 10:45:36.240', N'255', N'1', N'0')
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'19', N'24', N'11', N'2020-12-15 10:45:36.240', N'555', N'3', N'0')
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'20', N'5', N'8', N'2020-12-15 10:45:36.240', N'11', N'3', N'0')
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'21', N'5', N'11', N'2020-12-15 10:45:36.240', N'15', N'3', N'0')
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'22', N'6', N'5', N'2020-12-15 10:56:34.760', N'10', N'1', N'0')
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'23', N'6', N'77.55', N'2020-12-15 10:56:34.760', N'255', N'1', N'0')
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'24', N'24', N'11', N'2020-12-15 10:56:34.760', N'555', N'3', N'0')
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'25', N'5', N'8', N'2020-12-15 10:56:34.760', N'11', N'3', N'0')
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'26', N'5', N'11', N'2020-12-15 10:56:34.760', N'15', N'3', N'0')
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'27', N'6', N'5', N'2020-12-15 16:34:21.407', N'10', N'1', N'0')
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'28', N'6', N'77.55', N'2020-12-15 16:34:21.407', N'255', N'1', N'0')
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'29', N'24', N'11', N'2020-12-15 16:34:21.407', N'555', N'3', N'0')
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'30', N'5', N'8', N'2020-12-15 16:34:21.407', N'11', N'3', N'0')
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'31', N'5', N'11', N'2020-12-15 16:34:21.407', N'15', N'3', N'0')
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'32', N'6', N'5', N'2020-12-15 16:40:52.103', N'10', N'1', N'0')
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'33', N'6', N'77.55', N'2020-12-15 16:40:52.103', N'255', N'1', N'0')
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'34', N'24', N'11', N'2020-12-15 16:40:52.117', N'555', N'3', N'0')
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'35', N'5', N'8', N'2020-12-15 16:40:52.150', N'11', N'3', N'0')
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'36', N'5', N'11', N'2020-12-15 16:40:52.150', N'15', N'3', N'0')
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'37', N'6', N'5', N'2020-12-15 16:46:37.007', N'10', N'1', N'0')
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'38', N'6', N'77.55', N'2020-12-15 16:46:37.007', N'255', N'1', N'0')
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'39', N'24', N'11', N'2020-12-15 16:46:37.007', N'555', N'3', N'0')
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'40', N'5', N'8', N'2020-12-15 16:46:37.007', N'11', N'3', N'0')
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'41', N'5', N'11', N'2020-12-15 16:46:37.007', N'15', N'3', N'0')
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'42', N'6', N'5', N'2020-12-16 10:46:56.433', N'10', N'1', N'0')
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'43', N'6', N'77.55', N'2020-12-16 10:46:56.450', N'255', N'1', N'0')
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'44', N'24', N'11', N'2020-12-16 10:46:56.450', N'555', N'3', N'0')
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'45', N'5', N'8', N'2020-12-16 10:46:56.450', N'11', N'3', N'0')
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'46', N'5', N'11', N'2020-12-16 10:46:56.450', N'15', N'3', N'0')
GO

INSERT INTO [dbo].[out] ([oid], [cid], [price], [time], [num], [uid], [weight]) VALUES (N'47', N'30', N'10', N'2020-12-16 14:46:07.870', N'46', N'3', N'0')
GO

SET IDENTITY_INSERT [dbo].[out] OFF
GO


-- ----------------------------
-- Table structure for supplier
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[supplier]') AND type IN ('U'))
	DROP TABLE [dbo].[supplier]
GO

CREATE TABLE [dbo].[supplier] (
  [sid] int  IDENTITY(1,1) NOT NULL,
  [exist] int  NOT NULL,
  [sname] varchar(50) COLLATE Chinese_PRC_CI_AS  NOT NULL,
  [addr] varchar(50) COLLATE Chinese_PRC_CI_AS  NOT NULL,
  [tel] varchar(50) COLLATE Chinese_PRC_CI_AS  NOT NULL
)
GO

ALTER TABLE [dbo].[supplier] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Records of supplier
-- ----------------------------
SET IDENTITY_INSERT [dbo].[supplier] ON
GO

INSERT INTO [dbo].[supplier] ([sid], [exist], [sname], [addr], [tel]) VALUES (N'1', N'1', N'宝鸡水果批发公司', N'陕西省宝鸡市', N'00000000000')
GO

INSERT INTO [dbo].[supplier] ([sid], [exist], [sname], [addr], [tel]) VALUES (N'2', N'1', N'宝鸡日用百货公司', N'陕西省宝鸡市', N'11111111111')
GO

INSERT INTO [dbo].[supplier] ([sid], [exist], [sname], [addr], [tel]) VALUES (N'3', N'1', N'宝鸡文具批发公司', N'陕西省宝鸡市', N'22222222222')
GO

INSERT INTO [dbo].[supplier] ([sid], [exist], [sname], [addr], [tel]) VALUES (N'4', N'1', N'宝鸡零食批发公司', N'陕西省宝鸡市', N'33333333333')
GO

INSERT INTO [dbo].[supplier] ([sid], [exist], [sname], [addr], [tel]) VALUES (N'5', N'1', N'宝鸡批发商', N'陕西省西安市', N'44444433333')
GO

INSERT INTO [dbo].[supplier] ([sid], [exist], [sname], [addr], [tel]) VALUES (N'6', N'1', N'西安水果批发', N'陕西西安', N'5555555555')
GO

INSERT INTO [dbo].[supplier] ([sid], [exist], [sname], [addr], [tel]) VALUES (N'7', N'1', N'浙江三禾竹木有限公司', N'浙江绍兴', N'88888888888')
GO

INSERT INTO [dbo].[supplier] ([sid], [exist], [sname], [addr], [tel]) VALUES (N'8', N'1', N'龙泉绿瓯食品有限公司', N'陕西省西安市', N'999999999999')
GO

INSERT INTO [dbo].[supplier] ([sid], [exist], [sname], [addr], [tel]) VALUES (N'777', N'0', N'宝鸡批发商544', N'陕西西安', N'6666666666666666')
GO

INSERT INTO [dbo].[supplier] ([sid], [exist], [sname], [addr], [tel]) VALUES (N'778', N'0', N'龙泉绿瓯百货有限公司', N'陕西省西安市', N'88888888888')
GO

INSERT INTO [dbo].[supplier] ([sid], [exist], [sname], [addr], [tel]) VALUES (N'779', N'1', N'西安文具批发公司', N'陕西西安', N'1212121555555')
GO

INSERT INTO [dbo].[supplier] ([sid], [exist], [sname], [addr], [tel]) VALUES (N'780', N'1', N'西安日用百货公司', N'陕西省西安市', N'4545454545')
GO

SET IDENTITY_INSERT [dbo].[supplier] OFF
GO


-- ----------------------------
-- Table structure for sysdiagrams
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[sysdiagrams]') AND type IN ('U'))
	DROP TABLE [dbo].[sysdiagrams]
GO

CREATE TABLE [dbo].[sysdiagrams] (
  [name] sysname  NOT NULL,
  [principal_id] int  NOT NULL,
  [diagram_id] int  IDENTITY(1,1) NOT NULL,
  [version] int  NULL,
  [definition] varbinary(max)  NULL
)
GO

ALTER TABLE [dbo].[sysdiagrams] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Table structure for user
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[user]') AND type IN ('U'))
	DROP TABLE [dbo].[user]
GO

CREATE TABLE [dbo].[user] (
  [uid] int  NOT NULL,
  [exist] int  NULL,
  [uname] varchar(50) COLLATE Chinese_PRC_CI_AS  NULL,
  [upassword] varchar(50) COLLATE Chinese_PRC_CI_AS  NULL,
  [sex] varchar(50) COLLATE Chinese_PRC_CI_AS  NULL,
  [age] int  NULL,
  [tel] varchar(50) COLLATE Chinese_PRC_CI_AS  NULL,
  [time] datetime  NULL
)
GO

ALTER TABLE [dbo].[user] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Records of user
-- ----------------------------
INSERT INTO [dbo].[user] VALUES (N'1', N'1', N'dai', N'dai', N'男', N'21', N'15842594275', N'1900-01-01 20:04:08.000')
GO

INSERT INTO [dbo].[user] VALUES (N'2', N'1', N'hui', N'hui', N'男', N'22', N'15823674825', N'2020-11-28 20:53:21.000')
GO

INSERT INTO [dbo].[user] VALUES (N'3', N'1', N'admin', N'admin', N'男', N'20', N'15842942584', N'2020-11-28 20:53:25.000')
GO

INSERT INTO [dbo].[user] VALUES (N'6', N'1', N'代登辉', N'dai006', N'男', N'21', N'15829634728', N'2020-11-29 15:18:03.080')
GO

INSERT INTO [dbo].[user] VALUES (N'7', N'1', N'李正', N'li', N'男', N'21', N'15743842584', N'2020-11-29 15:18:59.210')
GO

INSERT INTO [dbo].[user] VALUES (N'8', N'1', N'陈培', N'chen', N'男', N'21', N'1574354842', N'2020-11-29 15:19:36.717')
GO

INSERT INTO [dbo].[user] VALUES (N'9', N'1', N'韩思琪', N'han', N'男', N'21', N'1584238425', N'2020-11-29 15:20:27.173')
GO

INSERT INTO [dbo].[user] VALUES (N'10', N'1', N'曹恒', N'cao', N'男', N'21', N'1584357428', N'2020-11-29 15:20:58.013')
GO

INSERT INTO [dbo].[user] VALUES (N'11', N'1', N'侯江涛', N'hou', N'男', N'21', N'15843574685', N'2020-11-29 15:21:22.507')
GO

INSERT INTO [dbo].[user] VALUES (N'12', N'1', N'赵永乐', N'zhao', N'男', N'21', N'13548654852', N'2020-11-29 15:22:13.770')
GO

INSERT INTO [dbo].[user] VALUES (N'13', N'1', N'李瑞豪', N'li', N'男', N'21', N'135478453615', N'2020-11-29 15:22:53.410')
GO

INSERT INTO [dbo].[user] VALUES (N'4545252', N'0', N'曹三', N'123', N'男', N'20', N'15843842578', N'2020-12-14 22:07:35.543')
GO


-- ----------------------------
-- View structure for getGoodCid
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[getGoodCid]') AND type IN ('V'))
	DROP VIEW [dbo].[getGoodCid]
GO

CREATE VIEW [dbo].[getGoodCid] AS SELECT cid,cname,category,sname from commodity LEFT JOIN supplier on commodity.sid = supplier.sid
GO


-- ----------------------------
-- View structure for goods
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[goods]') AND type IN ('V'))
	DROP VIEW [dbo].[goods]
GO

CREATE VIEW [dbo].[goods] AS SELECT
	commodity.cid,cname,SUM,category,sname,addr,tel,minnum,maxmun
FROM
	goodsnum
	LEFT JOIN commodity ON goodsnum.cid = commodity.cid
	LEFT JOIN supplier ON supplier.sid = commodity.sid
GO


-- ----------------------------
-- View structure for goodsin
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[goodsin]') AND type IN ('V'))
	DROP VIEW [dbo].[goodsin]
GO

CREATE VIEW [dbo].[goodsin] AS SELECT
	iid,
	cname,
	supplier.sname,
	category,
	price,
	[in].[time],
	shelftime,
	num,
	[user].uid,
	[user].uname,
	weight,
	minnum,
	maxmun 
FROM
	[in]
	LEFT JOIN [user] ON [in].uid = [user].uid
	LEFT JOIN commodity ON [in].cid = commodity.cid
	LEFT JOIN supplier ON commodity.sid = supplier.sid
GO


-- ----------------------------
-- View structure for goodsinnn
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[goodsinnn]') AND type IN ('V'))
	DROP VIEW [dbo].[goodsinnn]
GO

CREATE VIEW [dbo].[goodsinnn] AS SELECT
	iid,
	cname,
	supplier.sname,
	category,
	price,
	[in_copy].[time],
	shelftime,
	num,
	[user].uid,
	[user].uname,
	weight,
	minnum,
	maxmun 
FROM
	in_copy
	LEFT JOIN [user] ON [in_copy].uid = [user].uid
	LEFT JOIN commodity ON [in_copy].cid = commodity.cid
	LEFT JOIN supplier ON commodity.sid = supplier.sid
GO


-- ----------------------------
-- View structure for goodsnum
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[goodsnum]') AND type IN ('V'))
	DROP VIEW [dbo].[goodsnum]
GO

CREATE VIEW [dbo].[goodsnum] AS SELECT cid,SUM(num) "SUM" FROM [in] GROUP BY cid
GO


-- ----------------------------
-- View structure for goodsout
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[goodsout]') AND type IN ('V'))
	DROP VIEW [dbo].[goodsout]
GO

CREATE VIEW [dbo].[goodsout] AS SELECT
	oid,
	cname,
	supplier.sname,
	category,
	price,
	[out].[time],
	num,
	[user].uid,
	[user].uname,
	weight,
	minnum,
	maxmun 
FROM
	[out]
	LEFT JOIN [user] ON [out].uid = [user].uid
	LEFT JOIN commodity ON [out].cid = commodity.cid
	LEFT JOIN supplier ON commodity.sid = supplier.sid
GO


-- ----------------------------
-- View structure for vw1
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[vw1]') AND type IN ('V'))
	DROP VIEW [dbo].[vw1]
GO

CREATE VIEW [dbo].[vw1] AS SELECT
i.iid,cname,i.price ,i.[time],i.shelftime,i.num,category
FROM
	[dbo].[in] i,
	[dbo].[commodity] c
WHERE
	i.cid = c.cid
GO


-- ----------------------------
-- Procedure structure for pros
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[pros]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[pros]
GO

CREATE PROCEDURE [dbo].[pros] @sname CHAR ( 50 ) OUTPUT AS SELECT
i.iid,cname,num,price,[time],shelftime,category
FROM
	dbo.[in] i,
	dbo.commodity c 
WHERE
	i.cid = c.cid 
	AND c.cname=@sname
GO


-- ----------------------------
-- Procedure structure for logincheck
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[logincheck]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[logincheck]
GO

CREATE PROCEDURE [dbo].[logincheck]
	@us VARCHAR(20),
	@pw VARCHAR(20),
	@res int output
AS
	DECLARE @num int;
	SET @num = 0;
BEGIN
SELECT @res = COUNT(*) FROM [dbo].[user] WHERE [user].uname = @us and [user].upassword = @pw;
end;
GO


-- ----------------------------
-- Procedure structure for sp_upgraddiagrams
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[sp_upgraddiagrams]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[sp_upgraddiagrams]
GO

CREATE PROCEDURE [dbo].[sp_upgraddiagrams]
	AS
	BEGIN
		IF OBJECT_ID(N'dbo.sysdiagrams') IS NOT NULL
			return 0;
	
		CREATE TABLE dbo.sysdiagrams
		(
			name sysname NOT NULL,
			principal_id int NOT NULL,	-- we may change it to varbinary(85)
			diagram_id int PRIMARY KEY IDENTITY,
			version int,
	
			definition varbinary(max)
			CONSTRAINT UK_principal_name UNIQUE
			(
				principal_id,
				name
			)
		);


		/* Add this if we need to have some form of extended properties for diagrams */
		/*
		IF OBJECT_ID(N'dbo.sysdiagram_properties') IS NULL
		BEGIN
			CREATE TABLE dbo.sysdiagram_properties
			(
				diagram_id int,
				name sysname,
				value varbinary(max) NOT NULL
			)
		END
		*/

		IF OBJECT_ID(N'dbo.dtproperties') IS NOT NULL
		begin
			insert into dbo.sysdiagrams
			(
				[name],
				[principal_id],
				[version],
				[definition]
			)
			select	 
				convert(sysname, dgnm.[uvalue]),
				DATABASE_PRINCIPAL_ID(N'dbo'),			-- will change to the sid of sa
				0,							-- zero for old format, dgdef.[version],
				dgdef.[lvalue]
			from dbo.[dtproperties] dgnm
				inner join dbo.[dtproperties] dggd on dggd.[property] = 'DtgSchemaGUID' and dggd.[objectid] = dgnm.[objectid]	
				inner join dbo.[dtproperties] dgdef on dgdef.[property] = 'DtgSchemaDATA' and dgdef.[objectid] = dgnm.[objectid]
				
			where dgnm.[property] = 'DtgSchemaNAME' and dggd.[uvalue] like N'_EA3E6268-D998-11CE-9454-00AA00A3F36E_' 
			return 2;
		end
		return 1;
	END
GO


-- ----------------------------
-- Procedure structure for sp_helpdiagrams
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[sp_helpdiagrams]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[sp_helpdiagrams]
GO

CREATE PROCEDURE [dbo].[sp_helpdiagrams]
	(
		@diagramname sysname = NULL,
		@owner_id int = NULL
	)
	WITH EXECUTE AS N'dbo'
	AS
	BEGIN
		DECLARE @user sysname
		DECLARE @dboLogin bit
		EXECUTE AS CALLER;
			SET @user = USER_NAME();
			SET @dboLogin = CONVERT(bit,IS_MEMBER('db_owner'));
		REVERT;
		SELECT
			[Database] = DB_NAME(),
			[Name] = name,
			[ID] = diagram_id,
			[Owner] = USER_NAME(principal_id),
			[OwnerID] = principal_id
		FROM
			sysdiagrams
		WHERE
			(@dboLogin = 1 OR USER_NAME(principal_id) = @user) AND
			(@diagramname IS NULL OR name = @diagramname) AND
			(@owner_id IS NULL OR principal_id = @owner_id)
		ORDER BY
			4, 5, 1
	END
GO


-- ----------------------------
-- Procedure structure for sp_helpdiagramdefinition
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[sp_helpdiagramdefinition]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[sp_helpdiagramdefinition]
GO

CREATE PROCEDURE [dbo].[sp_helpdiagramdefinition]
	(
		@diagramname 	sysname,
		@owner_id	int	= null 		
	)
	WITH EXECUTE AS N'dbo'
	AS
	BEGIN
		set nocount on

		declare @theId 		int
		declare @IsDbo 		int
		declare @DiagId		int
		declare @UIDFound	int
	
		if(@diagramname is null)
		begin
			RAISERROR (N'E_INVALIDARG', 16, 1);
			return -1
		end
	
		execute as caller;
		select @theId = DATABASE_PRINCIPAL_ID();
		select @IsDbo = IS_MEMBER(N'db_owner');
		if(@owner_id is null)
			select @owner_id = @theId;
		revert; 
	
		select @DiagId = diagram_id, @UIDFound = principal_id from dbo.sysdiagrams where principal_id = @owner_id and name = @diagramname;
		if(@DiagId IS NULL or (@IsDbo = 0 and @UIDFound <> @theId ))
		begin
			RAISERROR ('Diagram does not exist or you do not have permission.', 16, 1);
			return -3
		end

		select version, definition FROM dbo.sysdiagrams where diagram_id = @DiagId ; 
		return 0
	END
GO


-- ----------------------------
-- Procedure structure for sp_creatediagram
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[sp_creatediagram]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[sp_creatediagram]
GO

CREATE PROCEDURE [dbo].[sp_creatediagram]
	(
		@diagramname 	sysname,
		@owner_id		int	= null, 	
		@version 		int,
		@definition 	varbinary(max)
	)
	WITH EXECUTE AS 'dbo'
	AS
	BEGIN
		set nocount on
	
		declare @theId int
		declare @retval int
		declare @IsDbo	int
		declare @userName sysname
		if(@version is null or @diagramname is null)
		begin
			RAISERROR (N'E_INVALIDARG', 16, 1);
			return -1
		end
	
		execute as caller;
		select @theId = DATABASE_PRINCIPAL_ID(); 
		select @IsDbo = IS_MEMBER(N'db_owner');
		revert; 
		
		if @owner_id is null
		begin
			select @owner_id = @theId;
		end
		else
		begin
			if @theId <> @owner_id
			begin
				if @IsDbo = 0
				begin
					RAISERROR (N'E_INVALIDARG', 16, 1);
					return -1
				end
				select @theId = @owner_id
			end
		end
		-- next 2 line only for test, will be removed after define name unique
		if EXISTS(select diagram_id from dbo.sysdiagrams where principal_id = @theId and name = @diagramname)
		begin
			RAISERROR ('The name is already used.', 16, 1);
			return -2
		end
	
		insert into dbo.sysdiagrams(name, principal_id , version, definition)
				VALUES(@diagramname, @theId, @version, @definition) ;
		
		select @retval = @@IDENTITY 
		return @retval
	END
GO


-- ----------------------------
-- Procedure structure for sp_renamediagram
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[sp_renamediagram]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[sp_renamediagram]
GO

CREATE PROCEDURE [dbo].[sp_renamediagram]
	(
		@diagramname 		sysname,
		@owner_id		int	= null,
		@new_diagramname	sysname
	
	)
	WITH EXECUTE AS 'dbo'
	AS
	BEGIN
		set nocount on
		declare @theId 			int
		declare @IsDbo 			int
		
		declare @UIDFound 		int
		declare @DiagId			int
		declare @DiagIdTarg		int
		declare @u_name			sysname
		if((@diagramname is null) or (@new_diagramname is null))
		begin
			RAISERROR ('Invalid value', 16, 1);
			return -1
		end
	
		EXECUTE AS CALLER;
		select @theId = DATABASE_PRINCIPAL_ID();
		select @IsDbo = IS_MEMBER(N'db_owner'); 
		if(@owner_id is null)
			select @owner_id = @theId;
		REVERT;
	
		select @u_name = USER_NAME(@owner_id)
	
		select @DiagId = diagram_id, @UIDFound = principal_id from dbo.sysdiagrams where principal_id = @owner_id and name = @diagramname 
		if(@DiagId IS NULL or (@IsDbo = 0 and @UIDFound <> @theId))
		begin
			RAISERROR ('Diagram does not exist or you do not have permission.', 16, 1)
			return -3
		end
	
		-- if((@u_name is not null) and (@new_diagramname = @diagramname))	-- nothing will change
		--	return 0;
	
		if(@u_name is null)
			select @DiagIdTarg = diagram_id from dbo.sysdiagrams where principal_id = @theId and name = @new_diagramname
		else
			select @DiagIdTarg = diagram_id from dbo.sysdiagrams where principal_id = @owner_id and name = @new_diagramname
	
		if((@DiagIdTarg is not null) and  @DiagId <> @DiagIdTarg)
		begin
			RAISERROR ('The name is already used.', 16, 1);
			return -2
		end		
	
		if(@u_name is null)
			update dbo.sysdiagrams set [name] = @new_diagramname, principal_id = @theId where diagram_id = @DiagId
		else
			update dbo.sysdiagrams set [name] = @new_diagramname where diagram_id = @DiagId
		return 0
	END
GO


-- ----------------------------
-- Procedure structure for sp_alterdiagram
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[sp_alterdiagram]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[sp_alterdiagram]
GO

CREATE PROCEDURE [dbo].[sp_alterdiagram]
	(
		@diagramname 	sysname,
		@owner_id	int	= null,
		@version 	int,
		@definition 	varbinary(max)
	)
	WITH EXECUTE AS 'dbo'
	AS
	BEGIN
		set nocount on
	
		declare @theId 			int
		declare @retval 		int
		declare @IsDbo 			int
		
		declare @UIDFound 		int
		declare @DiagId			int
		declare @ShouldChangeUID	int
	
		if(@diagramname is null)
		begin
			RAISERROR ('Invalid ARG', 16, 1)
			return -1
		end
	
		execute as caller;
		select @theId = DATABASE_PRINCIPAL_ID();	 
		select @IsDbo = IS_MEMBER(N'db_owner'); 
		if(@owner_id is null)
			select @owner_id = @theId;
		revert;
	
		select @ShouldChangeUID = 0
		select @DiagId = diagram_id, @UIDFound = principal_id from dbo.sysdiagrams where principal_id = @owner_id and name = @diagramname 
		
		if(@DiagId IS NULL or (@IsDbo = 0 and @theId <> @UIDFound))
		begin
			RAISERROR ('Diagram does not exist or you do not have permission.', 16, 1);
			return -3
		end
	
		if(@IsDbo <> 0)
		begin
			if(@UIDFound is null or USER_NAME(@UIDFound) is null) -- invalid principal_id
			begin
				select @ShouldChangeUID = 1 ;
			end
		end

		-- update dds data			
		update dbo.sysdiagrams set definition = @definition where diagram_id = @DiagId ;

		-- change owner
		if(@ShouldChangeUID = 1)
			update dbo.sysdiagrams set principal_id = @theId where diagram_id = @DiagId ;

		-- update dds version
		if(@version is not null)
			update dbo.sysdiagrams set version = @version where diagram_id = @DiagId ;

		return 0
	END
GO


-- ----------------------------
-- Procedure structure for sp_dropdiagram
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[sp_dropdiagram]') AND type IN ('P', 'PC', 'RF', 'X'))
	DROP PROCEDURE[dbo].[sp_dropdiagram]
GO

CREATE PROCEDURE [dbo].[sp_dropdiagram]
	(
		@diagramname 	sysname,
		@owner_id	int	= null
	)
	WITH EXECUTE AS 'dbo'
	AS
	BEGIN
		set nocount on
		declare @theId 			int
		declare @IsDbo 			int
		
		declare @UIDFound 		int
		declare @DiagId			int
	
		if(@diagramname is null)
		begin
			RAISERROR ('Invalid value', 16, 1);
			return -1
		end
	
		EXECUTE AS CALLER;
		select @theId = DATABASE_PRINCIPAL_ID();
		select @IsDbo = IS_MEMBER(N'db_owner'); 
		if(@owner_id is null)
			select @owner_id = @theId;
		REVERT; 
		
		select @DiagId = diagram_id, @UIDFound = principal_id from dbo.sysdiagrams where principal_id = @owner_id and name = @diagramname 
		if(@DiagId IS NULL or (@IsDbo = 0 and @UIDFound <> @theId))
		begin
			RAISERROR ('Diagram does not exist or you do not have permission.', 16, 1)
			return -3
		end
	
		delete from dbo.sysdiagrams where diagram_id = @DiagId;
	
		return 0;
	END
GO


-- ----------------------------
-- Function structure for fn_diagramobjects
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[fn_diagramobjects]') AND type IN ('FN', 'FS', 'FT', 'IF', 'TF'))
	DROP FUNCTION[dbo].[fn_diagramobjects]
GO

CREATE FUNCTION [dbo].[fn_diagramobjects]() 
	RETURNS int
	WITH EXECUTE AS N'dbo'
	AS
	BEGIN
		declare @id_upgraddiagrams		int
		declare @id_sysdiagrams			int
		declare @id_helpdiagrams		int
		declare @id_helpdiagramdefinition	int
		declare @id_creatediagram	int
		declare @id_renamediagram	int
		declare @id_alterdiagram 	int 
		declare @id_dropdiagram		int
		declare @InstalledObjects	int

		select @InstalledObjects = 0

		select 	@id_upgraddiagrams = object_id(N'dbo.sp_upgraddiagrams'),
			@id_sysdiagrams = object_id(N'dbo.sysdiagrams'),
			@id_helpdiagrams = object_id(N'dbo.sp_helpdiagrams'),
			@id_helpdiagramdefinition = object_id(N'dbo.sp_helpdiagramdefinition'),
			@id_creatediagram = object_id(N'dbo.sp_creatediagram'),
			@id_renamediagram = object_id(N'dbo.sp_renamediagram'),
			@id_alterdiagram = object_id(N'dbo.sp_alterdiagram'), 
			@id_dropdiagram = object_id(N'dbo.sp_dropdiagram')

		if @id_upgraddiagrams is not null
			select @InstalledObjects = @InstalledObjects + 1
		if @id_sysdiagrams is not null
			select @InstalledObjects = @InstalledObjects + 2
		if @id_helpdiagrams is not null
			select @InstalledObjects = @InstalledObjects + 4
		if @id_helpdiagramdefinition is not null
			select @InstalledObjects = @InstalledObjects + 8
		if @id_creatediagram is not null
			select @InstalledObjects = @InstalledObjects + 16
		if @id_renamediagram is not null
			select @InstalledObjects = @InstalledObjects + 32
		if @id_alterdiagram  is not null
			select @InstalledObjects = @InstalledObjects + 64
		if @id_dropdiagram is not null
			select @InstalledObjects = @InstalledObjects + 128
		
		return @InstalledObjects 
	END
GO


-- ----------------------------
-- Primary Key structure for table category
-- ----------------------------
ALTER TABLE [dbo].[category] ADD CONSTRAINT [PK__category__A88C49CC300424B4] PRIMARY KEY CLUSTERED ([cateid])
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)  
ON [PRIMARY]
GO


-- ----------------------------
-- Auto increment value for commodity
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[commodity]', RESEED, 30)
GO


-- ----------------------------
-- Triggers structure for table commodity
-- ----------------------------
CREATE TRIGGER [dbo].[MyTrigger]
ON [dbo].[commodity]
WITH EXECUTE AS CALLER
FOR UPDATE
AS
IF
	UPDATE (cid ) BEGIN
	DECLARE
		@IN_NEW INT,@IN_OLD INT
		SELECT @IN_NEW = cid FROM Inserted
		SELECT @IN_OLD = cid FROM Deleted
		UPDATE dbo.[in]
			SET cid = @IN_NEW 
		WHERE
		cid = @IN_OLD UPDATE dbo.out 
		SET cid = @IN_NEW 
	WHERE
	cid = @IN_OLD 
END
GO


-- ----------------------------
-- Primary Key structure for table commodity
-- ----------------------------
ALTER TABLE [dbo].[commodity] ADD CONSTRAINT [PK_commodity] PRIMARY KEY CLUSTERED ([cid])
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)  
ON [PRIMARY]
GO


-- ----------------------------
-- Auto increment value for in
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[in]', RESEED, 188)
GO


-- ----------------------------
-- Triggers structure for table in
-- ----------------------------
CREATE TRIGGER [dbo].[tgr_in_update]
ON [dbo].[in]
WITH EXECUTE AS CALLER
FOR UPDATE
AS
DELETE from [in] where [in].num < 1
GO


-- ----------------------------
-- Primary Key structure for table in
-- ----------------------------
ALTER TABLE [dbo].[in] ADD CONSTRAINT [PK__in__DC5021AA164452B1] PRIMARY KEY CLUSTERED ([iid])
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)  
ON [PRIMARY]
GO


-- ----------------------------
-- Auto increment value for in_copy
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[in_copy]', RESEED, 42)
GO


-- ----------------------------
-- Triggers structure for table in_copy
-- ----------------------------
CREATE TRIGGER [dbo].[tgr_in_update_copy1]
ON [dbo].[in_copy]
WITH EXECUTE AS CALLER
FOR UPDATE
AS
DELETE from [in] where [in].num < 1
GO


-- ----------------------------
-- Primary Key structure for table in_copy
-- ----------------------------
ALTER TABLE [dbo].[in_copy] ADD CONSTRAINT [PK__in__DC5021AA164452B1_copy1] PRIMARY KEY CLUSTERED ([iid])
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)  
ON [PRIMARY]
GO


-- ----------------------------
-- Auto increment value for out
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[out]', RESEED, 47)
GO


-- ----------------------------
-- Primary Key structure for table out
-- ----------------------------
ALTER TABLE [dbo].[out] ADD CONSTRAINT [PK_out] PRIMARY KEY CLUSTERED ([oid])
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)  
ON [PRIMARY]
GO


-- ----------------------------
-- Auto increment value for supplier
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[supplier]', RESEED, 780)
GO


-- ----------------------------
-- Primary Key structure for table supplier
-- ----------------------------
ALTER TABLE [dbo].[supplier] ADD CONSTRAINT [PK_supplier] PRIMARY KEY CLUSTERED ([sid])
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)  
ON [PRIMARY]
GO


-- ----------------------------
-- Auto increment value for sysdiagrams
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[sysdiagrams]', RESEED, 1)
GO


-- ----------------------------
-- Uniques structure for table sysdiagrams
-- ----------------------------
ALTER TABLE [dbo].[sysdiagrams] ADD CONSTRAINT [UK_principal_name] UNIQUE NONCLUSTERED ([principal_id] ASC, [name] ASC)
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)  
ON [PRIMARY]
GO


-- ----------------------------
-- Primary Key structure for table sysdiagrams
-- ----------------------------
ALTER TABLE [dbo].[sysdiagrams] ADD CONSTRAINT [PK__sysdiagr__C2B05B61398D8EEE] PRIMARY KEY CLUSTERED ([diagram_id])
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)  
ON [PRIMARY]
GO


-- ----------------------------
-- Primary Key structure for table user
-- ----------------------------
ALTER TABLE [dbo].[user] ADD CONSTRAINT [PK__user__DD7012640EA330E9] PRIMARY KEY CLUSTERED ([uid])
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)  
ON [PRIMARY]
GO


-- ----------------------------
-- Foreign Keys structure for table in
-- ----------------------------
ALTER TABLE [dbo].[in] ADD CONSTRAINT [cid] FOREIGN KEY ([cid]) REFERENCES [dbo].[commodity] ([cid]) ON DELETE SET NULL ON UPDATE NO ACTION
GO


-- ----------------------------
-- Foreign Keys structure for table in_copy
-- ----------------------------
ALTER TABLE [dbo].[in_copy] ADD CONSTRAINT [FK__in_copy1__cid__44FF419A] FOREIGN KEY ([cid]) REFERENCES [dbo].[commodity] ([cid]) ON DELETE SET NULL ON UPDATE NO ACTION
GO

