#include "modelloader.h"

ModelLoader::ModelLoader()
{
    file = std::make_shared<std::ifstream>();
}

ModelLoader::ModelLoader(std::shared_ptr<std::ifstream> &file_in)
{
    file = file_in;
}

void ModelLoader::open(std::string &file_name)
{
    if (!file) {
        std::string msg = "Error : File open";
        throw FileError(msg);
    }
    file->open(file_name);
    if (!file) {
        std::string msg = "Error : File open";
        throw FileError(msg);
    }
}

void ModelLoader::close()
{
    if (!file) {
        std::string msg = "Error : File open";
        throw FileError(msg);
    }
    file->close();
}


std::shared_ptr<Object> ModelLoader::load(std::shared_ptr<ModelBuilder> builder)
{
    builder->build();
    int point_count;
    *file >> point_count;
    for (int i = 0; i < point_count; i++) {
        double x, y, z;
        *file >> x >> y >> z;
        builder->buildPoint(x, y, z);
    }

    int connections_count;
    *file >> connections_count;

    for (int i = 0; i < connections_count; i++) {
        int dot1_num, dot2_num;
        *file >> dot1_num >> dot2_num;
        builder->buildConnect(dot1_num, dot2_num);
    }
    return builder->get();
}
