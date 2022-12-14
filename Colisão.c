#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void labirinto(int i, int j, int n, int m, int matriz[][m], char posicao[], int inicial_x, int inicial_y, int qtd)
{
	if (i < qtd)
	{
		if (posicao[i] == 'C')
		{
			if (inicial_x < n && inicial_x-1 >= 0)
			{
				if (matriz[inicial_x-1][inicial_y]  == 1)
				{
					inicial_x -= 1;
				}
			}

		}
		else if (posicao[i] == 'B') 
		{
			if (inicial_x+1 < n && inicial_x >= 0)
			{
				if (matriz[inicial_x+1][inicial_y] == 1)
				{
					inicial_x += 1;
				}
			}
		}
		else if (posicao[i] == 'E')
		{
			if (inicial_y < m && inicial_y-1 >= 0)
			{
				if (matriz[inicial_x][inicial_y-1] == 1)
				{
					inicial_y -= 1;
				}
			}
		}
		else if (posicao[i] == 'D')
		{
			if (inicial_y+1 < m && inicial_y >= 0)
			{
				if (matriz[inicial_x][inicial_y+1] == 1)
				{
					inicial_y += 1;
				}
			}
		}
		labirinto(++i, j, n, m, matriz, posicao, inicial_x, inicial_y, qtd);
	}
	else
	{
		printf("(%d,%d)\n", inicial_x, inicial_y);
	}

}

void ler_passos(int i, int n, int m, int matriz[][m],char posicao[], int qtd, int inicial_x, int inicial_y)
{
	if (i < qtd)
	{
		scanf(" %c", &posicao[i]);
		ler_passos(i+1, n, m, matriz, posicao, qtd, inicial_x, inicial_y);
	}
	else
	{
		scanf("%d%d", &inicial_x, &inicial_y);
		labirinto(0, 0, n, m, matriz, posicao, inicial_x, inicial_y, qtd);
	}
}

void ler(int i, int j, int n, int m, int matriz[][m])
{
	if (i < n)
	{
		if (j < m)
		{
			scanf("%d", &matriz[i][j]);
			ler(i, ++j, n, m, matriz);
		}
		else ler(++i, 0, n, m, matriz);
	}
}

int main()
{
	int n,m;
	scanf("%d\n%d", &n, &m);
	int matriz[n][m];

	ler(0, 0, n, m, matriz);

	int qtd, inicial_x = 0, inicial_y = 0;
	scanf("%d", &qtd);
	char posicao[qtd];
	ler_passos(0, n, m, matriz, posicao, qtd, inicial_x, inicial_y);
	
	return 0;
}