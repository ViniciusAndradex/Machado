#ifndef GAME
#define GAME

int get_number();
int* set_number();
enum WinningSets validate_game(int* numbers);
float payment(enum WinningSets set, float bet);
float game(float bet);
#endif