/** ******************************************************
	* @file		classAPI_subscriber.cpp
	* @author	Tsai,Li-chun
	******************************************************
**	**/


/* System Includes ------------------------------------------*/
/* System Includes Begin */
#include <iostream>
#include <functional>
/* System Includes End */
/* User Includes --------------------------------------------*/
/* User Includes Begin */
#include "classAPI_subscriber.hpp"
/* User Includes End */

/* namespace ------------------------------------------------*/
/* namespace Begin */
/* namespace End */


/* Define ---------------------------------------------------*/
/* Define Begin */
/* Define End */


/* Typedef --------------------------------------------------*/
/* Typedef Begin */
/* Typedef End */


/* Class --------------------------------------------------*/
/* Class Begin */
/* Class End */


/* Variables ------------------------------------------------*/
/* Variables Begin */
/* Variables End */


/* Function -------------------------------------------------*/
/* Function Begin */
/* Function End */



/* ---------------------------------------------------------*/
/* ⇩⇩⇩⇩⇩⇩⇩⇩⇩⇩ Program ⇩⇩⇩⇩⇩⇩⇩⇩⇩⇩ ---------------------------*/
/* ---------------------------------------------------------*/
/* Program Begin */

/** * @brief 建構涵式
 	* @param None
 	* @return None
**	**/
subscriber_string::subscriber_string():
	rclcpp::Node("subscriber_string")
{
	/* 建立訂閱用物件，並設定訂閱topic名,QoS,接收中斷函式 */
	subscriber_autotime_ = this->create_subscription<std_msgs::msg::String>(
		"topic_string_autotime",
		rclcpp::QoS(10),
		std::bind(
			&subscriber_string::topic_string_autotime_callback,
			this,
			std::placeholders::_1)	);
	/* 建立訂閱用物件，並設定訂閱topic名,QoS,接收中斷函式 */
	subscriber_manual_ = this->create_subscription<std_msgs::msg::String>(
		"topic_string_manual",
		rclcpp::QoS(10),
		std::bind(
			&subscriber_string::topic_string_manual_callback,
			this,
			std::placeholders::_1)	);
}

/** * @brief 解建構涵式
 	* @param None
 	* @return None
**	**/
subscriber_string::~subscriber_string()
{
	/* 打印結束訊息 */
	RCLCPP_INFO(this->get_logger(), "Quit Node subscriber_string");
}

/** * @brief topic_string_autotime接收中斷callback函式
 	* @param None
 	* @return None
**	**/
void subscriber_string::topic_string_autotime_callback(std_msgs::msg::String::SharedPtr msg)
{
	/* 打印接收訊息 */
	RCLCPP_INFO(this->get_logger(), msg->data.c_str());
}

/** * @brief topic_string_manual接收中斷callback函式
 	* @param None
 	* @return None
**	**/
void subscriber_string::topic_string_manual_callback(std_msgs::msg::String::SharedPtr msg)
{
	/* 打印接收訊息 */
	RCLCPP_INFO(this->get_logger(), msg->data.c_str());
}

/* Program End */
/* ---------------------------------------------------------*/
/* ⇧⇧⇧⇧⇧⇧⇧⇧⇧⇧ Program ⇧⇧⇧⇧⇧⇧⇧⇧⇧⇧ ---------------------------*/
/* ---------------------------------------------------------*/


/* ***** END OF classAPI_subscriber.cpp ***** */