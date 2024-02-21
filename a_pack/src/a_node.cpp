#include "a_pack/a.h"
#include "ros/ros.h"

int main(int argc, char **argv) {
  ros::init(argc, argv, "a_pack");

  // 创建一个A类的实例
  a_ns::A_Class a;
  a.hello_world();
  auto ret = a.calculate(1, 2, "+");
  auto ret_pri = a.calculate_private(1, 2, "+");
  std::cout << "ret:     1 + 2 = " << ret << std::endl;
  std::cout << "ret_pri: 1 + 2 = " << ret_pri << std::endl;

  std::cout << "waiting for ctrl c to exit..." << std::endl;
  ros::spin();
}