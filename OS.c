#include<stdio.h>

struct process
{
      int process_id,arrival_time, Service_time, ct, waiting_time, turnaround_time, priority;
      int status; 
}
process_queue[10]; 
int limit;
void Arrival_time_sorting() 
{
      struct process temp;
      int i, j;
      for(i = 0; i < limit - 1; i++) 
      {
            for(j = i + 1; j < limit; j++) 
            {
                  if(process_queue[i].arrival_time > process_queue[j].arrival_time)
                  {
                        temp = process_queue[i];
                        process_queue[i] = process_queue[j];
                        process_queue[j] = temp;
                  }
            }
      }
}

int main()
{
      int i, time = 0, Service_time = 0, largest,c;  
      float wait_time = 0, turnaround_time = 0, avg_waiting_time, avg_turnaround_time;
      printf("\nEnter Total Number of Processes:\t");
      scanf("%d", &limit); 
      for(i = 0, c =1; i < limit; i++, c++)
      {
            process_queue[i].process_id = c;  
            printf("\nEnter Details For Process[%d]:\n", process_queue[i].process_id); 
            printf("Enter Arrival Time:\t"); 
            scanf("%d", &process_queue[i].arrival_time ); 
            printf("Enter Service Time:\t"); 
            scanf("%d", &process_queue[i].Service_time); 
            process_queue[i].status = 0; 
            Service_time+= process_queue[i].Service_time; 
      }
      Arrival_time_sorting();
      process_queue[9].priority = -9999;
      printf("\nProcess Id\tArrival Time\tService Time\tPriority\tWaiting Time");
      for(time = process_queue[0].arrival_time; time < Service_time;)
      {
            largest = 9;
            for(i = 0; i < limit; i++)
            {
                  if(process_queue[i].arrival_time <= time && process_queue[i].status != 1 && process_queue[i].priority > process_queue[largest].priority)
                  {
                        largest = i;
                  }
            }
            time = time + process_queue[largest].Service_time; 
            process_queue[largest].ct = time;
            process_queue[largest].waiting_time = process_queue[largest].ct - process_queue[largest].arrival_time - process_queue[largest].Service_time; 
            process_queue[largest].turnaround_time = process_queue[largest].ct - process_queue[largest].arrival_time; 
            process_queue[largest].status = 1;
            wait_time = wait_time + process_queue[largest].waiting_time;
            turnaround_time = turnaround_time + process_queue[largest].turnaround_time; 
            printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", process_queue[largest].process_id, process_queue[largest].arrival_time, process_queue[largest].Service_time, process_queue[largest].priority, process_queue[largest].waiting_time);
      }
      avg_waiting_time = wait_time / limit; 
      avg_turnaround_time = turnaround_time / limit; 
      printf("\n\nAverage Waiting Time:\t%f\n", avg_waiting_time); 
      
}


