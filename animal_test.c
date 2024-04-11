#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "animal.h"

#define MAX_PETS 100
static animal pets[MAX_PETS];
static int num_pets = 0;


static animal get_pet_by_name(const char* name) {
	int i;
	for(i = 0; i < num_pets; i++) {
		animal a = pets[i];
		if(strcmp(animal_get_name(a), name) == 0)
			return a;
	}
	return NULL;
}

static void cmd_quit(int num, const char* arg1, const char* arg2, const char* arg3) {
	exit(0);
}

static void cmd_adopt(int num, const char* arg1, const char* arg2, const char* arg3) {
	if(num < 3) {
		printf("adopt <type> <name>\n");
		return;
	}

	if(num_pets >= MAX_PETS) {
		printf("You already own %d animals\n", num_pets);
		return;
	}
	
	animal a = get_pet_by_name(arg2);
	if(a != NULL) {
		printf("You already have a %s named %s\n", animal_get_type(a), arg2);
		return;
	}
	
	a = animal_create(arg1, arg2);
	if(a == NULL) {
		printf("Couldn't create %s\n", arg1);
		return;
	}

	pets[num_pets++] = a;
}

static void cmd_train(int num, const char* arg1, const char* arg2, const char* arg3) {
	if(num < 4) {
		printf("train <name> <command> <response>\n");
		return;
	}

	animal a = get_pet_by_name(arg1);
	if(a == NULL) {
		printf("No pet named %s\n", arg1);
		return;
	}
	//----------------------------remove later
	#include "dog.h";
	#include "parrot.h";
	#include "util.h";
	if (strcmp(animal_get_type(a),"dog") == 0){
		dog d = (dog)a;
		print("commands",d->commands,d->no_of_commands);
		print("responses",d->responses,d->no_of_commands);
		printi("mastery",d->mastery,d->no_of_commands);
	}
	else if (strcmp(animal_get_type(a),"parrot") == 0){
		parrot d = (parrot)a;
		print("commands",d->commands,d->no_of_commands);
		print("responses",d->responses,d->no_of_commands);
		printfl("mastery",d->mastery,d->no_of_commands);
	}
	//----------------------------remove later
	

	a->animal_train(a, arg2, arg3);
	
	
	//----------------------------remove later
	if (strcmp(animal_get_type(a),"dog") == 0){
		dog d = (dog)a;
		print("commands",d->commands,d->no_of_commands);
		print("responses",d->responses,d->no_of_commands);
		printi("mastery",d->mastery,d->no_of_commands);
	}
	else if (strcmp(animal_get_type(a),"parrot") == 0){
		parrot d = (parrot)a;
		print("commands",d->commands,d->no_of_commands);
		print("responses",d->responses,d->no_of_commands);
		printfl("mastery",d->mastery,d->no_of_commands);
	}
	//----------------------------remove later
}

static void cmd_command(int num, const char* arg1, const char* arg2, const char* arg3) {
	if(num < 3) {
		printf("command <name> <command>\n");
		return;
	}

	animal a = get_pet_by_name(arg1);
	if(a == NULL) {
		printf("No pet named %s\n", arg1);
		return;
	}

	const char* response = animal_command(a, arg2);

	printf("%s: %s\n", arg1, response);
}

int main(int argc, char** argv) {

	animals_init();

	while(true) {
		printf("> ");
		char* line = NULL;
		size_t n = 0;

		int rc = getline(&line, &n, stdin);


		char cmd[100];
		char arg1[100];
		char arg2[100];
		char arg3[100];
		rc = sscanf(line, "%99s %99s %99s %99s\n", cmd, arg1, arg2, arg3);

		if(rc > 0 && cmd != NULL && strlen(cmd) > 0) {
			if     (strcmp("quit",    cmd) == 0) cmd_quit   (rc, arg1, arg2, arg3);
			else if(strcmp("adopt",   cmd) == 0) cmd_adopt  (rc, arg1, arg2, arg3);
			else if(strcmp("train",   cmd) == 0) cmd_train  (rc, arg1, arg2, arg3);
			else if(strcmp("command", cmd) == 0) cmd_command(rc, arg1, arg2, arg3);
			else {
				printf("Unknown command: %s\n", cmd);
			}
			
		}
		
		free(line);
	}
}
