#ifndef _EXCEPTIONS_H
#define _EXCEPTIONS_H

#include <string>

class AbstractException {
 public:
  AbstractException(std::string src) { this->src = src; }
  ~AbstractException() { }

  const std::string &source(void) { return src; }

  virtual const std::string toString() =0;

 private:
  std::string
    src;
};

class Exception : public AbstractException {
 public:
  Exception(std::string src="") : AbstractException(src) { }
  ~Exception() { }

  const std::string toString();
};

class ContainerEmptyException : public Exception {
 public:
  ContainerEmptyException(std::string src="") : Exception(src) { }
  ~ContainerEmptyException() { }

  const std::string toString();
};

class ContainerFullException : public Exception {
 public:
  ContainerFullException(std::string src="") : Exception(src) { }
  ~ContainerFullException() { }

  const std::string toString();
};

class KeyNotFoundException : public Exception {
 public:
  KeyNotFoundException(std::string key="",std::string src="") :
	 Exception(src) { this->key = key; }
  ~KeyNotFoundException() { }

  const std::string toString();

 private:
  std::string
    key;
};

class InvalidIndexException : public Exception {
 public:
  InvalidIndexException(int index=0,std::string src="") :
	 Exception(src) { this->index = index; }
  ~InvalidIndexException() { }

  const std::string toString();

 private:
  int
    index;
};

#endif

