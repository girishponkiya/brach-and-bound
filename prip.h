#include<stdio.h>
#include<stdlib.h>

#ifndef _PRIP_H_
#define _PRIP_H_

struct _list {
  int num;
  struct _list *next;
};

typedef struct _list *list;
extern list tset, SMAX;


/**
 * Calculates the J Value.
 * This program simply adds the all params. But user can chage this function and
 * implemet his/her owen J function.
 *
 * @param set
 * @param size
 * @return int J-value for given set
 */
int calcJ( list fset, int size );


/**
 * Finds set of optimal features recursively.
 * 
 * @param set 
 * @param M
 * @param m
 * @param k
 * @return list
 */
list selectOptimalFeature( list funset, int M, int m, int k );


/**
 * Deletes the (x)th node of the link list. 
 * This function used in selectOptimalFeature.
 * 
 * @param temp
 * @param x
 * @return list
 */
list delete(list temp, int x);


/**
 * Deallocate space allocated for each element in List
 * 
 * @param temp list
 * @return list
 */
void deleteList(list temp);


/**
 * Creats th shadow-copy/dip-copy of given list.
 * 
 * @param set
 * @return list
 */
list dipCopy(list a);

#endif
