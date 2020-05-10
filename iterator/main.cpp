/**
 * Iterator Design Pattern
 *
 * Intent: Lets you traverse elements of a collection without exposing its
 * underlying representation (list, stack, tree, etc.).
 */

#include <iostream>
#include <string>
#include <vector>

 /**
  * C++ has its own implementation of iterator that works with a different
  * generics containers defined by the standard library.
  */

template <typename T, typename U>
class Iterator {
public:
  typedef typename std::vector<T>::iterator iter_type;
  Iterator(U *p_data, bool reverse = false) : m_p_data_(p_data) {
    m_it_ = m_p_data_->m_data_.begin();
  }

  void Frist() {
    m_it_ = m_p_data_->m_data_.begin();
  }

  void Next() {
    m_it_++;
  }

  bool IsDone() {
    return (m_it_ == m_p_data_->m_data_.end());
  }

  iter_type Current() {
    return m_it_;
  }

private:
  U *m_p_data_;
  iter_type m_it_;
};

/**
 * Generic Collections/Containers provides one or several methods for retrieving
 * fresh iterator instances, compatible with the collection class.
 */

template <class T>
class Container {
  friend class Iterator<T, Container>;

public:
  void Add(T a) {
    m_data_.push_back(a);
  }

  Iterator<T, Container> *CreateIterator() {
    return new Iterator<T, Container>(this);
  }

private:
  std::vector<T> m_data_;
};

class Data {
public:
  Data(int a = 0) : m_data_(a) {}

  void set_data(int a) {
    m_data_ = a;
  }

  int data() {
    return m_data_;
  }

private:
  int m_data_;
};

void ClientCode() {
  std::cout << "________________Iterator with int______________________________________" << '\n';
  Container<int> cont;

  for (int i = 0; i < 10; i++) {
    cont.Add(i);
  }
  
  Iterator<int, Container<int>> *iter = cont.CreateIterator();
  
  for (iter->Frist(); !iter->IsDone(); iter->Next()) {
    std::cout << *iter->Current() << '\n';
  }

  Container<Data> cont2;
  Data a(100), b(1000), c(10000);

  cont2.Add(a);
  cont2.Add(b);
  cont2.Add(c);

  std::cout << "________________Iterator with custom Class______________________________" << '\n';
  Iterator<Data, Container<Data>> *iter2 = cont2.CreateIterator();

  for (iter2->Frist(); !iter2->IsDone(); iter2->Next()) {
    std::cout << iter2->Current()->data() << '\n';
  }
}

int main(void) {
  ClientCode();
  return 0;
}