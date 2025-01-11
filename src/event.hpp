#ifndef _EVENT_HPP
#define _EVENT_HPP

#include "default_event_sender.hpp"
#include <list>
template <typename TEventArgs>
class Event : public DefaultEventSender<TEventArgs, std::list> { };

#endif //  _EVENT_HPP
