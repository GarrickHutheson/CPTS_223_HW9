/*
 * Cullen Williams & Garrick Hutcheson
 * Scheduler.cpp
 */

#include "Scheduler.h"
#include <fstream>
#include <iostream>
#include <istream>
#include <list>
#include <sstream>
#include <string>

Scheduler::Scheduler() {
  avaliableProcs = 8; // DEFAULTUNKNOWN
  jobFileCounter = 0; // starts at the first line of a file
  totalJobsToDo = 10;
}
Scheduler::Scheduler(int numJobs, int procs) {
  avaliableProcs = procs;
  jobFileCounter = 0;
  totalJobsToDo = numJobs;
}

void Scheculer::Run() {
  while (getTJobs()) {
    Tick();
    decrementTJobs();
  }
}
/*
  Tick


  prints the job_id numbers of any job submitted during the tick
  prints the job_id of any jobs compleated during the tick
*/
void Scheduler::Tick() {}

/*
  insertJob
  adds a job to the priority queue
  calls std priority queue push
  The InsertJob() function first checks if (0 < n_procs ≤ p) and (n_ticks > 0).
If  so,  it  inserts  the  job  into  a  “wait  queue”.  Otherwise,  a  job
submission error is raised with an appropriate message.
*/
void Scheduler::insertJob(int id, string desc, int procs, int ticks) {
  if (((0 < procs) && (procs <= allTheProcs)) && (ticks > 0)) {
    procaQueue.push(Job(id, desc, procs, ticks));
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
Job Scheduler::findShortest() { return procaQueue.top(); }

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
  return (avaliableProcs >= (findShortest().getProcs()));
}

/*
  runJob
  passes job to parallel computer( in theory)
  removes job from top of queue
*/
void Scheduler::runJob() { running.push_back(deleteShortest()); }

/*
  decrementTimer
*/
void Scheduler::decrementTimer() { theFinalCountdown--; }

/*
  releaseProcs
  adds procs back to pool checks to
*/
void Scheduler::releaseProcs(int procs) {
  if(avaliableProcs + procs <= avaliableProcs){
       (avaliableProcs += procs);
    }
  else{
   std::cout << "TOO MANY PROCESSORS!" << std::endl;
  }
}

/*
  pulls a job from input file
  assigns job an unused integer id
  calls InsertJob(job_id,job_description,n_procs,n_ticks)
*/
void Scheduler::getAJob() {
  // creates oldMan class that outputs "Get a JAOB" to terminal.
  std::string filePuller = "";
  std::ifstream fin;
  fin.open("Input.txt");
  for (int i = 0; i <= jobFileCounter; i++) {
    std::getline(fin, filePuller);
  }
  jobFileCounter++;

  // parse file puller
  string desc = ""; // TODO
  int procs = 0;    // TODO
  int ticks = 0;    // TODO

  // Assign a int id
  int id = jobFileCounter; // works but maybe better?

  insertJob(id, desc, procs, ticks);
}

/*while there are enough free processors call runJob.
  runJob pushes the job to be run to the back of the
   running list and deletes it from the queue
*/
void Scheduler::fillQueue() {
  while (checkAvailiability()) {
    runJob();
  }
}

/*prints the job_ids of any jobs compleated during the tick*/
string Scheduler::deleteByTimer() {
  std::stringstream done;
  int syntactorator = 0;
  for (std::list<Job>::iterator iter = running.begin(); (iter != running.end());
       iter++) {

    iter->decrementTimer();
    if (!(iter->getTimer())) {
      done << iter->getID() << ", ";
      releaseProcs(iter->getProcs());

      running.erase(iter);
      syntactorator++;
    }
  }
  /*
    if syntactorator = 0, adds " no jobs were deleted" to stringstream
    if syntactorator = 1, adds " job was deleted." to stringstream
    if syntactorator > 1, adds " jobs were deleted." to stringstream
  */
  (syntactorator) ? ((syntactorator - 1) ? (done << " were deleted.")
                                         : (done << " was deleted."))
                  : (done << "no jobs were deleted");
  done << std::endl; // idk if this will work
  return done.str();
}

int Scheduler::getTjobs() { return totalJobsToDo; }

void Scheduler::decrementTJobs() { totalJobsToDo--; }