#ifndef INPUT_STRING_HPP_
#define INPUT_STRING_HPP_

#include <string>

/* Using the methods in this class assume that input represents a string with no
   newline, carriage return, etc. delimiters at the end of the string. Only a null
   terminator is acceptable (std::string behavior).
*/

class InputString {
   public:

         // Constructor
      InputString(std::string _input);

         // IsType Methods
      bool isInt() const;
      bool isIntInRange(int low, int high) const;
      int  asInt() const;

   private:
      std::string input;
};


#endif // INPUT_STRING_HPP_
