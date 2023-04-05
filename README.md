# kli_console
Cute little custom console app I made after reading a reddit comment.

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

## Build
    gcc ./src/main.c -I./include -o ./bin/kli_console
This will only work on Linux for now, but Windows compatibility is on the TODO list.

## Run
In your terminal run
    
    ./bin/kli_console

and off you go!
