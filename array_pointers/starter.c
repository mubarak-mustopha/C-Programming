#include <stdio.h>

int main(){
    char vowels[] = {'A', 'B', 'C', 'D', 'E'};
    char * pvowels = vowels; 
    int i;

    for (i = 0; i < 5; i++){
        printf("&vowel[%d]: %p, pvowels + %d: %p, vowels + %d: %p\n", i, &vowels[0], i, pvowels + i, i, vowels + i);
    }

    for (i = 0; i < 5; i++){
        printf("vowels[%d]: %c, *(pvowels + %d):%c,*(vowels + %d):%c\n",i, vowels[i], i, *(pvowels + i), i, *(vowels + i));
    }

    for (i = 0; i < 5; i++){
        printf("%c == %c\n", pvowels[i], *(pvowels + i));
    }
}