#ifndef __SCHEDULER_H__
#define __SCHEDULER_H__

#include <string>
#include <queue>
#include "Job.h"
#include <functional>
using std::string;


class Scheduler {
public:

Scheduler();
Scheduler(int timer=10, int procs=8);


/*
  Tick
  
  
  prints the job_id numbers of any job submitted during the tick
  prints the job_id of any jobs compleated during the tick
*/
void Tick();

/*
  insertJob
  adds a job to the priority que
*/
void insertJob(string desc="NULL", int procs=0, int ticks=0);

/*
  findShortest
  acceses the top(shortest) element in the priority queue
*/
int findShortest();

/*
  deleteShortest
*/
bool deleteShortest();

/*
  checkAvailiability
*/
bool checkAvailiability();

/*
  runJob
*/
void runJob();

/*
  decrementTimer
*/
void decrementTimer();

/*
  releaseProcs
*/
void releaseProcs();

//private:
  std::priority_queue<int,Job,std::greater<int> > procaQueue;
  int theFinalCountdown; //timer
  int avaliableProcs; //keeps track of free proccessors

};
#endif