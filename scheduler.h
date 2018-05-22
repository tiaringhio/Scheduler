#ifndef SCHEDULER_H
#define SCHEDULER_H
#include "process.h"
#include <vector>

class Scheduler {
public:
    Scheduler();
    void clock ();
    Process getrun();
    void startProcess(Process *p);
    Process* getRun();
    std::vector <Process*> getWait();
    std::vector <Process*> getReady();
    void printState();
    bool Allempty();
private:
    Process* run = nullptr;
    std::vector <Process*> wait;
    std::vector <Process*> ready;
    int quanto;
};
#endif // SCHEDULER_H
