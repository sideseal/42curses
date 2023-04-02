#include <stdio.h>
#include <stdlib.h>

int		calc_base(int size)
{
	int floor;
	int width;
	int floor_step;

	floor = 1;
	width = 1;
	floor_step = 4;
	while (floor <= size)
	{
		width += 2 * (2 + floor);
		floor++;
		width += floor_step;
		if (floor % 2 && floor < size)
			floor_step += 2;
	}
	width -= floor_step;
	return (width);
}

void	put_line(int space)
{
	int pos;

	pos = 0;
	while (pos < space)
	{
		putchar(' ');
		pos++;
	}
}

void	put_blocks(int size, int floor, int width, int step)
{
	int door;
	int pos;

	door = 1 + 2 * ((floor - 1) / 2);
	pos = 0;
	while (pos < width)
	{
		if (pos == 0)
			putchar('/');
		else if (pos == width - 1)
			putchar('\\');
		else
		{
			if (floor == size && pos >= (width - door) / 2
					&& pos < (width + door) / 2 && 2 + floor - step <= door)
				if (door >= 5 && step == 2 + floor - door / 2 - 1
						&& pos == (width + door) / 2 - 2)
					putchar('$');
				else
					putchar('|');
			else
				putchar('*');
		}
		pos++;
	}
}

void	sastantua(int size)
{
	int	floor;
	int	height;
	int	step;
	int	width;

	if (size < 1)
		return ;
	floor = 1;
	width = 1;
	while (floor <= size)
	{
		height = 2 + floor;
		step = 0;
		while (step < height)
		{
			width += 2;
			put_line((calc_base(size) - width) / 2);
			put_blocks(size, floor, width, step);
			putchar('\n');
			step++;
		}
		floor++;
		width += 4 + 2 * ((floor - 2) / 2);
	}
}

int		main(int argc, char **argv)
{
	int floors;

	if (argc != 2 || !(floors = atoi(argv[1])))
		return (0);
	sastantua(floors);
	return (0);
}
