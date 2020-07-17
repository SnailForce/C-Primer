#pragma once
#include "Message.h"
class Folder
{
	friend class Message;
	friend void swap(Message&, Message&);
	friend void swap(Folder&, Folder&);
public:
	Folder() = default;
	Folder(const Folder&);
	Folder& operator=(const Folder&);
	~Folder();
private:
	set<Message*> msgs;
	void add_to_messages();
	void remove_from_messages();
	// msgsÔö¼Ó/É¾³ıMessage
	void add_message(Message* m)
	{
		msgs.insert(m);
	}
	void remove_message(Message* m)
	{
		msgs.erase(m);
	}
};

void swap(Folder&, Folder&);