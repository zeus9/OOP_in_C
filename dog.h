#ifndef DOG_H
#define DOG_H

#include "animal.h"


struct dog_t{
    struct animal_t base;

    char *def_response;
    char **commands;
    char **responses;
    int *mastery;
    int master;
    int no_of_commands;
    
};

typedef struct dog_t* dog;




// Class initialization
void dog_init(dog self);

// Create a new animal
// type - a string specifying a "known type" of animal. The type
// specified here will dictate the behavior of the animal.
//
// name - give the animal a name by which you can refer to it
//
// returns: a pointer to the new animal, or NULL if the specified type
// is unknown.
dog dog_create(animal base);

// Destroy/free an animal
// a - a pointer to the animal to deallodoge. All memory allocated
// during the lifetime of the animal should be freed.
void dog_destroy(dog self);

// Get the name of an animal
// a - a pointer to the animal
//
// returns: a pointer to a string of the name of animal a
const char* dog_get_name(dog self);

// Get the type of an animal
// a - a pointer to the animal
//
// returns: a pointer to a string specifying the type of animal a.
const char* dog_get_type(dog self);

// Train an animal
// a - a pointer to the animal to train
//
// command - the command word that the animal should learn
//
// response - the desired response from the animal
void dog_train(animal self, const char* command, const char* response);

// Command an animal
// a - a pointer to the animal to command
//
// command - the command word to give the animal
//
// returns: the response from the animal (varies by animal type)
const char* dog_command(animal self, const char* command);

#endif // DOG_H
