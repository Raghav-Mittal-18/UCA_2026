#include <stdio.h>
#include <string.h>

char base64[] =
"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

int main()
{
    char input[1000];

    printf("Enter string: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character
    input[strcspn(input, "\n")] = '\0';

    int len = strlen(input);

    for (int i = 0; i < len; i += 3)
    {
        unsigned int b1 = (unsigned char)input[i];
        unsigned int b2 = (i + 1 < len) ? (unsigned char)input[i + 1] : 0;
        unsigned int b3 = (i + 2 < len) ? (unsigned char)input[i + 2] : 0;

        unsigned int combined = (b1 << 16) | (b2 << 8) | b3;

        // First 6 bits
        printf("%c", base64[(combined >> 18) & 63]);

        // Second 6 bits
        printf("%c", base64[(combined >> 12) & 63]);

        // Third 6 bits
        if (i + 1 < len)
            printf("%c", base64[(combined >> 6) & 63]);
        else
            printf("=");

        // Fourth 6 bits
        if (i + 2 < len)
            printf("%c", base64[combined & 63]);
        else
            printf("=");
    }

    printf("\n");

    return 0;
}
