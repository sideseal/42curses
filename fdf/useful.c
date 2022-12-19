
void	iter(t_fdf *fdf)
{
	t_point	*curr;

	curr = fdf->map->point;
	while (curr)
	{
		printf("%d, %d, %d\n", curr->x, curr->y, curr->z);
		curr = curr->next;
	}
	printf("map: %d, %d\n", fdf->map->width, fdf->map->height);
}
