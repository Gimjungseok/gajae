#include <GLFW/glfw3.h>
#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

int main()
{
   chrono::steady_clock::time_point start = chrono::steady_clock::now();
   chrono::steady_clock::time_point prev_end = chrono::steady_clock::now();
   chrono::steady_clock::time_point end = chrono::steady_clock::now();
   
   

   int count = 0;
   while (count<100)
   {
      count++;
      cout << "카운트 : " << count << endl;
      
      start = end;
      
      chrono::steady_clock::duration diff = end - start;
      int duration_ms = chrono::duration_cast<chrono::milliseconds>(diff).count();
      cout << "시간 : " << chrono::duration_cast<chrono::milliseconds>(diff).count() << endl;

      if (duration_ms < 1000)
      {
         this_thread::sleep_for(chrono::milliseconds(1000 - duration_ms));
      }
      else this_thread::sleep_for(chrono::milliseconds(1000 + duration_ms));

      
   }
}