#include <stdio.h>
#include "animal.h"
#include "cat.h"
#include "util.h"


// Class initialization
void cat_init(cat obj){
    
    //UNCOMMENT AND TAKE CARE OF THIS!!
    // obj->base->type = CAT;
    
}

// Create a new animal
// type - a string specifying a "known type" of animal. The type
// specified here will dictate the behavior of the animal.
//
// name - give the animal a name by which you can refer to it
//
// returns: a pointer to the new animal, or NULL if the specified type
// is unknown.
cat cat_create(animal a){

    cat obj = (cat)malloc(sizeof(struct cat_t));
    
    obj->def_responses[0] = "purr";
    obj->def_responses[1] = "meow";
    obj->def_responses[2] = "walks away";
    
    // base initializations for cat type
    //------------------------------------
    obj->base = *a;

    obj->base.type = (char*)malloc(MAX_LEN*(sizeof(char)));    
    strcpy(obj->base.type, "cat");
    
    obj->base.animal_destroy = cat_destroy;
    obj->base.animal_train = cat_train;
    obj->base.animal_command = cat_command;
    //------------------------------------
    
    return obj;
}

// Destroy/free an animal
// a - a pointer to the animal to deallocate. All memory allocated
// during the lifetime of the animal should be freed.
void cat_destroy(animal a){
    cat self = (cat)a;
    
    // derived obj elements destroyed first
    free(self->def_responses);
    animal_destroy(&self->base);
    free(self);
    self = NULL;
}

// Train an animal
// a - a pointer to the animal to train
//
// command - the command word that the animal should learn
//
// response - the desired response from the animal
void cat_train(animal a, const char* command, const char* response){
    
}

// Command an animal
// a - a pointer to the animal to command
//
// command - the command word to give the animal
//
// returns: the response from the animal (varies by animal type)
const char* cat_command(animal a, const char* command){
    cat cat_obj = (cat)a;
    return cat_obj->def_responses[random_no(3)];
}
