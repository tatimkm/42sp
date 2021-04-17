void	ft_putchar(char c);

void	circles(int x, int y, int array[y][x])
{
	--x;
	--y;
	array[0][0] = 111;
	array[y][x] = 111;
	array[y][0] = 111;
	array[0][x] = 111;
}

void	pipes_and_hyphens(int x, int y, int array[y][x])
{
	int		line;
	int		column;

	--x; //4
	--y; //3
	line = y - 1;  //2
	while (line > 0)
	{
		array[line][0] = 124; //2,0 | 1,0
		array[line][x] = 124; //2,4 | 1,4
		line--;
	}
	column = x - 1; //3
	while (column > 0)
	{
		array[0][column] = 45; //0,3 | 0,2 | 0,1
		array[y][column] = 45; //3,3 | 3,2 | 3,1
		column--;
	}
}

void	spaces(int x, int y, int array[y][x])
{
	int		line;
	int		column;

	--x; //4
	--y; //3
	column = x - 1; // 3
	line = y - 1; // 2
	while (column > 0) // 3 > 0
	{
		line = y - 1; // 2
		array[line][column] = 32; // 2,3 | 2,2 | 2,1
		while (line > 0) // 2 > 0
		{
			array[line][column] = 32; // 2,3 | 1,3 | 2,2 | 1,2 | 2,1 | 1,1
			line--; // 1 | 0
		}
		column--; // 2 | 1 | 0
	}
}

void	rush(int x, int y)
{
	int		array[y][x];
	int		line;
	int		column;

	line = -1;
	column = -1;
	circles(x, y, array);
	pipes_and_hyphens(x, y, array);
	if (y != 1)
		spaces(x, y, array);
	while (++line < y) // 0 < 4 | 1 < 4 | 2 < 4
	{
		while (++column < x) // 0 < 5 | 1 < 5 ...
		{
			ft_putchar(array[line][column]); //0,0 | 0,1 ... | 1, 0 | 1,1 ...
		}
		column = -1; // -1
		ft_putchar('\n');
	}
}