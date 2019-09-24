#include <stdio.h>
#include <stdlib.h>
int i,c,x,y,z,d;
char tab[8][8];
void ptab()
{
	for(i=0;i<8;i++)
	{
		for(c=0;c<8;c++)
			tab[i][c] = ' ';
	}

	for (i=0;i<3;i++)
	{
		if((i%2)==0)
		{
			for(c=0;c<8;c+= 2)
				tab[i][c] = 'W';
		}else {
			for(c=1;c<8;c+=2)
				tab[i][c] = 'W';
		}
	}

	for (i=5;i<8;i++)
	{
		if ((i % 2) == 0)
		{
			for(c=0;c<8;c+=2)
				tab[i][c] = 'B';
		}else{
			for(c=1;c<8;c+=2)
				tab[i][c] = 'B';
		}
	}
}
void mtab()
{
	void linha1(int l)
	{
		int i;
		for (i=0;i<4;i++)
			printf(" _____         ");
		printf("\n");
		for (i=0;i<4;i++)
			printf("|     | *******");
		printf("\n");
		for (i=0;i<8;i+=2)
			printf("|  %c  | *******", tab[l][i]);
		printf("\n");
		for (i=0;i<4;i++)
			printf("|_____| *******");
		printf("\n");
	}
	void linha2(int l)
	{
		int i;
		for (i=0;i<4;i++)
			printf("         _____ ");
		printf("\n");
		for (i=0;i<4;i++)
			printf("******* |     |");
		printf("\n");
		for (i=1;i<8;i+=2)
			printf("******* |  %c  |", tab[l][i]);
		printf("\n");
		for (i=0;i<4;i++)
			printf("******* |_____|");
		printf("\n");
	}
	for(i=0;i<8;i++)
	{
		if(i % 2 == 0)
		{
			linha1(i);
		}else{
			linha2(i);
		}
	}
}
void verw()
{
	int aux = 0;
	d = 1;
		if(d == 1)
		{
			if((tab[x+1][y-1] == 'B' || tab[x+1][y-1] == 'b') && tab[x+2][y-2] == ' ')
			{
				aux = 1;
			}
		}
		if(aux == 2)
			d+=1;
		if(d == 2)
		{
			if((tab[x+1][y+1] == 'B' || tab[x+1][y+1] == 'b') && tab[x+2][y+2] == ' ')
			{
				aux = 1;
			}
		}
		if(aux == 2)
			d+=1;
		if(d == 3)
		{
			if((tab[x-1][y-1] == 'B' || tab[x-1][y-1] == 'b') && tab[x-2][y-2] == ' ')
			{
				aux = 1;
			}
		}
		if(aux == 2)
			d+=1;
		if(d == 4)
		{
			if((tab[x-1][y+1] == 'B' || tab[x-1][y+1] == 'b') && tab[x-2][y+2] == ' ')
			{
				aux = 1;
			}
		}
		if(aux == 1)
		{
			system("cls");
			mtab();
			puts("Encore!");
			scanf("%d",&d);
			if(d == 1)
			{
				if((tab[x+1][y-1] == 'B' || tab[x+1][y-1] == 'b') && tab[x+2][y-2] == ' ')
				{
					tab[x][y] = ' ';
					tab[x+1][y-1] = ' ';
					tab[x+2][y-2] = 'W';
				}
			}
			if(d == 2)
			{
				if((tab[x+1][y+1] == 'B' || tab[x+1][y+1] == 'b') && tab[x+2][y+2] == ' ')
				{
					tab[x][y] = ' ';
					tab[x+1][y+1] = ' ';
					tab[x+2][y+1] = 'W';
				}
			}
			if(d == 3)
			{
				if((tab[x-1][y-1] == 'B' || tab[x-1][y-1] == 'b') && tab[x-2][y-2] == ' ')
				{
					tab[x][y] = ' ';
					tab[x-1][y-1] = ' ';
					tab[x-2][y-1] = 'W';
				}
			}
			if(d == 4)
			{
				if((tab[x-1][y+1] == 'B' || tab[x-1][y+1] == 'b') && tab[x-2][y+2] == ' ')
				{
					tab[x][y] = ' ';
					tab[x-1][y+1] = ' ';
					tab[x-2][y+1] = 'W';
					verw();
				}
			}
		}

}
void verb()
{

	int aux = 0;
	d = 1;
		if(d == 1)
		{
			if((tab[x-1][y-1] == 'W' || tab[x-1][y-1] == 'w') && tab[x-2][y-2] == ' ')
			{
				aux = 1;
			}
		}
		if(aux == 2)
			d+=1;
		if(d == 2)
		{
			if((tab[x-1][y+1] == 'W' || tab[x-1][y+1] == 'w') && tab[x-2][y+2] == ' ')
			{
				aux = 1;
			}
		}
		if(aux == 2)
			d+=1;
		if(d == 3)
		{
			if((tab[x+1][y-1] == 'W' || tab[x+1][y-1] == 'w') && tab[x+2][y-2] == ' ')
			{
				aux = 1;
			}
		}
		if(aux == 2)
			d+=1;
		if(d == 4)
		{
			if((tab[x+1][y+1] == 'W' || tab[x+1][y+1] == 'w') && tab[x+2][y+2] == ' ')
			{
				aux = 1;
			}
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
				}
			}
			if(d == 4)
			{
				if((tab[x+1][y+1] == 'W' || tab[x+1][y+1] == 'w') && tab[x+2][y+2] == ' ')
				{
					tab[x][y] = ' ';
					tab[x+1][y+1] = ' ';
					tab[x+2][y+2] = 'B';
				}
			}
			if(d == 1)
			{
				if((tab[x-1][y-1] == 'W' || tab[x-1][y-1] == 'w') && tab[x-2][y-2] == ' ')
				{
					tab[x][y] = ' ';
					tab[x-1][y-1] = ' ';
					tab[x-2][y-2] = 'B';
				}
			}
			if(d == 2)
			{
				if((tab[x-1][y+1] == 'W' || tab[x-1][y+1] == 'w') && tab[x-2][y+2] == ' ')
				{
					tab[x][y] = ' ';
					tab[x-1][y+1] = ' ';
					tab[x-2][y+2] = 'B';
					verb();
				}
			}
		}

}
void main ()
{
	for(i=0;i<8;i++)
	{
		for(c=0;c<8;c++)
		{
			tab[i][c] = ' ';
		}
	}
	ptab();
	int es=0;
	int vez,jog=0;
	int v = 0;
	printf("[1].Jogar\n[2].Jogo Pesosnalizado\n[3].Sair\n");
	scanf("%d",&es);
	if(es == 1)
	{
		system("cls");
		es = 0;
		printf("[1].PvP\n[2].PvE\n");
		scanf("%d",&es);
		if(es == 1)
		{
			vez == 1;
			while(v == 0)
			{
				if(vez == 1)
				{
					while(jog == 0)
					{
						system("cls");
						mtab();
						printf("Vez das brancas:\n");
						scanf("%d %d",&x,&y);
						x-=1;
						y-=1;
						if(tab[x][y] == 'W')
						{
							printf("Para qual direçao?\n");
							scanf("%d",&d);
							if(d == 1)
							{
								if(tab[x+1][y-1] == 'W' || tab[x+1][y-1] == 'w')
								{
									printf("Jogada Bloqueada\n");
								}
								if(tab[x+1][y-1] == ' ')
								{
									tab[x][y] = ' ';
									tab[x+1][y-1] = 'W';
									jog = 1;
								}
								if(tab[x+1][y-1] == 'B' && tab[x+2][y-2] == ' ')
								{
									tab[x][y] = ' ';
									tab[x+1][y-1] = ' ';
									tab[x+2][y-2] = 'W';
									jog = 1;
									x+= 2;
									y-= 2;
									verw();
								}
							}
							if(d == 2)
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
							if(d == 3)
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
							if(d == 4)
							{
								if((tab[x-1][y+1] == 'B' || tab[x-1][y+1] == 'b') && tab[x-2][y+2] == ' ')
								{
									tab[x-1][y+1] = ' ';
									tab[x][y] = ' ';
									tab[x-2][y+2] = 'W';
									jog = 1;
									x-=2;
									y+=2;
								}else{
									puts("Jogada bloqueada");
								}
							}
						}else{
							if(tab[x][y] == 'w')
							{
								c=0;
								printf("Para qual direcao?\n");
								scanf("%d",&d);
								printf("Quantas casas?\n");
								scanf("%d",&z);
								if(d == 1)
								{
									for(i=1;i<z;i++)
									{
										if(tab[x+i][y-i] |= ' ')
										{
											c++;
										}
									}
									if(c > 0)
									{
										puts("Jogada bloqueada");
									}else{
										if(tab[x+z][y-z] == 'W' || tab[x+z][y-z] == 'w')
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
								if(d == 2)
								{
									for(i=1;i<z;i++)
									{
										if(tab[x+i][y+i] |= ' ')
										{
											c++;
										}
									}
									if(c > 0)
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
								if(d == 3)
								{
									for(i=1;i<z;i++)
									{
										if(tab[x-i][y-i] |= ' ')
										{
											c++;
										}
									}
									if(c > 0)
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
										if((tab[x-z][y-z] == 'B' || tab[x-z][y-z] == 'b') && tab[x-(z+1)][y-(z+1)])
										{
											tab[x][y] = ' ';
											tab[x-z][y-z] = ' ';
											tab[x-(z+1)][y-(z+1)] = 'w';
											jog = 1;
										}
									}
								}
								if(d == 4)
								{
									for(i=1;i<z;i++)
									{
										if(tab[x-i][y+i] |= ' ')
										{
											c++;
										}
									}
									if(c > 0)
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
										if((tab[x-z][y+z] == 'B' || tab[x-z][y+z] == 'b') && tab[x-(z+1)][y+(z+1)])
										{
											tab[x][y] = ' ';
											tab[x-z][y+z] = ' ';
											tab[x-(z+1)][y+(z+1)] = 'w';
											jog = 1;
										}
									}
								}
							}else{
							puts("Essa nao e uma das suas pecas");
							}
						}
					}
				}
			if(vez == 2)
			{
				while(jog == 0)
				{
					system("cls");
					mtab();
					puts("Vez das Pretas");
					scanf("%d %d",&x,&y);
					x-=1;
					y-=1;
					if(tab[x][y] == 'B')
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
						if(tab[x][y] == 'b')
						{
							c=0;
							printf("Para qual direcao?\n");
							scanf("%d",&d);
							printf("Quantas casas?\n");
							scanf("%d",&z);
							if(d == 1)
							{
								for(i=1;i<z;i++)
								{
									if(tab[x-i][y-i] |= ' ')
									{
										c++;
									}
								}
								if(c > 0)
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
									for(i=1;i<z;i++)
									{
										if(tab[x-i][y+i] |= ' ')
										{
											c++;
										}
									}
									if(c > 0)
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
									for(i=1;i<z;i++)
									{
										if(tab[x+i][y-i] |= ' ')
										{
											c++;
										}
									}
									if(c > 0)
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
									for(i=1;i<z;i++)
									{
										if(tab[x+i][y+i] |= ' ')
										{
											c++;
										}
									}
									if(c > 0)
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
			jog = 0;
			if(vez == 1)
			{
				vez = 2;
			}else{
				vez = 1;
			}
			for(i=0;i<8;i++)
			{
				if(tab[7][i] == 'W')
					tab[7][i] = 'w';
				if(tab[0][i] == 'B')
					tab[0][i] = 'b';
			}
			}
		}
	}
}
