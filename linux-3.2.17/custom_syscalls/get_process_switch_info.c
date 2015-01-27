#include <linux/kernel.h>
#include <linux/sched.h>

asmlinkage long sys_get_process_switch_info(struct process_switch_info * ps_info, int cpu_pid, int io_pid)
{
  printk("Hello world\n");
  struct process_switch_info* info;
	info=ps_info;
	struct task_struct *task_list;
	struct task_struct *process1;
	struct task_struct *process2;
	for_each_process(task_list)
	{
		if(task_list->pid==cpu_pid)
		{
			process1=task_list;
		}
		else if(task_list->pid==io_pid)
		{
			process2=task_list;
		}
	}
	if(process1&&process2)
	{
		info->counter_cpu		=process1->cs_count;
		info->counter_IO		=process2->cs_count;
		info->time_cpu.tv_sec	=process1->time_value.tv_sec;
		info->time_cpu.tv_usec	=process1->time_value.tv_usec;
		info->time_IO.tv_sec	=process2->time_value.tv_sec;
		info->time_IO.tv_usec	=process2->time_value.tv_usec;
	}
	else
	{
		printk("\nprocess1(PID:%d) or process2(PID:%d) not found\n",cpu_pid,io_pid);
		return 0;
	}
  return 0;
}
