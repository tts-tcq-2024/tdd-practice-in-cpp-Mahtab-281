#include "StringCalculator.h"
#include <sstream>
#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <string>
 
std::vector<int> negatives;
int flag = 0;
class NegativeNumberException : public std::runtime_error {
public:
    NegativeNumberException(const std::string& message)
        : std::runtime_error(message) {}
};
void throw_error()
{
        std::string message = "Negatives not allowed: ";
        for (int i = 0; i < negatives.size(); ++i) 
            {
                message += std::to_string(negatives[i]);
                if (i < negatives.size() - 1) 
                {
                    message += ", ";
                }
            }
        throw NegativeNumberException(message);
}
int StringCalculator::less_than_thousand(int num)
    {
       if (num>=1000)
         return 0;
      else
         return num;
    }
int StringCalculator::get_positive_number(int num)
{
    int digit = 0;
    if(num>=0)
        digit = less_than_thousand(num);
    else
    {
        negatives.push_back(num);
        flag++;
    }
    return digit;
}
 
std::string StringCalculator::processed_String_for_delimiters(std::string input)
{
      if (input.substr(0, 2) == "//") 
     {
        char delimiter = input[2];  
        input = input.substr(4);
        std::replace(input.begin(), input.end(), delimiter, ',');
     }
      std::replace(input.begin(), input.end(), '\n', ',');
    return input;
}
 
int StringCalculator::exception_handling_for_whitespce(std::string token)
{
    if (!token.empty()) 
    {  // Check if the token is not empty
        int num = std::stoi(token);  // Convert to integer
        return num;
    } 
    else 
    {
        return 0;
    }
}
int StringCalculator::add(std::string input)
   { 
      std::string processed_input = processed_String_for_delimiters(input);
      int sum = 0;
      std::stringstream ss(processed_input);
      std::string token;  
      while(std::getline(ss,token,','))
      {
          int num = exception_handling_for_whitespce(token);
          int addition = get_positive_number(num);
          sum += addition;
    }
       if(flag>0)
          throw_error();
      return sum;
   }
