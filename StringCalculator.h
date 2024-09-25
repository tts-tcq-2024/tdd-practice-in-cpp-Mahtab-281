#define STRINGCALCULATOR_H
#define STRINGCALCULATOR_H
 
#include <string>
#include <cctype>
#include <iostream>
 
class StringCalculator
{
  public:
    int less_than_thousand(int num);
    int get_positive_number(int num);
    std::string processed_String_for_delimiters(std::string input);
    int exception_handling_for_whitespce(std::string token);
    int add(std::string input);
};
