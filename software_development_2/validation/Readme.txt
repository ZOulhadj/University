***********************************
*                                 *
*            Building             *
*                                 *
***********************************
Compiler:                   g++ (GNU), clang (LLVM), cl (MSVC)
Build directory:            Root folder
Build command:              clang or g++ Source/Main.cpp

Build notes:                Building this program has been texted on both Windows
                            and the macOS operating system. All 3 compilers should
                            work when compiling.

***********************************
*                                 *
*              Notes              *
*                                 *
***********************************

This input validation program accpets input from a user which then stores and
subseqently saves the information into a text file called output.txt. To ensure
that the data being inputted is valid, I have used regular expressions. At a
basic level, the regex expressions are a pattern to which the input text must
match in order to be valid. Using this technique I am able to ensure that the
data being stored is formatted correctly.

When inputting the data into the program I decided to ensure the regex forces
the user to enter the correct format instead of the program handling that internally.
This is because since a user will be entering the data they will have the ability
to do the formating anyways by simply entering the right data. If we had to
load data from a file then this would be a different story.

Below is a link as to why I've decided to allow the use of a single name (Some
people don't have a surname).

https://en.wikipedia.org/wiki/Mononymous_person

On the other hand, in regards to quitting the application I make sure that
once the user starts entering the data that they fully enter all fields
as quiting in the middle of the process will leave the application in
an invalid state since all 4 pieces of information is required within
the output.txt file. Therefore, once they finish entering all the data
and the data has been written to the file, the application will ask
if they would like to quit.

The one thing I was not able to do was complete the date by taking into
account leap years :-(
