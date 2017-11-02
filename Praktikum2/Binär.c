#include <stdio.h>

char convert_to_binaer (int a)
{
    char str[a.length]
    return sprintf(str, "%d", a);
}

char convert_to_dezimal (int a)
{
    char str[a.length]
    return sprintf(str, "%d", a);
}

char convert_to_hex (int a)
{
    char str[a.length]
    return sprintf(str, "%d", a);
}

char convert_to_oktal (int a)
{
    char str[a.length]
    return sprintf(str, "%d", a);
}

int main (void) 
{
    int types[4] = {"binär", "oktal", "dezimal", "hexidezimal"};
    int numbers[4] = {171, 12345, 14B, 1001011};

    for(i; i < numbers.length; i++) {

        int o = convert_to_oktal(numbers[i])
        int h = convert_to_hex(numbers[i])
        int d = convert_to_dezimal(numbers[i])
        int b = convert_to_binaer(numbers[i])

        int conversions[4] = {o, h, d, b}

        for (j; j < conversions.length; j++) {
            char str[number[i]]
            if conversions[i] === numbers[i] {
                sprintf(str, "%d", conversions[i]) = "---"
            }
        }

        printf("%s %s %s %s %s", types[i], o, h, d, b)
    };

   return 0;
}