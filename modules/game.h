#ifndef GAME_H
#define GAME_H

struct GameResult
{
    int* game_numbers;
    float pay;
};

int get_number();
int* set_number();
enum WinningSets validate_game(int* numbers);
float payment(enum WinningSets set, float bet);
struct GameResult game(float bet);
#endif