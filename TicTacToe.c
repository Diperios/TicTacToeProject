#include <stdio.h>
#include <stdbool.h>

char board[9] = {'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N'};


void print_board()
{
    printf("\n");
    
    for(int i = 0; i < 9; i++)
    {
        
        if(board[i] == 'N')
        {
            printf("%d ", i + 1);
        } 
        else
        {
            printf("%c ", board[i]);
        }
        
        switch (i) {
            case 0:
            case 1:
            case 3:
            case 4:
            case 6:
            case 7:
                printf(" | ");
                break;
            case 2:
            case 5:
                printf("\n------------\n");
                break;
            case 8:
                printf("\n");
                break;
            
        }
    }
    
    return;
}

void do_turn(char player){
    
    int play = 0, num_of_runs = 0;
    
    printf("\n");
    
    while(play - 1 < 0 || board[play - 1] != 'N')
    {
        
        if(num_of_runs == 0)
            printf("%c make your move! >> ", player);
        else 
            printf("\n%c, you cant make this move, try again! >> ", player);
        
        
        scanf("%d", &play);
        num_of_runs++;
    }
    board[play - 1] = player;
}


char who_won()
{
    
    for(int i = 0; i < 3; i++){
        if(board[0 + i*3] != 'N' && board[0 + i*3] == board[1 + i*3] && board[1 + i*3] == board[2 + i*3])
        return board[0 + i*3];
    }
    
    for(int i = 0; i < 3; i++){
        if(board[0 + i] != 'N' && board[0 + i] == board[3 + i] && board[3 + i] == board[6 + i])
        return board[0 + i];
    }
    
    if(board[0] != 'N' && board[0] == board[4] && board[4] == board[8])
        return board[0];
    
    if(board[2] != 'N' && board[2] == board[4] && board[4] == board[6])
        return board[2];

    return 'N';
}


bool game_tie(){
    bool flag = true;
    for(int i = 0; i < 9; i++){
        flag &= board[i] != 'N';
    }
    return flag;
}


char one_game(){
    
    char won = 'N';
    
    print_board();
    
    while(won == 'N' && !game_tie())
    {
        
        do_turn('X');
        print_board();
        
        won = who_won();
        
        if(won != 'N')
        {
            won = board [0];
            break;
        }
        if(game_tie()){
            won = 'N';
            break;
        }
        
        do_turn('O');
        print_board();
        
        won = who_won();
    }
    
    return won;
}

void enter_to_continue(){
    int enter = 0;
    printf("Press enter 1 to continue...");
    enter = scanf("%d", &enter);
}

void clear_board(){
    for(int i = 0; i < 9; i++){
        board[i] = 'N';
    }
}


int casual_game(){
    int num_of_games = 3;
    printf("the winner is the best player out of %d games!\n", num_of_games);

    enter_to_continue();
    
    int x_wins = 0, o_wins = 0;

    int i;
    char won;

    for(i = 0; i < num_of_games; i++){
        printf("\nGame %d\n", i + 1);
        won = one_game();
        if(won == 'X'){
            x_wins++;
            printf("\n\n");
            printf("X won! congratulations!\n\n");
            printf("====================================\n\n");
            printf("The score is %d - for X and %d - for O\n", x_wins, o_wins);
            printf("====================================\n");
            printf("\n\n");
        }
        else if(won == 'O'){
            o_wins++;
            printf("\n\n");
            printf("O won! congratulations!\n");
            printf("====================================\n");
            printf("The score is %d - for X and %d - for O\n", x_wins, o_wins);
            printf("====================================\n");
            printf("\n\n");
        }
        else{
            printf("its a tie!\n");
            printf("game %d will be played again!\n", i + 1);
            
            i--;
        }
        clear_board();
        enter_to_continue();
    }

    printf("\n\n\n\n\n\n");
    printf("The score is %d - for X and %d - for O\n", x_wins, o_wins);
    printf("\n\n");

    printf("====================================\n");
    
    if(x_wins > o_wins){
        printf("X won the game!\n");
    }
    else if(x_wins < o_wins){
        printf("O won the game!\n");
    }
    else{
        printf("The game is a tie!\n");
    }

    printf("====================================\n");

    return 0;

}


int main()
{
    int game_type = 0;
    //int num_of_games = 0;

    printf("Welcome to Tic Tac Toe!\n\n");
    printf("btw game mode 2 does not work on the phone and i dont have koahh to fix it\n enter 1\n\n\n");
    printf("Enter 1 if you want to play for fun, or\n");
    printf("Enter 2 if you want to play competitively >> ");
    scanf("%d", &game_type);
    printf("\n");

    switch (game_type) {
        case 1:
            printf("You have chosen to play for fun!\n");
            return casual_game();
            break;
        case 2:

            printf("You have chosen to play competitively!\n");
            printf("This does not work right now\n");
            printf("I will fix it later\n");
        
            break;
        default:
            printf("Invalid input, please try again!\n");
            return 0;
    }


    // char won = one_game();
    
    // if(won == 'N'){
    //     printf("its a tie!");
    //     return 0;
    // }
    
    // printf("%c won! congratulations!", won);

    return 0;
}