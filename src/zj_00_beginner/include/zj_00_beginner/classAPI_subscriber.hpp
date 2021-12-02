/** ******************************************************
	* @file		classAPI_subscriber.hpp.h
	* @author	Tsai,Li-chun
	******************************************************
**	**/

/* Define to prevent recursive inclusi ----------------------*/
#ifndef __classAPI_subscriber_HPP__
#define __classAPI_subscriber_HPP__


/* System Includes ------------------------------------------*/
/* System Includes Begin */
/* System Includes End */
/* User Includes --------------------------------------------*/
/* User Includes Begin */
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
/* User Includes End */


/* Define ---------------------------------------------------*/
/* Define Begin */
/* Define End */


/* Extern Typedef -------------------------------------------*/
/* Extern Typedef Begin */
/* Extern Typedef End */


/* Extern Class -------------------------------------------*/
/* Extern Class Begin */

/** * @brief 訂閱服務物件，繼承rclcpp::Node
 	* @param None
 	* @return None
**	**/
class subscriber_string : public rclcpp::Node
{
private:
/* Class --------------------------------------------------*/
	/* 宣告訂閱用物件 */
	rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscriber_autotime_;
	/* 宣告訂閱用物件 */
	rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscriber_manual_;
/* Function ----------------------------------------------*/
	// 
	void topic_string_autotime_callback(std_msgs::msg::String::SharedPtr);
	void topic_string_manual_callback(std_msgs::msg::String::SharedPtr);
public:
/* setup -------------------------------------------------*/
	// 
	subscriber_string();
	~subscriber_string();
};

/* Extern Class End */


/* Extern Variables -----------------------------------------*/
/* Extern Variables Begin */
/* Extern Variables End */


/* Function -------------------------------------------------*/
/* Function Begin */
/* Function End */


#endif /*__ classAPI_subscriber_HPP__ */

/* ***** END OF classAPI_subscriber.HPP ***** */