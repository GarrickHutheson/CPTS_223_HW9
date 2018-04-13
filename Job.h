#ifndef __JOB_H__
#define __JOB_H__

#include <string>
using std::string;

class Job{
  public:
    Job();
    Job(string desc,int procs,int ticks);
    
    void setTicks(int ticks);
    void incrementTicks();
    void decrementTicks();

    void setTimer(int tiempo);
    void incrementTimer();
    void decrementTimer();
    int whatIsTimer();

    void setProcs(int procs);
    void incrementProcs();
    void decrementProcs();
  
    void setId(int iname);
  
  private:
    string job_description;
    int jobRunningTimer;
    int n_procs;
    int n_ticks;
    int job_id;
};
#endif