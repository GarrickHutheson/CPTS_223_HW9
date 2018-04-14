/*
 * Cullen Williams & Garrick Hutcheson
 * Scheduler.h
 */

#ifndef __SCHEDULER_H__
#define __SCHEDULER_H__

#include "Job.h"
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <string>
using std::string;

class Scheduler {
public:
  Scheduler();
  Scheduler(int numJobs, int procs = 8);

  void Run();

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
  void insertJob(int id, string desc = "NULL", int procs = 0, int ticks = 0);

  /*
    findShortest
    acceses the top(shortest) element in the priority queue
  */
  Job findShortest();

  /*
    deleteShortest
  */
  Job deleteShortest();

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
  void releaseProcs(int procs);

  /**/
  void getAJob();
  /**/
  void fillQueue();
  /**/
  void decrementEggTimers();
  /**/
  string deleteByTimer();

  int getTjobs();
  void decrementTJobs();

private:
  std::priority_queue<int, Job, std::greater<int>> procaQueue;
  int theFinalCountdown; // timer
  int avaliableProcs;    // keeps track of free proccessors
  int allTheProcs;
  int jobFileCounter;
  int totalJobsToDo;
  std::list<Job> running;
};
#endif