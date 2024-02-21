#ifndef __A_H
#define __A_H

#include <string>

namespace a_ns {

class A_Class {
 public:
  void hello_world();
  double calculate(double a, double b, std::string op);
  double calculate_private(double a, double b, std::string op);
};

}  // namespace a_ns

#endif