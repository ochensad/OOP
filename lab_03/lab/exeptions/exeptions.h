#ifndef EXEPTIONS_H
#define EXEPTIONS_H

#include <exception>
#include <string>

class Error : public std::exception
{
public:
    Error() = default;
    Error(std::string &message) : error_message(message) {};

    const char *what() const noexcept override
    {
        return "Something breaks...";
    }

    const std::string &getInfo() const noexcept
    {
        return error_message;
    }
protected:
    std::string error_message;
};


class CameraError : public Error
{
public:
    CameraError() = default;
    CameraError(std::string &message): Error(message) {};
    const char *what() const noexcept override
    {
        return "Camera doesn't set.";
    }
};

class FileError : public Error
{
public:
    FileError() = default;
    FileError(std::string &message): Error(message) {};
    const char *what() const noexcept override
    {
        return "File doesn't exist.";
    }
};

class ModelError : public Error
{
public:
    ModelError() = default;
    ModelError(std::string &message): Error(message) {};
    const char *what() const noexcept override
    {
        return "Error while building model.";
    }
};

class IdError : public Error
{
public:
    IdError() = default;
    IdError(std::string &message): Error(message) {};
    const char *what() const noexcept override
    {
        return "Error can't find id.";
    }
};

#endif // EXEPTIONS_H
