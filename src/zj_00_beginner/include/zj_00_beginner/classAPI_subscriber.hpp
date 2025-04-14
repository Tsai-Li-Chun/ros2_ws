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
#include "zj_00_beginner_interfaces/msg/interface_multiple_motors.hpp"
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
class subscriber_motors_info : public rclcpp::Node
{
private:
/* Class --------------------------------------------------*/
	/* declare subscribing object, used for publishing MultipleMotors data */
	rclcpp::Subscription<zj_00_beginner_interfaces::msg::InterfaceMultipleMotors>::SharedPtr _subscriber_motors_info;
/* Function ----------------------------------------------*/
	/* declare motors_info callback function for _subscriber object */
	void callback_topic_motors_info(zj_00_beginner_interfaces::msg::InterfaceMultipleMotors::SharedPtr);

public:
/* setup -------------------------------------------------*/
	/* constructor */
	subscriber_motors_info();
	/* destructor */
	~subscriber_motors_info();
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