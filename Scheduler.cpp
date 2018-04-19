/*
 * Cullen Williams & Garrick Hutcheson
 * Scheduler.cpp
 */

#include "Scheduler.h"



Scheduler::Scheduler() {
  allTheProcs = 13;
  avaliableProcs = allTheProcs;
  totalJobs = 0; // starts at the first line of a file
  fin.open("Input.txt");
  exitScheduler = false;
  inputMode=0;
}
Scheduler::Scheduler(int mode, int procs) {
  avaliableProcs = procs;
  allTheProcs = procs;
  totalJobs = 0;
  fin.open("Input.txt");
  exitScheduler = false;
  inputMode=mode;
}

//runs jobs from file w/o user input
void Scheduler::Run() {
  do {  
    Tick();
    if(exitScheduler){
      std::cout << "exiting" <<std::endl;
      return;
    }
  } while (!(procaQueue.top().getDesc() == "exit") || !running.empty());
}

/**/
void Scheduler::waitForUserInput() {
  string jobdesk="";
  int numprocs=0;
  int numticks=0;
  std::cout << "Enter your job description " << std::endl;
  std::cin >> jobdesk;
  if(!jobdesk.compare("exit")){
      exitScheduler = true;
  } else {
    std::cout << "Enter required number of processors " << std::endl;
    std::cin >> numprocs;
    std::cout << "Enter required number of ticks " << std::endl;  
    std::cin >> numticks;
    if(numprocs !=0){
      int id = totalJobs;
      insertJob(totalJobs,numprocs,numticks,jobdesk);
    }
  }
}

/*
  Tick
  prints the job_id numbers of any job submitted during the tick
  prints the job_id of any jobs compleated during the tick
*/
void Scheduler::Tick() {
  std::cout<<"\nTICK\n";
  if(inputMode==0){
    if (!fin.eof()) {
      exitScheduler = getAJobFromTextFile();
    } else {
      insertJob(-1,allTheProcs,0,"exit");
    }
  }else{
    waitForUserInput();
  }
 if(!procaQueue.empty() || !exitScheduler)
 {
  runJob();
 }
 if(!running.empty() || !exitScheduler)
 {
  decrementTimer();
 }
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
  if ((0 <= procs) && (0 <= ticks)) {
    Job toPriorityQueue = Job(id, procs, ticks, desc);
    procaQueue.push(toPriorityQueue);
    if(id!=-1)
      std::cout << toPriorityQueue << " inserted to priority Queue" << std::endl;

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
  limited by deleteShortest everything else has constant time
*/
void Scheduler::runJob() {
  int procs = procaQueue.top().getProcs();
  if(checkAvailiability(procs)&&(procaQueue.top().getID()!=-1))
  {
    avaliableProcs-= procs;
    Job toRunning = deleteShortest();
    running.push_back(toRunning);

    std::cout << toRunning <<
    " added to running processes and removed from priority queue"
    << std::endl;

  }
}

/*
  releaseProcs
  adds procs back to pool checks to
*/
void Scheduler::releaseProcs(int procs) {
    {
       (avaliableProcs += procs);
    }
}

/*
  pulls a job from input file
  assigns job an unused integer id
  calls InsertJob(job_id,job_description,n_procs,n_ticks)
*/
bool Scheduler::getAJobFromTextFile() {
  string desc;
  int procs = 0;    
  int ticks = 0;
  getline(fin, desc, ' ');
  for(int i = 0; i < desc.length(); i++)
  {
    desc[i] = tolower(desc[i]);
  }
  if(desc.find("exit") == string::npos) {
    fin >> procs;
    fin >> ticks;
    fin.ignore(1000, '\n');
    insertJob(totalJobs++, procs, ticks, desc);
    return false;
  }
  return true;
  
}



/*prints the job_ids of any jobs compleated during the tick
  on it's own this process takes O(n) but withing the context of the overall
   program it has O(#processors) because that is the limit of independent
    running prosseses
*/
void Scheduler::decrementTimer() {
  int syntactorator = 0;
    for (std::list<Job>::iterator iter = running.begin(); iter != running.end();iter++) {
      iter->decrementTimer();    
      if ((iter->getTimer() == 0)) {
        std::list<Job>::iterator deleteIter = iter; //don't erase loop guard
        std::cout << *iter <<", ";
        releaseProcs(iter->getProcs());
        iter--; //step off to be erased node
        running.erase(deleteIter); //erase node
        syntactorator++;
      }
    }
    std::cout << syntaxToTheMax(syntactorator);
}

string Scheduler::syntaxToTheMax(int syntactor) {
  return ((syntactor) ? ((syntactor - 1) ? ("were deleted.\n")
                                                  : ("was deleted.\n"))
                          : ("No jobs were deleted\n"));
}
