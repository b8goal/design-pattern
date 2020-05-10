#pragma once

#include "Model.h"

typedef vector<Model *> MVector;
typedef vector<Model *>::iterator MIter;

class Lens {

  int focuslevel;
  static const int min_focuslevel, max_focuslevel;
  MVector models;
  int min_index;

public:
  Lens(void);
  virtual string Take(string subjeryct, int distance) = 0;
  virtual void FocusUp(void);
  virtual void FocusDown(void);
  int GetFocusLevel(void) const;
  void AddModel(Model* model);
  void SetModelIndex(int index);
  int GetModelCount(void) const;

protected:
  int GetModelIndex(void) const;
  string ImageDetection(string subject, int index);
  string MakePicture(string subject, int distance);
};