# include <stdio.h>
# include <stdlib.h>
# include <math.h>

void modifyValue() {
    int x;

    printf("Enter a number: ");
    scanf("%d", &x);

    if (x >= 10){ 
        x += 100;
    }else {
        x -= 50;
    }

    printf("%d\n", x);
}

void bursary(){
    int level;
    float bursary = 0.0;

    printf("Enter your level (100, 200, 300, 400): ");
    scanf("%d", &level);

    switch(level) {
        case 100:
            bursary = 5000.0;
            printf("First year student: Bursary awarded is %.2f\n", bursary); 
            break;

        case 200:
            bursary = 7500.0;
            printf("Second year student: Bursary awarded is %.2f\n", bursary); 
            break;  
            
        case 300:
            bursary = 10000.0;
            printf("Third year student: Bursary awarded is %.2f\n", bursary); 
            break;   
            
        case 400:
            bursary = 12500.0;
            printf("Fourth year student: Bursary awarded is %.2f\n", bursary); 
            break;  
            
        default:
            printf("Null year student: Bursary awarded is %.2f\n", bursary); 
            break;       
    }
}

void print_avg(){
    int i = 0, size = 5;
    float num, sum = 0.0;

    for (i = 0; i < size;i++ ){
        printf("%d: Enter number: ", i);
        scanf("%f", &num);

        sum += num;
    }

    printf("Average is %.2f\n", sum / size);
}

void populate(int arr[], int size, int max){
    int i, num;

    for (i = 0; i < size; i++){
        num = rand() % max;
        arr[i] = num;
    }
}

void print_divisible(int nums[],int size,int divisor){
    if (divisor == 0){
        printf("Can't divide by 0");
        return;
    }

    int i;
    for (i = 0; i < size; i++){
        if (nums[i] % divisor == 0){
            printf("%d\n", nums[i]);
        }
    }
}

int main(){// modifyValue();
    int size = 500, max = 1000;
    int nums[size];

    populate(nums, size, 1000);
    print_divisible(nums, size, 6);

}