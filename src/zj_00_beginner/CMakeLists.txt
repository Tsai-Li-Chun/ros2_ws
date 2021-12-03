cmake_minimum_required(VERSION 3.5)
project(zj_00_beginner)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  	set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  	set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  	add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# 所需依賴
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(example_interfaces REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

# 指定額外的include路徑
include_directories(./include/${PROJECT_NAME})

# 生成可執行文件與其所需來源檔
add_executable(01_publisher 
			src/01_publisher.cpp 
			./include/${PROJECT_NAME}/classAPI_publisher.cpp	)
ament_target_dependencies(01_publisher rclcpp std_msgs)

add_executable(02_subscriber 
			src/02_subscriber.cpp
			./include/${PROJECT_NAME}/classAPI_subscriber.cpp	)
ament_target_dependencies(02_subscriber rclcpp std_msgs)

add_executable(03_service_TwoIntAdd 
			src/03_service_two_int_add.cpp	)
ament_target_dependencies(03_service_TwoIntAdd rclcpp example_interfaces)

add_executable(04_client_TwoIntAdd 
			src/04_client_two_int_add.cpp	)
ament_target_dependencies(04_client_TwoIntAdd rclcpp example_interfaces)

install(TARGETS
	01_publisher
	02_subscriber
	03_service_TwoIntAdd
	04_client_TwoIntAdd
	DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
	find_package(ament_lint_auto REQUIRED)
	# the following line skips the linter which checks for copyrights
	# uncomment the line when a copyright and license is not present in all source files
	#set(ament_cmake_copyright_FOUND TRUE)
	# the following line skips cpplint (only works in a git repo)
	# uncomment the line when this package is not in a git repo
	#set(ament_cmake_cpplint_FOUND TRUE)
	ament_lint_auto_find_test_dependencies()
endif()

ament_package()
