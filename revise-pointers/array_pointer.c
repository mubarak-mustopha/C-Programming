# include <stdio.h>
# include <stdlib.h>

int main(){
    char vowels[] = {'A', 'E', 'I', 'O', 'U'};
    char *pvowels = vowels; 

    int i;
    for (i = 0; i < 5; i++){
        printf("%p %p %p\n", &vowels[i], (vowels + i), (pvowels + i));
    }

    for (i = 0;i < 5; i++){
        printf("%c %c %c\n", vowels[i], *(vowels + i), *(pvowels + i));
    }
}