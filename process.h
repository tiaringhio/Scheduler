#ifndef PROCESS_H
#define PROCESS_H
#include <vector>

struct dupla {
    int cicli;
    int salti;
};

class Process {

public:
    Process(int PID, int totCPUtime, int CPUused, vector <dupla>);
    int getPID() const;
    int gettotCPUtime() const;
    int getCPUused() const;
    vector <dupla> getresNeed() const;
    bool Needres();
    void progress();

private:
    int P;
    int t;
    int C = 0;
    vector <dupla> r;
}

#endif // PROCESS_H
