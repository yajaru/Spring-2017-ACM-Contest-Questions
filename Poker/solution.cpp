
#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

struct Card {
    char value;
    char suit;
};

int valueLookup(char val) {
    switch (val) {
        case '2':
            return 1;
        case '3':
            return 2;
        case '4':
            return 3;
        case '5':
            return 4;
        case '6':
            return 5;
        case '7':
            return 6;
        case '8':
            return 7;
        case '9':
            return 8;
        case 'T':
            return 9;
        case 'J':
            return 10;
        case 'Q':
            return 11;
        case 'K':
            return 12;
        case 'A':
            return 13;
    }
    return 0;
}

enum WINSTATE {
    PLAYER1,
    PLAYER2,
    TIE,
    NEITHER
};

int card_cmp(const Card a, const Card b) {
    return a.value > b.value;
}

WINSTATE checkStraightFlush (const Card hand1[5], const Card hand2[5]) {
    char hand1_suit = hand1[0].suit;
    char hand2_suit = hand2[0].suit;
    int hand1_start_val = hand1[0].value;
    int hand2_start_val = hand2[0].value;
    bool hand1_failed = false;
    bool hand2_failed = false;

    for (int i = 0; i < 5; ++i) {
        if (hand1_failed || hand1_start_val - i != hand1[i].value || hand1[i].suit != hand1_suit)
            hand1_failed = true;

        if (hand2_failed || hand2_start_val - i != hand2[i].value || hand2[i].suit != hand2_suit)
            hand2_failed = true;
    }

    if(hand1_failed && hand2_failed)
        return NEITHER;
    else if (!hand1_failed && !hand2_failed)
        return TIE;
    else if (!hand1_failed)
        return PLAYER2;
    else
        return PLAYER1;

}

WINSTATE checkFourOfAKind(const Card hand1[5], const Card hand2[5]) {
    bool hand1_passed = false;
    bool hand2_passed = false;

    int hand1_values[13] = {0};
    int hand2_values[13] = {0};

    for (int i = 0; i < 5; ++i) {
        ++hand1_values[hand1[i].value - 1];
        ++hand2_values[hand2[i].value - 1];
    }

    for (int i = 0; i < 13; ++i) {
        if(hand1_values[i] == 4)
            hand1_passed = true;
        if(hand2_values[i] == 4)
            hand2_passed = true;
    }

    if(hand1_passed && hand2_passed)
        return TIE;
    else if (!hand1_passed && !hand2_passed)
        return NEITHER;
    else if (hand1_passed)
        return PLAYER1;
    else
        return PLAYER2;
}

WINSTATE checkFullHouse(const Card hand1[5], const Card hand2[5]) {
    int hand1_values[13] = {0};
    int hand2_values[13] = {0};
    for (int i = 0; i < 5; ++i) {
        ++hand1_values[hand1[i].value - 1];
        ++hand2_values[hand2[i].value - 1];
    }

    bool hand1_three = false;
    bool hand1_two = false;

    bool hand2_three = false;
    bool hand2_two = false;

    for (int i = 0; i < 13; ++i) {
        if(hand1_values[i] == 3)
            hand1_three = true;
        if(hand1_values[i] == 2)
            hand1_two = true;
        if(hand2_values[i] == 3)
            hand2_three = true;
        if(hand2_values[i] == 2)
            hand2_two = true;
    }

    bool hand1_passed = hand1_three && hand1_two;
    bool hand2_passed = hand2_three && hand2_two;

    if(hand1_passed && hand2_passed)
        return TIE;
    else if (!hand1_passed && !hand2_passed)
        return NEITHER;
    else if (hand1_passed)
        return PLAYER1;
    else
        return PLAYER2;
}

WINSTATE checkTwoPairs(const Card hand1[5], const Card hand2[5]) {

    int hand1_values[13] = {0};
    int hand2_values[13] = {0};
    for (int i = 0; i < 5; ++i) {
        ++hand1_values[hand1[i].value - 1];
        ++hand2_values[hand2[i].value - 1];
    }

    char hand1_pairs = 0;
    char hand2_pairs = 0;

    for (int i = 0; i < 13; ++i) {
        if(hand1_values[i] == 2)
            ++hand1_pairs;
        if(hand2_values[i] == 2)
            ++hand2_pairs;
    }

    bool hand1_passed = hand1_pairs >= 2 ? true: false;
    bool hand2_passed = hand2_pairs >= 2 ? true: false;

    if(hand1_passed && hand2_passed)
        return TIE;
    else if (!hand1_passed && !hand2_passed)
        return NEITHER;
    else if (hand1_passed)
        return PLAYER1;
    else
        return PLAYER2;
}

WINSTATE checkHighestCard (const Card hand1[5], const Card hand2[5]) {
    for (int i = 0; i < 5; ++i) {
        if (hand1[i].value > hand2[i].value)
            return PLAYER1;
        else if (hand1[i].value < hand2[i].value)
            return PLAYER2;
    }
    return TIE;
}

void printWinMessage(WINSTATE state) {
    switch (state) {
        case TIE:
            cout << "TIE " << endl;
            break;
        case PLAYER1:
            cout << "PLAYER 1 " << endl;
            break;
        case PLAYER2:
            cout << "PLAYER 2 " << endl;
            break;
        default:
            cout << "ERROR " << endl;
    }
}

int main() {
    int count = 0;
    string line = "";
    getline(cin, line);

    count = stoi(line);

    for(int i = 0; i < count; ++i) {
        getline(cin, line);

        Card hand1[5];
        Card hand2[5];

        for(int j = 0; j < 5; ++j) {

            hand1[j].value = valueLookup(line[j * 3]);
            hand1[j].suit = line[j * 3 + 1];

            hand2[j].value = valueLookup(line[j * 3 + 15]);
            hand2[j].suit = line[j * 3 + 16];
        }

        sort(begin(hand1), end(hand1), card_cmp);
        sort(begin(hand2), end(hand2), card_cmp);

        WINSTATE state = checkStraightFlush(hand1, hand2);
        if (state == TIE) {
            printWinMessage(checkHighestCard(hand1, hand2));
            continue;
        }
        else if (state == PLAYER1 || state == PLAYER2) {
            printWinMessage(state);
            continue;
        }

        state = checkFourOfAKind(hand1, hand2);
        if (state == TIE) {
            printWinMessage(checkHighestCard(hand1, hand2));
            continue;
        }
        else if (state == PLAYER1 || state == PLAYER2) {
            printWinMessage(state);
            continue;
        }

        state = checkFullHouse(hand1, hand2);
        if (state == TIE) {
            printWinMessage(checkHighestCard(hand1, hand2));
            continue;
        }
        else if (state == PLAYER1 || state == PLAYER2) {
            printWinMessage(state);
            continue;
        }

        state = checkTwoPairs(hand1, hand2);
        if (state == TIE) {
            printWinMessage(checkHighestCard(hand1, hand2));
            continue;
        }
        else if (state == PLAYER1 || state == PLAYER2) {
            printWinMessage(state);
            continue;
        }

        printWinMessage(checkHighestCard(hand1, hand2));
     }
}
