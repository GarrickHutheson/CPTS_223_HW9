/*
 * Cullen Williams & Garrick Hutcheson
 * Job.h
 */

#ifndef __JOB_H__
#define __JOB_H__

#include <string>
using std::string;

class Job {
public:
  Job(int id, string desc, int procs, int ticks);

  void setTicks(int ticks);
  int getTicks();

  void setTimer(int tiempo);
  void decrementTimer();
  int getTimer();

  void setProcs(int procs);
  int getProcs();

  void setId(int iname);
  int getID();

  string getDesc();

private:
  string job_description;
  int jobRunningTimer;
  int n_procs;
  int n_ticks;
  int job_id;
};
#endif