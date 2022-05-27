#include "cameraloader.h"

CameraLoader::CameraLoader()
{
    this->file = std::make_shared<std::ifstream>();
}

CameraLoader::CameraLoader(std::shared_ptr<std::ifstream> &file_in)
{
    file = file_in;
}

void CameraLoader::open(std::string &file_name)
{
    if (!file)
    {
        std::string msg = "Error : File open";
        throw FileError(msg);
    }

    file->open(file_name);

    if (!file) {
        std::string msg = "Error : File open";
        throw FileError(msg);
    }
}

void CameraLoader::close() {
    if (!file) {
        std::string msg = "Error : File open";
        throw FileError(msg);
    }
    file->close();
}

std::shared_ptr<Camera> CameraLoader::load(std::shared_ptr<CameraBuilder> builder)
{
    builder->build();
    double x, y, z;
    *file >> x >> y >> z;
    builder->buildCam(x, y, z);
    return builder->get();
}


