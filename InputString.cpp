/************************************************************************************
filename: InputString.cpp
 authors: Danny
************************************************************************************/

#include "InputString.hpp"

using std::string;
using std::stoi;
using std::to_string;

InputString::InputString(string _input) {
   input = _input;
}

   // Returns true if input can represent a value in the range of an int
bool InputString::isInt() const {
   try {
       int num = stoi(input);

          // If # of digits in num == input.length(), true. Else, false.
       if (to_string(num).length() == input.length()) {
          return true;
       } else {
          return false;
       }
   } catch (...) {
      return false;
   }
}

   // Returns true if input can represent an integer in range [low, high]
bool InputString::isIntInRange(int low, int high) const {
   if (!isInt()) {
      return false;
   } else {
      int myInt = stoi(input);

      if (myInt >= low && myInt <= high) {
         return true;
      } else {
         return false;
      }
   }
}


   // WARNING! User must ensure input can represent int before calling
int InputString::asInt() const {
   return stoi(input);
}