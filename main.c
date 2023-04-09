#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct SHOP
{
    char name[50];
    char contact[12];
}available_shops[1000];

struct CLOTHING
{
    char name[20];
    char code[5];
    char year[5];
    struct SHOP shop_sold;

    struct PRICE
    {
        char currency[3];
        char amount[10];
    }price;

    union SIZE
    {
        int digit;
        char letter;
        char word[20];
    }size;
    
    int sizetype;
}available_clothing[1000];

int shopCount = 2, clothesCount = 4;

//Function declarations
void showShops();
void showDetails(int shop);
void showClothes(int shop);
void addClothing();


int main() {

    struct SHOP shop_1, shop_2;
    strcpy(shop_1.name, "Vince's Couture");
    strcpy(shop_1.contact, "0541344662");
    strcpy(shop_2.name, "Keyshia's Couture");
    strcpy(shop_2.contact, "0595623451");

    available_shops[0] = shop_1;
    available_shops[1] = shop_2;

    struct CLOTHING item_1, item_2, item_3, item_4;
    //Item 1
    strcpy(item_1.name, "Tank Top");
    strcpy(item_1.code, "hx123");
    strcpy(item_1.year, "2016");
    item_1.shop_sold = shop_1;
    strcpy(item_1.price.currency, "GHC");
    strcpy(item_1.price.amount, "300");
    item_1.sizetype = 2;
    strcpy(item_1.size.word, "Large");
    //Item 2
    strcpy(item_2.name, "Lingerie");
    strcpy(item_2.code, "rt567");
    strcpy(item_2.year, "2019");
    item_2.shop_sold = shop_1;
    strcpy(item_2.price.currency, "USD");
    strcpy(item_2.price.amount, "45");
    item_2.sizetype = 0;
    strcpy(item_2.size.word, "40");
    //Item 3
    strcpy(item_3.name, "Hoodie");
    strcpy(item_3.code, "kt153");
    strcpy(item_3.year, "2010");
    item_3.shop_sold = shop_2;
    strcpy(item_3.price.currency, "GHC");
    strcpy(item_3.price.amount, "30");
    item_3.sizetype = 1;
    strcpy(item_3.size.word, "L");
    //Item 4
    strcpy(item_4.name, "Joggers");
    strcpy(item_4.code, "jcs13");
    strcpy(item_4.year, "2016");
    item_4.shop_sold = shop_2;
    strcpy(item_4.price.currency, "GHC");
    strcpy(item_4.price.amount, "300");
    item_4.sizetype = 2;
    strcpy(item_4.size.word, "Small");

    available_clothing[0] = item_1;
    available_clothing[1] = item_2;
    available_clothing[2] = item_3;
    available_clothing[3] = item_4;

    int looping = 0;
    do {
        printf("CLOTHING MALL\n1. Visit Shop\t2.Add Clothing\t3.Exit\n");
        int option = 0;
        scanf(" %d", &option);
        switch (option) 
        {
        case 1:
            showShops();
            scanf(" %d", &option);
            showDetails(option - 1);
            showClothes(option - 1);
            break;

        case 2:
            addClothing();break;

        case 3: looping = 0; printf("Thanks for shopping ;)"); break;
        
        default:
        printf("Invalid choice\n");break;
        }
    }while (looping > 0);

    return 0;
}

//Function Definitions

//Display available shops
void showShops() {
    printf("\nAVAILABLE SHOPS\n");
    printf("------------------------\n");
    for (int i = 0; i < shopCount; i++)
    {
        printf("%d\t%s\n", i+1, available_shops[i].name);
    }
    printf("\nWhich one would you like to visit?\n\nOption: ");
}

//Show the details of a particular shop
void showDetails(int shop) {
    printf("\n%s\t%s\n", available_shops[shop].name, available_shops[shop].contact);

}

//Display the clothing available in a particular shop
void showClothes(int shop) {
    printf("\nAVAILABLE CLOTHING\n");
    printf("------------------------\n");
    fflush(stdin);
    for (int i = 0; i < clothesCount; i++)
    {
        if (strcmp(available_clothing[i].shop_sold.name,available_shops[shop].name) == 0)
        {
            printf("Item Name: %s\n", available_clothing[i].name);
            printf("Item Code: %s\n", available_clothing[i].code);
            printf("Production Year: %s\n", available_clothing[i].year);
            printf("Price: %s\n", available_clothing[i].price.currency);
            switch (available_clothing[i].sizetype)
            {
            case 0:
                printf("Size: %d\n\n\n",available_clothing[i].size.digit);
                break;

            case 1:
                printf("Size: %c\n\n\n",available_clothing[i].size.letter);
                break;

            case 2:
                printf("Size: %s\n\n\n",available_clothing[i].size.word);
                break;
            
            default:
                break;
            }
        }
        
    }
    
}
//Add a new set of clothing to the app database
void addClothing() {
    printf("How many new items would you like to add?\n");
    int num, size_1, option, sizetype;
    char name[50], code[5], year[4], currency[3], amount[10], size_3[10], size_2;
    fflush(stdin);
    printf("Enter amount: ");
    scanf(" %d", &num);

    for (int i = clothesCount; i < clothesCount + num; i++)
    {
        printf("\nItem Name: ");
        gets(name);
        strcpy(available_clothing[i].name, name);
        fflush(stdin);
        printf("\nItem ID: ");
        gets(code);
        strcpy(available_clothing[i].code, code);
        fflush(stdin);
        printf("\nItem Production Year: ");
        gets(year);
        strcpy(available_clothing[i].year, year);
        fflush(stdin);
        printf("\nPrice (Currency): ");
        gets(currency);
        strcpy(available_clothing[i].price.currency, currency);
        printf("\nPrice (Amount): ");
        gets(amount);
        strcpy(available_clothing[i].price.amount, amount);

        do {printf("\nSizing System:\n1. Digits\n2. Letters\n3. Words\n\nEnter option: ");
            fflush(stdin);
            scanf(" %d", &sizetype);
            available_clothing[i].sizetype = sizetype;
            switch (sizetype)
            {
            case 1:
                printf("\nEnter size: ");
                fflush(stdin);
                scanf(" %d", &size_1);
                available_clothing[i].size.digit = size_1;
                break;

            case 2:
                printf("\nEnter size: ");
                fflush(stdin);
                scanf(" %c", &size_2);
                available_clothing[i].size.letter = size_2;
                break;

            case 3:
                printf("\nEnter size: ");
                fflush(stdin);
                scanf(" %s", &size_3);
                strcpy(available_clothing[i].size.word, size_3);
                break;
            
            default:
                printf("\nPlease enter a valid option");
                break;
        }} 
        while (sizetype > 3 && sizetype < 1);

        printf("\nSelect Shop where item is sold: \n");
        for (int i = 0; i < shopCount; i++)
        {
            printf("\n%d %s\n", i+1, available_shops[i].name);
        }

        do {printf("Select shop: ");
            fflush(stdin);
            scanf(" %d", &option);
            if (option < shopCount + 1) {
                    strcpy(available_clothing[i].shop_sold.name, available_shops[option-1].name);
                }
            else {
                printf("\nPlease enter a valid option");
            }}
        while (option > shopCount && option < 0);
        printf("\nItem successfully added");
    }
    printf("\nClothing Items successfully added");
}