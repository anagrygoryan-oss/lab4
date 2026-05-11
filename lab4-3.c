#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> // Потрібно для функції abs()

int main() {
    int n, choice;
    srand(time(NULL));

    while (1) {
        printf("\n--ГОЛОВНЕ МЕНЮ--\n");
        printf("1. Ввести масив з клавіатури (Варіант А)\n");
        printf("2. Заповнити масив випадково [-100; 100] (Варіант Б)\n");
        printf("0. Вихід з програми\n");
        printf("Ваш вибір: ");
        scanf("%d", &choice);

        if (choice == 0) break;
        if (choice < 1 || choice > 2) {
            printf("Невірний вибір!\n");
            continue;
        }

        printf("Введіть кількість елементів n: ");
        scanf("%d", &n);

        int a[n];
        switch (choice) {
            case 1:
                printf("Введіть %d елементів масиву:\n", n);
                for (int i = 0; i < n; i++) {
                    printf("a[%d]=", i);
                    scanf("%d", &a[i]);
                }
                break;
            case 2:
                printf("Згенерований масив: ");
                for (int i = 0; i < n; i++) {
                    a[i] = rand() % 201 - 100;
                    printf("%d ", a[i]);
                }
                printf("\n");
                break;
        }

        // 1) Визначення максимального за модулем елемента
        int max_mod = a[0];
        for (int i = 1; i < n; i++) {
            if (abs(a[i]) > abs(max_mod)) {
                max_mod = a[i];
            }
        }

        // 2) Сума елементів після останнього нульового елемента
        int last_zero_index = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                last_zero_index = i;
            }
        }

        int sum = 0;
        if (last_zero_index != -1) {
            for (int i = last_zero_index + 1; i < n; i++) {
                sum += a[i];
            }
            printf("\nМаксимальний за модулем елемент: %d (модуль: %d)\n", max_mod, abs(max_mod));
            printf("Сума після останнього нуля: %d\n", sum);
        } else {
            printf("\nМаксимальний за модулем елемент: %d\n", max_mod);
            printf("Нульових елементів не знайдено, суму не обчислено.\n");
        }
    }

    printf("Програму завершено.\n");
    return 0;
}