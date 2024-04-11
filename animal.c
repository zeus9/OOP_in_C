#include <stdio.h>
#include <string.h>
#include "animal.h"
#include "dog.h"
#include "cat.h"
#include "parrot.h"


// Class initialization
// Use this function to perform needed initialization, if any.
void animals_init(){

}

// Create a new animal
// type - a string specifying a "known type" of animal. The type
// specified here will dictate the behavior of the animal.
//
// name - give the animal a name by which you can refer to it
//
// returns: a pointer to the new animal, or NULL if the specified type
// is unknown.
animal animal_create(const char* type, const char* name){
    animal animal_obj = (animal)malloc(sizeof(struct animal_t));
    
    // set name
    animal_obj->name = (const char*)malloc(MAX_SIZE * sizeof(const char));
    strcpy(animal_obj->name, name);    

    // set function pointers
    animal_obj->animal_get_name = animal_get_name;    
    animal_obj->animal_get_type = animal_get_type;
    
    if (strcmpi("dog", type) == 0){
        
        dog dog_obj = dog_create(animal_obj);
        
        return (animal)dog_obj;
        
    }
    else if (strcmpi("cat", type) == 0){
        
        cat cat_obj = cat_create(animal_obj);
        
        return (animal)cat_obj;
    }
    else if (strcmpi("parrot", type) == 0){
        parrot parrot_obj = parrot_create(animal_obj);
        
        return (animal)parrot_obj;
    }
    else{
        return NULL;
    }
}

// Destroy/free an animal
// a - a pointer to the animal to deallocate. All memory allocated
// during the lifetime of the animal should be freed.
void animal_destroy(animal a){
    
    free(a->name);
    free(a->type);
    free(a);
    a = NULL;  

}

// Get the type of an animal
// a - a pointer to the animal
//
// returns: a pointer to a string specifying the type of animal a.
const char* animal_get_type(animal a){
    animal obj = (animal)a;
    return obj->type;
}

// Get the name of an animal
// a - a pointer to the animal
//
// returns: a pointer to a string of the name of animal a
const char* animal_get_name(animal a){
    animal obj = (animal)a;
    return obj->name;
}

// Train an animal
// a - a pointer to the animal to train
//
// command - the command word that the animal should learn
//
// response - the desired response from the animal
void animal_train(animal a, const char* command, const char* response){
   a->animal_train(a, command, response);
    // animal animal_obj = (animal)a;
    // animal_obj->animal_train(animal_obj, command, response);
}

// Command an animal
// a - a pointer to the animal to command
//
// command - the command word to give the animal
//
// returns: the response from the animal (varies by animal type)
const char* animal_command(animal a, const char* command){
    // animal animal_obj = (animal)a;
    // return animal_obj->animal_command(animal_obj, command);
    return a->animal_command(a, command);
}


