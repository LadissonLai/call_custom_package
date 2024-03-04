# 如何在同一工作空间下调用另一ros功能包

本项目有两个ros功能包，a_pack和b_pack，a_pack调用了b_pack的函数，本项目为了展示如何配置b_pack和a_pack功能包，让a_pack可以调用b_pack。

在c++编程中，常见用法是将b_pack编译成库文件，然后b_pack对外提供头文件，a_pack对b_pack的调用就是通过引用头文件和库文件完成的。这是c++编程的基本功，见我的另一个github仓库，使用cmake实现。

本项目给出在ROS环境下如何把功能包封装成库文件，以及如何给别人调用。

总结：

1. 创建b_pack功能包时，CMake编译时配置catkin_package()，里面说明了该功能包导出的库文件和头文件。
1. a_pack调用时b_pack时需要声明依赖，分别在a_pack的package.xml和CMakeLists.txt中声明。

详情请见下面的两个配置。

## 配置b_pack

### # CMakeLists.txt中的配置如下

```cmake
# 这里必须配置，说明b_pack功能包中，导出的库和头文件。
catkin_package(
 INCLUDE_DIRS include #a_pack功能包调用b_pack寻找的include文件夹
 LIBRARIES b_pack #如果这里没有写的库函数，a_pack功能包就无法使用，即使b_pack功能包编译了该库
)

# 声明b_pack库文件的头文件的位置
include_directories(
  include 
  ${catkin_INCLUDE_DIRS}
)
# 添加库，如果该库有依赖的库，还需要添加依赖
add_library(b_pack src/b.cpp)
```

## 配置a_pack

#### package.xml

```xml
<!--给功能包a_pack添加对b_pack功能包的引用-->
<build_depend>b_pack</build_depend>
<build_export_depend>b_pack</build_export_depend>
<exec_depend>b_pack</exec_depend>
```

### CMakeLists.txt

```cmake
find_package(catkin REQUIRED COMPONENTS
  b_pack #必须有
)

add_executable(a_node src/a_node.cpp src/a.cpp)
target_link_libraries(a_node
  ${catkin_LIBRARIES}
  b_pack #必须有
)
```

## 使用方法

```shell
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws/src
git clone https://github.com/LadissonLai/call_custom_package.git
cd ~/catkin_ws
catkin_make
source ./devel/setup.bash
rosrun a_pack a_node
```

## 完整项目
完整项目请见github[仓库](https://github.com/LadissonLai/call_custom_package.git).