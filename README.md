# kli_console
Cute little custom console app I made after reading a reddit comment.

## Build
Simply run:

    git clone https://github.com/MiiKaa3/kli_console.git
    cd ./kli_console
    make

## Run
In your terminal run
    
    ./bin/kli_console

and off you go!

## Instructions
We currently have 4 working commands!

### print
    print "[str]"
Prints $str to stdout. $str must be surrounded by '"' markers. At this stage you can't print '"' to the console, but its on the todo

### compute
    compute [A][op][B]
Calculates the result of $A $op $B and prints it to stdout. $A and $B must both be integers and $op must be
    
- '+' => calculates A + B
- '-' => calculates A - B
- '\*' => calculates A \* B
- '/' => calculates A / B
- '^' => calculates pow(A, B)

### help
    help [cmd]
$cmd must be on of the four commands mentioned here, and it prints out some helpful usage information

### exit
    exit
Gracefully exits the command prompt


## Scripting
To write and execute a script using kli_console just write the commands with the same syntax as in the repl, save with the *.kli extension, and execute. For example:

    // ----- helloworld.kli ----- //
    print "Hello World!"
    // ----- EOF ----- //

In terminal:

    >> ./bin/kli_console ./helloworld.kli
    Hello World!
    >> 

Check out the ./tests directory for some example scripts which should give you the idea!