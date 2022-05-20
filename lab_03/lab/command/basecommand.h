#ifndef BASECOMMAND_H
#define BASECOMMAND_H

#include <string>

class BaseCommand {
public:
    BaseCommand() = default;
    virtual ~BaseCommand() = default;
    virtual void execute() = 0;
};


class BaseCameraCommand : public BaseCommand { };

class BaseSceneCommand : public BaseCommand { };

class BaseModelCommand : public BaseCommand { };

#endif // BASECOMMAND_H
