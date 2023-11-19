# Studio 19

Team Members: Ethan McCormick, Charlie Eichman 

2. I created a file called testFile that took a name file named test.txt. I created a vector of chars called 
fileContents that contained the sentence "This is the test file", wrote it to the testFile object using 
.read(fileContents), and then read to a local variable readFile using .read() on the testFile object. I then printed
this out by interating through the readFile variable and printing its contents out to the console. I modified the
fileContents vector to now say "This is not the test file", and wrote it to the same testFile object using 
.write(fileContents). I created a new local variable called readFileAfterEdit, read the testFile using .read() to that
variable, and then printed its contents. The result was:
Before edit: This the test file
After edit: This not the test file

Process finished with exit code 0

3. WE have the abstract file visitor which has two separate member functions for each of the files we want to visit, that
   take a pointer to the files, allowing us to access their memory location. Abstract file then has an accept member function that
   takes a pointer to our filevisitor, allowing us to access the member functions of abstractfilevisitor within our abstract files.
   We define accept within our imageFile and textFile, so that the visitor can access those derived classes specifically. This
   allows the visitor to communicate with the concrete file types. 

4. Delegation is the passing of one task from one object to another. Visitor allows you to add new  functionality granted
   by the visitor without having to add anything to the visited class, which allows them to have less clutter interfaces. 

5. If we have many different types of file visitor, supporting a new file type means we have to edit the functionality of all
the visitor classes to handle the new type.
