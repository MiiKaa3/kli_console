#!/usr/bin/bash
printf "./bin/kli_console ./tests/doesntexist.kli ...\nExpected:\n\tThat file does not exist!\nOutput:\n\t"
./bin/kli_console ./tests/doesntexist.kli

printf "\n\n"
printf "./bin/kli_console ./tests/helloworld.kli ...\nExpected:\n\tHello World!\nOutput:\n\t"
./bin/kli_console ./tests/helloworld.kli

printf "\n\n"
printf "./bin/kli_console ./tests/oneToExit.kli ...\nExpected:\n\t1 2 3 4 5 *graceful exit*\nOutput:\n"
./bin/kli_console ./tests/oneToExit.kli

printf "\n\n"
printf "./bin/kli_console ./tests/somemaths.kli ...\nExpected:\n\t20, 600, 1024, 99712889, 6\nOutput:\n"
./bin/kli_console ./tests/somemaths.kli