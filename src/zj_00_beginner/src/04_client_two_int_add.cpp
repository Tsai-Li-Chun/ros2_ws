/** ******************************************************
	* @file		04_client_two_int_add.cpp
	* @author	Tsai,Li-chun
	******************************************************
**	**/


/* System Includes ------------------------------------------*/
/* System Includes Begin */
#include <chrono>
#include <cstdlib>
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

/** * @brief  Program entry point.
 	* @param argc(int) : Number of input parameters
 	* @param argv(int) : input parameters
 	* @return (int) Program Error.
**	**/
int main(int argc, char **argv)
{
	rclcpp::init(argc,argv);
	if(argc != 3)
	{
		RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "usage: client_add_two_ints: X Y");
		rclcpp::shutdown(); return 1;
	}

	std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("client_add_two_ints");
	rclcpp::Client<example_interfaces::srv::AddTwoInts>::SharedPtr client = 
		node->create_client<example_interfaces::srv::AddTwoInts>("Add_Two_Ints");

	std::shared_ptr<example_interfaces::srv::AddTwoInts::Request> request
		= std::make_shared<example_interfaces::srv::AddTwoInts::Request>();
	request->a = atoll(argv[1]);
	request->b = atoll(argv[2]);

	bool srv_setup_check = client->wait_for_service(std::chrono::seconds(1));
	while( !srv_setup_check )
	{
		RCLCPP_WARN(rclcpp::get_logger("rclcpp"), "service not available, waiting again...");
		srv_setup_check = client->wait_for_service(std::chrono::seconds(1));
		if( !(rclcpp::ok()) )
		{
			RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service");
			rclcpp::shutdown(); return 0;
		}
	}
	RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Confirm service \"Add_Two_Ints\" complete");
	
	rclcpp::Rate delay(std::chrono::seconds(5));
	delay.sleep();

	std::shared_future<std::shared_ptr<example_interfaces::srv::AddTwoInts::Response>> 
		result = client->async_send_request(request);

	rclcpp::FutureReturnCode srv_response_check
		= rclcpp::spin_until_future_complete(node, result, std::chrono::seconds(5));
	if( srv_response_check == rclcpp::FutureReturnCode::SUCCESS )
	{
		RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "service Add_Two_Int Success！");
		RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "sum: %ld", result.get()->sum);
	}
	else
	{
		RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to call service Add_Two_Int");
		rclcpp::shutdown();return 1;
	}

	rclcpp::shutdown();
}

/* Program End */
/* ---------------------------------------------------------*/
/* ⇧⇧⇧⇧⇧⇧⇧⇧⇧⇧ Program ⇧⇧⇧⇧⇧⇧⇧⇧⇧⇧ ---------------------------*/
/* ---------------------------------------------------------*/


/* ***** END OF 04_client_two_int_add.cpp ***** */