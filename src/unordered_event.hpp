#ifndef UNORDERED_EVENT_H_
#define UNORDERED_EVENT_H_

// Unlike Event<>, UnorderedEvent<> does not guarantee that all listeners will be executed
// in the same order as they were subscribed for event
#include "default_event_sender.hpp"
#include "fn_set.hpp"
template <typename TEventArgs>
class UnorderedEvent : public DefaultEventSender<TEventArgs, fn_set> { };

#endif // UNORDERED_EVENT_H_
