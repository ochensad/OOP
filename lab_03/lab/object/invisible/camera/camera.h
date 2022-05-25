#ifndef CAMERA_H
#define CAMERA_H

#include "../invisibleobject.h"

class Camera : public InvisibleObject
{
public:
    Camera() = default;
    Camera(const Point &pos) : cur_pos(pos) {};
    Camera(shared_ptr<Camera> &cam) : cur_pos(cam->getPos()) {};
    ~Camera() = default;

    virtual ObjectIterator begin() override {return ObjectIterator();};
    virtual ObjectIterator end() override {return ObjectIterator();};

    virtual bool isComposite() const override {return false;};
    virtual bool isVisible() const override {return false;};
    virtual void transform(const Point &move_val, const Point &rotate_val, const Point &scale_val) override;
    virtual void accept(std::shared_ptr<Visitor> visitor) override;

    Point getPos() {return cur_pos;};
    void setPos(double &x, double &y, double &z);
private:
    Point cur_pos;
};

#endif // CAMERA_H
