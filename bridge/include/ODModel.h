#pragma once

#include "Model.h"

class ODModel : public Model {
public:
  virtual string ImageDetection(string subject)
  {
    int index = -1;

    while ((index = subject.find("Object", index + 1)) != -1) {
      subject.replace(index, strlen("Object"), "Succes OD");
    }

    return subject;
  }
};
