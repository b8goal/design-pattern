#pragma once

#include "Lens.h"

class Camera {
  Lens* lens;

public:
  Camera(void);
  void PutInLens(Lens* _lens);
  void TakeAPicture(string subject, int distance);
  void FocusUp(void);
  void FoucusDown(void);
  int GetModelCount() const;
  void SetModelIndex(int index);
};
