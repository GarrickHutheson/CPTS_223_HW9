
class Scheduler() {

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

};
