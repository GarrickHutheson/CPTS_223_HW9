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
  allTheProcs =8;
  totalJobs = 0; // starts at the first line of a file
  totalJobsToDo = 10;
}
Scheduler::Scheduler(int numJobs, int procs) {
  avaliableProcs = procs;
  allTheProcs = procs;
  totalJobs = 0;
  totalJobsToDo = numJobs;
}

//runs jobs from file w/o user input
void Scheduler::Run() {
  while (getTJobs()) {
    Tick();
    decrementTJobs();
  }
}

void Scheduler::waitForUserInput() {
  string jobdesk="";
  int numprocs=0;
  int numticks=0;
  std::cout << "enter Job description " << std::endl;
  std::cin >> jobdesk;
  std::cout << "enter required processors " << std::endl;
  std::cin >> numprocs;
  std::cin >> numticks;
  if(numprocs !=0)
    int id = totalJobs;
}

/*
  Tick
  prints the job_id numbers of any job submitted during the tick
  prints the job_id of any jobs compleated during the tick
*/
void Scheduler::Tick() {
 // waitForUserInput();
  fillQueue();
  std::cout << deleteByTimer();
}

/*
  insertJob
  adds a job to the priority queue
  calls std priority queue push
  The InsertJob() function first checks if (0 < n_procs ≤ p) and (n_ticks > 0).
If  so,  it  inserts  the  job  into  a  “wait  queue”.  Otherwise,  a  job
submission error is raised with an appropriate message.
*/
void Scheduler::insertJob(int id, int procs, int ticks, string desc) {
  if (((0 < procs) && (procs <= allTheProcs)) && (ticks > 0)) {
    procaQueue.push(Job(id, procs, ticks, desc));
    avaliableProcs-=procs;
    totalJobs++;
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
  Job deletedJob = Job(procaQueue.top());
  avaliableProcs+= deletedJob.getProcs();
  procaQueue.pop();
  return deletedJob;
}

/*
  checkAvailiability
*/
bool Scheduler::checkAvailiability(int procs) {
  return (avaliableProcs >= procs);
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
  for (int i = 0; i <= totalJobs; i++) {
    std::getline(fin, filePuller);
  }
  totalJobs++;

  // parse file puller
  string desc = "abba"; // TODO
  int procs = 4;    // TODO
  int ticks = 2;    // TODO

  // Assign a int id
  int id = totalJobs; // works but maybe better?
  if(checkAvailiability(procs)) {
    std::cout << "HELO!" << std::endl;
    insertJob(id, procs, ticks, desc);
  }
}

/*while there are enough free processors call runJob.
  runJob pushes the job to be run to the back of the
   running list and deletes it from the queue
*/
void Scheduler::fillQueue() {
    getAJob();
}

/*prints the job_ids of any jobs compleated during the tick*/
string Scheduler::deleteByTimer() {
  std::stringstream done;
  int syntactorator = 0;
  for (std::list<Job>::iterator iter = running.begin(); (iter != running.end());
       iter++) {

    iter->decrementTimer();
    if (!(iter->getTimer())) {
      done << iter->getDesc() << ", Processors: "<< iter->getProcs() << ", Ticks: " << iter->getTicks() <<"\n";
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
                  : (done << "No jobs were deleted");
  done << std::endl; // idk if this will work
  return done.str();
}
//pho king important
  bool operator > (const Job &lhs, const Job &rhs)
  {
    return lhs.getProcs() > rhs.getProcs();
  }

int Scheduler::getTJobs() { return totalJobsToDo; }

void Scheduler::decrementTJobs() { totalJobsToDo--; }
