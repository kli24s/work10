struct population;

void print_population(struct population *p);

void print_list(struct population *p);

struct population * free_list(struct population *p);

struct population * make_population(char *location, int year, int population);

struct population * insert_front(char *location, int year, int population, struct population *next);

struct population * remove_node(struct population *front, int population);
