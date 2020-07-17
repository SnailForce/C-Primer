#pragma once
#include <set>
#include <string>
#include "Folder.h"
using namespace std;
class Folder;
class Message
{
	friend class Folder;
	friend void swap(Message&, Message&);
	friend void swap(Folder&, Folder&);
public:
	explicit Message(const string& str = "") : contents(str) {}
	Message(const Message&);
	Message& operator=(const Message&);
	~Message();
	void save(Folder&);
	void remove(Folder&);
private:
	string contents;
	set<Folder*> folders;
	void add_to_folders(const Message&);
	void remove_from_folders();
	// foldersÔö¼Ó/É¾³ıFolder
	void add_folder(Folder* f)
	{
		folders.insert(f);
	}
	void remove_folder(Folder* f)
	{
		folders.erase(f);
	}
};
void Message::save(Folder& f)
{
	folders.insert(&f);

}
void Message::remove(Folder& f)
{
	folders.erase(&f);
}
void Message::add_to_folders(const Message& m)
{
	for (auto f : m.folders)
	{
		f->add_message(this);
	}
}
void Message::remove_from_folders()
{
	for (auto f : folders)
	{
		f->remove_message(this);
	}
}

void swap(Message&, Message&);