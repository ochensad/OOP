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

    virtual shared_ptr<Object> load(shared_ptr<ModelBuilder> builder);
    virtual void open(string &fname) override;
    virtual void close() override;
protected:
    std::ifstream file;
};

#endif // FILELOADER_H
