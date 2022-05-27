#ifndef MODELLOADER_H
#define MODELLOADER_H

#include "basemodelloader.h"

class ModelLoader : public BaseModelLoader
{
public:
    ModelLoader();
    explicit ModelLoader(std::shared_ptr<std::ifstream> &file_in);
    ~ModelLoader() override = default;

    void open(std::string &file_name) override;
    void close() override;
    std::shared_ptr<Object> load(std::shared_ptr<ModelBuilder> builder) override;

protected:
    std::shared_ptr<std::ifstream> file;
};

#endif // MODELLOADER_H
