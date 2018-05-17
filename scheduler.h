#ifndef SCHEDULER_H
#define SCHEDULER_H
#include "process.h"
#include <vector>

class Scheduler {
public:
    Scheduler(Process run, vector <Process> wait, vector <Process> ready);
    Process getrun();
    void clock ();
    void startProcess(Process);
    vector <Process> getWait();
    vector <Process> getReady();
    void printState();
private:
    int r;
    vector <Process> w;
    vector <Process> ry;
}
#endif // SCHEDULER_H
