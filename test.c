#include <stdio.h>
#include <string.h>
#include "animal.h"
#include "dog.h"
#include "util.h"
#include "cat.h"
#include "parrot.h"



int main(){
    const char* type = "dog";
    const char* name = "fido";

    // animal a = (animal)malloc(sizeof(struct dog_t));

    // a->name = (const char*)malloc(MAX_SIZE * sizeof(const char));
    // strcpy(a->name, name);

    // a->animal_get_name = animal_get_name;    
    // a->animal_get_type = animal_get_type;
    
    // dog d = dog_create(a);
    
    animal a = animal_create(type,name);
    dog d = (dog)a;
    
    // printf("\n no of commands : %d",(d->no_of_commands));
    // printf("\n to master : %d",(d->master));
    
    // printf("\nmagic: %s",(const char*)(animal_command(a,"magic")));
    // animal_train(a,"sit","sits");
    // animal_train(a,"sit","sits");
    // // animal_train(a,"sit","sits");
    // animal_train(a,"sit","mazak");

    // print("commands",d->commands, d->no_of_commands);
	// print("responses",d->responses,d->no_of_commands);
	// printi("mastery",d->mastery,d->no_of_commands);
    // animal_train(a,"bark","bhaunk");

    // print("commands",d->commands,d->no_of_commands);
	// print("responses",d->responses,d->no_of_commands);
	// printi("mastery",d->mastery,d->no_of_commands);
    // animal_train(a,"bark","bhaunk");

    // print("commands",d->commands,d->no_of_commands);
	// print("responses",d->responses,d->no_of_commands);
	// printi("mastery",d->mastery,d->no_of_commands);
    // animal_train(a,"bark","bhaunk");

    // print("commands",d->commands,d->no_of_commands);
	// print("responses",d->responses,d->no_of_commands);
	// printi("mastery",d->mastery,d->no_of_commands);
    // animal_train(a,"bark","bhajaak");

    // printf("\nbark: %s",animal_command(a,"bark"));
    // printf("\nsit: %s",animal_command(a,"sit"));
    // printf("\nmagic: %s",(const char*)(animal_command(a,"magic")));
    

    // animal tuna = animal_create("cat","tuna");
    // printf("\n %s", animal_command(tuna, "something"));
    
    // int weights[] = {2, 4, 6};
    // int n = sizeof(weights) / sizeof(weights[0]);
    // int random_index = weighted_random(weights, n);
    // printf("Random Index: %d\n", random_index);

    // printf("\n%lf", generate_random_decimal(0, 1));
    
    animal pp = animal_create("parrot","par");
    parrot p = (parrot)pp;

    print("commands",p->commands,p->no_of_commands);
	print("responses",p->responses,p->no_of_commands);
	printfl("mastery",p->mastery,p->no_of_commands);
    printf("no of commands : %d",(p->no_of_commands));
    printf("not master : %f",(p->not_master));

    animal_train(pp,"talk","blab");

    print("commands",p->commands,p->no_of_commands);
	print("responses",p->responses,p->no_of_commands);
	printfl("mastery",p->mastery,p->no_of_commands);
    printf("no of commands : %f",(p->no_of_commands));
    printf("not master : %f",(p->not_master));

    animal_train(pp,"talk","blab");

    print("commands",p->commands,p->no_of_commands);
	print("responses",p->responses,p->no_of_commands);
	printfl("mastery",p->mastery,p->no_of_commands);
    printf("no of commands : %f",(p->no_of_commands));
    printf("not master : %f",(p->not_master));

    animal_train(pp,"talk","blab");

    print("commands",p->commands,p->no_of_commands);
	print("responses",p->responses,p->no_of_commands);
	printfl("mastery",p->mastery,p->no_of_commands);
    printf("no of commands : %f",(p->no_of_commands));
    printf("not master : %f",(p->not_master));

    printf("\nbark: %s",animal_command(pp,"bark"));
    printf("\ntalk: %s",animal_command(pp,"talk"));
    

    return 0;
}