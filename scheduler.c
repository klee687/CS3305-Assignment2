/******************************************************************************
* 
* Name: 	Zaid Albirawi
* Email: 	zalbiraw@uwo.ca
*
* scheduler.c 
*
******************************************************************************/

#include "scheduler.h"
#define FCFS 0
#define LIFO 1
#define SJF 2
#define RR 3

job_t *get_next_job(int mode, d_linked_list_t* jobs) {
	if (mode == FCFS) {
		job_t *j;
        j = dequeue(jobs);
        return j;
	}
    
    else if (mode == LIFO){
		job_t *j;
		j = pop(jobs);
	    return j;	
	}

	
    else if (mode == SJF){
		job_t *shortest;
		job_t *temp;
		int i = 0;
		shortest = dequeue(jobs); //dequeue the first element that was in the linked-list.
		while (i < jobs->size){ 	// while it is within jobs' size, you loop.
			
			temp = dequeue(jobs);	//dequeue the next node.
			if (shortest->required_time < temp->required_time){ //if temp required time is longer than the 'shortest' 
				enqueue(jobs,temp);				// just put it back (enqueue)
			}else if(shortest->required_time >=temp->required_time){	//if shortest takes longer than the temp
				enqueue(jobs,shortest);				//enqueue the shortest
				shortest = temp;			//and now temp is the shortest
			}
		i++;
	} return shortest;	//return shortest
}
    else{
        job_t *j;
        j = dequeue(jobs);
        if (jobs == NULL){
            j = pop(jobs);
		return j;
	    }   
    }	
}

