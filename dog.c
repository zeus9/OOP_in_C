#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "animal.h"
#include "dog.h"
#include "util.h"


// Class initialization
void dog_init(dog obj){
    
}

// Create a new animal
// type - a string specifying a "known type" of animal. The type
// specified here will dictate the behavior of the animal.
//
// name - give the animal a name by which you can refer to it
//
// returns: a pointer to the new animal, or NULL if the specified type
// is unknown.
dog dog_create(animal a){
    
    
    dog obj = (dog)malloc(sizeof(struct dog_t));
    
    // base initializations for dog type
    //------------------------------------
    obj->base = *a;

    obj->base.type = (char*)malloc(MAX_LEN*(sizeof(char)));    
    strcpy(obj->base.type, "dog");

    obj->base.animal_destroy = dog_destroy;
    obj->base.animal_train = dog_train;
    obj->base.animal_command = dog_command;
    //------------------------------------

    // Initialize def_response char array
    obj->def_response = (char*)malloc(MAX_SIZE);    
    strcpy(obj->def_response,"woof");
    
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

    // Initialize master int (3 for dog)
    obj->master = 3;

    // Initialize no_of_commands 1d int array which holds track of no of commands to store
    obj->no_of_commands = 0;
    
    //Initialize Mastery int array to Zero's
    // obj->mastery = (int*)calloc(MAX_LEN, sizeof(int));
    obj->mastery = (int*)malloc(MAX_LEN * sizeof(int));
    for(int i = 0; i < MAX_LEN; i++)
       obj->mastery[i] = 1; // initilize all with 1's which indicates no mastery. 
    
    return obj; 
}

// Destroy/free an animal
// a - a pointer to the animal to deallodoge. All memory allocated
// during the lifetime of the animal should be freed.
void dog_destroy(dog self){
    
    //only destroy non-base class members

    dog d = (dog)self;

    free(d->def_response);
    free(d->commands);
    free(d->responses);
    free(d->mastery);

    animal_destroy(&d->base);
    free(d);

    d = NULL;
}


// Train an animal
// a - a pointer to the animal to train
//
// command - the command word that the animal should learn
//
// response - the desired response from the animal
void dog_train(animal a, const char* command, const char* response){
    if (strcmp(a->animal_get_type(a),"dog") == 0){
        
        dog self = (dog)a;            
        int command_present = 0;

        // printf("\n%d", 1);    
        for (int i = 0; i < self->no_of_commands; i++) {
            
            // printf("\n | Command: %s", self->commands[self->no_of_commands-1]);
            // printf(" | Response: %s", self->responses[self->no_of_commands-1]);
            // printf(" | Input_response: %s", response);
            // printf(" | Mastery: %d", self->mastery[self->no_of_commands-1]);
            // printf(" | Master: %d", self->master);
            // printf(" | No of commands : %d\n",(self->no_of_commands));
        
            // printf("\n%d", 2);    
            // if command mentioned before, present in commands[][]
            if (strcmp(command, self->commands[i]) == 0){
        
                // printf("\n%d", 3);                    
        
                command_present++;
        
                // if command already mastered, do not disturb
                if (self->mastery[i] == self->master){
                    // printf("\n%d", 4);    
                    break;
                }
                else{
                    // printf("\n%d", 5);    
                    // if current response matches with previous response
                    printf(" Response: %s", self->responses[i]);
                    printf(" Input_response: %s", response);       
                        
                    if (strcmp(response, self->responses[i]) == 0){
                        
                        // printf("\n%d", 6); 
                        // printf("\n %p = %p",&self->responses[i], &response);
                        
                        
                        // if not mastered yet
                        if (self->mastery[i] < self->master){
                                
                                // printf("\n%d", 7);    
                                
                                self->mastery[i]++;
                        }
                    }            
                    // if responses don't match, update response
                    else{
                        // printf("\n%d", 8);    
                        
                        self->mastery[i] = 1;
                        self->responses[i] = response;
                    }
                }                    
                
            }
        }

        // if first time command (not present in commands[][])
        if(command_present == 0){
            
            // cap on no of new commands
            if (self->no_of_commands == MAX_LEN){
                printf(" Max commands reached");
                return;
            }

            strcpy(self->commands[self->no_of_commands], command);
            strcpy(self->responses[self->no_of_commands], response);
            self->mastery[self->no_of_commands] = 1; // not mastered value
            self->no_of_commands++;
            
        }    
        // printf("\n | Command: %s", self->commands[self->no_of_commands-1]);
        // printf(" | Response: %s", self->responses[self->no_of_commands-1]);
        // printf(" | Input_response: %s", response);
        // printf(" | Mastery: %d", self->mastery[self->no_of_commands-1]);
        // printf(" | Master: %d", self->master);
        // printf(" | No of commands : %d\n",(self->no_of_commands));
    }
    else{
        printf("Animal to train is not a dog");
    }
    
    
}

// Command an animal
// a - a pointer to the animal to command
//
// command - the command word to give the animal
//
// returns: the response from the animal (varies by animal type)
const char* dog_command(animal a, const char* command){

    // get command
    // check if commands[][] has any commands, else def_response
    // check if command in commands[][]
    //     if yes, return response
    //      else return def_response

    // typcast to access dog object
    dog self = (dog)a;

    // check if any commands registered
    if (self->no_of_commands > 0){
        
        // run through commands to see if command found
        for(int i = 0; i < self->no_of_commands; i++){
            
            
            if (strcmp(self->commands[i], command) == 0){
                
                // check if dog has mastered that command            
                if (self->mastery[i] == self->master){
                    // printf(" response: %s", self->responses[i]);
                    return self->responses[i];
                }
                else
                    break;
            }
        }

    }
    // if command not found or mastered, return default response "woof"
    return self->def_response;
    
    
    
}


