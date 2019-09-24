#include <stdio.h>
#include <stdlib.h>
int i,c,x,y,z,d;
char tab[10][10];
void ptab() // Essa fun��o preenche o tabuleiro com as pe�as
{
	for(i=1;i<9;i++) // Primeiro deixa todos os espa�os em branco
	{
		for(c=1;c<9;c++)
			tab[i][c] = ' ';
	}

	for (i=1;i<4;i++) // Ent�o coloca as pe�as 'W' (Brancas)
	{
		if(i%2 == 1)
		{
			for(c=1;c<9;c+= 2)
				tab[i][c] = 'W';
		}else {
			for(c=2;c<9;c+=2)
				tab[i][c] = 'W';
		}
	}

	for (i=6;i<9;i++) // Agora as pe�as 'B' (Pretas)
	{
		if (i%2 == 1)
		{
			for(c=1;c<9;c+=2)
				tab[i][c] = 'B';
		}else{
			for(c=2;c<9;c+=2)
				tab[i][c] = 'B';
		}
	}
	for(i=0;i<10;i++)
	{
		tab[i][0] = 'P';
		tab[0][i] = 'P';
		tab[i][9] = 'P';
		tab[9][i] = 'P';
	}
}
void mtab() // Essa fun��o serve para mostrar o tabuleiro ao jogador
{
	void linha1(int l) // Isso aqui serve para as linhas 1,3,5,7
	{
		int i;
		for (i=1;i<5;i++)
			printf(" _____         ");
		printf("\n");
		for (i=1;i<5;i++)
			printf("|     | *******");
		printf("\n");
		for (i=1;i<9;i+=2)
			printf("|  %c  | *******", tab[l][i]);
		printf("\n");
		for (i=2;i<6;i++)
			printf("|_____| *******");
		printf("\n");
	}
	void linha2(int l) // E essa para as linhas 2,4,6,8
	{
		int i;
		for (i=1;i<5;i++)
			printf("         _____ ");
		printf("\n");
		for (i=1;i<5;i++)
			printf("******* |     |");
		printf("\n");
		for (i=2;i<9;i+=2)
			printf("******* |  %c  |", tab[l][i]);
		printf("\n");
		for (i=1;i<5;i++)
			printf("******* |_____|");
		printf("\n");
	}
	for(i=1;i<9;i++) // Aqui s�o chamadas as duas fun��es para que em cada linha as fun��es sejam alternadas
	{
		if(i%2 == 1)
		{
			linha1(i);
		}else{
			linha2(i);
		}
	}
}
void verw() // Aqui n�s verificamos as pe�as ao redor da pe�a 'W' assim que for movida para poder fazer o "Encore" e comer em sequencia
{
	int aux = 0;
	if((tab[x+1][y-1] == 'B' || tab[x+1][y-1] == 'b') && tab[x+2][y-2] == ' ')// Aqui,
	{
		aux = 1;
	}
	if((tab[x+1][y+1] == 'B' || tab[x+1][y+1] == 'b') && tab[x+2][y+2] == ' ')//Aqui,
	{
		aux = 1;
	}
	if((tab[x-1][y-1] == 'B' || tab[x-1][y-1] == 'b') && tab[x-2][y-2] == ' ')//Aqui,
	{
		aux = 1;
	}
	if((tab[x-1][y+1] == 'B' || tab[x-1][y+1] == 'b') && tab[x-2][y+2] == ' ')// E aqui s�o checadas as pe�as ao redor da pe�a que foi movimentada
	{
		aux = 1;
	}
	if(aux == 1)
	{
		system("cls");
		mtab();
		puts("Encore!"); // Pra quem n�o sabe: "Encore" significa "De novo"
		scanf("%d",&d);
		if(d == 1)
		{
			if((tab[x+1][y-1] == 'B' || tab[x+1][y-1] == 'b') && tab[x+2][y-2] == ' ')// Daqui at�...
			{
				tab[x][y] = ' ';
				tab[x+1][y-1] = ' ';
				tab[x+2][y-2] = 'W';
				verw();
			}
		}
		if(d == 2)
		{
			if((tab[x+1][y+1] == 'B' || tab[x+1][y+1] == 'b') && tab[x+2][y+2] == ' ')
			{
				tab[x][y] = ' ';
				tab[x+1][y+1] = ' ';
				tab[x+2][y+2] = 'W';
				verw();
			}
		}
		if(d == 3)
		{
			if((tab[x-1][y-1] == 'B' || tab[x-1][y-1] == 'b') && tab[x-2][y-2] == ' ')
			{
				tab[x][y] = ' ';
				tab[x-1][y-1] = ' ';
				tab[x-2][y-2] = 'W';
				verw();
			}
		}
		if(d == 4)
		{
			if((tab[x-1][y+1] == 'B' || tab[x-1][y+1] == 'b') && tab[x-2][y+2] == ' ')// ...Aqui � feito o movimento
			{
				tab[x][y] = ' ';
				tab[x-1][y+1] = ' ';
				tab[x-2][y+2] = 'W';
				verw();// Rechamando a fun��o porqu� pode haver mais de duas comidas sucessivas
			}
		}
	}
	d = 0;
}
void verb() // Aqui � semelhante � fun��o anterior s� que dessa vez para as pe�as 'B'
{
	int aux = 0;
	if((tab[x-1][y-1] == 'W' || tab[x-1][y-1] == 'w') && tab[x-2][y-2] == ' ')
	{
		aux = 1;
	}
	if((tab[x-1][y+1] == 'W' || tab[x-1][y+1] == 'w') && tab[x-2][y+2] == ' ')
	{
		aux = 1;
	}
	if((tab[x+1][y+1] == 'W' || tab[x+1][y+1] == 'w') && tab[x+2][y+2] == ' ')// Denovo em todas essas partes � checado os arredores da pe�a que foi movida
	{
		aux = 1;
	}
	if(aux == 1)
	{
		system("cls");
		mtab();
		puts("Encore!");
		scanf("%d",&d);
		if(d == 3)
		{
			if((tab[x+1][y-1] == 'W' || tab[x+1][y-1] == 'w') && tab[x+2][y-2] == ' ')
			{
				tab[x][y] = ' ';
				tab[x+1][y-1] = ' ';
				tab[x+2][y-2] = 'B';
				verb();
			}
		}
		if(d == 4)
		{
			if((tab[x+1][y+1] == 'W' || tab[x+1][y+1] == 'w') && tab[x+2][y+2] == ' ')
			{
				tab[x][y] = ' ';
				tab[x+1][y+1] = ' ';
				tab[x+2][y+2] = 'B';
				verb();
			}
		}
		if(d == 1)
		{
			if((tab[x-1][y-1] == 'W' || tab[x-1][y-1] == 'w') && tab[x-2][y-2] == ' ')
			{
				tab[x][y] = ' ';
				tab[x-1][y-1] = ' ';
				tab[x-2][y-2] = 'B';
				verb();
			}
		}
		if(d == 2)
		{
			if((tab[x-1][y+1] == 'W' || tab[x-1][y+1] == 'w') && tab[x-2][y+2] == ' ')// Nesses "IFs" � feito o movimento
			{
				tab[x][y] = ' ';
				tab[x-1][y+1] = ' ';
				tab[x-2][y+2] = 'B';
				verb();
			}
		}
	}
	d = 0;
}
void main () // Fun��o Principal
{
	for(i=0;i<8;i++)
	{
		for(c=0;c<8;c++)
		{
			tab[i][c] = ' ';
		}
	}
	ptab();
	tab[8][8] = 'w';
	tab[7][7] = ' ';
	tab[6][6] = ' ';
	int es=0;
	int vez,jog=0;
	int vw,vb,v = 0;
	printf("[1].Jogar\n[2].Jogo Pesosnalizado\n[3].Sair\n");// Jogador seleciona se quer jogar ous sair
	scanf("%d",&es);
	if(es == 1)
	{
		system("cls");
		es = 0;
		printf("[1].PvP\n[2].PvE\n");// Modo de jogo
		scanf("%d",&es);
		if(es == 1)
		{
			vez == 1;
			while(v == 0)// V mantem tudo em um la�o at� que alguem ven�a
			{
				if(vez == 1)// Essa variavel indica de quem � a vez 1:Brancas 2:Pretas
				{
					while(jog == 0)// Jog serve para que caso o jogador fa�a uma jogada n�o permitida ele possa jogar de novo
					{
						system("cls");//Limpando
						mtab();// E atualizando o tabuleiro
						printf("Vez das brancas:\n");
						scanf("%d %d",&x,&y);
						if(tab[x][y] == 'W')// Checando para ver se � uma pe�a sua e se for, checando para ver se � uma dama
						{
							printf("Para qual dire�ao?\n");
							scanf("%d",&d);// Jogador digita dire��o do movimento
							if(d == 1)//Cada dire��o de movimento tem um calculo diferente
							{
								if(tab[x+1][y-1] == 'W' || tab[x+1][y-1] == 'w')
								{
									printf("Jogada Bloqueada\n");// Jogada bloqueada ent�o Jog n�o se altera
								}
								if(tab[x+1][y-1] == ' ')
								{
									tab[x][y] = ' ';
									tab[x+1][y-1] = 'W';
									jog = 1;//jogada efetuada Jog recebe 1
								}
								if(tab[x+1][y-1] == 'B' && tab[x+2][y-2] == ' ')
								{
									tab[x][y] = ' ';
									tab[x+1][y-1] = ' ';
									tab[x+2][y-2] = 'W';
									jog = 1;
									x+= 2;//Isso serve para a fun�o tendo a posi��o final da pe�a como nova posi��o
									y-= 2;
									verw();//Chamando a fun��o j� que uma pe�a foi comida
								}
							}
							if(d == 2)// Mesma coisa s� alterando os sinais
							{
								if(tab[x+1][y+1] == 'W' || tab[x+1][y+1] == 'w')
								{
									printf("Jogada Bloqueada\n");
								}
								if(tab[x+1][y+1] == ' ')
								{
									tab[x][y] = ' ';
									tab[x+1][y+1] = 'W';
									jog = 1;
								}
								if(tab[x+1][y+1] == 'B' && tab[x+2][y+2] == ' ')
								{
									tab[x][y] = ' ';
									tab[x+1][y+1] = ' ';
									tab[x+2][y+2] = 'W';
									jog = 1;
									x+=2;
									y+=2;
									verw();
								}
							}
							if(d == 3)// Movimento para tr�s, ent�o s� em caso de comer uma pe�a
							{
								if((tab[x-1][y-1] == 'B' || tab[x-1][y-1] == 'b') && tab[x-2][y-2] == ' ')
								{
									tab[x][y] = ' ';
									tab[x-1][y-1] = ' ';
									tab[x-2][y-2] = 'W';
									jog = 1;
									x-=2;
									y-=2;
									verw();
								}else{
									puts("Jogada bloqueada");
								}
							}
							if(d == 4)// Mesma coisa do anterior, s� com sinais diferentes
							{
								if((tab[x-1][y+1] == 'B' || tab[x-1][y+1] == 'b') && tab[x-2][y+2] == ' ')
								{
									tab[x-1][y+1] = ' ';
									tab[x][y] = ' ';
									tab[x-2][y+2] = 'W';
									jog = 1;
									x-=2;
									y+=2;
									verw();
								}else{
									puts("Jogada bloqueada");
								}
							}
						}else{
							if(tab[x][y] == 'w')// Se a pe�a for uma dama
							{
								c=0;
								i=1;
								printf("Para qual direcao?\n");
								scanf("%d",&d);
								printf("Quantas casas?\n");
								scanf("%d",&z);//Calculos agora s�o feitos com a variavel "z" para movimenta��o da dama
								if(d == 1)
								{
									while(i < z)//Esse la�o vai estar em todo inicio de movimento. Ele serve pra checar se n�o ha pe�as jo caminho do movimento
									{
										if(tab[x+i][y-i] == 'w' || tab[x+i][y-i] == 'W' || tab[x+i][y-i] == 'B' || tab[x+i][y-i] == 'b')
										{
											c++;
										}
										i++;
									}
									if(c |= 0)
									{
										puts("Jogada bloqueada");
									}else{
										if(tab[x+z][y-z] == 'W' || tab[x+z][y-z] == 'w')//Movimentos que voc� ja viu anteriormente
										{
											puts("jogada bloqueada");
										}
										if((tab[x+z][y-z] == 'B' || tab[x+z][y-z] == 'b') && tab[x+(z+1)][y-(z+1)] == ' ')
										{
											tab[x][y] = ' ';
											tab[x+z][y-z] = ' ';
											tab[x+(z+1)][y-(z+1)] = 'w';
											jog = 1;
										}
										if(tab[x+z][y-z] == ' ')
										{
											tab[x+z][y-z] = 'w';
											tab[x][y] = ' ';
											jog = 1;
										}
									}
								}
								if(d == 2)// Mesma coisa, sinais diferentes
								{
									while(i < z)
									{
										if(tab[x+i][y+i] == 'w' || tab[x+i][y+i] == 'W' || tab[x+i][y+i] == 'B' || tab[x+i][y+i] == 'b')
										{
											c++;
										}
										i++;
									}
									if(c |= 0)
									{
										puts("Jogada bloqueada");
									}else{
										if(tab[x+z][y+z] == 'w' || tab[x-z][y-z] == 'W')
										{
											puts("Jogada bloqueada");
										}
										if(tab[x+z][y+z] == ' ')
										{
											tab[x+z][y+z] = 'w';
											tab[x][y] = ' ';
											jog = 1;
										}
										if((tab[x+z][y+z] == 'B' || tab[x+z][y+z] == 'b') && tab[x+(z+1)][y+(z+1)] == ' ')
										{
											tab[x+z][y+z] = ' ';
											tab[x][y] = ' ';
											tab[x+(z+1)][y+(z+1)] = 'w';
											jog = 1;
										}
									}
								}
								if(d == 3)//Mesma coisa, sinais diferentes
								{
									while(i < z)
									{
										if(tab[x-i][y-i] == 'w' || tab[x-i][y-i] == 'B' || tab[x-i][y-i] == 'b' || tab[x-i][y-i] == 'W')
										{
											c++;
										}
										i++;
									}
									if(c |= 0)
									{
										puts("Jogada bloqueada");
									}else{
										if(tab[x-z][y-z] == 'w' || tab[x-z][y-z] == 'W')
										{
											puts("Jogada bloqueada");
										}
										if(tab[x-z][y-z] == ' ')
										{
											tab[x][y] = ' ';
											tab[x-z][y-z] = 'w';
											jog = 1;
										}
										if((tab[x-z][y-z] == 'B' || tab[x-z][y-z] == 'b') && tab[x-(z+1)][y-(z+1)] == ' ')
										{
											tab[x][y] = ' ';
											tab[x-z][y-z] = ' ';
											tab[x-(z+1)][y-(z+1)] = 'w';
											jog = 1;
										}
									}
								}
								if(d == 4)// Mesma coisa, sinais diferentes
								{
									while(i < z)
									{
										if(tab[x-i][y+i] == 'w' || tab[x-i][y+i] == 'W' || tab[x-i][y+i] == 'B' || tab[x-i][y+i] == 'b')
										{
											c++;
										}
										i++;
									}
									if(c |= 0)
									{
										puts("Jogada bloqueada");
									}else{
										if(tab[x-z][y+z] == 'w' || tab[x-z][y+z] == 'W')
										{
											puts("Jogada bloqueada");
										}
										if(tab[x-z][y+z] == ' ')
										{
											tab[x][y] = ' ';
											tab[x-z][y+z] = 'w';
											jog = 1;
										}
										if((tab[x-z][y+z] == 'B' || tab[x-z][y+z] == 'b') && tab[x-(z+1)][y+(z+1)] == ' ')
										{
											tab[x][y] = ' ';
											tab[x-z][y+z] = ' ';
											tab[x-(z+1)][y+(z+1)] = 'w';
											jog = 1;
										}
									}
								}
							}else{
							puts("Essa nao e uma das suas pecas");// Caso l� em cima o jogador escolha uma pe�a que n�o � dele.
							}
						}
					}
				}
			if(vez == 2)// Se for a vez das Pretas
			{
				while(jog == 0)
				{
					system("cls");//Limpando e...
					mtab();//Atualizando o tabuleiro
					puts("Vez das Pretas");//Aqui � tudo a mesma coisa enta� eu s� vou comentar as partes importantes
					scanf("%d %d",&x,&y);
					if(tab[x][y] == 'B')// Se for uma pe�a normal
					{
						puts("Para qual direcao?");
						scanf("%d",&d);
						if(d == 1)
						{
							if(tab[x-1][y-1] == 'B')
							{
								puts("Jogada bloqueada");
							}
							if(tab[x-1][y-1] == ' ')
							{
								tab[x][y] = ' ';
								tab[x-1][y-1] = 'B';
								jog = 1;
							}
							if(tab[x-1][y-1] == 'W' && tab[x-2][y-2] == ' ')
							{
								tab[x][y] = ' ';
								tab[x-1][y-1] = ' ';
								tab[x-2][y-2] = 'B';
								jog = 1;
								x-=2;
								y-=2;
								verb();
							}
						}
						if(d == 2)
						{
							if(tab[x-1][y+1] == 'B')
							{
								puts("Jogada Bloqueada");
							}
							if(tab[x-1][y+1] == ' ')
							{
								tab[x][y] = ' ';
								tab[x-1][y+1] = 'B';
								jog = 1;
							}
							if(tab[x-1][y+1] == 'W' && tab[x-2][y+2] == ' ')
							{
								tab[x][y] = ' ';
								tab[x-1][y+1] = ' ';
								tab[x-2][y+2] = 'B';
								jog = 1;
								x-=2;
								y+=2;
								verb();
							}
						}
						if(d == 3)
						{
							if((tab[x+1][y-1] == 'W' || tab[x+1][y-1] == 'w') && tab[x+2][y-2] == ' ')
							{
								tab[x][y] = ' ';
								tab[x+1][y-1] = ' ';
								tab[x+2][y-2] = 'B';
								jog = 1;
								x+=2;
								y-=2;
								verb();
							}else{
								puts("Jogada bloqueada");
							}
						}
						if(d == 4)
						{
							if((tab[x+1][y+1] == 'W' || tab[x+1][y+1] == 'w') && tab[x+2][y+2] == ' ')
							{
								tab[x][y] = ' ';
								tab[x+1][y+1] = ' ';
								tab[x+2][y+2] = 'B';
								jog = 1;
								x+=2;
								y+=2;
								verb();
							}else{
								puts("Jogada bloqueada");
							}
						}
					}else{
						if(tab[x][y] == 'b')//Se for uma dama
						{
							c=0;
							printf("Para qual direcao?\n");
							scanf("%d",&d);
							printf("Quantas casas?\n");
							scanf("%d",&z);
							if(d == 1)
							{
								while(i < z)// Checando pe�as no caminho
								{
									if(tab[x-i][y-i] == 'w' || tab[x-i][y-i] == 'W' || tab[x-i][y-i] == 'B' || tab[x-i][y-i] == 'b')
									{
										c++;
									}
									i++;
								}
								if(c |= 0)
								{
									puts("Jogada bloqueada");
								}else{
									if(tab[x-z][y-z] == 'B' || tab[x-z][y-z] == 'b')
									{
										puts("Jogada bloqueada");
									}
									if(tab[x-z][y-z] == ' ')
									{
										tab[x][y] = ' ';
										tab[x-z][y-z] = 'b';
										jog = 1;
									}
									if((tab[x-z][y-z] == 'w' || tab[x-z][y-z] == 'W') && tab[x-(z+1)][y-(z+1)] == ' ')
									{
										tab[x][y] = ' ';
										tab[x-z][y-z] = ' ';
										tab[x-(z+1)][y-(z+1)] = 'b';
										jog = 1;
									}
								}
								if(d == 2)
								{
									while(i < z)
									{
										if(tab[x-i][y+i] == 'b' || tab[x-i][y+i] == 'B' || tab[x-i][y+i] == 'w' || tab[x-i][y+i] == 'W')
										{
											c++;
										}
										i++;
									}
									if(c |= 0)
									{
										puts("Jogada bloqueada");
									}else{
										if(tab[x-z][y+z] == 'B' || tab[x-z][y+z] == 'b')
										{
											puts("Jogada bloqueada");
										}
										if(tab[x-z][y+z] == ' ')
										{
											tab[x][y] = ' ';
											tab[x-z][y+z] = 'b';
											jog = 1;
										}
										if((tab[x-z][y+z] == 'W' || tab[x-z][y+z] == 'w') && tab[x-(z+1)][y+(z+1)] == ' ')
										{
											tab[x][y] = ' ';
											tab[x-z][y+z] = ' ';
											tab[x-(z+1)][y+(z+1)] = 'b';
											jog = 1;
										}
									}
								}
								if(d == 3)
								{
									while(i < z)
									{
										if(tab[x+i][y-i] == 'b' || tab[x+i][y-i] == 'B' || tab[x+i][y-i] == 'w' || tab[x+i][y-i] == 'W')
										{
											c++;
										}
										i++;
									}
									if(c |= 0)
									{
										puts("Jogada bloqueada");
									}else{
										if(tab[x+z][y-z] == 'B' || tab[x+z][y-z] == 'b')
										{
											puts("Jogada bloqueada");
										}
										if(tab[x+z][y-z] == ' ')
										{
											tab[x][y] = ' ';
											tab[x+z][y-z] = 'b';
											jog = 1;
										}
										if((tab[x+z][y-z] == 'W' || tab[x+z][y-z] == 'w') && tab[x+(z+1)][y-(z+1)] == ' ')
										{
											tab[x][y] = ' ';
											tab[x+z][y-z] = ' ';
											tab[x+(z+1)][y-(z+1)] = 'b';
											jog = 1;
										}
									}
								}
								if(d == 4)
								{
									while(i < z)
									{
										if(tab[x+i][y+i] == 'b' || tab[x+i][y+i] == 'B' || tab[x+i][y+i] == 'w' || tab[x+i][y+i] == 'W')
										{
											c++;
										}
										i++;
									}
									if(c |= 0)
									{
										puts("Jogada bloqueada");
									}else{
										if(tab[x+z][y+z] == 'B' || tab[x+z][y+z] == 'b')
										{
											puts("Jogada bloqueada");
										}
										if(tab[x+z][y+z] == ' ')
										{
											tab[x][y] = ' ';
											tab[x+z][y+z] = 'b';
											jog = 1;
										}
										if((tab[x+z][y+z] == 'W' || tab[x+z][y+z] == 'w') && tab[x+(z+1)][y+(z+1)] == ' ')
										{
											tab[x][y] = ' ';
											tab[x+z][y+z] = ' ';
											tab[x+(z+1)][y+(z+1)] = 'b';
											jog = 1;
										}
									}
								}
							}
						}else{
							puts("Essa peca nao e sua");
						}
					}
				}
			}
			jog = 0;//Jog � reiniciado
			if(vez == 1)// Trocando a vez
			{
				vez = 2;
			}else{
				vez = 1;
			}
			for(i=1;i<9;i++)// Checando se alguem virou dama
			{
				if(tab[8][i] == 'W')
					tab[8][i] = 'w';
				if(tab[1][i] == 'B')
					tab[1][i] = 'b';
			}
			vb = 1;
			vw = 1;
			for(i=0;i=9;i++)
			{
				for(c=0;c=9;c++)
				{
					if(tab[i][c] == 'W' || tab[i][c] == 'w')
						vb = 0;
					if(tab[i][c] == 'B' || tab[i][c] == 'b')
						vw = 0;
				}
			}
			if(vb == 1 || vw == 1)
				v = 1;
			}
		if(vb == 1)
		{
			puts("A vit�ria � das Pretas");
		}else{
			puts("A vitoria � das Brancas");
		}
		}
	}
}
