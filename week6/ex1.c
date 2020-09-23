#include <stdio.h>

struct process {
	int arrival_time;
    int burst_time;
    int completion_time;
    int turn_around_time;
    int waiting_time;
    int number;
};

void swap(struct process *xp, struct process *yp) {
  struct process temp;
  temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void bubbleSort(struct process arr[], int n) {
  int i, j;
  for (i = 0; i < n - 1; i++)
    for (j = 0; j < n - i - 1; j++)
      if (arr[j].arrival_time > arr[j + 1].arrival_time)
        swap( & arr[j], & arr[j + 1]);
}

void printArray(struct process arr[], int size) {
  int i;
  for (i = 0; i < size; i++) {

    printf("process number: %d, arrival: %d, burst: %d, CT: %d, TAT: %d, WT: %d \n",
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
      0
    };
    processes[n] = pr;
  }	
  
  printf("Enter arrival and burst times for each process:\n");
	for (int i = 0; i < n; i++) {
    	scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time );
	}

  bubbleSort(processes, n);

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
  printf("Average TAT: %f", avg_tat / n);
  printf("Total CT: %d\n", total_completion_time);

}
