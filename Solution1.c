//Problem Statement

/*
 Sudesh Sharma is a Linux expert who wants to have an online system where he can handle student queries. Since there can be multiple
  requests at any time he wishes to dedicate a fixed amount of time to every request so that everyone gets a fair share of his time.
   He will log into the system from 10am to 12am only.  He wants to have separate requests queues for students and faculty. 
   Implement a strategy for the same. The summary at the end of the session should include the total time he spent on handling queries 
   and average query time. 


*/
//=======================================================================

//As per the scenerio given in the question the best practice that should bee used here is "Round-Robin Algorithm".(Time sharing system)
//for avg response time it is the best algorithm 
/*Important points :----
1.Criteria : Time Quantum
2.Mode: Preemptive
3.Turn Around Time = Completion Time - Arrival Time
4.Waiting time= TAT - BT(Burst time)
5.Response Time = Cpu given to process first time - Arrival time
6.Context switching - save running process and loading the new process (it is so fast that we cannot feel it as ex.music and video simultaneously )

Needs--
1. 2 Queues -- ready and running
in ready queue - put according to their arrival time.
after executing first check which got ready in the meantime and those which got ready put them in ready queue accord to arrival time

//============================================================================//
Assumptions:
time alloted for each query let be 3 minutes
we have total 120 minutes window 


*/




#include<stdio.h>
#include<string.h>
//defining structure 
struct Process{ 
 char process_name[25];
 int arrival_time,burst_time,completion_time,remaining_time_for_completion;                                                                          
};
struct Process Struct1;// global declaration of variable of process data type


//as we need two seperate request queues so 1.for teachers
void queue_for_faculties(int no_of_process){
	int count,arrival_time,burst_time,time_quantum;
	struct Process faculty_process[no_of_process];//making local variables of count given in no_of_process of data type process
	for(count=0;count<no_of_process;count++){
		printf("Enter the details of Process[%d]",count+1);
		puts("");
		
		
	}
	
	
}


struct information student_queue[100],faculty_queue[100],ready_queue[100],running[100];//m is ready
//void enqueue(int a[],int rear);
//void dequeue(int a[],int front);
int facultycount=0;//fc
int studentcount=0;//sc
int readypointer=0;//mc

//int time =0;
void worker(){
	int i;
	int jobs=0;
	int jobe=0;
	int tracker=0;
	printf("\n worker");
	while(time<120){
		printf("\nworker at time : %d",time);
		if(ready_queue[tracker].arrivaltime==time){
			jobe++;
			
		}
		for(i=0;i<=jobe;i++){
			if(ready_queue[i].bbd>2){
				ready_queue[i].bbd-=2;
				time+=2;
				
				
			}
			else{
				time+=ready_queue[i].bbd;
				ready_queue[i].bbd=0;
				ready_queue[i].endtime=time;
				jobs++;
				
			}
		}
	}
}

