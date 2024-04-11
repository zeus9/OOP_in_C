#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "animal.h"
#include "parrot.h"
#include "util.h"

// Class initialization
void parrot_init(parrot obj){
    
    //UNCOMMENT AND TAKE CARE OF THIS!!
    // obj->base->type = PARROT;
    
    
}

// Create a new animal
// type - a string specifying a "known type" of animal. The type
// specified here will dictate the behavior of the animal.
//
// name - give the animal a name by which you can refer to it
//
// returns: a pointer to the new animal, or NULL if the specified type
// is unknown.
parrot parrot_create(animal a){
    parrot obj = (parrot)malloc(sizeof(struct parrot_t));

    // base initializations for dog type
    //------------------------------------
    obj->base = *a;

    obj->base.type = (char*)malloc(MAX_LEN*(sizeof(char)));    
    strcpy(obj->base.type, "parrot");

    obj->base.animal_destroy = parrot_destroy;
    obj->base.animal_train = parrot_train;
    obj->base.animal_command = parrot_command;
    //------------------------------------

    // default response to command
    obj->def_response = (char*)malloc(MAX_SIZE);
    strcpy(obj->def_response,"squawk!");
    

    // Initialize commands 2d char arrary
    obj->commands = (char **)malloc(MAX_LEN * sizeof(char *));
        // Allocate memory for the columns
    for (int i = 0; i < MAX_LEN; i++)
        obj->commands[i] = (char *)malloc(MAX_SIZE* sizeof(char));


    // Initialize responses 2d char arrary
    obj->responses = (char **)malloc(MAX_LEN * sizeof(char *));
        // Allocate memory for the columns
    for (int i = 0; i < MAX_LEN; i++)
        obj->responses[i] = (char *)malloc(MAX_SIZE* sizeof(char));


    // Initialize no_of_commands 1d int array which holds track of no of commands to store
    obj->no_of_commands = 0;
    
    // Value to initialize mastery indicating not mastered for parrot
    obj->not_master = 0.5;

    //Initialize Mastery int array to Zero's
    obj->mastery = (float*)malloc(MAX_LEN * sizeof(float));
    for(int i = 0; i < MAX_LEN; i++)
       obj->mastery[i] = obj->not_master; // initilize all with 1's which indicates no mastery. 0 indicates full mastery
    
    return obj;
}

// Destroy/free an animal
// a - a pointer to the animal to deallocate. All memory allocated
// during the lifetime of the animal should be freed.
void parrot_destroy(animal a){
    
    parrot parrot_obj = (parrot)a;
    
    // derived elements destroyed first
    free(parrot_obj->def_response);
    free(parrot_obj->commands);
    free(parrot_obj->responses);
    free(parrot_obj->mastery);
    
    animal_destroy(&parrot_obj->base);
    free(parrot_obj);
    parrot_obj = NULL;
    
}

// Train an animal
// a - a pointer to the animal to train
//
// command - the command word that the animal should learn
//
// response - the desired response from the animal
void parrot_train(animal a, const char* command, const char* response){
    // parrot self = (parrot)a;
    // int command_present = 0;
    
    if (strcmp(animal_get_type(a),"parrot") == 0){
        parrot self = (parrot)a;
        int command_present = 0;

        // check list of learned commands
        for (int i = 0; i < self->no_of_commands; i++){
            

            // if command present in commands[][]
            if(strcmp(command, self->commands[i]) == 0){
                
                // note the command is present
                command_present++;
                
                // if responses match
                if (strcmp(response, self->responses[i]) == 0){
                    self->mastery[i] = (float)(self->mastery[i]/2.0);
                }
            }
        }

        // register new command
        if (command_present == 0){
            
            if (self->no_of_commands == MAX_LEN){
                printf(" Max commands reached");
                return;
            }

            strcpy(self->commands[self->no_of_commands], command);
            strcpy(self->responses[self->no_of_commands], response);
            self->mastery[self->no_of_commands] = self->not_master;
            self->no_of_commands++;
        }
    }
    else{
        printf(" This animal is not a parrot");
    }
}

// Command an animal
// a - a pointer to the animal to command
//
// command - the command word to give the animal
//
// returns: the response from the animal (varies by animal type)
const char* parrot_command(animal a, const char* command){
    
    parrot self = (parrot)a;
    // check if any command registered
    if (self->no_of_commands > 0){

        // check in list of commands
        for (int i = 0; i < self->no_of_commands; i++){

            // compare if command present in commands[][]
            if (strcmp(self->commands[i], command) == 0){

                // random response based on rules
                float dec = random_decimal();
                printf("\n dec: %f", dec);
                if (dec > self->mastery[i]){
                    return self->responses[i];
                }
                else{

                    // if only command learnt, return default response
                    if (self->no_of_commands == 1){
                        return self->def_response;
                    }

                    // find index which is not correct response
                    int rd;
                    int* random_index = &rd;
                    do{
                        *random_index = random_weighted_index(self->mastery, self->no_of_commands);
                    } while(*random_index == i);

                    return self->responses[*random_index];
                }
            }
        }
    }
    // default response 
    return self->def_response;

}

