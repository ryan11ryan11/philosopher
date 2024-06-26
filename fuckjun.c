
#include <stdio.h>

static int min1;
static int min2;

int three_or_two(int number, int count)
{    
    if (number % 3 == 0 && number % 2 == 0)
    {
        three_or_two(number / 3, count + 1);
        three_or_two(number / 2, count + 1);
    }
    else if (number % 3 == 0)
    {
        three_or_two(number / 3, count + 1);
        three_or_two(number - 1, count + 1);
    }
    else if (number % 2 == 0)
    {
        three_or_two(number / 2, count + 1);
        three_or_two(number - 1, count + 1);
    }
    else if (number % 3 != 0 && number % 2 != 0 && number != 1)
        three_or_two(number - 1, count + 1);
    if (number == 1)
    {
        min1 = count;
        min2 = count;
        printf("%d\n", count);
        return (0);
    }
    //printf("number : %d count : %d\n", number, count);
    return (0);
}

int main()
{
    int number;

    scanf("%d", &number);
    three_or_two(number, 0);
    // while (number != 1)
    // {
    //     if (number % 3 == 0)
    //         number = number / 3;
    //     else if (number % 2 == 0)
    //         number = number / 2;
    //     else if (number != 1)
    //         number -- ;
    //     count ++ ;
    // }
    // printf("%d\n",count);
    return 0;
}