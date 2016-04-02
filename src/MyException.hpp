#ifndef MYEXCEPTION_HPP
#define MYEXCEPTION_HPP

#include <curses.h>
#include <exception>
#include <iostream>
#include <locale.h>
#include <ncurses.h>
#include <unistd.h>
#include <vector>

typedef std::exception	Exception;
typedef std::string	String;

class MyException : public Exception
{
protected:
  const String	_msg;

public:
  MyException(const String &msg) throw();
  virtual ~MyException(void) throw();

  virtual const char	*what(void) const throw();
};

#endif /*!MYEXCEPTION_HPP*/
