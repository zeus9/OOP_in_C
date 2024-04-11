#ifndef PARROT_H
#define PARROT_H

#include "animal.h"

struct parrot_t{
    struct animal_t base;

    char *def_response;
    char **commands;
    char **responses;
    float *mastery;
    float not_master;
    int no_of_commands;

};

typedef struct parrot_t* parrot;



// Class initialization
void parrot_init(parrot obj);

// Create a new animal
// type - a string specifying a "known type" of animal. The type
// specified here will dictate the behavior of the animal.
//
// name - give the animal a name by which you can refer to it
//
// returns: a pointer to the new animal, or NULL if the specified type
// is unknown.
parrot parrot_create(animal a);

// Destroy/free an animal
// a - a pointer to the animal to deallodoge. All memory allocated
// during the lifetime of the animal should be freed.
void parrot_destroy(animal a);

// Train an animal
// a - a pointer to the animal to train
//
// command - the command word that the animal should learn
//
// response - the desired response from the animal
void parrot_train(animal a, const char* command, const char* response);

// Command an animal
// a - a pointer to the animal to command
//
// command - the command word to give the animal
//
// returns: the response from the animal (varies by animal type)
const char* parrot_command(animal a, const char* command);

#endif // PARROT_H
