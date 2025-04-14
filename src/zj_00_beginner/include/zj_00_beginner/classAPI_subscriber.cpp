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
subscriber_motors_info::subscriber_motors_info():
	rclcpp::Node("subscriber_string")
{
	/* 建立訂閱用物件，並設定訂閱topic名,QoS,接收中斷函式 */
	_subscriber_motors_info = this->create_subscription<zj_00_beginner_interfaces::msg::InterfaceMultipleMotors>(
		"topic_string",
		rclcpp::QoS(10),
		std::bind(
			&subscriber_motors_info::callback_topic_motors_info,
			this, std::placeholders::_1)	);
}

/** * @brief 解建構涵式
 	* @param None
 	* @return None
**	**/
subscriber_motors_info::~subscriber_motors_info()
{
	/* 打印結束訊息 */
	RCLCPP_INFO(this->get_logger(), "Quit Node _subscriber_motors_info");
}

/** * @brief topic_string_autotime接收中斷callback函式
 	* @param None
 	* @return None
**	**/
void subscriber_motors_info::callback_topic_motors_info(zj_00_beginner_interfaces::msg::InterfaceMultipleMotors::SharedPtr _motors_info)
{
	/* 宣告接收訊息變數 */
	std_msgs::msg::String motors_info;
	/* 取得接收訊息 */
	motors_info.data = "quantity: " + std::to_string(_motors_info->quantity) + "\n" +
				  "link_form: " + _motors_info->link_form + "\n";
	for (int i = 0; i < _motors_info->quantity; i++)
	{
		motors_info.data += "motor_info[" + std::to_string(i) + "]\n";
		motors_info.data += "\tmotor_id: " + std::to_string(_motors_info->motor_info[i].id) + "\n";
		motors_info.data += "\tcmd_position: " + std::to_string(_motors_info->motor_info[i].cmd_position) + "\n";
		motors_info.data += "\tcmd_velocity: " + std::to_string(_motors_info->motor_info[i].cmd_velocity) + "\n";
	}
	motors_info.data += "\n";
	/* 打印接收訊息 */
	RCLCPP_INFO(this->get_logger(), motors_info.data.c_str());
}

/* Program End */
/* ---------------------------------------------------------*/
/* ⇧⇧⇧⇧⇧⇧⇧⇧⇧⇧ Program ⇧⇧⇧⇧⇧⇧⇧⇧⇧⇧ ---------------------------*/
/* ---------------------------------------------------------*/


/* ***** END OF classAPI_subscriber.cpp ***** */