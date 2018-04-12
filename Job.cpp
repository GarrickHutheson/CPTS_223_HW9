#include "Job.h"

void Job::Ticks(string job_Description, int procs, int ticks) {
  job_description = job_Description;
  n_procs = procs;
  n_ticks = ticks;
}
/* sets number of ticks to a desired value*/
void Job::setTicks(int ticks) { n_ticks = ticks; }

/* increases number of ticks a job requires*/
void Job::incrementTicks() { ++n_ticks; }

/* decreases number of ticks a job requires*/
void Job::decrementTicks() { --n_ticks; }

/* sets number of processes a job requires*/
void Job::setProcs(int procs) { n_procs = procs; }

/* increases number of processes a job requires*/
void Job::incrementProcs() { ++n_procs; }

/* decreases number of processes a job requires*/
void Job::decrementProcs() { --n_procs; }

/* sets a job's integer id*/
void Job::setId(int iname) { job_id = iname; }
