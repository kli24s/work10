#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "populationlinkedlist.h"

//==================================================================================================

int main() {

  srand(time(NULL));
  int rand_year = (rand() % 2000) + 2022;
  int rand_pop_europa = rand();
  int rand_pop_titan = rand();
  int rand_pop_io = rand();

  struct population *list = NULL;
  list = insert_front("Europa", rand_year, rand_pop_europa, list);
  list = insert_front("Titan", rand_year, rand_pop_titan, list);
  list = insert_front("Io", rand_year, rand_pop_io, list);

  printf("================================================= Complete List:\n");
  print_list(list);

  list = remove_node(list, rand_pop_titan); // removes titan
  printf("================================================= Titan Removed:\n");
  print_list(list);

  list = remove_node(list, rand_pop_io); // removes io
  printf("================================================= Io Removed:\n");
  print_list(list);

  list = remove_node(list, rand_pop_europa); // removes europa
  printf("================================================= Europa Removed:\n");
  print_list(list);

  printf("================================================= Nothing Removed from an Empty List:\n");
  list = remove_node(list, 420); // removes nothing from an empty list
  print_list(list);

  printf("=================================================\n");

  list = free_list(list);

  return 0;

}
