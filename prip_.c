#include "prip.h"

list tset, SMAX;
int JMAX=0;


/**
 * Deletes the (x)th node of the link list. 
 * This function used in selectOptimalFeature.
 * 
 * @param temp
 * @param x
 * @return list
 */
list delete(list l, int x){

	int i;
	list temp, prev, ll;

	// no deap-copy required here.
	ll = l;
	
	i = 1;
	if( x==0 ){
		ll = ll->next;
  	}else{
		prev = ll;
		while( i<x && prev ){
	  		prev = prev->next;
	  		i++;
		}
		if( prev ){
			temp = prev->next;
			if( temp ){
				prev->next = prev->next->next;
				free( temp );
			}
		}
		
  	}
  	return ll;
}


/**
 * Deallocate space allocated for each element in List
 * 
 * @param temp list
 * @return list
 */
void deleteList(list l){
	list temp;
	while( l != NULL){
		temp = l;
		 l = l->next;
		free( temp );
	}
}


/**
 * Calculates the J Value.
 * This program simply adds the all params. But user can chage this function and
 * implemet his/her owen J function.
 *
 * @param set
 * @param size
 * @return int J-value for given set
 */
int calcJ(list set, int size ){
  	
  	int result = 0;
  	
  	//printf("J( {");
  	while( set != NULL ){
		result += set->num;
		//printf("%d,\n", set->num);
		set = set->next;
  	}
  	printf("} ) = %d\n", J);
  	
  	return result;
}

/**
 * Finds set of optimal features recursively.
 * 
 * @param set 
 * @param M
 * @param m
 * @param k
 * @return list
 */
list selectOptimalFeature( list set, int M, int m, int k){

	int i, j;

	if( M == m ){
		
		j = calcJ(set, m);

		if( j > JMAX ){
	  		JMAX = j;
	  		SMAX = dipCopy( set );
		}
  	}
  	else{
		selectOptimalFeature( delete(set, 0), M-1, m, 1);

		for(i=1; i<(m+1); i++){

	  		j = calcJ( delete(set, i), M-1 );
	  		if( j>JMAX )
				selectOptimalFeature( delete(set, i), M-1, m, i);
		}
  	}

  	return SMAX;
}      


/**
 * Creats th shadow-copy/dip-copy of given list.
 * 
 * @param set
 * @return list
 */
list dipCopy(list l){
	
	list temp, head, d;
  	
  	temp = head = d = NULL;

  	while( l ){

		temp = (list) malloc( sizeof(struct _list) );
		temp->num = l->num;
		temp->next = NULL;

		if( head == NULL ){
	  		head = temp;
	  		d = temp;
		}
		else{
	  		d->next = temp;
	  		d = temp;
		}

		l = l->next;
  	}

 	return head;
}
