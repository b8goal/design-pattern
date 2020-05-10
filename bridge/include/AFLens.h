#pragma once

#include "Lens.h"

class AFLens : public Lens {
public:
  virtual string Take(string subject, int distance);

private:
  void AutoFocusing(int distance);
  string Processing(string subject);
};