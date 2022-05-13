#include "exceptions.h"

ExceptionSet::ExceptionSet(string fileName, string className, int currentLine, const char *errorTime, string information = "Error")
{
    error_message = "\nFile: " + fileName + "\nClass: " + className +
            "\nAt line: " + std::to_string(currentLine) + "\nTime: " + errorTime +
            "Information about error: " + information;
}
