#include <stdio.h>
#include <stdlib.h>

int row01[1]  = { 75 };
int row02[2]  = { 95, 64 };
int row03[3]  = { 17, 47, 82 };
int row04[4]  = { 18, 35, 87, 10 };
int row05[5]  = { 20,  4, 82, 47, 65 };
int row06[6]  = { 19,  1, 23, 75,  3, 34 };
int row07[7]  = { 88,  2, 77, 73,  7, 63, 67 };
int row08[8]  = { 99, 65,  4, 28,  6, 16, 70, 92 };
int row09[9]  = { 41, 41, 26, 56, 83, 40, 80, 70, 33 };
int row10[10] = { 41, 48, 72, 33, 47, 32, 37, 16, 94, 29 };
int row11[11] = { 53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14 };
int row12[12] = { 70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57 };
int row13[13] = { 91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48 };
int row14[14] = { 63, 66,  4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31 };
int row15[15] = {  4, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60,  4, 23 };
int* triangle[15] = { row01, row02, row03, row04, row05,
                      row06, row07, row08, row09, row10,
                      row11, row12, row13, row14, row15 };

int path01[1]; 
int path02[2]; 
int path03[3]; 
int path04[4]; 
int path05[5]; 
int path06[6]; 
int path07[7]; 
int path08[8]; 
int path09[9]; 
int path10[10];
int path11[11];
int path12[12];
int path13[13];
int path14[14];
int path15[15];
int* paths[15] = { path01, path02, path03, path04, path05,
                   path06, path07, path08, path09, path10,
                   path11, path12, path13, path14, path15 };

int main (int argc, char* argv[]) {
    paths[0][0] = triangle[0][0];
    for (int i = 1; i < 15; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0)
                paths[i][j] = triangle[i][j] + paths[i - 1][j];
            else if (j == i)
                paths[i][j] = triangle[i][j] + paths[i - 1][j - 1];
            else {
                int left = paths[i - 1][j - 1];
                int right = paths[i - 1][j];
                if (left > right)
                    paths[i][j] = triangle[i][j] + left;
                else
                    paths[i][j] = triangle[i][j] + right;
            }
        }
    }

    printf("Triangle of Path Sums:\n");
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", paths[i][j]);
        }
        printf("\n");
    }

    int max_path_sum = 0;
    for (int i = 0; i < 15; i++) {
        if (paths[14][i] > max_path_sum)
            max_path_sum = paths[14][i];
    }
    printf("Maximum Path Sum: %d\n", max_path_sum);
}
