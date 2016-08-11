#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

long long int powerModule( long long int base,
						long long int exponent,
						long long int module)
{
    long long int result = 1;
    while (exponent != 0)
        if (exponent % 2 == 1)
        {
            result = (result * base) % module;
            exponent--;
        }
        else
        {
            base = (base * base) % module;
            exponent /= 2;
        }
    return result;
}

int get_rest_size(char* str)
{
	long long int x = 7, y = 42857146, field = 100000007;
	int len = strlen(str);
	int result = 0;

	int iter = 0;
    long long int x_cur = 1;
    long long int y_cur = 1;
    long long int hash_begin = str[0];
    long long int hash_end = str[len - 1];
    while (iter < len - 1)
	{
		if (hash_begin == (hash_end * x_cur) % field)
			result = iter + 1;
		x_cur *= x;
		x_cur %= field;
		y_cur *= y;
		y_cur %= field;
		iter++;
		hash_begin += x_cur * str[iter];
		hash_end += y_cur * str[len - 1 - iter];
		hash_begin %= field;
		hash_end %= field;
	}
	return result;
}

int main(void)
{
	char* str = (char*) calloc (50001, sizeof(char));
	scanf("%50001s", str);
	printf("%d\n", strlen(str) - get_rest_size(str));


	return 0;
}
