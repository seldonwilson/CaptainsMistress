#ifndef INPUT_STRING_HPP_
#define INPUT_STRING_HPP_

#include <string>


class InputString {
   public:

         // Constructor
      InputString(std::string _input);

         // IsType Methods
      bool isInt() const;
      bool isIntInRange(int low, int high) const;

   private:
      std::string input;
};


#endif // INPUT_STRING_HPP_
