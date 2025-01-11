#include "event.hpp"
#include "event_base.hpp"
using namespace std;

class MailSender;

struct MessageArgs {
    MailSender* const sender; // events may not know who sent the message, if it's not needed
    const char* msg;
};

class MailSender {
public:
    using callback_fn = Event<MessageArgs>::callback_fn;
private:
    Event<MessageArgs> event = Event<MessageArgs>();

public:
    void send_to_all(const char* msg)
    {
        event.raise(MessageArgs { this, msg });
    }

    void subscribe(const callback_fn fn)
    {
        event.subscribe(fn);
    }
    void unsubscribe(const callback_fn fn)
        {
            event.unsubscribe(fn);
        }

    const char* name()
    {
        return "John";
    }
    MailSender() = default;
};

class Receiver {
private:
    static int client_counter;
    int id;
    function<void(MessageArgs)> key;

public:
    void func(MessageArgs a)
    {
        cout << "Client with ID " << id << " has accepted message from " << a.sender->name() << endl;;
        cout << "Message: " << a.msg << endl;
    }
    Receiver(MailSender& mail)
    {
        client_counter++;
        id = client_counter;
        mail.subscribe(key = [this](MessageArgs a) {
            this->func(a);
        });
    }

    void unsubscribe(MailSender& mail) const
    {
        mail.unsubscribe(key);
    }
};
int Receiver::client_counter = 0;

int main()
{
    MailSender mail;
    Receiver first_client(mail);
    Receiver second_client(mail);
    Receiver third_client(mail);
    third_client.unsubscribe(mail);
    mail.send_to_all("Hello, World!");

    return 0;
}
