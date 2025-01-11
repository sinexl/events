#ifndef EVENT_BASE_H_
#define EVENT_BASE_H_

#include <functional>
#include "container_pusher.hpp"
#include "function_hash.hpp"
#include <algorithm>
#include <iostream>
template <typename TEventArgs, template <typename...> class Container, typename TContainerPusher = ContainerPusher>
class EventBase { // abstract class
public:
    using callback_signature = void(TEventArgs);
    using callback_fn = std::function<callback_signature>;

protected:
    Container<callback_fn> listeners;

public:
    EventBase()
        : listeners()
    {
    }

    virtual void raise(TEventArgs args) const = 0;
    // Unsubcribe all listeners
    virtual void clear()
    {
        listeners.clear();
    }

    virtual void subscribe(callback_fn fn)
    {
        TContainerPusher::push(listeners, fn);
    }

    void unsubscribe(callback_fn func)
    {
        auto it = find_if(listeners.begin(), listeners.end(), [&func](const callback_fn& i) {
            return FunctionEqual<callback_fn>().operator()(func, i);
        });
        if (it != listeners.end()) {
            std::cout << "DEBUG: Found function" << std::endl;
            listeners.erase(it);
        } else {
            std::cout << "DEBUG: Nothing found" << std::endl;
        }
    }
};

#endif // EVENT_BASE_H_
