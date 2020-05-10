#pragma once

#include "Lens.h"

class MFLens : public Lens {
public:
  virtual string Take(string subject, int distance);
  virtual void FocusUp();
  virtual void FocusDown();
};