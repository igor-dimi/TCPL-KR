#include <stdio.h>

//
// Created by igor on 25.12.19.
//

/*fahrenheit to celsius conversion formula*/
double f_to_c(double fahr){
    return (fahr - 32.0) * (5.0/9.0);
}

/*celsius to fahrenheit conversion formual*/
double c_to_f(double cels){
    return (cels * (9.0 / 5.0) + 32.0);
}

/*prints a table of conversion between fahrenheit and celsius values, interval specified by MIN and MAx, resolution specified by STEP */
void fctable(double MIN, double MAX, double STEP){
    double fahr;
    fahr = MIN;

    printf("%10s\t%10s\n", "FAHRENHEIT", "CELSIUS" );

    while(fahr <= MAX){
        printf("%10.2f\t%10.2f\n", fahr, f_to_c(fahr));
        fahr += STEP;
    }
}

void cftable(double MIN, double MAX, double STEP){

    double cels;

    printf("%10s\t%10s\n", "CELSIUS", "FAHRENHEIT" );
    for(cels = MIN; cels <= MAX; cels += STEP){
        printf("%10.2f\t%10.2f\n", cels, c_to_f(cels));
    }
}

int main(){

    /*Print header and menu*/
    printf("FCTABLE: a Fahrenheit - Celsius Table Printing Utility\n\n");
    printf("[1] Enter the temperature interval\n");
    printf("[2] Show the temperature interval\n");
    printf("[3] Print the table\n");
    printf("[4] Exit\n\n");

    int menu_option = -1;
    double MIN, MAX, STEP;
    int interval_set = 0;
    char temp_option = 'x' ;


    do{

        printf("Choose an option from the menu above: ");
        scanf("%d", &menu_option);

        switch(menu_option){

            case 1 :

                do{
                    printf("Enter temperature type; 'F' for fahrenheit or 'C' for Celsius:\n");
                    scanf("%c", &temp_option);
                    scanf("%c", &temp_option);

                    if(!(temp_option == 'c' || temp_option == 'C' || temp_option == 'F' || temp_option == 'f')){
                        printf("---ERROR: invalid temperature option\n");
                    }else{
                        break;
                    }

                }while(!(temp_option == 'c' || temp_option == 'C' || temp_option == 'F' || temp_option == 'f'));

              /*  scanf("%c", &temp_option);
                printf("------2) temperature option is: %c\n", temp_option);

                while(!(temp_option == 'c' || temp_option == 'C' || temp_option == 'F' || temp_option == 'f')){
                    printf("---ERROR: invalid temperature option --> please enter only 'F' or 'C': ");
                    scanf("%c", &temp_option);
                }*/

                if(temp_option == 'F' || temp_option == 'f'){
                    do{

                        printf("Enter the lower bound in Fahrenheit: ");
                        scanf("%lf", &MIN);

                        if(MIN < -459.7){
                            printf("---ERROR: lower bound can not be less than absolute zero (-459.7 F)\n");
                        }else{
                            break;
                        }

                    } while(MIN < -459.7);

                    printf("Enter the upper bound in Fahrenheit: ");
                    scanf("%lf", &MAX);


                }else{
                    printf("Enter the lower bound in Celsius: ");
                    scanf("%lf", &MIN);
                    while(MIN < -273.15){
                        printf("---ERROR: lower bound for temperature cannot be less than the absolute zero (-273.15 C)\n");
                        printf("re-enter the lower bound in Celsius: ");
                        scanf("%lf", &MIN );
                    }

                    printf("Enter the upper bound in Celsius: ");
                    scanf("%lf", &MAX);

                }

                /*swap MIN and MAX if user has confused the lower and upper bounds*/
                if(MAX < MIN){
                    double temp = MAX;
                    MAX = MIN;
                    MIN = temp;
                }


                printf("Enter the resolution, i.e. the temperature interval between consecutive temperature values: ");
                scanf("%lf", &STEP);

                while(STEP <= 0 || STEP > (MAX - MIN)){
                    if(STEP <= 0){
                        printf("---ERROR: step must be a positive number\n");
                    }else{
                        printf("---ERROR: resolution must not be greater than the interval\n");
                    }

                    printf("please re-enter the temperature interval: ");
                    scanf("%lf", &STEP);
                }

                interval_set = 1;

                break;

            case 2 :

                if(!interval_set){
                    printf("---ERROR: you must first set the interval --> [1]\n");
                }else{

                    if(temp_option == 'f' || temp_option == 'F'){
                    printf("lower temperature bound: %lf F\n", MIN);
                    printf("upper temperature bound: %lf F\n", MAX);

                    }else{
                        printf("lower temperature bound: %lf C\n", MIN);
                        printf("upper temperature bound: %lf C\n", MAX);
                    }
                }

                break;


            case 3 :

                if(!interval_set){
                    printf("---ERROR: you must first set the temperature interval --> [1]\n");
                }else{
                    if(temp_option == 'f' || temp_option == 'F'){
                        fctable(MIN, MAX, STEP);
                    }else{
                        cftable(MIN, MAX, STEP);
                    }
                }

                break;

            case 4 :
                printf("Bye!\n");
                break;

            default : printf("---ERROR: Invalid menu option!\n");

        }

    }while(menu_option != 4);


    return 0;
}

