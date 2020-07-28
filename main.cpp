#include "EventHandler.hpp"
#include "thread"
#include "chrono"
#include "ThreadCout.hpp"

void test();

int main()
{
    ThreadCout::get().print("start main");
    test();
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));

    ThreadCout::get().print("end main");
    return 0;
}


void test()
{
    shared_ptr<EventHandler> obj1 = make_shared<EventHandler>("obj1",obj1);
    //cout << "obj = " << obj1.use_count() << endl;
    //EventHandler* obj1 = new EventHandler("obj1");
    shared_ptr<EventHandler> obj2 = make_shared<EventHandler>("obj2",obj2);
    //shared_ptr<EventHandler> obj11(new EventHandler("obj11"));


    //EventHandler obj2("obj2");
    obj2->initPtr(obj2);
    obj2->subscribeToEvent(CREATION_OBJECT);
    obj2->subscribeToEvent(DELETE_OBJECT);
    std::this_thread::sleep_for(std::chrono::milliseconds(2500));
    shared_ptr<EventHandler> obj3 = make_shared<EventHandler>("obj3",obj3);
    obj1.reset();
    //EventHandler obj3("obj3");
    //delete obj1;;



    //obj2.unsubscribeToEvent(CREATION_OBJECT);
    //obj2.unsubscribeToEvent(DELETE_OBJECT);
}
