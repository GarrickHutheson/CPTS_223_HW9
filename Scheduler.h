#ifndef __SCHEDULER_H__
#define __SCHEDULER_H__

#include <string>
#include <queue>
using std::string;


class Scheduler {
public:
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
void insertJob();

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

private:
  std::priority_queue<Job> procaQueue;
  int avaliableProcs;

};
#endif