# Studio 16
Studio Team members:
    Charlie Eicheman
    Ethan McCormick

2. a) You need to declare an abstract base class which includes a pure vital function.
3. a) interface inheritance
b)Private, as if we create them to be public, they will be accessible from the outside the class, and we want them to differ
when new objects of the same class are made. 
4. I created a new TextFile called file with the name "new file" and used the write method to add the char vector containing
"This is a new file" to it's contents. I then used read to print that to the console. This worked after I figured out how to
change the area containing my main method for building using the drop down menu in CLion.
5. int main(){
      //    TextFile file("newfile");
      AbstractFile& file = *(new TextFile("newfile"));
      vector<char> writingData = {'T', 'h', 'i', 's', ' ', 'a', ' ', 'n', 'e', 'w', ' ', 'f', 'i', 'l', 'e'};
      //    file.write(writingData);
      file.write(writingData);
      //    file.read();
      file.read();
      return 0;
      }