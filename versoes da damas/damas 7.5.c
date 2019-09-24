#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int i,c,x,y,z,d,vez,vb,vw,v,es,h,partjoj=0,jog=0;
char tab[10][10];
void ptab() // Essa função preenche o tabuleiro com as peças
{
	for(i=1;i<9;i++) // Primeiro deixa todos os espaços em branco
	{
		for(c=1;c<9;c++)
			tab[i][c] = ' ';
	}

	for (i=1;i<4;i++) // Então coloca as peças 'W' (Brancas)
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

	for (i=6;i<9;i++) // Agora as peças 'B' (Pretas)
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
void mtab() // Essa função serve para mostrar o tabuleiro ao jogador
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
	for(i=1;i<9;i++) // Aqui são chamadas as duas funções para que em cada linha as funções sejam alternadas
	{
		if(i%2 == 1)
		{
			linha1(i);
		}else{
			linha2(i);
		}
	}
}
void verw() // Aqui nós verificamos as peças ao redor da peça 'W' assim que for movida para poder fazer o "Encore" e comer em sequencia
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
	if((tab[x-1][y+1] == 'B' || tab[x-1][y+1] == 'b') && tab[x-2][y+2] == ' ')// E aqui são checadas as peças ao redor da peça que foi movimentada
	{
		aux = 1;
	}
	if(aux == 1)
	{
		system("cls");
		mtab();
		puts("Encore!"); // Pra quem não sabe: "Encore" significa "De novo"
		scanf("%d",&d);
		if(d == 1)
		{
			if((tab[x+1][y-1] == 'B' || tab[x+1][y-1] == 'b') && tab[x+2][y-2] == ' ')// Daqui até...
			{
				tab[x][y] = ' ';
				tab[x+1][y-1] = ' ';
				tab[x+2][y-2] = 'W';
			}
			verw();
		}
		if(d == 2)
		{
			if((tab[x+1][y+1] == 'B' || tab[x+1][y+1] == 'b') && tab[x+2][y+2] == ' ')
			{
				tab[x][y] = ' ';
				tab[x+1][y+1] = ' ';
				tab[x+2][y+2] = 'W';
			}
			verw();
		}
		if(d == 3)
		{
			if((tab[x-1][y-1] == 'B' || tab[x-1][y-1] == 'b') && tab[x-2][y-2] == ' ')
			{
				tab[x][y] = ' ';
				tab[x-1][y-1] = ' ';
				tab[x-2][y-2] = 'W';
			}
			verw();
		}
		if(d == 4)
		{
			if((tab[x-1][y+1] == 'B' || tab[x-1][y+1] == 'b') && tab[x-2][y+2] == ' ')// ...Aqui é feito o movimento
			{
				tab[x][y] = ' ';
				tab[x-1][y+1] = ' ';
				tab[x-2][y+2] = 'W';
			}
			verw();// Rechamando a função porquê pode haver mais de duas comidas sucessivas
		}
	}
	d = 0;
}
void verb() // Aqui é semelhante à função anterior só que dessa vez para as peças 'B'
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
	if((tab[x+1][y+1] == 'W' || tab[x+1][y+1] == 'w') && tab[x+2][y+2] == ' ')// Denovo em todas essas partes é checado os arredores da peça que foi movida
	{
		aux = 1;
	}
	if(aux == 1)
	{
		system("cls");
		mtab();
		if(es == 1)
		{
			puts("Encore!");
			scanf("%d",&d);
		}
		if(es == 2)
		{
			d = (rand() % 4) + 1;
		}
		if(d == 3)
		{
			if((tab[x+1][y-1] == 'W' || tab[x+1][y-1] == 'w') && tab[x+2][y-2] == ' ')
			{
				tab[x][y] = ' ';
				tab[x+1][y-1] = ' ';
				tab[x+2][y-2] = 'B';
			}
			verb();
		}
		if(d == 4)
		{
			if((tab[x+1][y+1] == 'W' || tab[x+1][y+1] == 'w') && tab[x+2][y+2] == ' ')
			{
				tab[x][y] = ' ';
				tab[x+1][y+1] = ' ';
				tab[x+2][y+2] = 'B';
			}
			verb();
		}
		if(d == 1)
		{
			if((tab[x-1][y-1] == 'W' || tab[x-1][y-1] == 'w') && tab[x-2][y-2] == ' ')
			{
				tab[x][y] = ' ';
				tab[x-1][y-1] = ' ';
				tab[x-2][y-2] = 'B';
			}
			verb();
		}
		if(d == 2)
		{
			if((tab[x-1][y+1] == 'W' || tab[x-1][y+1] == 'w') && tab[x-2][y+2] == ' ')// Nesses "IFs" é feito o movimento
			{
				tab[x][y] = ' ';
				tab[x-1][y+1] = ' ';
				tab[x-2][y+2] = 'B';
			}
			verb();
		}
	}
	d = 0;
}
void movw() // Movimento das peças 'W'
{
	while(jog == 0)// Jog serve para que caso o jogador faça uma jogada não permitida ele possa jogar de novo
					{
						system("cls");//Limpando
						mtab();// E atualizando o tabuleiro
						if(es == 1)
							puts("Vez das brancas:");
						else
							puts("Sua vez");
						scanf("%d %d",&x,&y);
						if(tab[x][y] == 'W')// Checando para ver se é uma peça sua e se for, checando para ver se é uma dama
						{
							printf("Para qual direçao?\n");
							scanf("%d",&d);// Jogador digita direção do movimento
							if(d == 1)//Cada direção de movimento tem um calculo diferente
							{
								if(tab[x+1][y-1] == 'W' || tab[x+1][y-1] == 'w')
								{
									printf("Jogada Bloqueada\n");// Jogada bloqueada então Jog não se altera
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
									x+= 2;//Isso serve para a funão tendo a posição final da peça como nova posição
									y-= 2;
									verw();//Chamando a função já que uma peça foi comida
								}
							}
							if(d == 2)// Mesma coisa só alterando os sinais
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
							if(d == 3)// Movimento para trás, então só em caso de comer uma peça
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
							if(d == 4)// Mesma coisa do anterior, só com sinais diferentes
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
							if(tab[x][y] == 'w')// Se a peça for uma dama
							{
								c=0;
								i=1;
								printf("Para qual direcao?\n");
								scanf("%d",&d);
								printf("Quantas casas?\n");
								scanf("%d",&z);//Calculos agora são feitos com a variavel "z" para movimentação da dama
								if(d == 1)
								{
									while(i < z)//Esse laço vai estar em todo inicio de movimento. Ele serve pra checar se não ha peças jo caminho do movimento
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
										if(tab[x+z][y-z] == 'W' || tab[x+z][y-z] == 'w')//Movimentos que você ja viu anteriormente
										{
											puts("jogada bloqueada");
										}
										if((tab[x+z][y-z] == 'B' || tab[x+z][y-z] == 'b') && tab[x+(z+1)][y-(z+1)] == ' ')
										{
											tab[x][y] = ' ';
											tab[x+z][y-z] = ' ';
											tab[x+(z+1)][y-(z+1)] = 'w';
											jog = 1;
											x+=(z+1);
											y-=(z+1);
											verw();
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
											x+=(z+1);
											y+=(z+1);
											verw();
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
											x-=(z+1);
											y-=(z+1);
											verw();
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
											x-=(z+1);
											y+=(z+1);
											verw();
										}
									}
								}
							}else{
							puts("Essa nao e uma das suas pecas");// Caso lá em cima o jogador escolha uma peça que não é dele.
							}
						}
					}
}
void movb() // Movimento das peças 'B'
{
	while(jog == 0)
				{
					system("cls");//Limpando e...
					mtab();//Atualizando o tabuleiro
					puts("Vez das Pretas");//Aqui é tudo a mesma coisa entaõ eu só vou comentar as partes importantes
					scanf("%d %d",&x,&y);
					if(tab[x][y] == 'B')// Se for uma peça normal
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
								while(i < z)// Checando peças no caminho
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
										x-=(z+1);
										y-=(z+1);
										verb();
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
											x-=(z+1);
											y+=(z+1);
											verb();
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
											x+=(z+1);
											y-=(z+1);
											verb();
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
											x+=(z+1);
											y+=(z+1);
											verb();
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
void base() // Conjunto de ações básicas no vim de cada turno
{
	jog = 0;//Jog é reiniciado
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
				vb=0;
				vw=0;
				for(i=0;i<9;i++)
				{
					for(c=0;c<9;c++)
					{
						if(tab[i][c] == 'W' || tab[i][c] == 'w')
							vb = 1;
						if(tab[i][c] == 'B' || tab[i][c] == 'b')
							vw = 1;
					}
				}
				if(vb == 0 || vw == 0)
					v = 1;
}
void movia()// Movimento da 'I.A'
{
	system("cls");
	mtab();
	for(i=1;i<9;i++)
	{
		for(c=1;c<9;c++)
		{
			if(tab[i][c] == 'B' && tab[i+1][c+1] == 'W' && jog == 0)
			{
				if(tab[i+2][c+2] == ' ' && jog == 0)
				{
					tab[i][c] = ' ';
					tab[i+1][c+1] = ' ';
					tab[i+2][c+2] = 'B';
					jog = 1;
					verb();
				}
				if(tab[i-1][c-1] == ' ' && jog == 0)
				{
					if((tab[i-2][c-2] == 'B' || tab[i-2][c-2] == 'b') && jog == 0)
					{
						tab[i-1][c-1] = tab[i-2][c-2];
						tab[i-2][c-2] = ' ';
						jog = 1;
					}
					if((tab[i][c+2] == 'B' || tab[i][c+2] == 'b') && jog == 0)
					{
						tab[i+1][c+1] = tab[i][c+2];
						tab[i][c+2] = ' ';
						jog = 1;
					}
				}
				if(jog == 0 && tab[i+1][c-1] == ' ')
				{
					tab[i+1][c-1] = tab[i][c];
					tab[i][c] = ' ';
					jog = 1;
				}
			}
			if(tab[i][c] == 'B' && tab[i+1][c-1] == 'W' && jog == 0)
			{
				if(tab[i+2][c-2] == ' ' && jog == 0)
				{
					tab[i][c] = ' ';
					tab[i+1][c-1] = ' ';
					tab[i+2][c-2] = 'B';
					jog = 1;
					verb();
				}
				if(tab[i-1][c+1] == ' ' && jog == 0)
				{
					if((tab[i-2][c+2] == 'B' || tab[i-2][c+2] == 'b') && jog == 0)
					{
						tab[i-1][c+1] = tab[i+2][c-2];
						tab[i-2][c+2] = ' ';
						jog = 1;
					}
					if((tab[i][c+2] == 'B' || tab[i][c+2] == 'b') && jog == 0)
					{
						tab[i-1][c+1] = tab[i][c+2];
						tab[i][c+2] = ' ';
						jog = 1;
					}
				}
				if(jog == 0 && tab[i+1][c+1] == ' ')
				{
					tab[i+1][c+1] = tab[i][c];
					tab[i][c] = ' ';
					jog = 1;
				}
			}
			if(tab[i][c] == 'B' && tab[i-1][c+1] == 'W' && jog == 0)
			{
				if(tab[i-2][c+2] == ' ' && jog == 0)
				{
					tab[i][c] = ' ';
					tab[i-1][c+1] = ' ';
					tab[i-2][c+2] = 'B';
					jog = 1;
					verb();
				}
				if(tab[i+1][c-1] == ' ' && jog == 0)
				{
					if((tab[i+2][c-2] == 'B' || tab[i+2][c-2] == 'b') && jog == 0)
					{
						tab[i+1][c-1] = tab[i+2][c-2];
						tab[i+2][c-2] = ' ';
						jog = 1;
					}
					if((tab[i][c-2] == 'B' || tab[i][c-2] == 'b') && jog == 0)
					{
						tab[i+1][c-1] = tab[i][c-2];
						tab[i][c-2] = ' ';
						jog = 1;
					}
				}
				if(jog == 0 && tab[i-1][c-1] == ' ')
				{
					tab[i-1][c-1] = tab[i][c];
					tab[i][c] = ' ';
					jog = 1;
				}
			}
			if(tab[i][c] == 'B' && tab[i-1][c-1] == 'W' && jog == 0)
			{
				if(tab[i-2][c-2] == ' ' && jog == 0)
				{
					tab[i][c] = ' ';
					tab[i-1][c-1] = ' ';
					tab[i-2][c-2] = 'B';
					jog = 1;
					verb();
				}
				if(tab[i+1][c+1] == ' ' && jog == 0)
				{
					if((tab[i+2][c+2] == 'B' || tab[i+2][c+2] == 'b') && jog == 0)
					{
						tab[i+1][c+1] = tab[i+2][c+2];
						tab[i+2][c+2] = ' ';
						jog = 1;
					}
					if((tab[i][c+2] == 'B' || tab[i][c+2] == 'b') && jog == 0)
					{
						tab[i+1][c+1] = tab[i][c+2];
						tab[i][c+2] = ' ';
						jog = 1;
					}
				}
				if(jog == 0 && tab[i-1][c+1] == ' ')
				{
					tab[i-1][c+1] = tab[i][c];
					tab[i][c] = ' ';
					jog = 1;
				}
			}
		}
	}
	while(jog == 0)
	{
		x = (rand() % 8) + 1;
		y = (rand() % 8) + 1;
		d = (rand() % 4) + 1;
		if(tab[x][y] == 'B')
		{
			if(d == 1)
			{
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
				}
			}
			if(d == 2)
			{
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
				}
			}
			if(d == 3)
			{
				if(tab[x+1][y-1] == 'W' && tab[x+2][y-2] == ' ')
				{
					tab[x][y] = ' ';
					tab[x+1][y-1] = ' ';
					tab[x+2][y-2] = 'B';
					jog = 1;
				}
			}
			if(d == 4)
			{
				if(tab[x+1][y+1] == 'W' && tab[x+2][y+2] == ' ')
				{
					tab[x][y] = ' ';
					tab[x+1][y+1] = ' ';
					tab[x+2][y+2] = 'B';
					jog = 1;
				}
			}
		}
	}
}
void menu ( ){

  printf("(1)jogar\n (2)jogo personalizado\n (3)extras\n");


// Jogador seleciona se quer jogar ous sair

	scanf("%d",&es);

	if(es == 1)
	{

		system("cls");
		es = 0;
		printf("[1].player x player\n[2].hokage x hokage \n");// Modo de jogo
		scanf("%d",&es);

		if(es == 1)
		{
			vez = 1;
			while(v == 0)// V mantem tudo em um laço até que alguem vença
			{
				if(vez == 1)// Essa variavel indica de quem é a vez 1:Brancas 2:Pretas
				{
					movw();
				}
				if(vez == 2)// Se for a vez das Pretas
				{
					movb();
				}
				base();
			}
			if(vb == 1)
			{

				puts("A vitória é das Pretas");
			}else{

				puts("A vitoria é das Brancas");
			}
		}
		if(es == 2)
		{
			vez = 1;
			while(v == 0)
			{
				if(vez == 1)
				{
					movw();
				}
				if(vez == 2)
				{
					movia();
				}
				base();
			}

		}
	}
	if(es==3)
    {
      system("cls");

      printf("(1)partidas jogadas\n (2)ranking\n");
        scanf("%d",&h );
        if(h==1){
            system("cls");
            printf("partidas jogadas\n");
        }
        if(h==2){
            system("cls");
            printf("1°lugar\n 2°lugar\n 3°lugar\n 4°lugar\n 5°lugar");
        }
    }
	return 0;
}






int main ( ) //
 //Função Principal
{
	srand(time(NULL));
	for(i=0;i<8;i++)
	{
		for(c=0;c<8;c++)
		{
			tab[i][c] = ' ';
		}
	}
    ptab();

	menu();
	return 0;
}
