# printf_42
A personal printf with full-functionality

## Key Details

This project was a great excercise for understanding variable argument lists in C and the full power behind printf's many flags and format identifiers. The first function to be addressed, *run_thru_string*, gives a glimpse into how this project is organized:

<img width="571" alt="screen shot 2017-11-28 at 1 39 20 pm" src="https://user-images.githubusercontent.com/13093517/33345618-c7973602-d441-11e7-870f-262381000e8a.png">

The format string here runs similar to how the string in a simple <a href="https://github.com/keenanromain/printf_42/blob/master/src/libft/ft_putstr.c">putstr</a> would. This is achieved by outputting each character through the write system call as long as each character is valid and not a format identifier (subsequences beginning with %). If the loop does encounters a % however, the additional arguments are formatted and inserted in the resulting string where their respective specifiers would have been. To view the many format identifier's, please refer to the image below:

<img width="521" alt="screen shot 2017-11-28 at 1 51 19 pm" src="https://user-images.githubusercontent.com/13093517/33346066-40ed8bb8-d443-11e7-8f9c-c36b3c6529e7.png">
*Note*

## Acknowledgement

printf_42 was developed at École 42 USA in Fremont, California
