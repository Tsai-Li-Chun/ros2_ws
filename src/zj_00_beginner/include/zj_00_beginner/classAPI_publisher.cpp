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
publisher_motors_info::publisher_motors_info():
	rclcpp::Node("publisher_motors_info"),
	count(0)
{
	/* 建立自動發佈用物件，並設定topic名與QoS */
	_publisher_motors_info = this->create_publisher<zj_00_beginner_interfaces::msg::InterfaceMultipleMotors>(
		"topic_MultipleMotors",
		rclcpp::QoS(10)	);

	/* 建立時間管理物件，並設定中斷時間與指定callback函式 */
	_timer = this->create_wall_timer(
		std::chrono::milliseconds(500),
		std::bind(&publisher_motors_info::callback_timer, this)	);

	/* set the array length of SingleMotor in MultipleMotors */
	motors_info.motor_info.resize(7);
}

/** * @brief 解建構涵式
 	* @param None
 	* @return None
**	**/
publisher_motors_info::~publisher_motors_info()
{
	/* 打印結束訊息 */
	RCLCPP_INFO(this->get_logger(),"Quit Node publisher_string");
}

/** * @brief 500ms計時中斷callback函式
 	* @param None
 	* @return None
**	**/
void publisher_motors_info::callback_timer(void)
{
	/* fill in value */
	motors_info.link_form = "parallel connection";
	motors_info.quantity = 7;
	for(int i=0;i<7;i++)
	{
		motor_info.id = count+i;
		motor_info.device_type = "delta A3";
		motor_info.cmd_position = count+i+1.1;
		motor_info.cmd_velocity = count+i+2.2;
		motors_info.motor_info[i] = motor_info;
	}

	msg.data = "number of publish: " + std::to_string(++count);
	/* 打印相關訊息 */
	RCLCPP_INFO(this->get_logger(), msg.data.c_str());
	/* 發佈(中斷時間一到會自動呼叫此函式) */
	_publisher_motors_info->publish(motors_info);
}

/* Program End */
/* ---------------------------------------------------------*/
/* ⇧⇧⇧⇧⇧⇧⇧⇧⇧⇧ Program ⇧⇧⇧⇧⇧⇧⇧⇧⇧⇧ ---------------------------*/
/* ---------------------------------------------------------*/


/* ***** END OF classAPI_publisher.cpp ***** */