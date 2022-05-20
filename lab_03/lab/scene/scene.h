#ifndef SCENE_H
#define SCENE_H

#include "object/object.h"
#include "object/composite/composite.h"
#include "object/invisible/camera/camera.h"


class Scene
{
public:
    Scene() : objects(make_shared<Composite>()) {};
    ~Scene() = default;

    bool addObject(shared_ptr<Object> &obj);
    void removeObject(ObjectIterator &obj);

    void addCamera(shared_ptr<Camera> &cam);
    void removeCamera(size_t index);

    vector<shared_ptr<Camera>> getCameras();
    shared_ptr<Composite> getObjects();

protected:
    shared_ptr<Composite> objects;
    vector<shared_ptr<Camera>> cameras;
};

#endif // SCENE_H
