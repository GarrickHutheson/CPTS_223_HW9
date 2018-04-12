#include <string>
using std::string;

class Job{
  public:
    void Job::Ticks(string job_description, int procs, int ticks);
    void decrementTicks();
    void incrementTicks();
  
    void decrementProcs();
    void incrementProcs();
  
    void setName(string iname);
  
  private:
    string job_Description;
    int n_procs;
    int n_ticks;
    int job_id;
}
