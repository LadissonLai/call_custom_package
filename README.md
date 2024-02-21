# 如何在同一工作空间下调用另一ros功能包

本项目有两个ros功能包，a_pack和b_pack。a_pack调用了b_pack的函数，b_pack提供了两个函数，假发和减法。本项目说明如何配置b_pack和a_pack功能包，让a_pack可以调用b_pack。

## 配置b_pack

### # CMakeLists.txt中的配置如下

```cmake
# 这里必须配置，说明b_pack功能包中，可以供外部调用的库。
catkin_package(
 INCLUDE_DIRS include #a_pack功能包调用b_pack寻找的include文件夹
 LIBRARIES b_pack #如果这里没有写的库函数，a_pack功能包就无法使用，即使b_pack功能包编译了该库
)

# 下面两个语句是编译动态库的基本语句，必须有，不必多说。
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)
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

