#include "../so_long.h"

void initialize_directions(int directions[4][2]) {
    directions[0][0] = -1;
    directions[0][1] = 0;
    directions[1][0] = 1;
    directions[1][1] = 0;
    directions[2][0] = 0;
    directions[2][1] = -1;
    directions[3][0] = 0;
    directions[3][1] = 1;
}

int is_valid(t_mlx *mlx, int x, int y) {
    if (x >= 0 && x < mlx->map_width && y >= 0 && y < mlx->map_height
        && !ft_strchr(mlx->flood->wall, mlx->map[y][x]) && !mlx->flood->visited[y][x]) {
        return (1);
    }
    return (0);
}

int flood_fill(t_mlx *mlx, int x, int y) {
    int i;
    int new_x;
    int new_y;
    int num_c;
    int num_c2;

    num_c = 0;
    if (mlx->map[y][x] == mlx->flood->target) {
        num_c++;
    }
    mlx->flood->visited[y][x] = 1;
    if (x == 0 || x == mlx->map_width - 1 || y == 0 || y == mlx->map_height - 1) {
        ft_printf("ERROR\nMap not enclosed\n");
        return (-1);
    }
    i = 0;
    while (i < 4) {
        new_x = x + mlx->flood->directions[i][0];
        new_y = y + mlx->flood->directions[i][1];
        if (is_valid(mlx, new_x, new_y)) {
            num_c2 = num_c;
            num_c += flood_fill(mlx, new_x, new_y);
            if (num_c == num_c2 - 1)
                return (-1);
        }
        i++;
    }
    return (num_c);
}

void free_flood(t_flood *f, int map_height) {
    int y;

    y = 0;
    while (y < map_height) {
        free(f->visited[y]);
        y++;
    }
    free(f->visited);
    free(f);
}

int is_path_to_exit(t_mlx *mlx, char c, char *wall) {
    int result;
    t_flood *f;

    f = malloc(sizeof(t_flood));
    if (!f)
        return (0);
    f->visited = (int **)malloc(mlx->map_height * sizeof(int *));
    if (!f->visited) {
        free(f);
        return (0);
    }
    for (int y = 0; y < mlx->map_height; y++) {
        f->visited[y] = (int *)malloc(mlx->map_width * sizeof(int));
        if (!f->visited[y]) {
            for (int j = 0; j < y; j++) {
                free(f->visited[j]);
            }
            free(f->visited);
            free(f);
            return (0);
        }
        for (int x = 0; x < mlx->map_width; x++) {
            f->visited[y][x] = 0;
        }
    }

    if (is_path_to_exit_continued(f, mlx) != 1) {
        free_flood(f, mlx->map_height);
        return (0);
    }
    initialize_directions(f->directions);
    mlx->flood = f;
    mlx->flood->y2 = mlx->y;
    mlx->flood->x2 = mlx->x;
    mlx->flood->wall = wall;
    mlx->flood->target = c;
    result = flood_fill(mlx, mlx->flood->x2, mlx->flood->y2);
    free_flood(f, mlx->map_height);
    return (result);
}
