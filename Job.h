#include <string>
using std::string;

class Job{
  public:
    void Ticks(string job_description, int procs, int ticks);
    
    void setTicks(int ticks);
    void incrementTicks();
    void decrementTicks();
  
    void setProcs(int procs);
    void incrementProcs();
    void decrementProcs();
  
    void setId(int iname);
  
  private:
    string job_description;
    int n_procs;
    int n_ticks;
    int job_id;
};
