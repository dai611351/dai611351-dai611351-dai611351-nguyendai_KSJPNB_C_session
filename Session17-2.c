#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inputString(char **str) {
    char userInput[1000];  // Ğ?i tên buffer thành userInput
    printf("Nhap chuoi: ");
    getchar(); // Loai bo ky tu \n con lai tu lenh truoc
    fgets(userInput, sizeof(userInput), stdin);
    userInput[strcspn(userInput, "\n")] = '\0'; // Loai bo ky tu xuong dong

    free(*str); // Giai phong bo nho cu neu co
    *str = (char *)malloc((strlen(userInput) + 1) * sizeof(char)); // Cap phat bo nho cho chuoi moi
    if (*str == NULL) {
        printf("Khong the cap phat bo nho!\n");
        return;
    }
    strcpy(*str, userInput); // Sao chep chuoi moi vao *str
}

void displayString(char *str) {
    printf("Chuoi da nhap: %s\n", str ? str : "(rong)");
}

void countLetters(char *str) {
    if (!str) {
        printf("Chuoi rong!\n");
        return;
    }

    int letters = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
            letters++;
    }
    printf("So luong chu cai: %d\n", letters);
}

void countDigits(char *str) {
    if (!str) {
        printf("Chuoi rong!\n");
        return;
    }

    int digits = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9')
            digits++;
    }
    printf("So luong chu so: %d\n", digits);
}

void countSpecialCharacters(char *str) {
    if (!str) {
        printf("Chuoi rong!\n");
        return;
    }

    int specials = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && 
            !((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9')))
            specials++;
    }
    printf("So luong ky tu dac biet: %d\n", specials);
}

int main() {
    char *str = NULL;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Dem so luong chu cai\n");
        printf("4. Dem so luong chu so\n");
        printf("5. Dem so luong ky tu dac biet\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputString(&str);
                break;
            case 2:
                displayString(str);
                break;
            case 3:
                countLetters(str);
                break;
            case 4:
                countDigits(str);
                break;
            case 5:
                countSpecialCharacters(str);
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai!\n");
        }
    } while (choice != 6);

    free(str);
    return 0;
}

