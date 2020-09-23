#include <stdio.h>

struct process {
	int arrival_time;
    int burst_time;
    int completion_time;
    int turn_around_time;
    int waiting_time;
    int number;
    int start;
};

void swap(struct process *xp, struct process *yp) {
  struct process temp;
  temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void printArray(struct process arr[], int size) {
  int i;
  printf("P#	AT	BT	CT	TAT	WT\n"); 
  //AT is arrival time, BT - burst time, CT - completion time, TAT - turn around time and WT is waiting time
  for (i = 0; i < size; i++) {
    printf("%d	%d	%d	%d	%d	%d \n",
      arr[i].number, arr[i].arrival_time, arr[i].burst_time,
      arr[i].completion_time, arr[i].turn_around_time, arr[i].waiting_time);

  }
}

int main(int argc, char * argv[]) {

  int n = 0;
  printf("Enter the number of processes:\n");
  scanf("%d", &n);

  struct process processes[n];
  for (int i = 0; i < n; i++) {
    struct process pr = {
      0,
      0,
      0,
      0,
      0,
      0,
      0
    };
    processes[n] = pr;
  }	
  
  printf("Enter arrival and burst times for each process:\n");
	for (int i = 0; i < n; i++) {
    	scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time );
	}
	
	int time = 0;
	int shortest;
	for (int i = 0; i < n; i++) {
		shortest = i;
		for (int j = i + 1; j < n; j++) {
			if (processes[j].arrival_time <= time && processes[j].burst_time < processes[shortest].burst_time)
				shortest = j;
		}
		
		processes[shortest].start = time;
		time += processes[shortest].burst_time;
		
		//we are not in that process anymore if
		if (shortest != i) {
			swap(&processes[shortest], &processes[i]);
		}
		
	}
	  int compl_sum = 0;
  double avg_tat = 0;
  double avg_wait = 0;
  for (int i = 0; i < n; i++) {
    processes[i].number = i;
    compl_sum = compl_sum + processes[i].burst_time;
    processes[i].completion_time = compl_sum;
    processes[i].turn_around_time = processes[i].completion_time - processes[i].arrival_time;

    processes[i].waiting_time = processes[i].turn_around_time - processes[i].burst_time;
    if (processes[i].waiting_time < 0) {
      processes[i].waiting_time = 0;
    }
    avg_tat += (double) processes[i].turn_around_time;
    avg_wait += (double) processes[i].waiting_time;
  }

  printArray(processes, n);
  
  int total_completion_time = processes[n - 1].completion_time - processes[0].arrival_time;
  
  n = (double) n;
  printf("\nAverage WT: %f\n", avg_wait / n);
  printf("Average TAT: %f\n", avg_tat / n);
  printf("Total CT: %d\n", total_completion_time);


  return 0;

}
