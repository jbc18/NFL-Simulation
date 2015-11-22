#include <stdio.h>
#include <stdlib.h>

int kickoff();
void start_drive();
int starting_yardline();

void defense_sim();

int main() {
    int i;
    for (i = 0; i < 10; i++){
        start_drive();
    puts("");}
    if (kickoff() == 0) {
        start_drive();
    } else if (kickoff() == 1) {
        defense_sim();
    }
}

int kickoff() {
    char team_name[20];
    char coin_choice[1];
    char coin_outcome[1] = {'h'};
    char kickoff_choice[1];
    printf("Welcome to the NFL Game Simulator!\nPlease enter your team's name, up to 20 characters: ");
    scanf("%s", team_name);
    printf("\nThe game is about to start and it's time for the coin toss!\nWould %s like to pick heads (h) or tails (t)? ", team_name);
    scanf("%s", coin_choice);
    
    //coin toss happens, random chance decides if coin is heads or tails
    //show outcome "The coin landed on __"
    
    if (coin_outcome[0] == coin_choice[0]) {
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

void start_drive() {
    int yard = starting_yardline();
    //generate random yard
}

int starting_yardline() {
    return rand() % 50 + 1;
}

void defense_sim() {
    puts("");
}
