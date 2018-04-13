/*
 * Cullen Williams & Garrick Hutcheson
 * Job.cpp
 */

#include "Job.h"

Job::Job() {
  job_description = "NULL";
  n_procs = 0;
  n_ticks = 0;
  job_id = setID();
}

Job::Job(string desc = "NULL", int procs, int ticks) {
  job_description = job_Description;
  n_procs = procs;
  n_ticks = ticks;
  job_id = setID();
}

/* sets number of ticks to a desired value */
void Job::setTicks(int ticks) { n_ticks = ticks; }

/* increases number of ticks a job requires */
void Job::incrementTicks() { ++n_ticks; }

/* decreases number of ticks a job requires */
void Job::decrementTicks() { --n_ticks; }

/* sets number of ticks to a desired value */
void Job::setTimer(int tiempo) { jobRunningTimer = tiempo; }

/* increases number of ticks a job requires */
void Job::incrementTimer() { ++jobRunningTimer; }

/* decreases number of ticks a job requires */
void Job::decrementTimer() { --jobRunningTimer; }

/* returns timer value */
int Job::whatIsTimer() { return jobRunningTimer; }

/* sets number of processes a job requires */
void Job::setProcs(int procs) { n_procs = procs; }

/* increases number of processes a job requires */
void Job::incrementProcs() { ++n_procs; }

/* decreases number of processes a job requires */
void Job::decrementProcs() { --n_procs; }

int Job::whatIsProcs() {
  return n_procs;
}


/* sets a job's integer id */
void Job::setId() { /*something fancy*/ }
