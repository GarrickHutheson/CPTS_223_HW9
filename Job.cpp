#include "Job.h"

  void Job::Ticks(string job_Description, int procs, int ticks ) {
    job_description = job_Description;
    n_procs = procs;
    n_ticks = ticks;
  }
  
  void Job::decrementTicks() {
    --n_ticks;
  }
  void Job::incrementTicks() {
    ++n_ticks;
  }
  
  void Job::decrementProcs() {
    --n_procs;
  }
  
  void Job::incrementProcs(){
    ++n_procs;
  }
  
  void Job::setId(int iname) {
    job_id=iname;
  }
  
