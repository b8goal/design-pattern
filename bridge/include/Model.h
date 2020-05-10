#pragma once

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Model {

public:
  virtual string ImageDetection(string subject) = 0;
};