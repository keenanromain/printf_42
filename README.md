# printf_42
A personal printf. 

This project was a great excercise in understanding how variable arguments work in C and how versatile the printf function is through it's many flags and format identifiers. The aim for this README is to give a concise explanation of the project's most important features and touch on other points of interest.
## Key Details

 The first function to be addressed, *run_thru_string*, gives a glimpse into how this project is organized through the loop found on line 43:

<img width="571" alt="screen shot 2017-11-28 at 1 39 20 pm" src="https://user-images.githubusercontent.com/13093517/33345618-c7973602-d441-11e7-870f-262381000e8a.png">

The format string runs similar to how a string in a simple <a href="https://github.com/keenanromain/printf_42/blob/master/src/libft/ft_putstr.c">putstr</a> would. Basically, each character is outputted through the write system call as long as said character is not null. However, printf would not be printf if not for it's ability to print formatted data to the standard output. This is why the while loop also checks for format identifiers (subsequences beginning with %) on line 45. If the loop does encounters a %, the additional arguments fed to the function are properly formatted and inserted into the resulting string where their respective specifiers would have been. The first of which is found on line 49, where 'n' takes the total number of characters written so far. All other specifiers are determined later on in the program. To view the many types of format identifiers, please refer to the image below. The last thing worth mentioning is the variable named 'size'. Printf returns the number of characters in the resulting string which is why size is incremented with each call to write and is passed as an argument throughout the program.  

<img width="521" alt="screen shot 2017-11-28 at 1 51 19 pm" src="https://user-images.githubusercontent.com/13093517/33346066-40ed8bb8-d443-11e7-8f9c-c36b3c6529e7.png">
Note ~ This program does not manage doubles (%f, %e/%E, %g/%G), but does manage wide characters (%C and %S). 

## Acknowledgement

printf_42 was developed at École 42 USA in Fremont, California
