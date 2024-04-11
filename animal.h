#ifndef ANIMAL_H
#define ANIMAL_H

// Object definitions referenced in the header file
//-----------------------------------------------
#define MAX_LEN 100
#define MAX_SIZE 50

// enum animal_type {
//     DOG, CAT, PARROT
// };

// typedef enum animal_type animal_type;

struct animal_t;
typedef struct animal_t* animal;

struct animal_t {
    const char* name;
    const char* type;

    // animal (*animal_create)(const char* type, const char* name);
    void (*animal_destroy)(animal a);
    const char* (*animal_get_type)(animal a);
    const char* (*animal_get_name)(animal a);
    void (*animal_train)(animal a, const char* command, const char* response);
    const char* (*animal_command)(animal a, const char* command);

};



//-----------------------------------------------



// Class initialization
// Use this function to perform needed initialization, if any.
void animals_init();

// Create a new animal
// type - a string specifying a "known type" of animal. The type
// specified here will dictate the behavior of the animal.
//
// name - give the animal a name by which you can refer to it
//
// returns: a pointer to the new animal, or NULL if the specified type
// is unknown.
animal animal_create(const char* type, const char* name);

// Destroy/free an animal
// a - a pointer to the animal to deallocate. All memory allocated
// during the lifetime of the animal should be freed.
void animal_destroy(animal a);

// Get the type of an animal
// a - a pointer to the animal
//
// returns: a pointer to a string specifying the type of animal a.
const char* animal_get_type(animal a);

// Get the name of an animal
// a - a pointer to the animal
//
// returns: a pointer to a string of the name of animal a
const char* animal_get_name(animal a);

// Train an animal
// a - a pointer to the animal to train
//
// command - the command word that the animal should learn
//
// response - the desired response from the animal
void animal_train(animal a, const char* command, const char* response);

// Command an animal
// a - a pointer to the animal to command
//
// command - the command word to give the animal
//
// returns: the response from the animal (varies by animal type)
const char* animal_command(animal a, const char* command);

#endif // ANIMAL_H
