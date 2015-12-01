#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int start_game();
void drive();
int starting_yardline();
void run_play();

void defense_sim();

int main() {
    char *team_name[20];
    if (start_game(team_name) == 0) {
        drive();
    } else {
        defense_sim();
    }
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
    
    if (yard > 0 && yard < 50) {
        printf("\nThe ball is on your own %d-yard-line.", yard);
    } else if (yard > 50 && yard < 100) {
        printf("\nThe ball is on the opponent's %d-yard-line.", 100 - yard);
    } else if (yard == 50) {
        printf("\nThe ball is on the %d-yard-line.", yard);
    }
    
    run_play();
}

int starting_yardline() {
    return rand() % 100 + 1;
}

void run_play() {
    
}

void defense_sim() {
    puts("");
}
