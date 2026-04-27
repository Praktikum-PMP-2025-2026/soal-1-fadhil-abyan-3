/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : Structures and Dynamic Arrays
 *   Hari dan Tanggal    : Senin, 27 April 2026
 *   Nama (NIM)          : Muhammad Fadhil Abyan (13224008)
 *   Nama File           : soal1.c
 *   Deskripsi           : Terdapat suatu array dinamis yang menampung pembacaan input data. 
                           Kemudian, array dinamis tersebut diurutkan dari besar ke kecil dan dihitung mediannya.
 */


#include <stdio.h>
#include <stdlib.h>
#define INIT_CAP 4
#define INCREMENT 2

void sortArray(int* arr, int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1-i; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

float median(int* arr, int n){
    float hasil = 0;
    if (n % 2 == 0){
        hasil = (float) (arr[n/2 -1] + arr[n/2])/2.0;
    
    }
    else{
        hasil = arr[n/2];
    }
    return hasil;
}

void printArray(int* arr, int n){
    printf("SORTED ");
    for(int i = 0; i < n; i++){
        printf("%d", arr[i]);
        if(i != n-1){
            printf(" ");
        }
    }
    printf(" ");
}
  
 int main(){
    int kapasitas = INIT_CAP;
    int* data = (int*)malloc(sizeof(int)*kapasitas);
    
    if(data == NULL){
        printf("Alokasi memori gagal\n");
        return 1;
    }

    int count = 0;
    int temp = 0;

    while(temp != -1){
        scanf("%d", &temp);
        if(temp != -1){
            data[count] = temp;
            count++;

            if(kapasitas == count){
                int kapasitas_baru = kapasitas * INCREMENT;
                data = (int*)realloc(data, sizeof(int) * kapasitas_baru);

                if(data == NULL){
                    printf("Alokasi memori gagal\n");
                    return 1;
                }
                kapasitas = kapasitas_baru;
            }
        }
    }
    
    if(count != 0){
        sortArray(data, count);
        float med = median(data, count);
        printf("COUNT %d ", count);
        printArray(data, count);
        if (count % 2 == 0){
            printf("MEDIAN %.2f", med);
        }
        else{
            printf("MEDIAN %d", (int)med);
        }
    }else{
        return 1;
    }

    

    return 0;
 }
 
