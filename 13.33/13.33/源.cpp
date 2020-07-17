#include <iostream>
#include "message.h"
#include "Folder.h"
using namespace std;
void swap(Message& lhs, Message& rhs)
{
	using std::swap;
	lhs.remove_from_folders();
	rhs.remove_from_folders();
	swap(lhs.contents, rhs.contents);
	swap(lhs.folders, rhs.folders);
	lhs.add_to_folders(lhs);
	rhs.add_to_folders(rhs);
}
Message::Message(const Message& m) : contents(m.contents), folders(m.folders)
{
	add_to_folders(m);
}
Message& Message::operator=(const Message& m)
{
	remove_from_folders();
	contents = m.contents;
	folders = m.folders;
	add_to_folders(*this);
	return *this;
}
Message::~Message()
{
	remove_from_folders();
}
void Message::save(Folder& f)
{
	folders.insert(&f);
	f.add_message(this);
}
void Message::remove(Folder& f)
{
	folders.erase(&f);
	f.remove_message(this);
}

void swap(Folder& lhs, Folder& rhs)
{
	using std::swap;
	lhs.remove_from_messages();
	rhs.remove_from_messages();
	swap(lhs.msgs, rhs.msgs);
	lhs.add_to_messages();
	rhs.add_to_messages();
}
Folder::Folder(const Folder& f) : msgs(f.msgs)
{
	add_to_messages();
}
Folder& Folder::operator=(const Folder& f)
{
	remove_from_messages();
	msgs = f.msgs;
	add_to_messages();
	return *this;
}
Folder::~Folder()
{
	remove_from_messages();
}
void Folder::add_to_messages()
{
	for (auto m : msgs)
	{
		m->add_folder(this);
	}
}
void Folder::remove_from_messages()
{
	for (auto m : msgs)
	{
		m->remove_folder(this);
	}
}