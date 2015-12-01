//
//  main.c
//  asdf
//
//  Created by Jarrett Cathcart on 8/31/15.
//  Copyright (c) 2015 Jarrett Cathcart. All rights reserved.
//

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
void run_play();

void defense_sim();

int main() {
    struct stats total_stats;
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
    int down = 0;
    
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
    int play_selection;
    
    printf("Select a play from the following list: ");
    
    if (down == 1 || down == 2 || down == 3) {
        puts("Short pass - 1, Long pass - 2, Inside run - 3, Outside run - 4");
        printf("Play selection: ");
        scanf("%d", &play_selection);
        switch(play_selection) {
            case 1:
                //short_pass();
            case 2:
                //long_pass();
            case 3:
                //inside_run();
            case 4:
                //outside_run();
            default:
                puts("");//error message, try again
        }
    } else if (down == 4) {
        if (yard < 55) {
            printf("Short pass - 1, Long pass - 2, Inside run - 3, Outside run - 4, Punt - 5");
            printf("Play selection: ");
            scanf("%d", &play_selection);
            switch(play_selection) {
                case 1:
                    //short_pass();
                case 2:
                    //long_pass();
                case 3:
                    //inside_run();
                case 4:
                    //outside_run();
                case 5:
                    //punt();
                default:
                    puts("");//error message, try again
            }
        } else if (yard >= 55) {
            printf("Short pass - 1, Long pass - 2, Inside run - 3, Outside run - 4, Field goal - 5");
            printf("Play selection: ");
            scanf("%d", &play_selection);
            switch(play_selection) {
                case 1:
                    //short_pass();
                case 2:
                    //long_pass();
                case 3:
                    //inside_run();
                case 4:
                    //outside_run();
                case 5:
                    //field_goal();
                default:
                    puts("");//error message, try again
            }
        }
    }
}

void defense_sim() {
    puts("");
}
