#ifndef FILECAMERALOADER_H
#define FILECAMERALOADER_H

#include "builder/basebuilder.h"
#include "loader/baseloader.h"
#include <fstream>
#include "builder/camerabuilder.h"


class FileCameraLoader : public BaseLoader
{
public:
    FileCameraLoader() = default;
    virtual ~FileCameraLoader() = default;

    virtual shared_ptr<Object> load(shared_ptr<BaseBuilder> builder) override;
    virtual void open(string &fname) override;
    virtual void close() override;
protected:
    std::ifstream file;
};

#endif // FILECAMERALOADER_H
