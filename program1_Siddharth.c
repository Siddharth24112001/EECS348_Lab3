#include <stdio.h>
#include <math.h>

float average(float array[], int start, int end);

int main() {
    
    FILE *file;
    int count = 0;
    
    char months[12][10] = {"January  ", 
                           "February ",
                           "March    ",
                           "April    ",
                           "May      ",
                           "June     ",
                           "July     ",
                           "August   ",
                           "September",
                           "October  ",
                           "November ",
                           "December "};
    
    
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("error opening file");
        return(1);
    } else {
        while (fscanf(file, "%*s") != EOF) {
            count++;
        }
    }
    float sales[count];
    rewind(file);
    int i = 0;
    while (fscanf(file, "%f", &sales[i]) != EOF) {
        i++;
    }
    fclose(file);

    printf("Monthly sales report for 2022:\n");
    printf("Month\t\tSales\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t$%.2f\n", months[i], sales[i]);

    }

    float max_value = sales[0];
    float min_value = sales[0];

    for (int i = 0; i < count; i++) {
        max_value = fmax(max_value, sales[i]);
        min_value = fmin(min_value, sales[i]);
    }

    printf("\nSales summary:\n");
    printf("Minimum sales:\t%.2f\n", min_value);
    printf("Maximum sales:\t%.2f\n", max_value);

    printf("\nSix-Month Moving Average Report:\n");
   
    int j = 0;
    int k = 5;
    while (j <= 6 && k <= 11) {
        printf("%s-\t%s\t$%.2f\n", months[j], months[k], average(sales, j, k));
        j++;
        k++;
    }

    float sales_htl[count];
    printf("\nSales Report (Highest to Lowest):\n");
    printf("Month\t\tSales\n");
    for (int i = 0; i < count; i++) {
        sales_htl[i] = sales[i];
    }

    for (int i = 0; i < count; i++) {
       for (int j = 0; j < count; j++) {
           if (sales_htl[i] > sales_htl[j]) {
               float temp = sales_htl[i];
               sales_htl[i] = sales_htl[j];
               sales_htl[j] = temp;
           }
        }
    }
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            if (sales_htl[i] == sales[j]) {
                printf("%s\t$%.2f\n", months[j], sales[j]);
            }
        }
    }

    return(0);
}

float average(float array[], int start, int end) {
    float sum = 0.00;
    float avg = 0.00;
    for (int i = start; i <= end; i++) {
        sum += array[i];
    }
    avg = sum / (end - start + 1);
    double rounded = round(avg * 100.0) / 100.0;
    return (rounded);
}
