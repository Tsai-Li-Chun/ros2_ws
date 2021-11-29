/** ******************************************************
	* @file		01_publisher.cpp
	* @author	Tsai,Li-chun
	******************************************************
**	**/


/* System Includes ------------------------------------------*/
/* System Includes Begin */
#include <iostream>
#include <memory>
#include <functional>
/* System Includes End */
/* User Includes --------------------------------------------*/
/* User Includes Begin */
#include "rclcpp/rclcpp.hpp"
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

/** * @brief  Program entry point.
 	* @param argc(int) : Number of input parameters
 	* @param argv(int) : input parameters
 	* @return (int) Program Error.
**	**/
int main(int argc, char* argv[])
{
	/* 初始化ROS2 Node */
	rclcpp::init(argc,argv);
	/* 建立發佈服務物件 */
	std::shared_ptr<publisher_string> ps = std::make_shared<publisher_string>();
	/* 建立delay服務物件 */
	rclcpp::Rate loop_rate(std::chrono::milliseconds(250));

	/* main loop, 按下ctrl+C跳出 */
	while( rclcpp::ok() )
	{
		/* 更新物件執行 */
		rclcpp::spin_some(ps);
		/* 手動呼叫發佈函式 */
		ps->pub_manual_();
		/* delay */
		loop_rate.sleep();
	}

	/* 關閉Node */
	rclcpp::shutdown();
}

/* Program End */
/* ---------------------------------------------------------*/
/* ⇧⇧⇧⇧⇧⇧⇧⇧⇧⇧ Program ⇧⇧⇧⇧⇧⇧⇧⇧⇧⇧ ---------------------------*/
/* ---------------------------------------------------------*/


/* ***** END OF 01_publisher.cpp ***** */