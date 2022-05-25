#include "filecameraloader.h"

shared_ptr<Object> FileCameraLoader::load(shared_ptr<BaseBuilder> builder)
{
    auto builder_new =  std::dynamic_pointer_cast<CameraBuilder>(builder);
    builder_new->build();

    double x, y, z;
    this->file >> x >> y >> z;
    builder_new->buildCam(x, y, z);

    return builder_new->get();
}

void FileCameraLoader::open(std::string &fname)
{
    try
    {
        this->file.open(fname);
    }
    catch (std::ifstream::failure &error)
    {
        error.what();
    }
}

void FileCameraLoader::close()
{
    try
    {
        this->file.close();
    } catch (std::ifstream::failure &error)
    {
        error.what();
    }
}
