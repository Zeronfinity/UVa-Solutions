#include <stdio.h>

int main()
{
    char card[13][3];
    int i, point, temp, j, Scount, Hcount, Dcount, Ccount, Sstop, Hstop, Dstop, Cstop, ntpoint;
    while(scanf("%s", card[0]) != EOF)
    {
        for (i = 1; i < 13; i++)
            scanf(" %s", card[i]);
        point = 0, Scount = 0, Hcount = 0, Dcount = 0, Ccount = 0, Sstop = 0, Hstop = 0, Dstop = 0, Cstop = 0, ntpoint = 0, temp = 0;
        for (i = 0; i < 13; i++)
        {
            temp = 0;
            switch(card[i][0])
            {
            case 'A':
                point += 4;
                switch (card[i][1])
                {
                case 'S':
                    Sstop = 1;
                    break;
                case 'H':
                    Hstop = 1;
                    break;
                case 'D':
                    Dstop = 1;
                    break;
                case 'C':
                    Cstop = 1;
                    break;
                }
                break;
            case 'K':
                point += 3;
                for (j = 0; j < 13; j++)
                    if (card[j][1] == card[i][1])
                        temp++;
                if (temp <= 1)
                {
                    point--;
                }
                if (temp >= 2)
                    switch (card[i][1])
                    {
                    case 'S':
                        Sstop = 1;
                        break;
                    case 'H':
                        Hstop = 1;
                        break;
                    case 'D':
                        Dstop = 1;
                        break;
                    case 'C':
                        Cstop = 1;
                        break;
                    }
                temp = 0;
                break;
            case 'Q':
                point += 2;
                for (j = 0; j < 13; j++)
                    if (card[j][1] == card[i][1])
                        temp++;
                if (temp <= 2)
                {
                    point--;
                }
                if (temp >= 3)
                    switch (card[i][1])
                    {
                    case 'S':
                        Sstop = 1;
                        break;
                    case 'H':
                        Hstop = 1;
                        break;
                    case 'D':
                        Dstop = 1;
                        break;
                    case 'C':
                        Cstop = 1;
                        break;
                    }
                    temp = 0;
                break;
            case 'J':
                point += 1;
                for (j = 0; j < 13; j++)
                    if (card[j][1] == card[i][1])
                        temp++;
                if (temp <= 3)
                {
                    point--;
                }
                temp = 0;
                break;
            }
            switch (card[i][1])
            {
            case 'S':
                Scount++;
                break;
            case 'H':
                Hcount++;
                break;
            case 'D':
                Dcount++;
                break;
            case 'C':
                Ccount++;
                break;
            }
        }
        ntpoint = point;
        switch (Scount)
        {
        case 2:
            point++;
            break;
        case 1:
            point += 2;
            break;
        case 0:
            point += 2;
            break;
        }
        switch (Hcount)
        {
        case 2:
            point++;
            break;
        case 1:
            point += 2;
            break;
        case 0:
            point += 2;
            break;
        }
        switch (Dcount)
        {
        case 2:
            point++;
            break;
        case 1:
            point += 2;
            break;
        case 0:
            point += 2;
            break;
        }
        switch (Ccount)
        {
        case 2:
            point++;
            break;
        case 1:
            point += 2;
            break;
        case 0:
            point += 2;
            break;
        }
        if (point < 14)
        {
            printf("PASS\n");
            continue;
        }
        if (ntpoint >= 16 && Sstop == 1 && Hstop == 1 && Dstop == 1 && Cstop == 1)
        {
            printf("BID NO-TRUMP\n");
            continue;
        }
        if (point >= 14)
        {
            if (Scount >= Hcount && Scount >= Dcount && Scount >= Ccount)
            {
                printf("BID S\n");
                continue;
            }
            if (Hcount >= Dcount && Hcount >= Ccount)
            {
                printf("BID H\n");
                continue;
            }
            if (Dcount >= Ccount)
            {
                printf("BID D\n");
                continue;
            }
            printf("BID C\n");
        }
    }
return 0;
}
