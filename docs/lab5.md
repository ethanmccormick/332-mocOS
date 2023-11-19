# Lab 5

After completing the lab through item #8, I decided to run the unit tests to make sure all functionality was working as intended. Multiple failures were indicated, and the first I decided to investigate was
a return value of 1 from TouchCommand.execute(filename + " -p"). This was because the function didn't correctly separate the the filename from the -p option, so a ' ' delineator was added to the getline call inside.

Next, I decided to investigate an error in DSCommand. Somehow, LSCommand.execute() returned a 1, and I found that it was because I had forgotten to include return statements.
The next error I found within LSCommand was due to some extra formatting I had placed in the metadata display which the unit test parsed as incorrect. I removed this so that the output matched the lab example, which required an edit of MetadataDisplayVisitor.
I also found an error in which the files manipulated by LSCommand were not closed after having been accessed, so I fixed this as well.

I then moved on to CatCommand where the input to a file didn't seem to match its output, instead having an extra \n appended at the end. This was due to the way I decided to store input before it was saved to the file.
I manually removed this extra newline, and the tests passed.

DisplayCommand also suffered from the files-not-closed bug, so I added code to close the files before DisplayCommand.execute() returned.
I had also forgotten to post a newline to cout after the file was done displaying, and this fixed its final error.

CopyCommand also needed its reference file closed, so this was fixed.

The rest of the errors were in the rename macro, the first of which being that the arguments for the copy command had an extra space at the end. I fixed this by adding a ' ' delimiter to the getline() parser.
The same error for the remove command was present, so I changed both getline() calls to include a ' ' delimiter.
Additionally, the tests indicated that the second file was never removed. I found that this was because MacroCommand.execute() had its return statement inside the for loop over its commands vector, causing it to return before the old file was removed. I moved the return statement to the end of the function.


Now that all test cases were passing, I decided to implement a new MacroCommand called edit to both append (using cat -a) and display (ds) a file in one macro. I declared and defined a new AbstractParsingStrategy called EditParsingStrategy which automatically passes the option -a of the cat command.
The parser passes <filename> -a to the cat command, and <filename> (with correct formatting , so no -d option) to the ds command.
While testing the macro, it failed to execute succesfully in the command prompt. I decided to investigate by using cat by itself.
I then found that the cat command left the file open, making future file access by any command impossible. Fixing this solved the problem.
Bugs in the command prompt's parsing routine prohibited input of multiple strings, so I solved this with getline() delimiters as previously.
All functions now worked as expected.





