#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct stats {
    int total_yards;
    int total_passing_yards;
    int total_running_yards;
    int first_downs;
};

int start_game();
void drive();
int starting_yardline();
void run_play(int yard, int down);

void defense_sim();

//plays
int short_pass();
int long_pass();
int inside_run();
int outside_run();
int punt();
int field_goal(int yard);

int main() {
    struct stats total_stats;
    char *team_name[20];

    if (start_game(team_name) == 0) {
        drive();
    } else {
        defense_sim();
    }
    return 0;
}

int start_game(char *team_name) {
    srand(time(NULL));
    char coin_choice[1];
    int coin_number;
    int coin_outcome = rand() % 2;
    char kickoff_choice[1];
    printf("Welcome to the NFL Game Simulator!\nPlease enter your team's name, up to 20 characters: ");
    scanf("%s", team_name);
    printf("\nThe game is about to start and it's time for the coin toss!\nWould %s like to pick heads (h) or tails (t)? ", team_name);
    scanf("%s", coin_choice);



    if (coin_choice[0] == 'h') {
        coin_number = 0;
    } else if (coin_choice[0] == 't') {
        coin_number = 1;
    } else {
        puts("Invalid input, heads selected by default.");
    }

    if (coin_outcome == coin_number) {
        printf("%s won the coin toss!\nWould %s like to receive (r) or kick (k)? ", team_name, team_name);
        scanf("%s", kickoff_choice);
        switch(kickoff_choice[0]) {
            case 'k':
                printf("%s has elected to kick, so %s will receive the ball at the beginning of the 2nd half.\nGet ready for the kickoff!", team_name, team_name);
                return 1;
            default:
                printf("%s has elected to receive.\nGet ready for the kickoff!", team_name);
                return 0;
        }
    } else {
        printf("%s lost the coin toss.\nThe other team will receive the kickoff.", team_name);
        return 1;
    }
}

void drive() {
    int yard = starting_yardline();
    int down = 1;

    //while
    if (yard > 0 && yard < 50) {
        printf("\nThe ball is on your own %d-yard-line.", yard);
    } else if (yard > 50 && yard < 100) {
        printf("\nThe ball is on the opponent's %d-yard-line.", 100 - yard);
    } else if (yard == 50) {
        printf("\nThe ball is on the %d-yard-line.", yard);
    }

    //calculate down and yards left

    run_play(yard, down);

    //new yardline and down
    //count towards total stats

    //set of if statements before next play


}

int starting_yardline() {
    return rand() % 100 + 1;
}

void run_play(int yard, int down) {
    char play_selection;

    int yards_gained;

    printf("Select a play from the following list: ");

    if (down == 1 || down == 2 || down == 3) {
        puts("Short pass - S, Long pass - L, Inside run - I, Outside run - O");
        printf("Play selection: ");
        scanf("%s", &play_selection);
        switch(play_selection) {
            case 'S':
                short_pass();
            case 'L':
                long_pass();
            case 'I':
                inside_run();
            case 'O':
                outside_run();
            default:
                puts("Invalid input type");//error message, try again
        }
    } else if (down == 4) {
        if (yard < 55) {
            printf("Short pass - S, Long pass - L, Inside run - I, Outside run - O, Punt - P");
            printf("Play selection: ");
            scanf("%s", &play_selection);
            switch(play_selection) {
                case 'S':
                    short_pass();

                case 'L':
                    long_pass();
                case 'I':
                    inside_run();
                case 'O':
                    outside_run();
                case 'P':
                    punt();
                default:
                    puts("Invalid input type");//error message, try again
            }
        } else if (yard >= 55) {
            printf("Short pass - S, Long pass - L, Inside run - I, Outside run - O, Field goal - F");
            printf("Play selection: ");
            scanf("%s", &play_selection);
            switch(play_selection) {
                case 'S':
                    short_pass();
                case 'L':
                    long_pass();
                case 'I':
                    inside_run();
                case 'O':
                    outside_run();
                case 'F':
                    field_goal(yard);
                default:
                    puts("Invalid input type");//error message, try again
            }
        }
    }
}

void defense_sim() {

    int result;
    int score;

    result = rand() % 100 + 1;

    if (result <= 50) {
        score = rand() % 100 + 1;

            if( score <= 35 ) {
                puts("The opposing team has scored a touchdown! :(");
                score = 7;
            }
            else {
                puts ("The opposing team has score a field goal! :/");
                score = 3;
            }
    } else {
        puts ("The opposing team has elected to punt! :)");
        punt();
    }

    drive();
}

