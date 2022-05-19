#ifndef CONNECT_H
#define CONNECT_H

#include <stdlib.h>


class Connect
{
public:
    Connect() : first_point_index(0), second_point_index(0) {};
    Connect(const size_t &first_p, const size_t &second_p): first_point_index(first_p), second_point_index(second_p) {};
    Connect(const Connect &con);
    ~Connect() = default;

    size_t getFirstPoint() const;
    size_t getSecondPoint() const;

    void setFirstPoint(const size_t &fst);
    void setSecondPoint(const size_t &snd);
private:
    size_t first_point_index;
    size_t second_point_index;
};

#endif // CONNECT_H
