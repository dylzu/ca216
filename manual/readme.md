This shell responds to various commands both built-in and external linux commands.

Built-in command list ------

clr - clears the past shell outputs.

cd - will change the working directory when followed by something e.g(cd xxxx), when followed by nothing it will print the current working directory.

dir - lists the contents of the current directory.

echo - outputs whatever is followed by the echo command.

pause - pauses the shell until the "Enter" key is pressed.

environ - lists all the enviroment strings.

help - displays the user manual.

quit - closes the shell.

-------

For external linux commands just enter them as normal into the shell.

-------

Environment:
    An environment variable is a dynamic-named value that can affect the way running processes will behave on a computer[3] and is set with a name and value in the form "name=value".
    Common environment vairables include PWD, SHELL and USER, these are used to store information regarding to the current working directory, the current shell and the current logged user.
    Its also possible to alter these variables using setenv and putenv to provide additional functionality to our program's inbuilt commands. Examples include;
    environ - prints all the enviroment variables

-------

I/O Redirection:
    I/O stands for input/output and the redirection of this is whats refered to as I/O Redirection.
    An example of this is how the user can can control the input and how this can alter the output by being able to send the output to a seperate txt file.

    I/O redirection is currently not supported within my shell but an example usage would look like the following:

        programname arg1 arg2 < inputfile > outputfile [2]
    
    Token options include:

        < filename    redirect input from a file.
		> filename    redirect output to a file.
		>> filename   redirect output to a file, but instead append to the end of the given file.

-------

Foreground and Background Execution:

    Foreground execution:
        Processes that require a user to start them or to interact with them are called foreground processes.[1]

    Background execution:
        Processes that are run independently of a user are referred to as background processes.[1]

    Difference:
        Programs and commands run as foreground processes by default. To run a process in the background, place an ampersand (&) at the end of the command name that you use to start the process.[1]

-------
References:
    used in manual:
    [1]: <https://www.ibm.com/docs/en/aix/7.1?topic=processes-> , section "Foreground and background processes".
    [2]:  Donal Fitzpatrick and Graham Healy. February 2022. Lab 6F: I/O redirection. Available at: <https://loop.dcu.ie/mod/book/view.php?id=1796411&chapterid=377039>.
    [3]: <https://en.wikipedia.org/wiki/Environment_variable>.

    used in code:
    Donal Fitzpatrick and Graham Healy. February 2022. Lab 3C: Building your own shell. Available at: <https://loop.dcu.ie/mod/book/view.php?id=1796411&chapterid=377036>.   
    Donal Fitzpatrick and Graham Healy. February 2022. Lab 4D: Enhancing your shell. Available at: <https://loop.dcu.ie/mod/book/view.php?id=1796411&chapterid=377037>.
    David Collazo. January 2014. An Introduction to Linux I/O Redirection. Available at: <https://www.digitalocean.com/community/tutorials/an-introduction-to-linux-i-o-redirection>.
    Stephen Brennan. January 2015. Tutorial - Write a Shell in C. Available at: <https://brennan.io/2015/01/16/write-a-shell-in-c/>.

-------
/*
Student Name: Dylan Corbari
Student Number: 20341171
In submitting this project, I declare that the project material, which I now submit, is my own work. Any assistance received by ways of online resources has been cited and acknowledged within my work. I make this declaration in the knowledge that a breach of the rules pertaining to project submission will carry serious consequences including a mark of 0 for this assignment.
*/
