#include <stdio.h>
#include <string.h>

// Define maximum menu items and orders
#define MAX_MENU 10
#define MAX_ORDER 20

// Structure to hold menu items
typedef struct {
    char name[50];
    float price;
} Menu;

// Structure to hold orders
typedef struct {
    char name[50];
    int qty;
    float total;
} Order;

// Function to display the menu
void showMenu(Menu menu[], int menuCount) {
    printf("\n--- Menu ---\n");
    for (int i = 0; i < menuCount; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
}

// Function to take an order
int takeOrder(Menu menu[], int menuCount, Order orders[], int *orderCount) {
    int itemNum, qty;
    printf("\nEnter the menu item number: ");
    scanf("%d", &itemNum);

    if (itemNum < 1 || itemNum > menuCount) {
        printf("Invalid item number! Please try again.\n");
        return 0;
    }

    printf("Enter the quantity: ");
    scanf("%d", &qty);

    if (qty <= 0) {
        printf("Invalid quantity! Please try again.\n");
        return 0;
    }

    // Add the order
    strcpy(orders[*orderCount].name, menu[itemNum - 1].name);
    orders[*orderCount].qty = qty;
    orders[*orderCount].total = menu[itemNum - 1].price * qty;
    (*orderCount)++;

    printf("Order added: %s x %d - $%.2f\n", menu[itemNum - 1].name, qty, orders[*orderCount - 1].total);
    return 1;
}

// Function to calculate the bill
void printBill(Order orders[], int orderCount) {
    float totalBill = 0.0;

    printf("\n--- Bill ---\n");
    for (int i = 0; i < orderCount; i++) {
        printf("%d. %s x %d - $%.2f\n", i + 1, orders[i].name, orders[i].qty, orders[i].total);
        totalBill += orders[i].total;
    }
    printf("\nTotal: $%.2f\n", totalBill);
}

int main() {
    Menu menu[MAX_MENU] = {
        {"Burger", 5.99},
        {"Pizza", 8.99},
        {"Pasta", 7.49},
        {"Fries", 2.99},
        {"Soda", 1.49}
    };
    Order orders[MAX_ORDER];
    int menuCount = 5, orderCount = 0;
    int choice;

    while (1) {
        printf("\n--- Restaurant System ---\n");
        printf("1. Show Menu\n");
        printf("2. Take Order\n");
        printf("3. Print Bill\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                showMenu(menu, menuCount);
                break;
            case 2:
                if (orderCount < MAX_ORDER) {
                    takeOrder(menu, menuCount, orders, &orderCount);
                } else {
                    printf("Order limit reached! Cannot take more orders.\n");
                }
                break;
            case 3:
                printBill(orders, orderCount);
                break;

                
            case 4:
                printf("Exiting the system. Thank you!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
