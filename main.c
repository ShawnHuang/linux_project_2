#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
 
#define __NR_hello 312 //349 if you are running a 32bit kernel and following my tutorial
 struct process_switch_info
{
  unsigned int   counter_cpu, counter_IO;
  struct timeval time_cpu, time_IO;
};

long get_process_switch_info(struct process_switch_info* ps_info, int cpu_pid, int io_pid)
{
    return syscall(__NR_hello, ps_info, cpu_pid, io_pid);
}
 
int main(int argc, char *argv[])
{
    int                        pid_cpu,pid_IO;
    unsigned long              temp_ul;
    struct process_switch_info ps_info;

    if(argc<3)
    {
      printf("Input the PIDs of the CPU-bound process and I/O-bound process as the parameters of this executable.\n");
      printf("Format: program pid_cpu pid_IO\n");
      exit(0);
    }

    pid_cpu=atoi(argv[1]);
    pid_IO=atoi(argv[2]);

    long int a = get_process_switch_info(&ps_info,pid_cpu,pid_IO);
    temp_ul=(ps_info.time_cpu.tv_sec * 1000000 + ps_info.time_cpu.tv_usec);
    printf("The CPU-bound process has made %ld process switches\n", ps_info.counter_cpu);
    printf("This process has idle %lu usecs\n", temp_ul); 

    temp_ul=(ps_info.time_IO.tv_sec * 1000000 + ps_info.time_IO.tv_usec);
    printf("The IO-bound process has made %ld process switches\n", ps_info.counter_IO);
    printf("This process has idle %lu usecs\n", temp_ul);printf("System call returned %ld\n", a);
    return 0;
}