int short_pass() {

    int attempt;
    int gain;
    int yards_gained;

    attempt = rand() % 100 + 1;

    if (attempt <= 70) {
        gain = rand() % 100 + 1;

            if ( gain <= 5 ) {
                yards_gained = 1;
                return yards_gained;
                }
            else if ( 6 <= gain && gain <= 15 ) {
                yards_gained = 2;
                return yards_gained;
                }
            else if ( 16 <= gain && gain <= 40 ) {
                yards_gained = 3;
                return yards_gained;
                }
            else if ( 41 <= gain && gain <= 60 ) {
                yards_gained = 4;
                return yards_gained;
                }
            else if ( 61 <= gain && gain <= 70 ) {
                yards_gained = 5;
                return yards_gained;
                }
            else if ( 71 <= gain && gain <= 80 ) {
                yards_gained = 6;
                return yards_gained;
                }
            else if ( 81 <= gain && gain <= 85 ) {
                yards_gained = 7;
                return yards_gained;
                }
            else if ( 86 <= gain && gain <= 90 ) {
                yards_gained = 8;
                return yards_gained;
                }
            else if ( 91 <= gain && gain <= 93 ) {
                yards_gained = 9;
                return yards_gained;
                }
            else if ( 94 <= gain && gain <= 96) {
                yards_gained = 10;
                return yards_gained;
                }
            else if ( 97 <= gain && gain <= 98) {
                yards_gained = 15;
                return yards_gained;
                }
            else if (gain == 99) {
                yards_gained = 25;
                return yards_gained;
                }
            else {
                yards_gained = 100;
                return yards_gained;
            }
        }
     else {
        puts("The pass fell incomplete!");
    }
}

int long_pass() {

    int attempt;
    int gain;
    int yards_gained;

    attempt = rand() % 100 + 1;

    if (attempt <= 40) {
        gain = rand() % 100 + 1;

            if ( gain <= 5 ) {
                yards_gained = 5;
                return yards_gained;
                }
            else if ( 6 <= gain && gain <= 15 ) {
                yards_gained = 7;
                return yards_gained;
                }
            else if ( 16 <= gain && gain <= 40 ) {
                yards_gained = 8;
                return yards_gained;
                }
            else if ( 41 <= gain && gain <= 60 ) {
                yards_gained = 10;
                return yards_gained;
                }
            else if ( 61 <= gain && gain <= 70 ) {
                yards_gained = 12;
                return yards_gained;
                }
            else if ( 71 <= gain && gain <= 80 ) {
                yards_gained = 15;
                return yards_gained;
                }
            else if ( 81 <= gain && gain <= 85 ) {
                yards_gained = 20;
                return yards_gained;
                }
            else if ( 86 <= gain && gain <= 90 ) {
                yards_gained = 25;
                return yards_gained;
                }
            else if ( 91 <= gain && gain <= 93 ) {
                yards_gained = 35;
                return yards_gained;
                }
            else if ( 94 <= gain && gain <= 96) {
                yards_gained = 50;
                return yards_gained;
                }
            else if ( 97 <= gain && gain <= 98) {
                yards_gained = 60;
                return yards_gained;
                }
            else if (gain == 99) {
                yards_gained = 75;
                return yards_gained;
                }
            else {
                yards_gained = 100;
                return yards_gained;
            }
        }
     else {
        puts("The pass fell incomplete!");
    }
}

int inside_run() {

    int gain;
    int yards_gained;

    gain = rand() % 100 + 1;

    if ( gain <= 5 ) {
        yards_gained = 1;
        return yards_gained;
    }
    else if ( 6 <= gain && gain <= 15 ) {
        yards_gained = 2;
        return yards_gained;
    }
    else if ( 16 <= gain && gain <= 40 ) {
        yards_gained = 3;
        return yards_gained;
    }
    else if ( 41 <= gain && gain <= 60 ) {
        yards_gained = 4;
        return yards_gained;
    }
    else if ( 61 <= gain && gain <= 70 ) {
        yards_gained = 5;
        return yards_gained;
    }
    else if ( 71 <= gain && gain <= 80 ) {
        yards_gained = 6;
        return yards_gained;
    }
    else if ( 81 <= gain && gain <= 85 ) {
        yards_gained = 7;
        return yards_gained;
    }
    else if ( 86 <= gain && gain <= 90 ) {
        yards_gained = 8;
        return yards_gained;
    }
    else if ( 91 <= gain && gain <= 93 ) {
        yards_gained = 9;
        return yards_gained;
        }
    else if ( 94 <= gain && gain <= 96) {
        yards_gained = 10;
        return yards_gained;
    }
    else if ( 97 <= gain && gain <= 98) {
        yards_gained = 15;
        return yards_gained;
    }
    else if (gain == 99) {
        yards_gained = 25;
        return yards_gained;
    }
    else {
        yards_gained = 100;
        return yards_gained;
    }
}

