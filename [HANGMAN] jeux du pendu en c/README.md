Creation of a hangman game in a short time (1h30) with recoded libC functions.

USAGE:

To run that shell, you will need :

- `make` : [What is make ?](https://www.gnu.org/software/make/) (`sudo apt-get install make`)

Once you installed make, clone this repository (`git clone ...`) and run the following :

    make
    ./hangman file [tries]
    
    (./hangman your file with your words inside (one of them will be chosen at random and it's up to you to find it) and the number of tries)


DESCRIPTION:

the game starts by default with 10 tries but you can choose the number of tries by putting it after the file.The goal
of the game is to find the chosen word before the remaining number of tries.

this project was done in less than 1h30 without an internet connection as part of an exam.
