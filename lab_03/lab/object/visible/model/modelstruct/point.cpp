#include "point.h"
#include <iostream>

Point::Point()
{
    this->x = 0.0;
    this->y = 0.0;
    this->z = 0.0;
}

Point::Point(const double x, const double y, const double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Point::Point(const Point &point)
{
    this->x = point.x;
    this->y = point.y;
    this->z = point.z;
}

Point& Point::operator=(const Point& point)
{
    this->x = point.x;
    this->y = point.y;
    this->z = point.z;
    return *this;
}

Point::Point(const Point &&point)
{
    this->x = point.x;
    this->y = point.y;
    this->z = point.z;
    point.~Point();
}

Point& Point::operator=(const Point&& point)
{
    this->x = point.x;
    this->y = point.y;
    this->z = point.z;
    point.~Point();
    return *this;
}

void Point::move(const double &dx, const double &dy, const double &dz)
{
    this->x += dx;
    this->y += dy;
    this->z += dz;
}

void Point::scale(const double &kx, const double &ky, const double &kz)
{
    this->x *= kx;
    this->y *= ky;
    this->z *= kz;
}

void Point::rotate(const double &fx, const double &fy, const double &fz)
{
    this->rotateX(fx);
    this->rotateY(fy);
    this->rotateZ(fz);
}

void Point::rotateX(const double &fx)
{
    const double temp_y = this->y;
    const double temp_z = this->z;
    this->y = temp_y * cos(fx * M_PI / 180.0) + temp_z * sin(fx * M_PI / 180.0);
    this->z = - temp_y * sin(fx * M_PI / 180.0) + temp_z * cos(fx * M_PI / 180.0);
}

void Point::rotateY(const double &fy)
{
    const double temp_x = this->x;
    const double temp_z = this->z;
    this->x = temp_x * cos((fy * M_PI) / 180.0) + temp_z * sin((fy * M_PI) / 180.0);
    this->z = -temp_x * sin((fy * M_PI) / 180.0) + temp_z * cos((fy * M_PI) / 180.0);
}

void Point::rotateZ(const double &fz)
{
    const double temp_x = this->x;
    const double temp_y = this->y;
    this->x = temp_x * cos(fz * M_PI / 180.0) + temp_y * sin(fz * M_PI / 180.0);
    this->y = -temp_x * sin(fz * M_PI / 180.0) + temp_y * cos(fz * M_PI / 180.0);
}
