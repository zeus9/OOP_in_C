# OOP_in_C
As a fun project, I implemented object-oriented paradigms of encapsulation and polymorphism in the C language, leveraging features like modules, structures, and function pointers.

The objective is to implement a type system of animals. Each animal has a type
property and a name property. Each animal can be trained (with varying
degrees of success) by calling a function (or method, if you like) and
specifying a command word and the desired response. We can test the
results of your training efforts by calling another function to issue
a command word to the animal.

We can implement three types of animals: dog, cat, and parrot. Each
animal type should respond to training differently, as specified
below:


dog - a reliable learner; can be trained (eventually)

Giving a dog any command that it doesn't know yet should result in a
response of "woof".

Consistently training the same command word with the same desired
response three times will teach a dog the command.

Giving a dog a conflicting desired response before the command is
learned will confuse the dog, and we will lose all of the training
progress for that command.

A dog will never forget a learned command.

Once a dog has learned a command, the dog's response to that command
cannot be changed.


cat - cannot be trained

Giving a cat any command will result in one of three responses, chosen
at random: "purr", "meow", "walks away".

No amount of training will teach a cat anything (but go ahead and try,
I suppose).


parrot - an inconsistent performer; knows what it knows, but might
give the wrong response

An untrained parrot will always respond to every command with
"squawk!".

Training a parrot will improve its mastery of the command. Each time
we train a parrot, it cuts in half the chances that the parrot
responds incorrectly.

A parrot will respond to a command word that it doesn't know with one
of its other learned responses. It will choose the response randomly,
but in proportion to the relative mastery of each response.

If a parrot knows only one command, and it doesn't issue the correct
response to that command, it will respond with "squawk!".

If a parrot knows more than one command, and it doesn't issue the
correct response to that command, it will choose a response randomly
from its *other* responses, in proportion to its relative mastery of
these other responses.



animal.h - a header file for the base class of the animal type
hierarchy, containing seven function signatures. We must implement
each of these seven functions.

animal_test.c - a test driver. We can run this to expose a simple
command-line interface to your animal types. The test driver
implements the following four commands:

adopt <type> <name> - create a new animal object, and add it to our
menagerie.

train <name> <command> <response> - train an animal by calling the
animal_train() function on the animal named <name>.

command <name> <command> - issue the command <command> to an animal by
calling the animal_command() function on the animal named <name>.

quit - terminates the program


We must create at least a new file named animal.c (and probably
others too). We can compile the test with a command like:

   gcc -o animal_test animal_test.c animal.c

We can add other source files to the compilation command as needed.


Here is a sample run of a fully function test program. Because of the
random nature of a cat's or parrot's responses, our output (or even
subsequent runs of this test program) won't look *exactly* the same as
this:

> command fido sit

No pet named fido
> adopt dog fido

> command fido sit

fido: woof
> train fido sit sits

> command fido sit

fido: woof
> train fido sit sits

> train fido sit sits

> command fido sit

fido: sits
> adopt cat tuna

> train tuna play_dead plays_dead

> train tuna play_dead plays_dead

> train tuna play_dead plays_dead

> command tuna play_dead

tuna: meow
> command tuna play_dead

tuna: meow
> command tuna play_dead

tuna: purr
> adopt parrot spike

> command spike hello

spike: squawk!
> train spike hello hello

> command spike hello

spike: squawk!
> command spike hello

spike: hello
> train spike hello hello

> train spike hello hello

> command spike hello

spike: hello
> command spike pretty_bird

spike: hello
> train spike pretty_bird pretty_bird

> command spike pretty_bird

spike: hello
> command spike pretty_bird

spike: hello
> command spike pretty_bird

spike: hello
> command spike pretty_bird

spike: hello
> command spike pretty_bird

spike: hello
> command spike pretty_bird

spike: hello
> command spike pretty_bird

spike: pretty_bird
> command spike pretty_bird

spike: pretty_bird
> command spike pretty_bird

spike: hello
> command spike pretty_bird

spike: pretty_bird
> train spike pretty_bird pretty_bird

> train spike pretty_bird pretty_bird

> train spike pretty_bird pretty_bird

> command spike pretty_bird

spike: pretty_bird
> command spike hello

spike: hello
> adopt dog sammy

> train sammy speak BARK

> train sammy speak BARK

> train sammy speak BARK

> command sammy speak

sammy: BARK
> command sammy sit

sammy: woof
> command fido speak

fido: woof
> command fido sit

fido: sits
> quit

