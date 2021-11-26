/** ******************************************************
	* @file		01_publisher.cpp
	* @author	Tsai,Li-chun
	******************************************************
**	**/


/* System Includes ------------------------------------------*/
/* System Includes Begin */
/* System Includes End */
/* User Includes --------------------------------------------*/
/* User Includes Begin */
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
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
class publisher_string : public rclcpp::Node
{
public:
	publisher_string():rclcpp::Node("publisher_string"),count_autotime_(0),count_manual_(0)
	{
		publisher_autotime_ = this->create_publisher<std_msgs::msg::String>("topic_string_autotime", 10);
		publisher_manual_ = this->create_publisher<std_msgs::msg::String>("topic_string_manual", 10);
		timer_ = this->create_wall_timer(
			std::chrono::milliseconds(500),
			std::bind(&publisher_string::timer_callback, this)	);
	}
	~publisher_string(){}

	void pub_manual_(void)
	{
		msg.data = "manual pub: " + std::to_string(++count_manual_);
		RCLCPP_INFO(this->get_logger(), msg.data.c_str());
		publisher_manual_->publish(msg);
	}
private:
	void timer_callback(void)
	{
		msg.data = "autotime pub: " + std::to_string(++count_autotime_);
		RCLCPP_INFO(this->get_logger(), msg.data.c_str());
		publisher_autotime_->publish(msg);
	}

	rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_autotime_;
	rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_manual_;
	rclcpp::TimerBase::SharedPtr timer_;
	std_msgs::msg::String msg;
	size_t count_autotime_;
	size_t count_manual_;
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
	rclcpp::init(argc,argv);
	std::shared_ptr<publisher_string> ps = std::make_shared<publisher_string>();
	rclcpp::Rate loop_rate(std::chrono::milliseconds(250));

	while( rclcpp::ok() )
	{
		rclcpp::spin_some(ps);
		ps->pub_manual_();
		loop_rate.sleep();
	}
	rclcpp::shutdown();
}

/* Program End */
/* ---------------------------------------------------------*/
/* ⇧⇧⇧⇧⇧⇧⇧⇧⇧⇧ Program ⇧⇧⇧⇧⇧⇧⇧⇧⇧⇧ ---------------------------*/
/* ---------------------------------------------------------*/


/* ***** END OF 01_publisher.cpp ***** */