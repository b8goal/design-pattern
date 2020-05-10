#pragma once

#include "Model.h"

class LDModel : public Model {
  virtual string ImageDetection(string subject) {
    int index = -1;
    
    while ((index = subject.find("Lane", index + 1)) != -1) {
      subject.replace(index, strlen("Lane"), "Succes LD");
    }

    return subject;
  }
};