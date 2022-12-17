#include <map>
#include <iostream>
#include <chrono>
#include <cmath>
#include <thread> //the easiest platform-independent way to make your program sleep


//to type less and maybe change clocks if needed, these act as ALIASES
using CHRONO = std::chrono::steady_clock;
using TIME_UNIT = std::chrono::milliseconds;

// Class that stores the number of calls and the time elapsed
struct Timer_Data{
  unsigned int n_calls;
  TIME_UNIT elapsed;
};

// We overload the << operator for an object of class Timer_Data to return the number of calls and the time passed.
std::ostream& operator<<(std::ostream& os, const Timer_Data& t){
  os << t.n_calls << "\t" << std::chrono::duration_cast<TIME_UNIT>(t.elapsed).count();
  return os;
}

// Global class that contains 
//    - a map (like a dictionary) made of a string and an object of class timer data
//    - a starting time
//    - a print table function to output the final table, which is called when it goes out of scope.
class CTimer{
  std::map<std::string, Timer_Data> table;
  std::chrono::time_point<CHRONO> t_start;
  void print_table(){
    for (const auto& p : table)
      std::cout << p.first << "\t" << p.second  << std::endl;
    }
public:
  CTimer() : t_start{CHRONO::now()} {}
  ~CTimer() noexcept { print_table(); }
  friend class CScoped_Timer;
};

class CScoped_Timer{
  CTimer& timer;                            // reference to an object of class CTimer
  std::chrono::time_point<CHRONO> t_start;  // a starting point
  std::string section;                      // a string

  // It updates the table it has as reference member function 
  void update_table(){
    // Collects the time and evaluates time since the start (i.e. when it was called see the public constructor)
    auto t_end = CHRONO::now();
    auto tot = (t_end - t_start);
    // Increments by one the number of times this function was called and increases the time spent by the program on it
    ++timer.table[section].n_calls;
    timer.table[section].elapsed += std::chrono::duration_cast<TIME_UNIT>(tot);
  }
public:
  CScoped_Timer(CTimer& t, std::string s): timer{t},
					 t_start{CHRONO::now()},
					 section{s} {}
  ~CScoped_Timer() noexcept { update_table();}
};

//we need a global variable
//if you are using headers (as you should), you can put this declaration into some "global.hpp" file, or declare it after the timer class
CTimer the_timer;

int main(){
    double a{0};
    
    //open the scope, initialize the timer with global variable that will "remember" timings
    {CScoped_Timer t{the_timer, "sleep"};
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));   
    }//close the scope
    
    {CScoped_Timer t{the_timer, "test"};
    for (int i=0;i<100000000;i++){
        a+=std::sqrt(i*std::sqrt(i))*pow(i,0.234);
    }
    std::cout<<a<<std::endl;
    }//of timer
    
    {CScoped_Timer t{the_timer, "sleep"};
        std::this_thread::sleep_for(std::chrono::milliseconds(500));   
    }
    
    
    return 0;
}

