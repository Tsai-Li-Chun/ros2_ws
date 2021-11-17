/** ******************************************************
	* @file		01_publisher.cpp
	* @author	Tsai,Li-chun
	******************************************************
**	**/


/* System Includes ------------------------------------------*/
/* System Includes Begin */
#include <chrono>
#include <functional>
#include <memory>
#include <string>
/* System Includes End */
/* User Includes --------------------------------------------*/
/* User Includes Begin */
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
/* User Includes End */

/* namespace ------------------------------------------------*/
/* namespace Begin */
using namespace std::chrono_literals;
/* namespace End */


/* Define ---------------------------------------------------*/
/* Define Begin */
/* Define End */


/* Typedef --------------------------------------------------*/
/* Typedef Begin */
/* Typedef End */


/* Class --------------------------------------------------*/
/* Class Begin */

/* 建立發佈用node物件,從rclcpp裡提供的node基礎物件繼承 */
class minimal_publisher : public rclcpp::Node
{
public:
	/* 建構函數 */
	minimal_publisher() : Node("minimal_publisher"),count_(0)
	{
		publisher_ = this->create_publisher<std_msgs::msg::String>
								 ( "topic_string", rclcpp::QoS(10) );
		timer_ = this->create_wall_timer( 500ms, std::bind(&minimal_publisher::timer_callback,this) );
	}
	/* 解建構函數 */
	~minimal_publisher(){}
private:
	void timer_callback()
	{
		msg.data = "ROS2 TsaiLiChun " + std::to_string(count_++);
		RCLCPP_INFO(this->get_logger(), "%s", msg.data.c_str());
      	publisher_->publish(msg);
	}

	/* 建立topic發佈物件 */
	rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
	/* 建立timer物件 */
	rclcpp::TimerBase::SharedPtr timer_;
	/* 建立發佈用資料 */
	std_msgs::msg::String msg;
	/* 宣告計數變數 */
	size_t count_;
};

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
	rclcpp::init(argc, argv);
	rclcpp::spin(std::make_shared<minimal_publisher>());
	rclcpp::shutdown();
}

/* Program End */
/* ---------------------------------------------------------*/
/* ⇧⇧⇧⇧⇧⇧⇧⇧⇧⇧ Program ⇧⇧⇧⇧⇧⇧⇧⇧⇧⇧ ---------------------------*/
/* ---------------------------------------------------------*/


/* ***** END OF 01_publisher.cpp ***** */