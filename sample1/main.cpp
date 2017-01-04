#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <iostream>

int main(){
    int arr[6][6];

    int mask[3][3] =
    {
        {1,1,1},
        {0,1,0},
        {1,1,1}
    };

    for(int arr_i = 0; arr_i < 6; arr_i++){
       for(int arr_j = 0; arr_j < 6; arr_j++){

          scanf("%d",&arr[arr_i][arr_j]);
       }
    }

    int max = -1;

//    int _i, _j;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){

            int total = 0;
            for(int k = 0; k < 3; k++){
                for(int t = 0; t < 3; t++){
                    total  += arr[i + k][j + t] * mask[k][t];
                }
            }

            if(total > max)
            {
                max = total;
//                _i = i;
//                _j = j;
            }
        }
    }


    std::cout << max;
//    for(int i = 0; i < 3; ++i){
//        for(int j = 0; j < 3; ++j){
//            std::cout << arr[i + _i][j + _j] << " ";
//        }
//        std::cout << std::endl;
//    }

    return 0;
}
