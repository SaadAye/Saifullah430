#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

int gri[4][4] = {{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0}};

void randomGenerator(){
    int row, col;
    srand(time(0));
    row = (rand() % 4);
            col = (rand() % 4);
            while(gri[row][col] != 0 ){
                row = (rand() % 4);
                col = (rand() % 4);
            }
            gri[row][col] = ((rand() % 2) + 1);
    
}
void shuffle(){
    int row, col;
        srand(time(0));
        for(int i = 0; i < 2; i++){
            row = (rand() % 4);
            col = (rand() % 4);
            while(gri[row][col] != 0 ){
                row = (rand() % 4);
                col = (rand() % 4);
            }
            gri[row][col] = ((rand() % 2) + 1);
        }
}
void newGame(){
    int row, col,count = 9;
    for(int i = 0; i < 7; i++) cout << endl;
     for(int i = 0; i < 9; i++){
         cout << setw(32) << ' ';
         if(i % 2 != 0){
        for(int j = 0; j < 4; j++){
            cout << setw(8) << gri[i-(count-(9-i))][j];
            if(j == 3){
                cout << endl<<endl;
            }
        }
        count--;}
        else cout  <<setw(36)<<"-----------------------------\n\n";
     }
}
void right(){
    int temp = 0;
    for(int i = 0; i < 4; i++){
        int addTrue = true;
        for(int j = 2; j >= 0; j--){
            if(gri[i][j] != 0){
                temp = gri[i][j];
                for(int k = j; k <= 2; k++){
                    if(gri[i][k+1] == 0){
                        gri[i][k+1] = temp;
                        gri[i][k] = 0;
                    }
                    else if(gri[i][k+1] == temp && addTrue){
                        gri[i][k+1] += temp;
                        gri[i][k] = 0;
                        addTrue = false;
                    }
                    else{
                        break;
                    }

                }
            }
             
        }
    }
}
void down(){
    int temp = 0;
    for(int i = 2; i >= 0; i--){
        for(int j = 0; j < 4; j++){
            int addTrue = true;
            if(gri[i][j] != 0){
                temp = gri[i][j];
                for(int k = i; k <= 2; k++){
                    if(gri[k+1][j] == 0){
                        gri[k+1][j] = temp;
                        gri[k][j] = 0;
                    }
                    else if(gri[k+1][j] == temp && addTrue){
                        gri[k+1][j] += temp;
                        gri[k][j] = 0;
                        addTrue = false;
                    }
                    else{
                        break;
                    }

                }
            }

        }
    }
}
void left(){
     int temp = 0;
    for(int i = 0; i < 4; i++){
        int addTrue = true;
        for(int j = 1; j <= 3; j++){
            if(gri[i][j] != 0){
                temp = gri[i][j];
                for(int k = j; k >= 1; k--){
                    if(gri[i][k-1] == 0){
                        gri[i][k-1] = temp;
                        gri[i][k] = 0;
                    }
                    else if(gri[i][k-1] == temp && addTrue){
                        gri[i][k-1] += temp;
                        gri[i][k] = 0;
                        addTrue = false;
                    }
                    else{
                        break;
                    }

                }
            }
             
        }
    }
}
void up(){
     int temp = 0;
    for(int i = 1; i < 4; i++){
        for(int j = 0; j <= 3; j++){
            int addTrue = true;
            if(gri[i][j] != 0){
                temp = gri[i][j];
                for(int k = i; k >= 1; k--){
                    if(gri[k-1][j] == 0){
                        gri[k-1][j] = temp;
                        gri[k][j] = 0;
                    }
                    else if(gri[k-1][j] == temp && addTrue){
                        gri[k-1][j] += temp;
                        gri[k][j] = 0;
                        addTrue = false;
                    }
                    else{
                        break;
                    }

                }
            }
        }
    }
}
void move(){
    char i ;
    cout << "\n\nSelect Move: \n";
    cin >> i;
    switch (i)
    {
    case 'd':
        right();
        break;
    case 'a':
         left();
         break;
    case 'w':
         up();
         break;
    case 's':
         down();
         break;

    default:
    cout << "pspu";
        break;
    }
}


int main(){
    shuffle();

   while(true){
       cout <<"\n\n";
       cout <<setw(60)<< "Saifullah 430 \n";
       newGame();
       move();
       randomGenerator();
       system("cls");
   }
   system("pause");
}
