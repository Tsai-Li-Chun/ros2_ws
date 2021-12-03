/** ******************************************************
	* @file		03_service_two_int_add.cpp
	* @author	Tsai,Li-chun
	******************************************************
**	**/


/* System Includes ------------------------------------------*/
/* System Includes Begin */
#include <memory>
/* System Includes End */
/* User Includes --------------------------------------------*/
/* User Includes Begin */
#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"
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

/** * @brief  service 服務中斷函式
 	* @param request service所需輸入參數
 	* @param response service返回參數
 	* @return Node
**	**/
void add(std::shared_ptr<example_interfaces::srv::AddTwoInts::Request> request,
		 std::shared_ptr<example_interfaces::srv::AddTwoInts::Response> response)
{
	response->sum = request->a + request->b;
	RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request\na: %ld" " b: %ld",request->a,request->b);
	RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "sneding back reponse: [%ld]",response->sum);
}

/** * @brief  Program entry point.
 	* @param argc(int) : Number of input parameters
 	* @param argv(int) : input parameters
 	* @return (int) Program Error.
**	**/
int main(int argc, char* argv[])
{
	rclcpp::init(argc, argv);
	std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("service_add_two_ints");
	// std::shared_ptr<rclcpp::Node> nn = std::make_shared<rclcpp::Node>("add_two_ints_service");
	rclcpp::Service<example_interfaces::srv::AddTwoInts>::SharedPtr service
		= node->create_service<example_interfaces::srv::AddTwoInts>("Add_Two_Ints",&add);

	RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready to add two ints.");

	rclcpp::spin(node);
	rclcpp::shutdown();
}

/* Program End */
/* ---------------------------------------------------------*/
/* ⇧⇧⇧⇧⇧⇧⇧⇧⇧⇧ Program ⇧⇧⇧⇧⇧⇧⇧⇧⇧⇧ ---------------------------*/
/* ---------------------------------------------------------*/


/* ***** END OF 03_service_two_int_add.cpp ***** */