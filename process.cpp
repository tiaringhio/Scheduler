#include "process.h"
#include <vector>

using namespace std;

Process::Process(int p, int t) {
PID = p;
totCPUtime = t;
CPUused = 0;
NumCicli = 0;
incrVett1 = 0;
incrVett2 = 0;
inRun = 0;
inWait = 0;
}

void Process::addDupla(int c,int s) {
    Dupla d;
    d.cicli = c;
    d.salti = s;
    resNeed.push_back(d);
}

vector<Dupla> Process::getresNeed() const{
return resNeed;
}

bool Process::Needres() {
if(NumCicli == resNeed[incrVett1].cicli){       /// controllo che la variabile che conta i num di cicli fatti sia uguale al 1 num della
NumCicli = 0;                                                 /// parentesi
incrVett ++;
return true;
}
else {return false;
}
}

bool Process::finishWait() {
if(inWait == resNeed[incrVett2].salti){         /// controllo che la variabile che conta i num di cicli fatti in wait sia uguale
    inWait = 0;                                                /// al 2 num in parentesi
    incrVett2 ++;
    return true;
else {return false;
}
}
}

void Process::progress() {
CPUused ++;
NumCicli ++;
}
