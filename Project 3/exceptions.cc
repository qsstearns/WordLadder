#include "exceptions.h"

const std::string Exception::toString(void) {
  std::string
    msg;

  if (source().length() > 0)
    msg = source() + ": ";
  else
    msg = "";

  msg += "generic exception";

  return msg;
}

const std::string ContainerEmptyException::toString(void) {
  std::string
    msg;

  if (source().length() > 0)
    msg = source() + ": ";
  else
    msg = "";

  msg += "container empty";

  return msg;
}

const std::string ContainerFullException::toString(void) {
  std::string
    msg;

  if (source().length() > 0)
    msg = source() + ": ";
  else
    msg = "";

  msg += "container full";

  return msg;
}

const std::string KeyNotFoundException::toString(void) {
  std::string
    msg;

  if (source().length() > 0)
    msg = source() + ": ";
  else
    msg = "";

  msg += "key '" + key + "' not found";

  return msg;
}

const std::string InvalidIndexException::toString(void) {
  std::string
    msg;

  if (source().length() > 0)
    msg = source() + ": ";
  else
    msg = "";

  msg += "invalid index " + std::to_string(index);

  return msg;
}

