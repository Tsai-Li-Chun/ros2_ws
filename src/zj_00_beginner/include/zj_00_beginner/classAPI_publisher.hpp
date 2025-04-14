/** ******************************************************
	* @file		classAPI_publisher.h
	* @author	Tsai,Li-chun
	******************************************************
**	**/

/* Define to prevent recursive inclusi ----------------------*/
#ifndef __classAPI_publisher_HPP__
#define __classAPI_publisher_HPP__


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

/** * @brief 發佈服務物件，繼承rclcpp::Node
 	* @param None
 	* @return None
**	**/
class publisher_motors_info : public rclcpp::Node
{
private:
/* Class --------------------------------------------------*/
	/* declare publishing object, used for publishing MultipleMotors data */
	rclcpp::Publisher<zj_00_beginner_interfaces::msg::InterfaceMultipleMotors>::SharedPtr _publisher_motors_info;
	/* declare time management object */
	rclcpp::TimerBase::SharedPtr _timer;
	/* declare String data type object */
	std_msgs::msg::String msg;
	/* declare MultipleMotors data type object */
	zj_00_beginner_interfaces::msg::InterfaceMultipleMotors motors_info;
	/* declare SingleMotor data type object */
	zj_00_beginner_interfaces::msg::InterfaceSingleMotor motor_info;
/* Variables ----------------------------------------------*/
	/* declare variable to count the number of publish */
	size_t count;
/* Function -----------------------------------------------*/
	/* declare timer callback function for _timer object */
	void callback_timer(void);

public:
/* setup -------------------------------------------------*/
	/* constructor */
	publisher_motors_info();
	/* destructor */
	~publisher_motors_info();
/* Class --------------------------------------------------*/
/* Variables ----------------------------------------------*/
/* Function -----------------------------------------------*/

};

/* Extern Class End */


/* Extern Variables -----------------------------------------*/
/* Extern Variables Begin */
/* Extern Variables End */


/* Function -------------------------------------------------*/
/* Function Begin */
/* Function End */


#endif /*__ classAPI_publisher_HPP__ */

/* ***** END OF classAPI_publisher.HPP ***** */