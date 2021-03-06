#include "camera.h"

void Camera::move(const Point &move_val)
{
    this->cur_pos.move(move_val.getX(), move_val.getY(), move_val.getZ());
}

void Camera::scale(const Point &scale_val)
{
    this->cur_pos.scale(scale_val.getX(), scale_val.getY(), scale_val.getZ());
}

void Camera::rotate(const Point &rotate_val)
{
    this->cur_pos.rotate(rotate_val.getX(), rotate_val.getY(), rotate_val.getZ());
}

void Camera::setPos(double &x, double &y, double &z)
{
    Point buf(x,y,z);
    this->cur_pos = buf;
}

void Camera::accept(std::shared_ptr<Visitor> visitor)
{
    visitor->visit(*this);
}
