typedef struct {
    int x;
    int y;
} tuple;

bool check_tuple_valid(tuple tup, snake* snakey);
bool check_pellet_eaten(tuple pellet, tuple head);
tuple get_random_tuple();

