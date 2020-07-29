#ifndef THREADCOUT_HPP
#define THREADCOUT_HPP

#include <mutex>
#include <iostream>
#include <string>
#include <sstream>
//using namespace std;


class ThreadCout
{
public:
    static ThreadCout& get(){
        static ThreadCout obj;
        return obj;
    }
    template<class T>
    void print(T value){
        std::lock_guard<std::mutex> lock(mMutex);
        std::cout << value << std::endl;
    }
    void print(std::ostringstream& stream){
        std::lock_guard<std::mutex> lock(mMutex);
        std::cout << stream.str();
    }

private:
    ThreadCout(){}
    std::mutex mMutex;

};


#endif // THREADCOUT_HPP
