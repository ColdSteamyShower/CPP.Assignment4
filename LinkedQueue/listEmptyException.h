#include <exception>

using namespace std;

class listEmptyException {
private:
  string errorMessage;
public:
  listEmptyException() //constructor
  {
    errorMessage = "The list is empty. Cannot remove item";
  }

  listEmptyException(string err) //constructor
  {
    errorMessage = err;
  }

  string getError() // accessing the error message
  {
    return errorMessage;
  }
};
