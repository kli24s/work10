#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//==================================================================================================

struct population {

  char location[100];        // location
  int year;                  // year
  int population;            // population (number of people)
  struct population *next;   // next node

};

//==================================================================================================

void print_population(struct population *p) {

  printf("\t{%s, %d, %d}", p->location, p->year, p->population);

}

void print_list(struct population *p) {

  printf("[\n");
  while (p) {
    print_population(p);
    printf("\n");
    p = p->next;
  }
  printf("]\n");

}

//==================================================================================================

struct population * free_list(struct population *p) {

  struct population *tmp = p;

  while (p) {
    p = p->next;
    free(tmp);
    tmp = p;
  }

  return p;

}

//==================================================================================================

struct population * make_population(char *location, int year, int population) {

  struct population *p = malloc(sizeof(struct population));

  strncpy(p->location, location, sizeof(p->location));
  p->year = year;
  p->population = population;

  return p;

}

//==================================================================================================

struct population * insert_front(char *location, int year, int population, struct population *next) {

  struct population *front = make_population(location, year, population);
  front->next = next;
  return front;

}

//==================================================================================================

struct population * remove_node(struct population *front, int population) {

  if (front == NULL) return front;

  if (front->population == population) {
    struct population *tmp = front->next;
    free(front);
    return tmp;
  }

  else {
    struct population *front_copy = front;
    struct population *back = front;

    while(front) {
      if (front->population == population) {
        back->next = front->next;
        free(front);
      }
      back = front;
      front = front->next;
    }
    return front_copy;
  }

}

//==================================================================================================
