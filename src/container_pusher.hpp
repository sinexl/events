#ifndef CONTAINER_PUSHER_H_
#define CONTAINER_PUSHER_H_

#include "fn_set.hpp"
#include <list>
#include <vector>
class ContainerPusher { // static class
private:
    ContainerPusher() = delete;
    ~ContainerPusher() = delete;

public:
    template <typename T>
    static inline void push(std::vector<T>& container, const T& value)
    {
        container.push_back(value);
    }

    template <typename T>
    static inline void push(std::list<T>& container, const T& value)
    {
        container.push_back(value);
    }

    template <typename T>
    static inline void push(fn_set<T>& container, const T& value)
    {
        container.insert(value);
    }
};

#endif // CONTAINER_PUSHER_H_
