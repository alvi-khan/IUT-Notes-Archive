#include<stdio.h>

struct ing_list             //structure for ingredients
{
    char name[100];
    int code;
    float price_per_gram;
    char details[100];
};

struct item                 //structure for food item
{
    char name[100];
    int code;
    struct ing_list *ptr[7];
    float ingredient_amount[7];
    float price;
};

int main()
{
    //the following is a list of available ingredients
    //only the names of the ingredients are given for now
    struct ing_list chicken_meat = {"Chicken Meat"};
    struct ing_list mustard = {"Mustard"};
    struct ing_list lettuce = {"Lettuce"};
    struct ing_list bread_flour = {"Bread/Flour"};
    struct ing_list onions = {"Onions"};
    struct ing_list cucumber = {"Cucumber"};
    struct ing_list tomato = {"Tomato"};

    //these are details of the food item
    struct item chicken_burger ={"Chicken Burger"};
    chicken_burger.code = 100239;
    chicken_burger.price = 200.00;

    //these are details of the ingredients of the food item
    //the structure of the food item contains two arrays
    //the first is an array of pointers, where each pointer points to a separate ingredient
    //the next array is an array of the amounts of each ingredient
    //just changing what each pointer points to will change the ingredients of the food item
    chicken_burger.ptr[0] = &chicken_meat;
    chicken_burger.ingredient_amount[0] = 200.00;
    chicken_burger.ptr[1] = &mustard;
    chicken_burger.ingredient_amount[1] = 20.00;
    chicken_burger.ptr[2] = &lettuce;
    chicken_burger.ingredient_amount[2] = 10.00;
    chicken_burger.ptr[3] = &bread_flour;
    chicken_burger.ingredient_amount[3] = 100.00;
    chicken_burger.ptr[4] = &onions;
    chicken_burger.ingredient_amount[4] = 20.00;
    chicken_burger.ptr[5] = &cucumber;
    chicken_burger.ingredient_amount[5] = 10.00;
    chicken_burger.ptr[6] = &tomato;
    chicken_burger.ingredient_amount[6] = 10.00;

    int i;
    printf("Name: %s\nCode: %d\nIngredient List:\n", chicken_burger.name, chicken_burger.code);
    for(i=0; i<7; i++)  printf("->%s %0.2fgm\n", chicken_burger.ptr[i]->name, chicken_burger.ingredient_amount[i]);
    printf("Price: %0.2f BDT", chicken_burger.price);
}
