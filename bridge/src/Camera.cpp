#include "Camera.h"

Camera::Camera(void) {
  lens = 0;
}

void Camera::PutInLens(Lens* _lens) {
  lens = _lens;
}

void Camera::TakeAPicture(string subject, int distance) {
  cout << "Subject:" << subject << '\n';

  if (lens == 0) {
    cout << "Picture:" << "[]" << '\n';
  }

  cout << "Picture:" << lens->Take(subject, distance) << '\n';
}

void Camera::FocusUp(void) {
  if (lens != 0) {
    lens->FocusUp();
  }
}

void Camera::FoucusDown(void) {
  if (lens != 0) {
    lens->FocusDown();
  }
}

int Camera::GetModelCount(void) const {
  if (lens != 0) {
    return lens->GetModelCount();
  }
  return -1;
}

void Camera::SetModelIndex(int index) {
  if (lens != 0) {
    return lens->SetModelIndex(index);
  }
}
