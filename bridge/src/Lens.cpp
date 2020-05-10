#include "Lens.h"

const int Lens::min_focuslevel = 1;
const int Lens::max_focuslevel = 5;

Lens::Lens(void) {
  focuslevel = min_focuslevel;
  min_index = -1;
}

void Lens::FocusUp(void) {
  if (focuslevel < max_focuslevel) {
    focuslevel++;
  }
}

void Lens::FocusDown(void) {
  if (focuslevel > min_focuslevel) {
    focuslevel--;
  }
}

int Lens::GetFocusLevel() const {
  return focuslevel;
}

void Lens::AddModel(Model* model) {
  models.push_back(model);
}

int Lens::GetModelCount() const {
  return models.size();
}

int Lens::GetModelIndex() const {
  return min_index;
}

string Lens::ImageDetection(string subject, int index) {
  if ((index >= 0 || (index < GetModelCount()))) {
    Model* model = models[index];
    subject = model->ImageDetection(subject);
  }

  return subject;
}

string Lens::MakePicture(string subject, int distance) {
  char buf[256];
  string str = itoa(distance, buf, 256);
  int index = -1;

  while ((index = subject.find(str, index + 1)) != -1) {
    subject.replace(index, str.size(), "Succes Detect");
  }

  return subject;
}

void Lens::SetModelIndex(int index) {
  min_index = index;
}