int outside_run() {

    int gain;
    int yards_gained;

    gain = rand() % 100 + 1;

    if ( gain <= 5 ) {
        yards_gained = 1;
        return yards_gained;
    }
    else if ( 6 <= gain && gain <= 15 ) {
        yards_gained = 2;
        return yards_gained;
    }
    else if ( 16 <= gain && gain <= 40 ) {
        yards_gained = 3;
        return yards_gained;
    }
    else if ( 41 <= gain && gain <= 60 ) {
        yards_gained = 4;
        return yards_gained;
    }
    else if ( 61 <= gain && gain <= 70 ) {
        yards_gained = 5;
        return yards_gained;
    }
    else if ( 71 <= gain && gain <= 80 ) {
        yards_gained = 6;
        return yards_gained;
    }
    else if ( 81 <= gain && gain <= 85 ) {
        yards_gained = 7;
        return yards_gained;
    }
    else if ( 86 <= gain && gain <= 90 ) {
        yards_gained = 8;
        return yards_gained;
    }
    else if ( 91 <= gain && gain <= 93 ) {
        yards_gained = 9;
        return yards_gained;
        }
    else if ( 94 <= gain && gain <= 96) {
        yards_gained = 10;
        return yards_gained;
    }
    else if ( 97 <= gain && gain <= 98) {
        yards_gained = 15;
        return yards_gained;
    }
    else if (gain == 99) {
        yards_gained = 25;
        return yards_gained;
    }
    else {
        yards_gained = 100;
        return yards_gained;
    }
}

int punt() {

    int yards;
    int yards_punted;

    yards = rand() % 100 + 1;

            if ( yards <= 5 ) {
                yards_punted = 55;
                //print
                }
            else if ( 6 <= yards && yards <= 15 ) {
                yards_punted = 50;
                //print
                }
            else if ( 16 <= yards && yards <= 40 ) {
                yards_punted = 45;
                //print
                }
            else if ( 41 <= yards && yards <= 60 ) {
                yards_punted = 40;
                //print
                }
            else if ( 61 <= yards && yards <= 70 ) {
                yards_punted = 35;
                //print
                }
            else if ( 71 <= yards && yards <= 80 ) {
                yards_punted = 30;
                //print
                }
            else if ( 81 <= yards && yards <= 85 ) {
                yards_punted = 25;
                //print
                }
            else if ( 86 <= yards && yards <= 90 ) {
                yards_punted = 22;
                //print
                }
            else if ( 91 <= yards && yards <= 93 ) {
                yards_punted = 20;
                //print
                }
            else if ( 94 <= yards && yards <= 96) {
                yards_punted = 18;
                //print
                }
            else if ( 97 <= yards && yards <= 98) {
                yards_punted = 15;
                //print
                }
            else if (yards == 99) {
                yards_punted = 10;
                //print
                }
            else {
                yards_punted = 5;
                //print
            }
}

int field_goal(int yard) {

    int attempt;
    int result;

    if (yard >= 90) {
        attempt = rand() % 100 + 1;
        if (attempt <= 95) {
            result = 3;
        }
        else {
            result = 0;
        }
        return result;
    }
    else if (89 >= yard && yard >= 80) {
        attempt = rand() % 100 + 1;
        if (attempt <= 85) {
            result = 3;
        }
        else {
            result = 0;
        }
        return result;
    }
    else if (79 >= yard && yard >= 70) {
        attempt = rand() % 100 + 1;
        if (attempt <= 75) {
            result = 3;
        }
        else {
            result = 0;
        }
        return result;
    }
    else if (69 >= yard && yard >= 60) {
        attempt = rand() % 100 + 1;
        if (attempt <= 55) {
            result = 3;
        }
        else {
            result = 0;
        }
        return result;
    }
    else {
        attempt = rand() % 100 + 1;
        if (attempt <= 20) {
            result = 3;
        }
        else {
            result = 0;
        }
        return result;
    }

}
