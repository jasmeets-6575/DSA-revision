#include <stdio.h>
#include <string.h>

int main() {
    int r;
    char s[] = "finding";
    int H[26];
    int i;
    char temp;
    
    for (i = 0; s[i]!='\0'; i++)          
    {
        H[s[i] - 97] += 1;
    }
    for(i =0; i<26; i++)
    {
        if(H[i] > 1)
        {
            printf("%c", i+97);
            printf("%d", H[i]);
        }
    }

    return 0;
}