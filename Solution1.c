#include<stdio.h>
#include<string.h>
#include<stdbool.h>
struct information{


	//int completiontime;
	int remainingtime;//rbt
	int turnaroundtime;//+
	int waitingtime;
	int processid;
	int arrivaltime;
	int bursttime;
	
};
struct information facultyqueue[100];//f
struct information studentqueue[100];//s
struct information readyqueue[100];//merger
int n, fc=0,sc=0, readycount=0;//facultycount,studentcount,no of process

int time;//total time of execution +
int totalwaiting=0;
int totalturnaroundtime=0;

void roundrobin_implementation(){
int timequantum;
printf("\nEnter time quantum\n");
scanf("%d",&timequantum);
int queriesleft=n;

bool cpustate=0;
printf("\nOverall Summary of process execution\n");
for(time=readyqueue[0].arrivaltime,readycount=0;queriesleft!=0;){
	if(readyqueue[readycount].remainingtime<=timequantum && readyqueue[readycount].remainingtime!=0){
		time += readyqueue[readycount].remainingtime;
		readyqueue[readycount].remainingtime=0;
		cpustate=1;
		
      readyqueue[readycount].waitingtime += time-(readyqueue[readycount].arrivaltime+readyqueue[readycount].bursttime);
      readyqueue[readycount].turnaroundtime += time-(readyqueue[readycount].arrivaltime);
      totalwaiting += readyqueue[readycount].waitingtime;
      totalturnaroundtime += readyqueue[readycount].turnaroundtime;
      queriesleft--;
      printf("%d ",readyqueue[readycount].processid);
	}
	else if(readyqueue[readycount].remainingtime>timequantum){
		time += timequantum;
		readyqueue[readycount].remainingtime -= timequantum;
		printf("%d",readyqueue[readycount].processid);
		cpustate=0;
		
	}
	if(readycount==n-1){
	readycount=0;
	
	
}
else if(readyqueue[readycount+1].arrivaltime<time){
	readycount++;
	
	
}
else if(cpustate==1 && readyqueue[readycount+1].arrivaltime>time && readyqueue[readycount-1].remainingtime==0){
	time=readyqueue[readycount+1].arrivaltime;
	readycount++;
	
}
else{
	readycount=0;
}
}
}

////

///
void putting_data_of_both_queues(){
	int studentiterator=0, facultyiterator= 0;
	if( fc!=0  && sc!=0){
		while( facultyiterator<fc && studentiterator<sc ){
			if(facultyqueue[facultyiterator].arrivaltime == studentqueue[studentiterator].arrivaltime){
				readyqueue[readycount] = facultyqueue[facultyiterator];
				readycount++;
				facultyiterator++;
//				readyqueue[readycount]= studentqueue[studentiterator];
//				readycount++;
//				studentiterator++;
			}
			else if(facultyqueue[facultyiterator].arrivaltime > studentqueue[studentiterator].arrivaltime){
				readyqueue[readycount]= studentqueue[studentiterator];
				readycount++;
				studentiterator++;
			}
			
			else if(facultyqueue[facultyiterator].arrivaltime < studentqueue[studentiterator].arrivaltime){
				readyqueue[readycount]= facultyqueue[facultyiterator];
				readycount++;
				facultyiterator++;
			}
			
			
		}
		if(fc==facultyiterator)
    {
      while(studentiterator!=sc)
      {
        readyqueue[readycount]=studentqueue[studentiterator];
        studentiterator++;
        readycount++;
      }
    }
    else if(sc==studentiterator)
    {
      while(facultyiterator!=fc)
      {
        readyqueue[readycount]=facultyqueue[facultyiterator];
        facultyiterator++;
        readycount++;
      }
    }
  }

  else if(fc==0)
  {
    while(studentiterator!=sc)
    {
      readyqueue[readycount]=studentqueue[studentiterator];
      studentiterator++;
      readycount++;
    }
  }
  else if(sc==0)
  {
    while(facultyiterator!=fc)
    {
      readyqueue[readycount]=facultyqueue[facultyiterator];
      facultyiterator++;
      readycount++;
    }
  }
}


void allinputhere(){
	
	int querytype,  i;
	printf("Enter total no of queries: ");
	scanf("%d", &n);

		printf("\nEnter 1 for faculty and 2 for student\n");
		for(i=0; i<n; i++){
			printf("\n:Press 1(faculty) or 2(student) "); 
			scanf("%d", &querytype);
			if(querytype==1){
			
				facultyqueue[fc].processid=i;
				printf("Arrival Time: "); scanf("%d", &facultyqueue[fc].arrivaltime);
				if(facultyqueue[fc].arrivaltime<1000 || facultyqueue[fc].arrivaltime>1200){
					printf("\n Entered wrong slot time.Enter again ");
					i--;//to go at same iteration
					continue;
				}
				//else{facultyqueue[fc].arrivaltime= t-1000;}
				printf("Burst time: "); scanf("%d", &facultyqueue[fc].bursttime);	 
				facultyqueue[fc].remainingtime= facultyqueue[fc].bursttime; 
				fc++;
			} 
			else if(querytype==2){
				//printf("Query Id: "); scanf("%d", &studentqueue[sc].processid);
				studentqueue[sc].processid=i;
				printf("Arrival Time: "); scanf("%d", &studentqueue[sc].arrivaltime); 
				if(studentqueue[sc].arrivaltime<1000 || studentqueue[sc].arrivaltime>1200){
					printf("\nEntered wrong slot time\n");
					i--;
					continue;
				}
				//else {studentqueue[sc].arrivaltime= t-1000; }
				printf("Burst time: "); scanf("%d", &studentqueue[sc].bursttime);
				 studentqueue[sc].remainingtime= studentqueue[sc].bursttime;
				sc++;
			}
			else{
				printf("Please choose only from 1 and 2");
				i--;
				
			}
		}
	}





void main(){
	puts("...................................................Good Morning.......................................................\n");
	puts("Important points are as follows  ------\n");
	puts("*** Mr.Sharma will be available from 10am to 12 am only and respond to your query shortly.");
	puts("*** Please enter arrival time of process in format 1000 to 1200  and in bw this slot only otherwise your query will not be handled.");
	puts("*** Faculty query will be given more preference. So please have patience till your turn comes...");
	puts("*** Time units are in minutes.\n\n\n");
	

	allinputhere();
	
	//combining both queues
	putting_data_of_both_queues();
	//implementation of round robin
	roundrobin_implementation();
	//summary
	
	int z;
  printf("\nProcess id\t\tBurst Time\t\tArrival Time\t\tWaiting Time\t\tTurnaround Time\n");
  for(z=0;z<n;z++)
  {
    printf("\n%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d",readyqueue[z].processid,readyqueue[z].bursttime,readyqueue[z].arrivaltime,readyqueue[z].waitingtime,readyqueue[z].turnaroundtime);
  }
  printf("\n\nTime Spent :%d\n\n", (time-readyqueue[readycount].arrivaltime));
  printf("\nAvg Waiting Time:%d\n\n",(totalwaiting/n));
  printf("\nAvg Turnaround Time:%d\n\n",(totalturnaroundtime/n));
	puts("\nThanks, for your patience...");
	
	
	
}
