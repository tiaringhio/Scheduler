#include "scheduler.h"
#include <vector>
#include <iostream>
using namespace std;

Scheduler::Scheduler () {
run = nullptr;
quanto = 5;}

void Scheduler::clock() {
if(Allempty() == true){                                                                      /// Controllo se tutti i run e le liste sono vuoti tutti i processi hanno finito
    cout << "Ho terminato";
}

if (run == nullptr) {                                                                           /// Se non c'e' nulla in run prelevo un processo da ready
    run = ready[0];
}
if (run -> getCPUused() == run -> gettotCPUtime()) {                    /// Controllo se il processo in run ha finito
    run = nullptr;
}
if (run -> Needres() == true) {                                                         /// Contollo se il processo in run ha bisogno di una risorsa
    wait.push_back(run);                                                                 /// Se si lo mando in wait
    run = ready[0];                                                                           /// Prelevo un processo da ready e lo metto in run elimindandolo da ready
    ready.erase(ready.begin(), ready.begin());
}

if ((run->getinRun() == quanto) && (run->Needres() == false)) {   /// Se la risorsa ha terminato il suo tempo in run la metto in
    ready.push_back(run);                                                              /// coda in ready
    run = ready[0];
    ready.erase(ready.begin(), ready.begin());
}
for (auto i: getWait()) {                                                                  /// Controllo se la risorsa e' pronta
    wait[i].inWait ++;
    if (wait[i] -> finishWait() == true) {                                           /// Se si il processo puo tornare in ready
        ready.push_back(wait[i]);
        wait.erase(wait.begin(), wait.begin());
    }
}
run -> getinRun() ++;
run -> progress();
}

void Scheduler::startProcess(Process *p) {
ready.push_back(p);
}

Process* Scheduler::getRun() {
   return run;
}

vector Scheduler::getWait() {
    return wait;
}

vector Scheduler::getReady() {
    return ready;
}

void Scheduler::printState() {
cout << "Il processo " << getRun() << " e' in Run" << endl;
cout << "Il/i processo/i "<< getReady() << " e'/sono in Ready" << endl;
cout << "Il/i processo/i "<< getWait() << " e'/sono in Wait" << endl;
}
bool Scheduler::Allempty() {
if ((getRun() == nullptr) && (getWait() == nullptr) && (getReady() == nullptr)) {
return true;
}
else{ return false; }
}
