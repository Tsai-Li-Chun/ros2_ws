/** ******************************************************
	* @file		classAPI_publisher.cpp
	* @author	Tsai,Li-chun
	******************************************************
**	**/


/* System Includes ------------------------------------------*/
/* System Includes Begin */
#include <iostream>
#include <memory>
#include <functional>
#include <chrono>
/* System Includes End */
/* User Includes --------------------------------------------*/
/* User Includes Begin */
#include "classAPI_publisher.hpp"
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
publisher_string::publisher_string():
	rclcpp::Node("publisher_string"),
	count_autotime_(0),
	count_manual_(0)
{
	/* 建立自動發佈用物件，並設定topic名與QoS */
	publisher_autotime_ = this->create_publisher<std_msgs::msg::String>(
		"topic_string_autotime", 
		rclcpp::QoS(10)	);
	/* 建立手動發佈用物件，並設定topic名與QoS */
	publisher_manual_ = this->create_publisher<std_msgs::msg::String>(
		"topic_string_manual",
		rclcpp::QoS(10)	);
	/* 建立時間管理物件，並設定中斷時間與指定callback函式 */
	timer_ = this->create_wall_timer(
		std::chrono::milliseconds(500),
		std::bind(&publisher_string::timer_callback, this)	);
}

/** * @brief 解建構涵式
 	* @param None
 	* @return None
**	**/
publisher_string::~publisher_string()
{
	/* 打印結束訊息 */
	RCLCPP_INFO(this->get_logger(),"Quit Node publisher_string");
}

/** * @brief 手動發佈msg涵式
 	* @param None
 	* @return None
**	**/
void publisher_string::pub_manual_(void)
{
	/* msg填值 */
	msg.data = "pub_manual: " + std::to_string(++count_manual_);
	/* 打印相關訊息 */
	RCLCPP_INFO(this->get_logger(), msg.data.c_str());
	/* 發佈(手動呼叫此函式) */
	publisher_manual_->publish(msg);
}

/** * @brief 500ms計時中斷callback函式
 	* @param None
 	* @return None
**	**/
void publisher_string::timer_callback(void)
{
	/* msg填值 */
	msg.data = "pub_autotime: " + std::to_string(++count_autotime_);
	/* 打印相關訊息 */
	RCLCPP_INFO(this->get_logger(), msg.data.c_str());
	/* 發佈(中斷時間一到會自動呼叫此函式) */
	publisher_autotime_->publish(msg);
}

/* Program End */
/* ---------------------------------------------------------*/
/* ⇧⇧⇧⇧⇧⇧⇧⇧⇧⇧ Program ⇧⇧⇧⇧⇧⇧⇧⇧⇧⇧ ---------------------------*/
/* ---------------------------------------------------------*/


/* ***** END OF classAPI_publisher.cpp ***** */