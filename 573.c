#include <stdio.h>
int main ()
{
    double H, U, D, F, fin, up;
    int i;

    while (1)
    {
        fin = 0;
        scanf("%lf %lf %lf %lf", &H, &U, &D, &F);
        if (H == 0)
            break;
        for (i = 1; ; i++)
        {
            up = U - F*U*(i-1)/100;
            if (up > 0)
                fin = fin + up;
            else fin = fin;

            if (fin > H)
            {
                printf("success on day %d\n", i);
                break;
            }


            fin = fin - D;

            if (fin < 0)
            {
                printf("failure on day %d\n", i);
                break;
            }

        }
    }
}
