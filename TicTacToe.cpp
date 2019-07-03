#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	char jogo[4][4] = {{' ', '1', '2', '3'},{'A', '-', '-', '-'},{'B', '-', '-', '-'},{'C', '-', '-', '-'},};
	int x, y; // valores posicionais
	string cd; // coordenadas
	char s; // sinal
	int e = 0; // caso o jogador 2 insira uma tecla errada
	string v; // Vencedor

	while(true)
	{	

		for (int i = 1; i < 3 ; i++)
		{
			if (e==1){
				i = 2;
			}

			// Imprime o jogo atual no terminal
			cout << "Tic Tac Toe\n" << endl;
			for (int l = 0; l < 4; l++)
			{
			 	for (int c = 0; c < 4; c++)
			 	{
			 		cout << " " << jogo[l][c];
			 	}
			 	cout << endl;
			}

			// Pergunta qual local vai ser inserido X ou O
			s = (i==1) ? 'X' : 'O';
			cout << "\nJogador " << i << ", escolha uma coordenada: ";
			cin >> cd;
			x = (cd[0]=='a' or cd[0]=='A') ? 1 :
				(cd[0]=='b' or cd[0]=='B') ? 2 :
				(cd[0]=='c' or cd[0]=='C') ? 3 :
											 0;
			y = (cd[1]=='1') ? 1 :
				(cd[1]=='2') ? 2 :
				(cd[1]=='3') ? 3 :
							   0;

			// Testa se o jogador inseriu alguma coordenada errada				   
			if (x==0 or y==0)
			{
				system("clear");
				cout << "Foi inserido uma coordenada inválida\n" << endl;

				// Testa se o erro foi cometido pelo jogador 2
				if (i==2)
				{
					e = 1;
					break;
				}else{
			 		e = 0;
			 		break;
			 	}

			}else{
				// Testa se a coordenada selecionada já está preenchida
				if (jogo[x][y]!='-')
				{
					system("clear");
					cout << "Foi escolhido uma coordenada já preenchida\n" << endl;

					// Testa se o erro foi cometido pelo jogador 2
					if (i==2)
					{
						e = 1;
						break;
					}else{
				 		e = 0;
				 		break;
				 	}
				}else{
				jogo[x][y] = s;
				e = 0;
				}
			}

			// Testa se houve algum vencedor ou se deu velha
			v = (jogo[1][1]=='X' and jogo[1][2]=='X' and jogo[1][3]=='X') ? "Jogador 1 venceu!" :
				(jogo[2][1]=='X' and jogo[2][2]=='X' and jogo[2][3]=='X') ? "Jogador 1 venceu!" :
				(jogo[3][1]=='X' and jogo[3][2]=='X' and jogo[3][3]=='X') ? "Jogador 1 venceu!" :
				(jogo[1][1]=='X' and jogo[2][1]=='X' and jogo[3][1]=='X') ? "Jogador 1 venceu!" :
				(jogo[1][2]=='X' and jogo[2][2]=='X' and jogo[3][2]=='X') ? "Jogador 1 venceu!" :
				(jogo[1][3]=='X' and jogo[2][3]=='X' and jogo[3][3]=='X') ? "Jogador 1 venceu!" :
				(jogo[1][1]=='X' and jogo[2][2]=='X' and jogo[3][3]=='X') ? "Jogador 1 venceu!" :
				(jogo[3][1]=='X' and jogo[2][2]=='X' and jogo[1][3]=='X') ? "Jogador 1 venceu!" :
				(jogo[1][1]=='O' and jogo[1][2]=='O' and jogo[1][3]=='O') ? "Jogador 2 venceu!" :
				(jogo[2][1]=='O' and jogo[2][2]=='O' and jogo[2][3]=='O') ? "Jogador 2 venceu!" :
				(jogo[3][1]=='O' and jogo[3][2]=='O' and jogo[3][3]=='O') ? "Jogador 2 venceu!" :
				(jogo[1][1]=='O' and jogo[2][1]=='O' and jogo[3][1]=='O') ? "Jogador 2 venceu!" :
				(jogo[1][2]=='O' and jogo[2][2]=='O' and jogo[3][2]=='O') ? "Jogador 2 venceu!" :
				(jogo[1][3]=='O' and jogo[2][3]=='O' and jogo[3][3]=='O') ? "Jogador 2 venceu!" :
				(jogo[1][1]=='O' and jogo[2][2]=='O' and jogo[3][3]=='O') ? "Jogador 2 venceu!" :
				(jogo[3][1]=='O' and jogo[2][2]=='O' and jogo[1][3]=='O') ? "Jogador 2 venceu!" :
				(jogo[1][1]!='-' and jogo[1][2]!='-' and jogo[1][3]!='-' and jogo[2][1]!='-' and jogo[2][2]!='-' and jogo[2][3]!='-' and jogo[3][1]!='-' and jogo[3][2]!='-' and jogo[3][3]!='-') ? "Velha!" :
																			"nao";
				if (v!="nao")
				break;

			system("clear");
		}
		if (v!="nao") 
		{
			system("clear");
			// Imprime o jogo atual no terminal
			for (int l = 0; l < 4; l++)
			{
			 	for (int c = 0; c < 4; c++)
			 	{
			 		cout << " " << jogo[l][c];
			 	}
			 	cout << endl;
			}
			cout << "\n" << v << endl;
			break;
		}
	}
	return 0;
}