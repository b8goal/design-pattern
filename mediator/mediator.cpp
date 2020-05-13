#include <iostream>
#include <string>

using namespace std;

struct IMediator {
  virtual void NotifyEvent(string name, string ev) = 0;
  virtual ~IMediator() {}
};

class ComponentA {
  IMediator* pMediator;

public:
  void SetMediator(IMediator* p) { pMediator = p; }
  void SendEvent(string ev) { pMediator->NotifyEvent("A", ev); }
  void ReceiveEvent(string name, string ev) { cout << "Receieve " << ev << " Event from " << name << '\n'; }
};

class ComponentB {
  IMediator* pMediator;

public:
  void SetMediator(IMediator* p) { pMediator = p; }
  void SendEvent(string ev) { pMediator->NotifyEvent("B", ev); }
  void ReceiveEvent(string name, string ev) { cout << "Receieve " << ev << " Event from " << name << '\n'; }
};

class ComponentC {
  IMediator* pMediator;

public:
  void SetMediator(IMediator* p) { pMediator = p; }
  void SendEvent(string ev) { pMediator->NotifyEvent("C", ev); }
  void ReceiveEvent(string name, string ev) { cout << "Receieve " << ev << " Event from " << name << '\n'; }
};

class Mediator : public IMediator {
  ComponentA* pCompA;
  ComponentB* pCompB;
  ComponentC* pCompC;

public:
  Mediator(ComponentA* pCompA_, ComponentB* pCompB_, ComponentC* pCompC_) : pCompA(pCompA_), pCompB(pCompB_), pCompC(pCompC_) {
    pCompA->SetMediator(this);
    pCompB->SetMediator(this);
    pCompC->SetMediator(this);
  }

  void NotifyEvent(string name, string ev) {
    if (name == "A") {
      pCompB->ReceiveEvent(name, ev);
      pCompC->ReceiveEvent(name, ev);
    }
  }
};

int main(void)
{
  ComponentA compA;
  ComponentB compB;
  ComponentC compC;
  Mediator mediator(&compA, &compB, &compC);
  compA.SendEvent("Recieved mail");
  return 0;
}