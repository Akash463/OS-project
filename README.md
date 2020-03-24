# OS-project
Use of Round Robin algorithm for solving the given problem.
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
