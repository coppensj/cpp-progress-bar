#include <chrono>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <thread>

void show_progress_bar_v2(std::ostream& os, std::string message, 
        float percentage, char symbol = '#', int delay = 0)
{
    static const auto bar_length = 50;
    int progress_level = static_cast<int>(percentage/100*bar_length);

    if (percentage <=0)
        os << message << '\n';
    message.clear();

    message += std::string(progress_level, symbol);
    os << "\r["
       << message << std::string(bar_length - progress_level, ' ') << "] " 
       << std::setw(3) << static_cast<int>(percentage) << "%"
       << std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    
    if (percentage >= 100)
        os << "\n";
}
