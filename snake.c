snake initialize_snake(){
    snake snakey;
    snakey.length = 1;
    snakey.positions[0].x = 1;  
    snakey.positions[0].y = 1;
    return snakey;
}

void add_body(tuple position, snake* snakey){
    snakey->length++;
    snakey->positions[snakey->length - 1] = position;
}

bool check_crash(snake* snakey){
    if (snakey->positions[0].x == 0 || snakey->positions[0].y == 0 || snakey->positions[0].x == 2 * SIZE - 1 || snakey->positions[0].y == SIZE - 1){
        return true;
    } else {
        return false;
    }
}

bool check_collision(snake* snakey){
    tuple head = snakey->positions[0];
    for (int i = 1 ; i < snakey->length ; i++){
        if (head.x == snakey->positions[i].x && head.y == snakey->positions[i].y){
            //printf("%d", i);
            return true;
        }
    }
    return false;
}

char calculate_direc(char current_direc, int ch) {
    if (ch == 'd' || ch == KEY_DOWN && current_direc != 'u') return 'd';
    else if (ch == 'u' || ch == KEY_UP && current_direc != 'd') return 'u';
    else if (ch == 'l' || ch == KEY_LEFT && current_direc != 'r') return 'l';
    else if (ch == 'r' || ch == KEY_RIGHT && current_direc != 'l') return 'r';
    return current_direc;
}

snake update_snake(char direc, snake snakey){
    tuple new_positions[SIZE * SIZE];
    int ch = -1;
   
    if (direc == 'd'){
        new_positions[0].x = snakey.positions[0].x;
        new_positions[0].y = snakey.positions[0].y + 1;
    }
    else if (direc == 'u'){
        new_positions[0].x = snakey.positions[0].x;
        new_positions[0].y = snakey.positions[0].y - 1;
    }
    else if (direc == 'l'){
        new_positions[0].x = snakey.positions[0].x - 1;
        new_positions[0].y = snakey.positions[0].y;
    }
    else if (direc == 'r'){
        new_positions[0].x = snakey.positions[0].x + 1;
        new_positions[0].y = snakey.positions[0].y;
    }
    for (int i = 0 ; i + 1 < snakey.length ; i++){
        new_positions[i + 1].x = snakey.positions[i].x;
        new_positions[i + 1].y = snakey.positions[i].y;
    }
    for (int i = 0 ; i < snakey.length ; i++){
        snakey.positions[i].x = new_positions[i].x;
        snakey.positions[i].y = new_positions[i].y;
    }
    return snakey;
}