#ifndef DEFAULT_EVENT_SENDER_H_
#define DEFAULT_EVENT_SENDER_H_
#include "event_base.hpp"

template <typename TEventArgs, template <typename...> typename TContainer>
class DefaultEventSender : public EventBase<TEventArgs, TContainer> {
public:
    virtual void raise(TEventArgs args) const override
    {
        for (auto function : this->listeners) {
            function(args);
        }
    }
};

#endif // DEFAULT_EVENT_SENDER_H_
