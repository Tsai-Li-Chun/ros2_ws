/** ******************************************************
	* @file		classAPI_publisher.cpp
	* @author	Tsai,Li-chun
	******************************************************
**	**/


/* System Includes ------------------------------------------*/
/* System Includes Begin */
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

/** * @brief class(publisher_string) 建構涵式
 	* @param None
 	* @return None
**	**/
publisher_string::publisher_string():
	rclcpp::Node("publisher_string"),
	count_autotime_(0),
	count_manual_(0)
{
	publisher_autotime_ = this->create_publisher<std_msgs::msg::String>(
		"topic_string_autotime", 
		10	);
	publisher_manual_ = this->create_publisher<std_msgs::msg::String>(
		"topic_string_manual",
		10	);
	timer_ = this->create_wall_timer(
		std::chrono::milliseconds(500),
		std::bind(&publisher_string::timer_callback, this)	);
}

/** * @brief class(publisher_string) 解建構涵式
 	* @param None
 	* @return None
**	**/
publisher_string::~publisher_string()
{
	RCLCPP_INFO(this->get_logger(),"Quit class publisher_string");
}

/** * @brief class(publisher_string) 手動發佈msg涵式
 	* @param None
 	* @return None
**	**/
void publisher_string::pub_manual_(void)
{
	msg.data = "pub_manual: " + std::to_string(++count_manual_);
	RCLCPP_INFO(this->get_logger(), msg.data.c_str());
	publisher_manual_->publish(msg);
}

/** * @brief class(publisher_string) 500ms計時中斷callback函式
 	* @param None
 	* @return None
**	**/
void publisher_string::timer_callback(void)
{
	msg.data = "pub_autotime: " + std::to_string(++count_autotime_);
	RCLCPP_INFO(this->get_logger(), msg.data.c_str());
	publisher_autotime_->publish(msg);
}

/* Program End */
/* ---------------------------------------------------------*/
/* ⇧⇧⇧⇧⇧⇧⇧⇧⇧⇧ Program ⇧⇧⇧⇧⇧⇧⇧⇧⇧⇧ ---------------------------*/
/* ---------------------------------------------------------*/


/* ***** END OF classAPI_publisher.cpp ***** */