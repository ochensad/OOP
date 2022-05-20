#ifndef FILELOADER_H
#define FILELOADER_H

#include "baseloader.h"
#include <fstream>
#include "builder/modelbuilder.h"

class FileLoader : public BaseLoader
{
public:
    FileLoader() = default;
    virtual ~FileLoader() = default;

    virtual shared_ptr<Object> load(shared_ptr<BaseBuilder> builder) override;
    virtual void open(string &fname) override;
    virtual void close() override;
protected:
    std::ifstream file;
};

#endif // FILELOADER_H
