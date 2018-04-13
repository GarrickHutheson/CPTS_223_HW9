/*
 * Cullen Williams & Garrick Hutcheson
 * Scheduler.cpp
 */

#include <iostream>
#include <list>
#include "Scheduler.h"

Scheduler::Scheduler() {
  theFinalCountdown = 10; //DEFAULTUNKNOWN
  avaliableProcs = 8;//DEFAULTUNKNOWN
}
Scheduler::Scheduler(int timer, int procs) {
  theFinalCountdown = timer;
  avaliableProcs = procs;
}
/*
  Tick


  prints the job_id numbers of any job submitted during the tick
  prints the job_id of any jobs compleated during the tick
*/
void Scheduler::Tick() {

}

/*
  insertJob
  adds a job to the priority queue
  calls std priority queue push  
*/
void Scheduler::insertJob(string desc, int procs, int ticks) {
  procaQueue.push(1/*TODO*/);
  /*so it needs to take a
   job object but I don't think 
   i'm sorting these things correctly.
   I think what it needs is to get passed (jobID,Job)but idk */
}

/*
  findShortest
  acceses the top(shortest) element in the priority queue  
*/
Job Scheduler::findShortest() {
  return procaQueue.top();
}

/*
  deleteShortest
  calls std priority queue pop
*/
Job Scheduler::deleteShortest() {
  std::list<Job>::iterator iter = procaQueue.top();
  procaQueue.pop();
  return *iter;
}

/*
  checkAvailiability
*/
bool Scheduler::checkAvailiability() {
  return (avaliableProcs >= (findShortest().whatIsProcs()));
}

/*
  runJob
  passes job to parallel computer( in theory)
  removes job from top of queue
*/
void Scheduler::runJob() {
  
}

/*
  decrementTimer
*/
void Scheduler::decrementTimer() {
  theFinalCountdown--;
}

/*
  releaseProcs
*/
void Scheduler::releaseProcs() {

}

/**/
void Scheduler::housekeeping1() {

}

/**/
void Scheduler::queueNotEmpty() {
  if(checkAvailiability()) {
    //do thing
  }
}

/**/
void Scheduler::decrementEggTimers() {
  for (std::list<Job>::iterator iter = running.begin(); (iter != running.end()); iter++) {
    iter->decrementTimer();
  }
}

/**/
void Scheduler::deleteByTimer() {
  for (std::list<Job>::iterator iter = running.begin(); (iter != running.end()); iter++) {
    if(!(iter-> whatIsTimer())) {
      running.erase(iter);
    }
  }
}