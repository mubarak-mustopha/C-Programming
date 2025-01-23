# include <stdio.h>

typedef struct {
    char * brand;
    int model;
} vehicle;

int main(){
    vehicle mycar;
    mycar.brand = "Mercedes Benz";
    mycar.model = 2007;
}