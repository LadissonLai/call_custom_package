#include "a_pack/a.h"
#include "b_pack/b.h"
#include "b_pack/b_private.h"
#include "iostream"

namespace a_ns {

void A_Class::hello_world() { std::cout << "Hello, world!" << std::endl; }
double A_Class::calculate(double a, double b, std::string op) {
  if (op == "+") {
    return b_ns::add(a, b);
  } else if (op == "-") {
    return b_ns::sub(a, b);
  }
  return 0;
}

double A_Class::calculate_private(double a, double b, std::string op) {
  if (op == "+") {
    return b_ns::add_private(a, b);
  } else if (op == "-") {
    return b_ns::sub_private(a, b);
  }
  return 0;
}

}  // namespace a_ns
