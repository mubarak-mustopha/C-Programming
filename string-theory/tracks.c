# include <stdio.h>
# include <string.h>

char tracks[][80] = {
    "I left my heart in Harvard Med School",
    "Newark, Newark - a wonderful town",
    "Dancing with a Dork",
    "From here to maternity",
    "The girl from Iwo Jima",
};


void find_track(char search_for[]){
    int i;
    for (i = 0; i < 5; i++){
        if(strstr(tracks[i], search_for)) 
            printf("Track %i: '%s'\n", i, tracks[i]);
    }
}

int main(){
    // printf("strlen: %li\n", strlen(tracks[2]));
    // printf("sizeof: %li\n", sizeof(tracks[2]));

    char search_for[80];

    printf("Search for: ");
    fgets(search_for, 80, stdin);
    // scanf("%79s", search_for);

    find_track(search_for);
    return 0;
}