#include "InputString.hpp"

using std::string;

InputString::InputString(string _input) {
   input = _input;
}

   // Returns true if input can represent a value in the range of an int
bool InputString::isInt() const {
   try {
       std::stoi(input);
       return true;
   } catch (...) {
      return false;
   }
}

   // Returns true if input can represent an integer in range [low, high]
bool InputString::isIntInRange(int low, int high) const {
   if (!isInt()) {
      return false;
   } else {
      int myInt = std::stoi(input);

      if (myInt >= low && myInt <= high) {
         return true;
      } else {
         return false;
      }
   }
}
