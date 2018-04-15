/*
 * Cullen Williams & Garrick Hutcheson
 * Job.cpp
 */

#include "Job.h"

Job::Job(int id, int procs, int ticks, string desc) {
  job_description = desc;
  n_procs = procs;
  n_ticks = ticks;
  job_id = id;
  jobRunningTimer=ticks;
}

/* sets number of ticks to a desired value */
void Job::setTicks(int ticks) { n_ticks = ticks; }

int const Job::getTicks() { return n_ticks; }

/* sets number of ticks to a desired value */
void Job::setTimer(int tiempo) { jobRunningTimer = tiempo; }

/* decreases number of ticks a job requires */
void Job::decrementTimer() { if (jobRunningTimer > 0) --jobRunningTimer; }

/* returns timer value */
int const Job::getTimer() { return jobRunningTimer; }

/* sets number of processes a job requires */
void Job::setProcs(int procs) { n_procs = procs; }

int Job::getProcs() const { return n_procs; }

int Job::getID() { return job_id; }

string Job::getDesc() { return job_description; }

