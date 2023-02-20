#include <stdio.h>

int main() {

    int score = 0;
    

    do {
        
        printf("Enter 0 or 1 to STOP \n");
        
        
            printf("Enter the NFL score: ");
            scanf("%d", &score);

            int safety = 2;
            int fg = 3;
            int td_0 = 6;
            int td_1 = 7;
            int td_2 = 8;

            for (int i = 0; i <= score; i++) {
                for (int j = 0; j <= score; j++) {
                    for (int k = 0; k <= score; k++) {
                        for (int l = 0; l <= score; l++) {
                            for (int m = 0; m <= score; m++) {
                                if (i * safety + j * fg + k * td_0 + l * td_1 + m * td_2 == score) {
                                    printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", m, l, k, j, i);
                                }
                            }
                        }
                    }
                }
            }
        }
     while (score != 0 && score != 1);
    return(0);
}
