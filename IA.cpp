#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

using namespace std;

int main()
{
	int l, c;
	cout << "Digite a quantidade de Linhas: ";
	cin >> l;
	cout << "Digite a quantidade de Colunas: ";
	cin >> c;
	
    // Criação das salas
    int prin[l][c];
    int auxiliar[l][c];
    for(int i = 0; i < l;++i){
        for(int j = 0; j < c; ++j){
            prin[i][j] = 0;
            auxiliar[i][j] = 0;
        }
    }
    
    // 'Sujar' as salas de forma aleatoria
	int maximo = l*c;
    int minimo = 1;
    srand (time(NULL));
    int random = (rand() % maximo) + minimo;
    int cont = 0;
    for(int i = 0; i < random; ++i){
        int x = (rand() % l) + minimo;
        int y = (rand() % c) + minimo;
        
        prin[x][y] = 1;
    }
    for(int i = 0; i < l;++i){
        for(int j = 0; j < c; ++j){
            if(prin[i][j] == 1){
                cont++;
            }
        }
    }
    
    // Caminho onde o limpador deve fazer
    int X=0,Y=0;
	int rodadas=0;
    for(int i=0; cont > 0; i++){
    	system("cls");
    	
		if(X == 0 && Y == 0){
	    	if(prin[X][Y] == 1){
	    		prin[X][Y] = 0;
	    		cont--;
			}
    		int random = rand() % 2;
	    	if(random == 0) {
	    		Y++;
	    		if(auxiliar[X][Y] == 1){
	    			Y--;
	    			X++;
				}else auxiliar[0][0] = 1;	
			}	
	    	else {
				X++;
	    		if(auxiliar[X][Y] == 1){
	    			X--;
					Y++;
				}else auxiliar[0][0] = 1;	
			}
		}
		
		else if(X == 0 && (Y > 0 && Y < c-1)){
			if(prin[X][Y] == 1){
				prin[X][Y]=0;
				cont--;
			}
			int random = rand() % 3;
			if(random == 0){
				Y++;
				if(auxiliar[X][Y] == 1){
	    			Y--;
	    			random = rand() % 2;
	    			if(random == 0) Y--;
	    			else X++;
				}else auxiliar[X][Y-1] = 1;
			}
			else if(random == 1){
				Y--;
				if(auxiliar[X][Y] == 1){
	    			Y--;
	    			random = rand() % 2;
	    			if(random == 0) Y++;
	    			else X++;
				}else auxiliar[X][Y+1] = 1;
			}
				
			else{
				X++;
				if(auxiliar[X][Y] == 1){
	    			Y--;
	    			random = rand() % 2;
	    			if(random == 0) Y++;
	    			else Y--;
				}else auxiliar[X-1][Y] = 1;
			}
		}
		
		else if(X == 0 && Y == c-1){
	    	if(prin[X][Y] == 1){
	    		prin[X][Y] = 0;
	    		cont--;
			}
			int random = rand() % 2;
	    	if(random == 0){
	    		Y--;
	    		if(auxiliar[X][Y] == 1){
	    			Y++;
	    			X++;
				}else auxiliar[X][Y+1] = 1;
			}
	    	else{
	    		X++;
	    		if(auxiliar[X][Y] == 1){
	    			Y++;
	    			X++;
				}else auxiliar[X-1][Y] = 1;
			}	
		}
		
		else if(X > 0 && X < l-1 && Y == c-1){
			if(prin[X][Y] == 1){
				prin[X][Y] = 0;
				cont--;
				
			}
			int random = rand() % 3;
			if(random == 0){
				Y--;
				if(auxiliar[X][Y] == 1){
	    			Y++;
	    			random = rand() % 2;
	    			if(random == 0) X--;
	    			else X++;
				}else auxiliar[X][Y-1] = 1;
			}
			else if(random == 1){
				X--;
				if(auxiliar[X][Y] == 1){
	    			X++;
	    			random = rand() % 2;
	    			if(random == 0) Y--;
	    			else X++;
				}else auxiliar[X+1][Y] = 1;
			}
				
			else {
				X++;
				if(auxiliar[X][Y] == 1){
	    			X--;
	    			random = rand() % 2;
	    			if(random == 0) Y--;
	    			else X--;
				}else auxiliar[X-1][Y] = 1;
			}
		}
		
		else if(X == l-1 && Y == c-1){
			if(prin[X][Y] == 1){
	    		prin[X][Y] = 0;
	    		cont--;
			}
			int random = rand() % 2;
	    	if(random == 0)
	    	{
	    		Y--;
	    		if(auxiliar[X][Y] == 1){
	    			Y++;
	    			X--;
				}else auxiliar[X][Y+1] = 1;
			}
	    		
	    	else{
	    		X--;
				if(auxiliar[X][Y] == 1){
	    			X++;
	    			Y--;
				}else auxiliar[X+1][Y] = 1;
			}	
		}
		
		else if(X == l-1 && (Y > 0 && Y < c-1)){
			if(prin[X][Y] == 1){
				prin[X][Y] = 0;
				cont--;
			}
			int random = rand() % 3;
			if(random == 0){
				Y++;
				if(auxiliar[X][Y] == 1){
	    			Y--;
	    			random = rand() % 2;
	    			if(random == 0) Y--;
	    			else X--;
				}else auxiliar[X][Y-1] = 1;

			}
			else if(random == 1){
				Y--;
				if(auxiliar[X][Y] == 1){
	    			Y++;
	    			random = rand() % 2;
	    			if(random == 0) Y++;
	    			else X--;
				}else auxiliar[X][Y+1] = 1;
			}
				
			else {
				X--;
				if(auxiliar[X][Y] == 1){
	    			X++;
	    			random = rand() % 2;
	    			if(random == 0) Y++;
	    			else Y--;
				}else auxiliar[X+1][Y] = 1;
			}
		}
		
		else if(X == (l-1) && Y == 0){
			
			if(prin[X][Y] == 1){
				prin[X][Y] = 0;
				cont--;
			}
			int random = rand() % 2;
			if(random == 0){
				Y++;
				if(auxiliar[X][Y] == 1){
	    			Y--;
	    			X--;
				}else auxiliar[X][Y-1] = 1;

			}
			else{
				X--;
				if(auxiliar[X][Y] == 1){
	    			X++;
	    			Y++;
				}else auxiliar[X+1][Y] = 1;
			}	
		}
		
		else if((X > 0 & X < l-1) && Y == 0){
			
			if(prin[X][Y] == 1){
				prin[X][Y] = 0;
				cont--;
			}
			
			int random = rand() % 3;
			if(random == 0){
				Y++;
				if(auxiliar[X][Y] == 1){
	    			Y--;
	    			random = rand() % 2;
	    			if(random == 0) X--;
	    			else X++;
				}else auxiliar[X][Y-1] = 1;
			}
				
			else if(random == 1){
				X--;
				if(auxiliar[X][Y] == 1){
	    			X++;
	    			random = rand() % 2;
	    			if(random == 0) Y++;
	    			else X++;
				}else auxiliar[X+1][Y] = 1;
			}
				
			else {
				X++;
				if(auxiliar[X][Y] == 1){
	    			X--;
	    			random = rand() % 2;
	    			if(random == 0) Y++;
	    			else X--;
				}else auxiliar[X-1][Y] = 1;
			}
		}	
				
		else{
			if(prin[X][Y] == 1){
				prin[X][Y] = 0;
				cont--;
			}
			int random = rand() % 4;
			if(random == 0){
				Y++;
				if(auxiliar[X][Y] == 1){
	    			Y--;
	    			random = rand() % 3;
	    			if(random == 0) Y--;
	    			else if(random == 1) X--;
	    			else X++;
				}else auxiliar[X][Y-1] = 1;
			}
				
			else if(random == 1){
				Y--;
				if(auxiliar[X][Y] == 1){
	    			Y++;
	    			random = rand() % 3;
	    			if(random == 0) Y++;
	    			else if(random == 1) X--;
	    			else X++;
				}else auxiliar[X][Y+1] = 1;
			}
				
			else if(random == 2){
				X--;
				if(auxiliar[X][Y] == 1){
	    			X++;
	    			random = rand() % 3;
	    			if(random == 0) Y++;
	    			else if(random == 1) Y--;
	    			else X++;
				}else auxiliar[X+1][Y] = 1;
			}
				
			else{
				X++;
				if(auxiliar[X][Y] == 1){
	    			X--;
	    			random = rand() % 3;
	    			if(random == 0) Y++;
	    			else if(random == 1) Y--;
	    			else X--;
				}else auxiliar[X-1][Y] = 1;
			}	
		}
		for(int i = 0; i < l;++i){
        	for(int j = 0; j < c; ++j){
            	if(i==X && j==Y) cout << "L ";
            	else cout << prin[i][j] << " ";
			}
			cout << endl;
		}
		Sleep(300);
		if(cont == 0) rodadas = i;
	}
	cout << "Rodadas: " << rodadas <<endl;
	for(int i = 0; i < l;++i){
        for(int j = 0; j < c; ++j){
            if(prin[i][j] == 1)
            	cout << "Nem todas as salas poderam ser limpas !!!";
            	break;
        }
    }
}
