/*
 * Cullen Williams & Garrick Hutcheson
 * Job.cpp
 */

#include "Job.h"

Job::Job(int id, string desc = "NULL", int procs, int ticks) {
  job_description = desc;
  n_procs = procs;
  n_ticks = ticks;
  job_id = id;
}

/* sets number of ticks to a desired value */
void Job::setTicks(int ticks) { n_ticks = ticks; }

/* sets number of ticks to a desired value */
void Job::setTimer(int tiempo) { jobRunningTimer = tiempo; }

/* decreases number of ticks a job requires */
void Job::decrementTimer() { --jobRunningTimer; }

/* returns timer value */
int Job::getTimer() { return jobRunningTimer; }

/* sets number of processes a job requires */
void Job::setProcs(int procs) { n_procs = procs; }


int Job::getProcs() { return n_procs; }

int Job::getID() { return job_id; }

string Job::getDesc() {
  return job_description;
}