# Sodium Password Generator

This tool is a simple password generator 100% written in C. It implements [libsodium](https://github.com/jedisct1/libsodium), an audited secure library that generates random values, to choose among possible characters, forming a password.
It's a CLI tool and still don't have support to graphical interface.


## Getting Started

To get started, you only need to make libsodium available to your compiler. Fully tested using gcc.
Then clone this repository and build the executable on your machine.

### Prerequisites

Requirements 
- [Libsodium official installation guide](https://libsodium.gitbook.io/doc/installation)
- [Libsodium downloads page](https://download.libsodium.org/libsodium/releases/)

### Installing

After installing libsodium and making sure it's available to your compiler, clone this repository:

Clone this repo:

    $ git clone https://github.com/victorbonato/SodiumPassGen.git

Compile it (this example uses gcc):

    $ cd src && gcc main.c filterArgv.c interpreters.c generateRandomChar.c print.c -lsodium -o ../sogen.exe && cd ..

## Using it

After building the executable, on the current directory:

On Windows:

    .\sogen.exe length=<password_length> type=<types_of_characters_allowed>

or

On Linux:

    ./sogen length=<password_length> type=<types_of_characters_allowed>


## Example usage:

    $ .\sogen.exe length=27 type=ANS

<img src="https://github.com/victorbonato/SodiumPassGen/main/res/images/image.png" alt="Example usage" title="Example Usage">

To get help on options:

    .\sogen.exe -h

## Authors

  - **Victor Bonato** -\
    Github: [victorbonato](https://github.com/victorbonato)\
    Contact mail: [victorbonatoit@gmail.com](victorbonatoit@gmail.com)

## Acknowledgments

  - This is my first GitHub project, i've made it just for learning purposes, the C code can probably improve *a lot*, feel free to give tips, advices or making pull requests.
