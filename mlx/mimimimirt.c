
#include "cub3d.h"
#include "mlx.h"

void            my_mlx_pixel_put(int x, int y, unsigned int color, char *data, int size_line)
{
    char    *dst;
    size_line += 0;
    dst = data + y * 4000 + x * 4;
    *(unsigned int*)dst = color;
}
unsigned int dark(unsigned int color)
{
    color +=0;
    return 1;
}
int exita()
{
    exit(0);
}
int main ()
{
    int i = 0;
    char **line;
    line = (char **)malloc(7 * sizeof(char *));
    while (i != 6)
    {
        line[i] = (char *)malloc(8);
        i++;
    }

    line[0] = "1111111";
    line[1] = "1000001";
    line[2] = "1000001";
    line[3] = "100A001";
    line[4] = "1000001";
    line[5] = "1111111";
    line[6] = 0;
 void    *mlx_win;
    void    *mlx;
    float x = 500;
    float x2 = 500;
    float y = 999;
    float k = 0;
    int ppp = 32;
    int size_line = 1000;
    int endian = 0;
    int r = 0, g = 0, b = 0;
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1000, 1000, "Hello world!");
   void *image =  mlx_new_image(mlx, 1000, 1000);
   char *data;
   data = mlx_get_data_addr(image, &ppp, &size_line, &endian);
i = 0;
    float x3;
    float x4;
    unsigned int color;
    int t = 0;
    int col = 300;
    while (x < 999 && x2 > 0 && y > 100)
    {
        color = 0xFFFFFF;
        x3 = 500;
        x4 = 500;
        my_mlx_pixel_put (x, y, 0xFFFFFF, data, size_line);
        my_mlx_pixel_put (x2, y, 0xFFFFFF, data, size_line);
        if (k == 0)
            y = y - 0.0001f;
        else
            y = y - (k) * (k);
        if (y < 200)
            while (x3 != x)
            {
                my_mlx_pixel_put (x3, y, color, data, size_line);
                my_mlx_pixel_put (x4, y, color, data, size_line);
                x3 = x3 + 0.05f;
                x4 = x4 - 0.05f;
                // printf("%u\n", color);
                r = (color & 0xFF0000) >> 16;
                g = (color & 0x00FF00) >> 8;
                b = (color & 0x0000FF);
                // printf("%u\n", color);
                if (t == 25)
                {
                    r *= 0.999999999999999;
                    g *= 0.999999999999999;
                    b *= 0.999999999999999;
                    t = 0;
            }
            t++;
    
            color = ((r << 16) | (g << 8) | b);
            }
        else
        {
            i = 0;
            color = 0x56c5FF;
            while (i < col + 100)
            {
                r = (color & 0xFF0000) >> 16;
                g = (color & 0x00FF00) >> 8;
                b = (color & 0x0000FF);
                r *= 0.999999999999999;
                g *= 0.999999999999999;
                b *= 0.999999999999999;
                i++;
                color = ((r << 16) | (g << 8) | b);
            }
            
            while (x3 != x)
            {
                
                my_mlx_pixel_put (x3, y, color, data, size_line);
                my_mlx_pixel_put (x4, y, color, data, size_line);
                x3 = x3 + 0.05f;
                x4 = x4 - 0.05f;
                r = (color & 0xFF0000) >> 16;
                g = (color & 0x00FF00) >> 8;
                b = (color & 0x0000FF);
                if (t == 30)
                {
                    r *= 0.999999999999999;
                    g *= 0.999999999999999;
                    b *= 0.999999999999999;
                    t = 0;
                }
            t++;
            color = ((r << 16) | (g << 8) | b);
            }
        }
      
         if (y - floorf(y) < 0.1f)
            col = col - 1;
        x2 = x2 - 0.05f;
        x = x + 0.05f;
        k = k + 0.0001f;
    }
    float r1;
    float x2_cpy = x2;
    float y_cer;
    k = k - 0.0001f;
    y = y + (k) * (k);
    x2 = x2 + 0.05f;
    x = x - 0.05f;
    r1 = 500.0f - x2;
    while (ceilf(x2 * 100)!= ceilf(x * 100))
    {
        x2 += 0.001f;
        my_mlx_pixel_put(x2, sqrt(r1 * r1 - pow(x2 - 500, 2)) / 6 + 100, 0xFFFFFF, data, size_line);
        my_mlx_pixel_put(x2, -sqrt(r1 * r1 - pow(x2 - 500, 2)) / 6 + 100, 0xFFFFFF, data, size_line);
        if (ceilf(x2 * 100) / 100 == 500)
                y_cer = sqrt(r1 * r1 - pow(x2 - 500, 2)) / 6 + 100;
    }
    printf("%f\n", y_cer);
    x2 = x2_cpy;
    // while (y_cer < 999)
    // {
    //      my_mlx_pixel_put(500, y_cer, 16777215, data, size_line);
    //      y_cer += 0.1f;
    // }
    // while ()

    mlx_put_image_to_window(mlx, mlx_win, image, 0, 0);
    i = 400;
    
     
    
    // while (i < h)
    // {
    //     j = 400;
    //     while (j < k)
    //     {
    //         mlx_pixel_put (mlx, mlx_win, i, j, 0xFF0000);
    //         j = j + 1;
    //     }
    //     i = i + 1;
    //     k--;
    // }
    // i = 400;
    // k = 400;
    // while (i < 600)
    // {
    //     j = 400;
    //     while (j > k - (i - 400) && j > k)
    //     {
    //         if (j == 400 || j == 399)
    //             mlx_pixel_put (mlx, mlx_win, i, j, 0x0000FF);
    //         else
    //             mlx_pixel_put (mlx, mlx_win, i, j, 0xFF0000);
    //         j = j - 1;
    //     }
    //     i = i + 1;
    //     k--;
    // }
mlx_hook(mlx_win, 17, 1L << 17, exita, 0);
mlx_hook(mlx_win, 2, 1L << 0, exita, 0);
    mlx_loop(mlx);
    return (0);
}
//-lmlx -framework OpenGL -framework AppKit

