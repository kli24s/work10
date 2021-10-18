#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//==================================================================================================

struct population {

  char location[100];        // location
  int year;                  // year
  int pop;                   // population (number of people)
  struct population *next;   // next node

};

//==================================================================================================

void print_population(struct population *p) {

  printf("The population of %s in %d is %d.\n", p->location, p->year, p->pop);

}

void print_list(struct population *p) {

  while (p) {
    print_population(p);
    p = p->next;
  }

}

//==================================================================================================

struct population * free_list(struct population *p) {

  struct population *tmp;

  while (p) {
    tmp = p;
    p = p->next;
    free(tmp);
  }

  return p;

}

//==================================================================================================

struct population * make_population(char *location, int year, int pop, struct population *next) {

  struct population *p = malloc(sizeof(struct population));

  strncpy(p->location, location, sizeof(p->location));
  p->year = year;
  p->pop = pop;
  p->next = next;

  return p;

}

//==================================================================================================

struct population * insert_front(char *location, int year, int pop, struct population *next) {

  struct population *front = make_population(location, year, pop, next);
  return front;

}

//==================================================================================================

int main() {

  srand(time(NULL));
  int rand_year = (rand() % 2000) + 2022;

  struct population *europa = make_population("Europa", rand_year, rand(), NULL);
  struct population *titan = insert_front("Titan", rand_year, rand(), europa);
  struct population *io = insert_front("Io", rand_year, rand(), titan);

  print_list(io);
  free_list(io);

  return 0;

}
