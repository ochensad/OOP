#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>
#include <iostream>

using string = std::string;

class ExceptionSet: public std::exception
{
    protected:
        string error_message;
    public:
        ExceptionSet(string fileName, string className,
                  int currentLine, const char *errorTime,
                  string information);
        virtual ~ExceptionSet() {};
        virtual const char *what() const noexcept override
        {
            return error_message.c_str();
        };
};

class DeletedObjectException: public ExceptionSet
{
    public:
        DeletedObjectException(string filename, string className, int currentLine, const char *errorTime, string information = "Object doesn't exist"):
        ExceptionSet(filename, className, currentLine, errorTime, information)
        {};
};

class OutOfRangeIndexException: public ExceptionSet
{
    public:
        OutOfRangeIndexException(string fileName, string className,
                               int currentLine, const char *errorTime,
                               string information = "Iterator index is out of range!"):
            ExceptionSet(fileName, className, currentLine, errorTime, information) {
        };
};

class WrongIndexException: public ExceptionSet
{
    public:
        WrongIndexException(string fileName, string className,
                               int currentLine, const char *errorTime,
                               string information = "Iterator index is less than zero!"):
            ExceptionSet(fileName, className, currentLine, errorTime, information) {
        };
};

class EmptyBaseException: public ExceptionSet
{
    public:
        EmptyBaseException(string fileName, string className,
                               int currentLine, const char *errorTime,
                               string information = "The Base is empty!"):
            ExceptionSet(fileName, className, currentLine, errorTime, information) {
        };
};

class MemoryException: public ExceptionSet
{
public:
    MemoryException(string fileName, string className,
                    int currentLine, const char *errorTime,
                    string information = "Allocation memory error!\n"):
    ExceptionSet(fileName, className, currentLine, errorTime, information) {
    };
};

#include "exceptions.hpp"

#endif