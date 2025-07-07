#include <stdio.h>
#include <dlfcn.h>
#include "calc.h"

void print_menu() 
{
    printf("\nМеню калькулятора:\n");
    printf("1) Сложение\n");
    printf("2) Вычитание\n");
    printf("3) Умножение\n");
    printf("4) Деление\n");
    printf("5) Выход\n");
    printf("Выберите операцию: ");
}

int main() 
{
    void *lib_handle;
    int (*add_ptr)(int, int) = NULL;
    int (*sub_ptr)(int, int) = NULL;
    int (*mul_ptr)(int, int) = NULL;
    int (*div_ptr)(int, int) = NULL;

    lib_handle = dlopen("./libcalc.so", RTLD_LAZY);
    
    add_ptr = dlsym(lib_handle, "add");
    sub_ptr = dlsym(lib_handle, "sub");
    mul_ptr = dlsym(lib_handle, "mul");
    div_ptr = dlsym(lib_handle, "div");

    int choice, a, b, result;

    while (1) 
    {
        print_menu();
        scanf("%d", &choice);

        if (choice == 5) break;

        printf("Введите первое число: ");
        scanf("%d", &a);
        printf("Введите второе число: ");
        scanf("%d", &b);

        switch (choice) 
        {
            case 1: result = add_ptr(a, b); break;
            case 2: result = sub_ptr(a, b); break;
            case 3: result = mul_ptr(a, b); break;
            case 4: result = (b != 0) ? div_ptr(a, b) : 0; break;
            default: printf("Неверный выбор!\n"); continue;
        }

        printf("Результат: %d\n", result);
    }

    dlclose(lib_handle);
    return 0;
}
