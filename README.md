# CS210AirgeadBanking
Project completed in CLion as part of CS210: Programming Languages at SNHU. Takes a number of years, initial investment amount, monthly deposit amount, and annual interest rate. It returns a table of account balances compounded yearly both with and without monthly deposits. It has a menu for changing any value and reprinting the tables.

Account.h and Account.cpp: comprise the Account class which holds and calculates values. Values are stored in a vector.

UserInterface.h and UserInterface.cpp: holds various functions which print the tables, menu, and overall user interface.

## Reflection

  Summarize the project and what problem it was solving. 
  
  * This project displays a table representing a bank account with yearly balances and amount gained through interest. The user enters the initial value, annual interest rate, monthly deposit amount, and number of years to be calculated. The user can change any particular value and reprint the tables. 
    
  What did you do particularly well?
  
  * For my very first time ever using multiple files for a single project, I think I did well with modularizing the program. I tend to get frustrated with formatting output and give up on it entirely, but for this project I powered through and it turned out very nicely. 
    
  Where could you enhance your code? How would these improvements make your code more efficient, secure, etc?
  
  * While the project requirements did not specify monthly or yearly compounding, I could add a monthly compounding option. I think that main() could be at least partially refactored into the other files in order to make main() more readable. 
    
  Which pieces of code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
  
  * The most challenging code was the output formatting, which I overcame with trial and error mostly. The resources I have recently added to my arsenal include w3schools for keyword referencing, cplusplus.com for library referencing, and stack overflow for bugs and solutions
  * I have also begun a list of bugs I have encountered and had a hard time figuring out alongside their solutions. For example, in this project I attempted to have this line inside a switch/case `int inputINT = <static_cast>(int) input;` but the compiler throws an error when a variable is declared and assigned a value through a function inside a switch/case. The solution is declaring the variable outside of the switch/case. This took too long to figure out the first time, and as such is now on my "list of bugs no one tells you about".
    
  What skills from this project will be particularly transferable to other projects or course work?
  
  * I have certainly learned a lot about output formatting from this project, which will be very useful in future projects. Modularizing the project was also a new experience, and is certainly prevalent to many coding languages. 
    
  How did you make this program maintainable, readable, and adaptable?
  
  * This program is maintainable because it has separate files for the UI and the value storage and calculation. It is readable with inline comments and this ReadMe. It is adaptable since features can easily be added or removed without altering the entire data structure. 
