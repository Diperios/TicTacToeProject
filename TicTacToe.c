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


int main()
{
    
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
    
    if(won == 'N'){
        printf("its a tie!");
        return 0;
    }
    
    printf("%c won! congratulations!", won);

    return 0;
}