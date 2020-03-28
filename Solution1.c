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
struct information{
	int processid;
	int arrivaltime;
	int bursttime;
	int completiontime;
	int remainingtime;
};
struct information facultyqueue[100];//f
struct information studentqueue[100];//s
struct information readyqueue[100];//m
int n, fc=0,sc=0, readycount=0;
int timequantum;

void roundrobin_implementation(){
	int time= readyqueue[0].arrivaltime, mark=0, cc=0, i, rc;
	while(time!=120 && cc!=readycount){
		for(i=0; i<=mark; i++){
			if(readyqueue[i].remainingtime > timequantum){
				time=time + timequantum;
				readyqueue[i].remainingtime -= timequantum;
			}
			else if(readyqueue[i].remainingtime <=timequantum && readyqueue[i].remainingtime !=0){
				time += readyqueue[i].remainingtime;
				readyqueue[i].remainingtime =0;
				readyqueue[i].completiontime = time;
				cc++;
			}
			else;
		}
		int start = mark+1;
		for(rc= start; rc<readycount; rc++){
			if(readyqueue[rc].arrivaltime <= time){
				mark++;
			}
		}
	}	
}

////

///
void putting_data_of_both_queues(){
	int isc=0, ifc= 0, min, flag;
	if( fc!=0  && sc!=0){
		while(isc<sc && ifc<fc){
			if(facultyqueue[ifc].arrivaltime == studentqueue[isc].arrivaltime){
				readyqueue[readycount] = facultyqueue[ifc];
				readycount++;
				ifc++;
				readyqueue[readycount]= studentqueue[isc];
				readycount++;
				isc++;
			}
			else if(facultyqueue[ifc].arrivaltime < studentqueue[isc].arrivaltime){
				readyqueue[readycount]= facultyqueue[ifc];
				readycount++;
				ifc++;
			}
			else if(facultyqueue[ifc].arrivaltime > studentqueue[isc].arrivaltime){
				readyqueue[readycount]= studentqueue[isc];
				readycount++;
				isc++;
			}
			else;
		}
		if(readycount != (fc+sc)){
			if(fc!=ifc){
				while(ifc!=fc){
					readyqueue[readycount]= facultyqueue[ifc];
					readycount++;
					ifc++;
				}
			}
			else if(sc!=isc){
				while(isc!=sc){
					readyqueue[readycount]= studentqueue[isc];
					readycount++;
					isc++;
				}
			}
		}
	}
	else if(fc==0){
		while(isc!=sc){
			readyqueue[readycount]= studentqueue[isc];
			readycount++;
			isc++;
		}
	}
	else if(sc==0){
		while(ifc!=fc){
		readyqueue[readycount]= facultyqueue[ifc];
			readycount++;
			ifc++;
		}
	}
	else {
		printf("\nPlease select as per instruction...\n");
	}}
void allinputhere(){
	
	int querytype,  i, t;
	printf("Enter total no of queries: "); scanf("%d", &n);
	if(n==0) { printf("\n No queries has be accepeted\n"); }
	else{
		printf("\nEnter timequantum for each Process: "); scanf("%d", &timequantum);
		printf("\nEnter 1 for faculty and 2 for student\n");
		for(i=0; i<n; i++){
			printf("\n:Press 1(faculty) or 2(student) "); scanf("%d", &querytype);
			if(querytype==1){
				printf("Query Id: "); scanf("%d", &facultyqueue[fc].processid);
				printf("Arrival Time: "); scanf("%d", &t);
				if(t<1000 || t>1200){
					printf("\n Entered wrong slot time. Please enter again.");
					allinputhere();
				}
				else{facultyqueue[fc].arrivaltime= t-1000;}
				printf("Burst time: "); scanf("%d", &facultyqueue[fc].bursttime);	 facultyqueue[fc].remainingtime= facultyqueue[fc].bursttime; 
				fc++;
			} else{
				printf("Query Id: "); scanf("%d", &studentqueue[sc].processid);
				printf("Arrival Time: "); scanf("%d", &t); 
				if(t<1000 || t>1200){
					printf("\nEntered wrong slot time. Please enter again.\n");
					allinputhere();
				}
				else {studentqueue[sc].arrivaltime= t-1000; }
				printf("Burst time: "); scanf("%d", &studentqueue[sc].bursttime);	 studentqueue[sc].remainingtime= studentqueue[sc].bursttime;
				sc++;
			}
		}
	}}
	void printinginformation(){
	
	int i=0, total=0, sum=0; 
	double avg;
	printf("\nHere is the summary....\n");
	printf("\nQuery ID\tArrival Time\tRessolving Time\tCompletion Time\tTurn Around Time\tWaiting Time");
	for(i; i<readycount; i++){
		printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d",
		readyqueue[i].processid, (readyqueue[i].arrivaltime+1000), readyqueue[i].bursttime, (readyqueue[i].completiontime+1000), (readyqueue[i].completiontime-readyqueue[i].arrivaltime), ((readyqueue[i].completiontime-readyqueue[i].arrivaltime)- readyqueue[i].bursttime));
		total= readyqueue[i].completiontime;
		sum+= (readyqueue[i].completiontime-readyqueue[i].arrivaltime);}
			avg = sum/readycount;
	printf("\n\nTotal time Spent for all queries: %d", total);
	printf("\nAverage query time taken is : %f", avg);//lf
	printf("\nAll queries have been solved");}





void main(){
	puts("...................................................Good Morning.......................................................\n");
	puts("Important points are as follows  ------\n");
	puts("*** Mr.Sharma will be available from 10am to 12 am only and respond to your query shortly.");
	puts("*** Please enter arrival time of process in format 1000 to 1200  and in bw this slot only otherwise your query will not be handled.");
	puts("*** Faculty query will be given more preference. So please have patience till your turn comes...");
	puts("*** Time units are in minutes.\n\n\n");
	
	/////////////////////////////taking input
	allinputhere();
	
	//combining both queues
	putting_data_of_both_queues();
	//implementation of round robin
	roundrobin_implementation();
	//summary
	printinginformation();
	
	
	
}





