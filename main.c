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

int start_game();
void drive();
int starting_yardline();

char team_name

void defense_sim();

int main() {
    char team_name[20];
    if (start_game(team_name) == 0) {
        drive();
    } else {
        defense_sim();
    }
}

int start_game(team_name[]) {
    srand(time(NULL));
    char team_name[20];
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
        printf("The ball is on ")
    }
    
    //generate random yard
}

int starting_yardline() {
    return rand() % 100 + 1;
}

void defense_sim() {
    puts("");
}

0-50
your own yard
51-100
100-yard = opponent's yard'



/*
 
 kickoff()
 
 start_drive()
 
 starting_yardline()
 
 show_down_and_yard()
 
 allowed_plays()
 
 input_play()
 
 random_outcome()
 
 show_outcome()
 
 down_plus_one()
 
 new_yardage()
 
 show_clock()
 
 yards_total()
 
 points_total()
 
 show_stats()
 
 */
