#include <stdlib.h>

enum WinningSets {
    THREE_0,
    THREE_OTHER,
    PAIR_0,
    PAIR_OTHER,
    NONE
};

// Multiplers
#define THREE_PLUS 15.0
#define THREE 6.5
#define PAIR_PLUS 5.5
#define PAIR 3.2

int get_number() {
    return rand() % 10;
}

int* set_number() {
    static int drawn_numbers[3];
    for (int i = 0; i < 3; i++)
    {
        drawn_numbers[i] = get_number();
    }
    return drawn_numbers;
}

enum WinningSets validate_game(int* numbers) {
    if (numbers[0] == 0 && numbers[1] == 0 && numbers[2] == 0) {
        return THREE_0;
    }
    else if (numbers[0] == numbers[1] && numbers[0] == numbers[2] && numbers[0] != 0) {
        return THREE_OTHER;
    }
    else if ((numbers[0] == numbers[1] && numbers[0] == 0) || 
             (numbers[0] == numbers[2] && numbers[0] == 0) || 
             (numbers[1] == numbers[2] && numbers[1] == 0)) {
        return PAIR_0;
    }
    else if (numbers[0] == numbers[1] || numbers[0] == numbers[2] || numbers[1] == numbers[2]) {
        return PAIR_OTHER;
    }
    return NONE;
}

float payment(enum WinningSets set, float bet) {
    float pay;
    switch (set)
    {
    case THREE_0:
        pay = bet * THREE_PLUS;
        break;
    case THREE_OTHER:
        pay = bet * THREE;
        break;
    case PAIR_0:
        pay = bet * PAIR_PLUS;
        break;
    case PAIR_OTHER:
        pay = bet * PAIR;
        break;
    default:
         pay = 0;
        break;
    }
    return pay;
}

float game(float bet) {
    int* nums = set_number();
    enum WinningSets result = validate_game(nums);

    return payment(result, bet);
}