#include "scheduler.h"
using namespace std;

Scheduler::Scheduler (Process run, vector <Process> wait, vector <Process> ready) {}

void Scheduler::clock() {

}

void Scheduler::startProcess(Process) {

}

Process Scheduler::getrun() {
    return r;
}

vector Scheduler::getwait() {
    return w;
}

vector Scheduler::getReady() {
    return ry;
}

void Scheduler::printState() {

}
Scheduler::~Scheduler() {}
