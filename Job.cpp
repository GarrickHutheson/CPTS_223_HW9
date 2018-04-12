  void Job::Ticks(job_description, procs, ticks ) {
    job_Description = job_description;
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
  
  void Job::setName(string iname) {
    job_id=iname;
  }
  
