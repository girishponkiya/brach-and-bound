#include "prip.h"


int main(){

	int M, m, 	//input paramss
		cntr, i;	// counter variable for iteration

	list set = NULL,
		 temp, ptr;

	printf("\n\n===: Program for feature selection :===");

	printf("\n\n M = ");
  	scanf("%d",&M);
  	printf(" m = ");
  	scanf("%d",&m);
  
  	cntr = 1;
 
  	for( i=0; i<M; i++){

  		temp=(list)malloc(sizeof(struct _list));
  		temp->num = i+1;
		temp->next = NULL;
		
		if(set==NULL){
			set = temp;
			ptr = temp;
		}else{
	 	 	ptr->next = temp;
	 	 	ptr = temp;
		}
  	}

  	ptr = set;
  	printf("\n Set of features: ");
  	while( ptr != NULL ){
	  	printf("%d, ", ptr->num);
	  	ptr = ptr->next;
  	}    
  
  	printf("\n J value of all features: %d", calcJ(set, M));
	
  	tset = selectOptimalFeature( set, M, m, m+1 );
	
  	printf("\n\n Optimal subset is: ");
  	ptr = tset;
  	while( ptr != NULL ){
	  	printf("%d, ", ptr->num);
	  	ptr = ptr->next;
  	}

  	printf("\n J of optimal features: %d \n\n", calcJ( tset, m ));

  	deleteList( tset );
  	deleteList( set );
  	tset = set = NULL;

	return 0;
}

