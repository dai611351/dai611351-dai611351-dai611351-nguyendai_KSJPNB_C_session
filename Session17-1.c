#include <stdio.h>
#include <stdlib.h>

void inputArray(int **arr, int *size) {
    printf("Nhap so phan tu: ");
    scanf("%d", size);

    *arr = (int *)malloc(*size * sizeof(int));
    if (*arr == NULL) {
        printf("Khong the cap phat bo nho!\n");
        return;
    }

    printf("Nhap %d phan tu:\n", *size);
    for (int i = 0; i < *size; i++) {
        printf("Phan tu %d: ", i + 1);
        scanf("%d", &((*arr)[i]));
    }
}

void displayArray(int *arr, int size) {
    if (arr == NULL || size == 0) {
        printf("Mang rong!\n");
        return;
    }
    printf("Cac phan tu trong mang: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int arraySum(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int maxElement(int *arr, int size) {
    if (size == 0) return 0;
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int *arr = NULL;
    int size = 0;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. Hien thi cac phan tu trong mang\n");
        printf("3. Tinh do dai mang\n");
        printf("4. Tinh tong cac phan tu trong mang\n");
        printf("5. Hien thi phan tu lon nhat\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputArray(&arr, &size);
                break;
            case 2:
                displayArray(arr, size);
                break;
            case 3:
                printf("Do dai mang: %d\n", size);
                break;
            case 4:
                printf("Tong cac phan tu trong mang: %d\n", arraySum(arr, size));
                break;
            case 5:
                printf("Phan tu lon nhat: %d\n", maxElement(arr, size));
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai!\n");
        }
    } while (choice != 6);

    free(arr);
    return 0;
}

