#include <iostream>
#include <thread>
#include <mutex>
std::string myString2;
std::mutex myStringLock;
void setter()
{
   std::lock_guard<std::mutex> guard(myStringLock);
   myString2 = "asdsadd";
}
void getter()
{
   std::cout << myString2 << std::endl;
}
int main()
{
   std::thread thread1(setter);
   std::thread thread2(getter);
   thread1.join();
   thread2.join();
   return 0;
}