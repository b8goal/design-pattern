#include "AFLens.h"

string AFLens::Take(string subject, int distance) {
  
  AutoFocusing(distance);
  subject = Processing(subject);
  
  return MakePicture(subject, distance);
}

void AFLens::AutoFocusing(int distance) {
  while (distance > GetFocusLevel()) {
    FocusUp();
  }

  while (distance < GetFocusLevel()) {
    FocusDown();
  }
}

string AFLens::Processing(string subject) {
  int model_count = GetModelCount();

  for (int index = 0; index < model_count; index++) {
    subject = ImageDetection(subject, index);
  }

  return subject;
}