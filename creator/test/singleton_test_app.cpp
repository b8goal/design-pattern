#include <chrono>
#include <ctime>
#include <iostream>
#include <string>
#include <type_traits>
#include <mutex>

#include "singleton/singleton.hpp"

class Logger : public Singleton<Logger>
{
public:
  Logger(const std::string& log_header = "SingletonApp", std::ostream& out_stream = std::cout)
  : log_header_(log_header)
  , out_stream_(out_stream)
  , next_is_begin_(true)
  {
  }

public:
  
  using endl_type = decltype(std::endl<char, std::char_traits<char>>);

  Logger& operator<<(endl_type endl)
  {
    next_is_begin_ = true;

    out_stream_ << endl;

    return *this;
  }
  
  template <typename T>
  Logger& operator<<(const T& data)
  {
    std::lock_guard<std::mutex> log(mutex_);

    auto now = std::chrono::system_clock::now();
    auto now_time_t = std::chrono::system_clock::to_time_t(now);
    auto now_tm = std::localtime(&now_time_t);

    if (next_is_begin_) {
      out_stream_ << log_header_ << "(" << now_tm->tm_hour << ":" << now_tm->tm_min << ":" << now_tm->tm_sec << "): " << data;
    } else {
      out_stream_ << data;
    }

    next_is_begin_ = false;

    return *this;
  }

  void log(const std::string& message);  

private:
  const std::string log_header_;
  std::ostream& out_stream_;
  bool next_is_begin_ = true;

  std::mutex mutex_;
};

void Logger::log(const std::string& message)
{
  *this << message;
}

int main(int argc, char* argv[])
{
  Logger::instance().log("Singleton Design pattern test app!!\n");

  return 0;
}