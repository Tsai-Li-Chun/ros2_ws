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
/* User Includes End */


/* Define ---------------------------------------------------*/
/* Define Begin */
/* Define End */


/* Extern Typedef -------------------------------------------*/
/* Extern Typedef Begin */
/* Extern Typedef End */


/* Class --------------------------------------------------*/
/* Class Begin */

class publisher_string : public rclcpp::Node
{
private:
	rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_autotime_;
	rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_manual_;
	rclcpp::TimerBase::SharedPtr timer_;
	std_msgs::msg::String msg;
	size_t count_autotime_;
	size_t count_manual_;
	void timer_callback(void);
public:
	publisher_string();
	~publisher_string();
	void pub_manual_(void);
};

/* Class End */


/* Extern Variables -----------------------------------------*/
/* Extern Variables Begin */
/* Extern Variables End */


/* Function -------------------------------------------------*/
/* Function Begin */
/* Function End */


#endif /*__ classAPI_publisher_HPP__ */

/* ***** END OF classAPI_publisher.HPP ***** */