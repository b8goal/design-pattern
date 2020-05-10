#include "MFLens.h"

string MFLens::Take(string subject, int distance) {
  int min_index = GetModelIndex();
  int mcount = GetModelCount();

  if ((min_index >= 0) && (min_index < mcount)) {
    subject = ImageDetection(subject, min_index);
  }

  return MakePicture(subject, GetFocusLevel());
}

void MFLens::FocusUp(void) {
  Lens::FocusUp();
  cout << "current FocusLevel:" << GetFocusLevel() << '\n';
}

void MFLens::FocusDown(void) {
  Lens::FocusDown();
  cout << "current FocusLevel:" << GetFocusLevel() << '\n';
}