# printf_42
A personal printf built out of Professor Don Colton's wonderful resource <a href="http://www.cypress.com/file/54761/download">Secrets of "printf"</a>. 

This project was a great excercise in understanding how variable arguments work in C and how versatile the printf function is through it's many flags and format identifiers. The aim for this README is to give a concise explanation of the project's most important features and touch on other points of interest.
## Key Details

 The first function to be addressed, *run_thru_string*, gives a glimpse into how this project is organized through the loop found on line 43:

<img width="571" alt="screen shot 2017-11-28 at 1 39 20 pm" src="https://user-images.githubusercontent.com/13093517/33345618-c7973602-d441-11e7-870f-262381000e8a.png">

The format string runs similar to how a string in a simple <a href="https://github.com/keenanromain/printf_42/blob/master/src/libft/ft_putstr.c">putstr</a> would. Basically, each character is outputted through the write system call as long as said character is not null. However, printf would not be printf if not for it's ability to print formatted data to the standard output. This is why the while loop also checks for format identifiers (subsequences beginning with %) on line 45. If the loop does encounters a %, the additional arguments fed to printf are properly formatted and inserted into the resulting string where their respective specifiers would have been. The first of which is found on line 49, where 'n' is used to store the total number of characters written so far. All other specifiers are determined later on in the program. To view the many types of format identifiers, please refer to the image below. The last thing worth mentioning is the variable named 'size'. Printf returns the number of characters in the resulting string which is why size is incremented with each call to write and is passed as an argument throughout the program.  

<img width="521" alt="screen shot 2017-11-28 at 1 51 19 pm" src="https://user-images.githubusercontent.com/13093517/33346066-40ed8bb8-d443-11e7-8f9c-c36b3c6529e7.png">
<sub>Note ~ This program does not manage doubles (%f, %e/%E, %g/%G), but does manage wide characters (%C and %S).</sub>
<br /><br />

After running some validation checks on what follows the % in the *run_thru_string* function, the next major function worth examining is the *determine_flags* function. The format specifier in printf is interesting because it can also contain sub-specifiers such as flags, width, precision, and modifiers. The *determine_flags* function is the main function responsible for checking all of the above. Please refer to the detailed explanation behind each sub-specifier in the table below before moving on to *determine_flags*:

<br />
<img width="688" alt="screen shot 2017-11-28 at 2 38 03 pm" src="https://user-images.githubusercontent.com/13093517/33348087-cde68852-d449-11e7-8a8a-9c05dcf79f45.png">
<img width="589" alt="screen shot 2017-11-28 at 2 28 35 pm" src="https://user-images.githubusercontent.com/13093517/33348499-79aee53e-d44b-11e7-9635-c570a7aa399c.png">

*determine_flags* takes both the sub-string that followed the % from earlier as well as the list of variable argument vectors. The purpose of this function is two-fold. First, it takes the content from it's sub-string argument and parses it into the project's struct. Secondly, it turns on flags and manages the data for the appropriate sub-specifiers (listed above) if they are found in the sub-string. For the latter purpose, this is done primarily though the function calls on line 101 to 103. *determine_width* will be looked at to get an idea of how this is done on a more detailed level before moving on to *dispatcher*.

<img width="483" alt="screen shot 2017-11-28 at 4 01 38 pm" src="https://user-images.githubusercontent.com/13093517/33350806-9a5210f4-d455-11e7-8b21-8e5f8bb100da.png">

To determine the width (and precision for floating point value) of the given sub-string, the *determine_width* function contains two if-statements to be evaluated. The first checks for a numerical value (but not zero as zero is it's own sub-specifier - see diagram above) in the sub-string as this number is used to determine the width offset for the corresponding variable argument. If true, this case is noted and the value is stored as seen on lines 23 and 24. 
<br />
<sub>How output looks like with width adjusted to the right</sub>
<br />
<img width="244" alt="screen shot 2017-11-28 at 5 08 35 pm" src="https://user-images.githubusercontent.com/13093517/33352665-d965325e-d45e-11e7-9d9b-14cdd488a30a.png">
<br />
<sub>How output looks like with width adjusted to the left (Note the preceding minus sign)</sub>
<br />
<img width="251" alt="screen shot 2017-11-28 at 5 08 49 pm" src="https://user-images.githubusercontent.com/13093517/33352675-e342195e-d45e-11e7-8e9e-ea34ef3d7a48.png">

The second if-statement checks for the appropriate sign to set precision, '.', and if true, makes note of it and stores the value in a similar fashion on lines 30 and 31. Lastly, the two nested while-loops are used to escape the numerical value used to set width and/or precision.

Next, the *dispatcher* function will be examined. This function was originally planned to store a dispatch table, but for the sake of brevity and quickness, it now is the first of three functions that contain a few if-statements that correspond to the appropriate format specifier.

<img width="471" alt="screen shot 2017-11-28 at 5 16 57 pm" src="https://user-images.githubusercontent.com/13093517/33352947-29b7a9d4-d460-11e7-9ea3-54e9d9e167d2.png">

This function passes the different integers into their appropriate functions on line 44, strings, characters, and pointers to their respective functions on line 46, and all else into the invalid function on line 47.

As seen in the *dispatcher* function above, this recoded printf supports 15 conversion specifiers with invalid options handled in a separate function. To showcase this variety, the support for strings, octal integers, and wide characters will be discussed in full.

<img width="585" alt="screen shot 2017-12-03 at 12 42 23 am" src="https://user-images.githubusercontent.com/13093517/33523777-d98ba5e8-d7c3-11e7-80e6-8607b49cf571.png">

The handler for string types was perhaps the most straightforward to implement. The first task was to evaluate the truthfulness of the trailing variable argument. If said argument is false, the program's output should then mimic printf's error handling as seen on lines 50 and 52. Otherwise, the variable argument is duplicated and passed to the auxillary function in charge of output. In *helper*, the auxillary, two calls to precision and width formatting functions (listed as *s_precision* and *s_width* in reference to the string type) finally perform the specifications from earlier in the program if they were given. The functions alter the duplicated string by either limiting the number of characters to be printed or justifying the result according to white space. Once these two actions have been performed, the string is ready to be printed and the resultant length of it is returned.

## Acknowledgement

printf_42 was developed at École 42 USA in Fremont, California
