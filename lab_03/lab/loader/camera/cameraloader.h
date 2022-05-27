#ifndef CAMERALOADER_H
#define CAMERALOADER_H


#include "basecameraloader.h"

class CameraLoader : public BaseCameraLoader {
public:
    CameraLoader();
    explicit CameraLoader(std::shared_ptr<std::ifstream> &file_in);
    ~CameraLoader() override = default;

    void open(std::string &file_name) override;
    void close() override;
    std::shared_ptr<Camera> load(std::shared_ptr<CameraBuilder> builder) override;

protected:
    std::shared_ptr<std::ifstream> file;
};

#endif // CAMERALOADER_H