//void getstats(int findex,int sindex);//faculty f ,student s
//void round_robin();//scheduler
//int time_quantum=2;
//void round_robin(){
//	int faculty_pointer=0,student_pointer=0;
//	int total_time=120,i;//total time=time
//	for(i=0;i<=total_time;i++){
//		if(student_queue[student_pointer].arrivaltime==i || faculty_queue[faculty_pointer]==i){
//			if(faculty_queue[faculty_pointer]==i){
//				
//			}
//			else{
//				
//			}
//		else{
//			continue;
//		}
//		}
//	}

	
//}
void ready(){
	int i;
	int s=0,f=0;
	int r=0;
	for(i=0;i<=120;i++){//aswe have 120 min
		if(i==student_queue[s].arrivaltime && i==faculty[f].arrivaltime){
			ready_queue[r]=faculty_queue[f];
			r++;
			f++;
			while(i==faculty_queue[f].arrivaltime){
				ready_queue[r]=faculty_queue[f];
				r++;
				f++;
				
			}
			ready_queue[r]=student_queue[s];
			r++;
			s++;
			while(i==student_queue[s].arrivaltime){
				ready_queue[r]=student_queue[s];
				r++;
				s++;
				
			}
			
			
			
		}
		else if(i==student_queue[s].arrivaltime){
				ready_queue[r]=student_queue[s];
				r++;
				s++;
				while(i==student_queue[s].arrivaltime){
				ready_queue[r]=student_queue[s];
				r++;
				s++;
		}
		else if(i==faculty_queue[f].arrivaltime){
				ready_queue[r]=faculty_queue[f];
				r++;
				s++;
				while(i==faculty_queue[f].arrivaltime){
				ready_queue[r]=faculty_queue[f];
				r++;
				f++;
		}
		else continue;
		
		
	}
	readypointer=r;
	
	
}
void print_info(){
	int i=0,j=0;
	printf("faculty \n");
	for(i=0;i<facultycount;i++){
		printf("id: %d,attime: %d,bttime: %d \n",faculty_queue[i].processid,faculty_queue[i].arrivaltime,faculty_queue[i].bursttime);
		
	}
	printf("student queries:\n");
	for(i=0;i<studentcount;i++){
		printf("id: %d,attime: %d,bttime: %d \n",student_queue[i].processid,student_queue[i].arrivaltime,student_queue[i].bursttime);
		
	}
	printf("ready queues:\n");
	for(i=0;i<readypointer;i++){
		printf("id: %d,attime: %d,bttime: %d \n",ready_queue[i].processid,ready_queue[i].arrivaltime,ready_queue[i].bursttime);
		
	}
}
void summary(int findex,int sindex);

	
void main(){
	int total_no_of_query,type_of_query,i;
	//struct information student_queue[100],faculty_queue[100];
	int facultycount=0,studentcount=0;
	
	printf("Welcome\n");
	printf("\nEnter total no of queries: ");
	scanf("%d",&total_no_of_query);
	for(i=0;i<total_no_of_query;i++){
		printf("\nPress 1 for student or 2 for faculty");
		scanf("%d",&type_of_query);
		if(type_of_query==1){
			printf("you selected faculty:\n");
			printf("queryid:\n");
			scanf("%d",&faculty_queue[facultycount].processid);
			printf("Arrival time should be in bw 10am to 12 pm, your format should be of type hhmm");
			scanf("%d",&faculty_queue[facultycount].arrivaltime);
			printf("burst time in minutes:");
			scanf("%d",&faculty_queue[facultycount].bursttime);
			//faculty_queue[facultycount].completion_time=0;
			facultycount++;
			
			
		}
		else{
			printf("you selected student query:\n");
			printf("queryid:\n");
			scanf("%d",&student_queue[studentcount].processid);
			printf("Arrival time should be in bw 10am to 12 pm, your format should be of type hhmm");
			scanf("%d",&student_queue[studentcount].arrivaltime);
			printf("burst time in minutes:");
			scanf("%d",&student_queue[studentcount].bursttime);
			//student_queue[studentcount].completion_time=0;
			studentcount++;
			
		}
		//getstats(facultycount,studentcount);
		ready();
		//print_info();
		//summary(facultycount,studentcount);
		worker();
		
		
			
		
	}
	
}
void summary(int findex , int sindex ){
	int i;
	printf("\n summary");
	printf("\nfaculty queries details\n");
			printf("\n query id \  arrivaltime  \ burst time \n");
			for(i=0;i<findex;i++){
				printf("%d / %d / %d",faculty_queue[i].processid,faculty_queue.arrivaltime,faculty_queue.bursttime);
			}
}
//void getstats(int findex,int sindex){
//			int i;
//			printf("details for all jobs completed");
//			printf("\nfaculty queries details\n");
//			printf("\n query id \  arrivaltime  \ resolving time \n");
//			for(i=0;i<findex;i++){
//				printf("%d / %d / %d",faculty_queue[i].processid,faculty_queue.arrivaltime,faculty_queue.bursttime);
//			}
//		}





