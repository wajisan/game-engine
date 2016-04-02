#include "MyException.hpp"

MyException::MyException(const String &msg) throw()
  : _msg(msg)
{}

MyException::~MyException(void) throw()
{}

const char	*MyException::what(void) const throw()
{
  return (this->_msg.c_str());
}
