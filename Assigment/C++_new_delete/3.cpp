#include <iostream>
using namespace std;
 
class Test 
{
  int x;
  Test() { x = 5;}
};
 //fix
 class Test_fix{
    private:
        int x;
    public:
        Test_fix(){x=5;}
        int getX(){
            return this->x;
        }
 };
int main()
{
   Test_fix *t = new Test_fix;
   cout << t->getX();
   return 0;
}