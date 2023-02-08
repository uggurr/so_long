#include "so_long.h"

void    map_opened_check5()
{
    t_open t_open;

    t_open.x = open("./textures/EXIT2.xpm", O_RDONLY);
    t_open.y = open("./textures/wall1.xpm", O_RDONLY);
    while (t_open.x < 0 || t_open.y < 0 || t_open.z < 0 || t_open.j < 0 || t_open.k < 0)
	{
		printf("File Not Found!");
		close(t_open.x);
		close(t_open.y);
		exit(0);
	}
    close(t_open.x);
	close(t_open.y);
}

void    map_opened_check4()
{
    t_open t_open;

    t_open.x = open("./textures/ENEMY4.xpm", O_RDONLY);
    t_open.y = open("./textures/ENEMY5.xpm", O_RDONLY);
    t_open.z = open("./textures/ENEMY6.xpm", O_RDONLY);
    t_open.j = open("./textures/ENEMY7.xpm", O_RDONLY);
    t_open.k = open("./textures/EXIT1.xpm", O_RDONLY);
    while (t_open.x < 0 || t_open.y < 0 || t_open.z < 0 || t_open.j < 0 || t_open.k < 0)
	{
		printf("File Not Found!");
		close(t_open.x);
		close(t_open.y);
		close(t_open.z);
		close(t_open.j);
		close(t_open.k);
		exit(0);
	}
    close(t_open.x);
	close(t_open.y);
	close(t_open.z);
	close(t_open.j);
    close(t_open.k);
    map_opened_check5();
}

void    map_opened_check3()
{
    t_open t_open;

    t_open.x = open("./textures/coingif6.xpm", O_RDONLY);
    t_open.y = open("./textures/coingif7.xpm", O_RDONLY);
    t_open.z = open("./textures/ENEMY1.xpm", O_RDONLY);
    t_open.j = open("./textures/ENEMY2.xpm", O_RDONLY);
    t_open.k = open("./textures/ENEMY3.xpm", O_RDONLY);
    while (t_open.x < 0 || t_open.y < 0 || t_open.z < 0 || t_open.j < 0 || t_open.k < 0)
	{
		printf("File Not Found!");
		close(t_open.x);
		close(t_open.y);
		close(t_open.z);
		close(t_open.j);
		close(t_open.k);
		exit(0);
	}
    close(t_open.x);
	close(t_open.y);
	close(t_open.z);
	close(t_open.j);
    close(t_open.k);
    map_opened_check4();
}

void    map_opened_check2()
{
    t_open t_open;

    t_open.x = open("./textures/coingif1.xpm", O_RDONLY);
    t_open.y = open("./textures/coingif2.xpm", O_RDONLY);
    t_open.z = open("./textures/coingif3.xpm", O_RDONLY);
    t_open.j = open("./textures/coingif4.xpm", O_RDONLY);
    t_open.k = open("./textures/coingif5.xpm", O_RDONLY);
    while (t_open.x < 0 || t_open.y < 0 || t_open.z < 0 || t_open.j < 0 || t_open.k < 0)
	{
		printf("File Not Found!");
		close(t_open.x);
		close(t_open.y);
		close(t_open.z);
		close(t_open.j);
		close(t_open.k);
		exit(0);
	}
    close(t_open.x);
	close(t_open.y);
	close(t_open.z);
	close(t_open.j);
    close(t_open.k);
    map_opened_check3();
}

void	map_opened_check()
{
    t_open t_open;

    t_open.x = open("./textures/characterDown.xpm", O_RDONLY);
    t_open.y = open("./textures/characterAbove.xpm", O_RDONLY);
    t_open.z = open("./textures/characterLeft.xpm", O_RDONLY);
    t_open.j = open("./textures/characterRight.xpm", O_RDONLY);
    t_open.k = open("./textures/BG.xpm", O_RDONLY);
    while (t_open.x < 0 || t_open.y < 0 || t_open.z < 0 || t_open.j < 0 || t_open.k < 0)
	{
		printf("File Not Found!");
		close(t_open.x);
		close(t_open.y);
		close(t_open.z);
		close(t_open.j);
		close(t_open.k);
		exit(0);
	}
    close(t_open.x);
	close(t_open.y);
	close(t_open.z);
	close(t_open.j);
    close(t_open.k);
    map_opened_check2();
}