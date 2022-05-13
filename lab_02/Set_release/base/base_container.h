#ifndef BASE_CONTAINER_H
#define BASE_CONTAINER_H

#include <cstddef>


class base_container
{
    public:
        base_container(): amount(0) {};
        virtual ~base_container() {amount = 0;};
        virtual bool is_empty() const = 0;
        virtual size_t get_size() const = 0;
    protected:
        size_t amount;
};

#endif