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

/** * @brief 發佈服務物件，繼承rclcpp::Node
 	* @param None
 	* @return None
**	**/
class publisher_string : public rclcpp::Node
{
private:
/* Class --------------------------------------------------*/
	/* 宣告自動發佈用物件 */
	rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_autotime_;
	/* 宣告手動發佈用物件 */
	rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_manual_;
	/* 宣告時間管理物件 */
	rclcpp::TimerBase::SharedPtr timer_;
	/* 宣告string資料型態物件 */
	std_msgs::msg::String msg;
/* Variables ----------------------------------------------*/
	/* 宣告計數自動發佈次數用變數 */
	size_t count_autotime_;
	/* 宣告計數手動發佈次數用變數 */
	size_t count_manual_;
/* Function ----------------------------------------------*/
	// 
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