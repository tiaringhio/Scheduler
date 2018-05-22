#ifndef PROCESS_H
#define PROCESS_H
#include <vector>

struct Dupla {
    int cicli;
    int salti;
};

class Process {

public:
    Process(int p, int t);
    std::vector<Dupla> getresNeed();
    bool Needres();
    void progress();
    void addDupla(int c,int s);
    bool finishWait();
    int getCPUused();
    int gettotCPUtime();
    int getinRun();
private:
    int PID;
    int totCPUtime;
    int CPUused;
    int NumCicli;
    int incrVett1;
    int incrVett2;
    int inWait;
    int inRun;
    std::vector<Dupla> resNeed;
};

#endif // PROCESS_H
