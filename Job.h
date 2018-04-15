/*
 * Cullen Williams & Garrick Hutcheson
 * Job.h
 */

#ifndef __JOB_H__
#define __JOB_H__

#include <string>
#include <ostream>
using std::string;

class Job {
public:
  Job(int id, int procs, int ticks, string desc = "NULL");

  void setTicks(int ticks);
  int getTicks() const;

  void setTimer(int tiempo);
  void decrementTimer();
  int getTimer() const;

  void setProcs(int procs);
  int getProcs() const;

  void setId(int iname);
  int getID() const;

  string getDesc() const;

private:
  string job_description;
  int jobRunningTimer;
  int n_procs;
  int n_ticks;
  int job_id;
};

  bool operator > (const Job &lhs, const Job &rhs);
  std::ostream & operator <<(std::ostream &out, const Job &j);
#endif

