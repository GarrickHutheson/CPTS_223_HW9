/*
 * Cullen Williams & Garrick Hutcheson
 * Scheduler.cpp
 */

#include "Scheduler.h"



Scheduler::Scheduler() {
  avaliableProcs = 8; // DEFAULTUNKNOWN
  allTheProcs =8;
  totalJobs = 0; // starts at the first line of a file
  totalJobsToDo = 10;
  fin.open("Input.txt");
}
Scheduler::Scheduler(int numJobs, int procs) {
  avaliableProcs = procs;
  allTheProcs = procs;
  totalJobs = 0;
  totalJobsToDo = numJobs;
  fin.open("Input.txt");
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
  runJob();
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
  if (((0 < procs) && (procs <= avaliableProcs)) && (ticks > 0)) {
    procaQueue.push(Job(id, procs, ticks, desc));
    avaliableProcs-=procs;
    totalJobs++;
   std::cout << "insert successfull "<<procs<<std::endl;
  } else {
    std::cout << "UNSUCCESSFULL PROBE";
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
  std::cout << "DELETING JOB" << std::endl;
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

<<<<<<< HEAD
=======

>>>>>>> 7f8202c2d52f3791607a417937f9e579d4059b95
/*
  releaseProcs
  adds procs back to pool checks to
*/
void Scheduler::releaseProcs(int procs) {
  if(avaliableProcs + procs <= allTheProcs){
       (avaliableProcs += procs);
    } else {
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
    string desc;
  int procs = 0;    // TODO
  int ticks = 0;    // TODO
  std::string filePuller = "";
<<<<<<< HEAD
  std::ifstream fin;
  fin.open("Input.txt");
  for (int i = 0; i <= totalJobs; i++) {
    std::getline(fin, filePuller);
  }
=======
  std::getline(fin, filePuller);
  std::stringstream parseLine(filePuller);
>>>>>>> 7f8202c2d52f3791607a417937f9e579d4059b95

  // parse file puller

  getline(parseLine, desc, ' ');
  parseLine >> procs;
  parseLine >> ticks;

  // Assign a int id
  int id = totalJobs; // works but maybe better?
  totalJobs++;
  if(checkAvailiability(procs)) {
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
  if(running.begin()==running.end()){
    }
    for (std::list<Job>::iterator iter = running.begin(); (iter != running.end());iter++) {
      iter->decrementTimer();
      if ((iter->getTimer())) {
        done << iter->getDesc() << ", Processors: "<< iter->getProcs() << ", Ticks: " << iter->getTicks() <<"\n";
        releaseProcs(iter->getProcs());
       running.erase(iter);
        syntactorator++;
      }
      std::cout <<"this ever happens"<<std::endl;
  }
  /*
    if syntactorator = 0, adds " no jobs were deleted" to stringstream
    if syntactorator = 1, adds " job was deleted." to stringstream
    if syntactorator > 1, adds " jobs were deleted." to stringstream
  */
  done <<(syntactorator) ? ((syntactorator - 1) ? (" were deleted.")
                                         : (" was deleted."))
                  : ("No jobs were deleted");
  //done << std::endl; // idk if this will work
  return done.str();
}
//pho king important
  bool operator > (const Job &lhs, const Job &rhs)
  {
    return lhs.getProcs() > rhs.getProcs();
  }

int Scheduler::getTJobs() { return totalJobsToDo; }

void Scheduler::decrementTJobs() { totalJobsToDo--; }
