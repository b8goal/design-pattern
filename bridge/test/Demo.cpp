#include "Camera.h"
#include "AFLens.h"
#include "MFLens.h"
#include "ODModel.h"
#include "LDModel.h"

void TestAFODLDLens(Camera* camera);
void TestMFLDLens(Camera* camera);

void main(void) {
  Camera* camera = new Camera();
  TestAFODLDLens(camera);
  TestMFLDLens(camera);

  delete camera;
}

void TestAFODLDLens(Camera* camera) {
  
  cout << "AFODLDLens Test" << '\n';
  
  ODModel* od_model = new ODModel();
  LDModel* ld_model = new LDModel();
  Lens* lens = new AFLens();

  int control_distance = 1;

  lens->AddModel(od_model);
  lens->AddModel(ld_model);

  camera->PutInLens(lens);
  camera->TakeAPicture("Solid Lane(0) Dahsed Lane (1) Botts dot Lane (2) Car Object (3) Pedestrian Object (4) Bicycle Object (5)", control_distance);

  delete od_model;
  delete ld_model;
}

void TestMFLDLens(Camera* camera) {

  cout << "MFLDLens Test" << '\n';

  LDModel* ld_model = new LDModel;
  Lens* lens = new MFLens();

  int control_distance = 1;

  lens->AddModel(ld_model);

  camera->PutInLens(lens);
  camera->TakeAPicture("Solid Lane(0) Dahsed Lane (1) Botts dot Lane (2) Car Object (3) Pedestrian Object (4) Bicycle Object (5)", control_distance);

  camera->FocusUp();
  camera->TakeAPicture("Solid Lane(0) Dahsed Lane (1) Botts dot Lane (2) Car Object (3) Pedestrian Object (4) Bicycle Object (5)", control_distance);

  camera->FoucusDown();
  camera->SetModelIndex(0);
  camera->TakeAPicture("Solid Lane(0) Dahsed Lane (1) Botts dot Lane (2) Car Object (3) Pedestrian Object (4) Bicycle Object (5)", control_distance);

  delete ld_model;
  delete lens;
}