// uLogDevelopment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fmt/format.h>

int main()
{
  std::string s = fmt::format("Hello, {}!\n", "world");
  
  std::cout << s;
}