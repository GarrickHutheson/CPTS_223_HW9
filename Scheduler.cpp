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
  The InsertJob() function first checks if (0 < n_procs ≤ p) and (n_ticks > 0). 
If  so,  it  inserts  the  job  into  a  “wait  queue”.  Otherwise,  a  job  submission 
error is raised with an appropriate message. 
*/
void Scheduler::insertJob(string desc, int procs, int ticks) {
  if(((0 < procs) && (procs<= allTheProcs)) && (ticks > 0)) {
  procaQueue.push(Job(desc,procs,ticks));
  /*so it needs to take a
   job object but I don't think 
   i'm sorting these things correctly.
   I think what it needs is to get passed (jobID,Job)but idk */
  }
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
  running.push_back(deleteShortest());
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
void Scheduler::releaseProcs(int procs) {
  if(avaliableProcs + procs <= avaliableProcs)
    avaliableProcs += procs;
}

/**/
void Scheduler::getAJob() {

}

/*while there are enough free processors call runJob.
  runJob pushes the job to be run to the back of the
   running list and deletes it from the queue
*/
void Scheduler::fillQueue() {
  while(checkAvailiability()) {
    runJob();
  }
}

/**/
void Scheduler::decrementEggTimers() {
  for (std::list<Job>::iterator iter = running.begin(); (iter != running.end()); iter++) {
    iter->decrementTimer();
  }
}
//maybe combine ^v
/**/
void Scheduler::deleteByTimer() {
  for (std::list<Job>::iterator iter = running.begin(); (iter != running.end()); iter++) {
    if(!(iter-> whatIsTimer())) {
      releaseProcs(iter->whatIsProcs());
      running.erase(iter);
    }
  }
}