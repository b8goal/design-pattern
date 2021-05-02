#ifndef __SINGLETON_HPP__
#define __SINGLETON_HPP__

#include <memory>
#include <mutex>

template <typename T>
class Singleton
{
public:
  static T& instance()
  {
    std::call_once(singleton_flag_, []() {
      instance_ = std::make_shared<T>();
    });
    
    return *instance_;
  }

private:
  static std::once_flag singleton_flag_;
  static std::shared_ptr<T> instance_;
};

template<typename T>
std::once_flag Singleton<T>::singleton_flag_;

template<typename T>
std::shared_ptr<T> Singleton<T>::instance_;

#endif // __SINGLETON_HPP__