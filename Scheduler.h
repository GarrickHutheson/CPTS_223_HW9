/*
 * Cullen Williams & Garrick Hutcheson
 * Scheduler.h
 */

#ifndef __SCHEDULER_H__
#define __SCHEDULER_H__

#include "Job.h"
#include <functional>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <queue>
#include <string>
using std::string;

class Scheduler {
public:
  Scheduler();
  Scheduler(int mode, int procs = 8);

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
  void insertJob(int id, int procs = 0, int ticks = 0, string desc = "NULL");

  /*
    findShortest
    acceses the top(shortest) element in the priority queue
  */
  Job findShortest();

  /*
    deleteShortest
  */
  Job deleteShortest();

  void waitForUserInput();

  /*
    checkAvailiability
  */
  bool checkAvailiability(int procs);

  /*
    run job
  */
  void runJob();

  /*
    releaseProcs
  */
  void releaseProcs(int procs);

  /**/
  bool getAJobFromTextFile();
  /**/
  void fillQueue();
  /**/
  void decrementEggTimers();

  /*prints the job_ids of any jobs compleated during the tick*/
  void deleteByTimer();

  /*function that controlls syntax for job deletion output*/
  string syntaxToTheMax(int syntactor);

private:
  std::priority_queue<Job, std::vector<Job>, std::greater<Job> > procaQueue;
  int avaliableProcs;    // keeps track of free proccessors
  int allTheProcs;  //keeps track of total "processors" in the cluster
  int totalJobs; //keeps track of the total number of jobs for independent naming
  std::list<Job> running; //linked list to track jobs running in the "computer"
  std::ifstream fin;
  bool exitScheduler; //set to true if exit condition met
  int inputMode; //0 for reading from file anything else for user input
};
#endif
