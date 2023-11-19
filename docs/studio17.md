# Studio 17
Studio Team members:
    Charlie Eicheman
    Ethan McCormick

2. To test my ImageFile class, I first passed correct input in the contents vector. Then I tested both bad characters and size mismatches, and both were handled as expected.
3. Programming to an interface allows us to use dynamic binding in client code to change what concrete class should be used without having to redefine existing functionality.
   Additional functionality can easily be added by adapting the implementation to work with a generic interface, ensuring that clients will always be compatible with shared methods.
4. To add file type compatibility to SimpleFileSystem, the createFile() method should be modified to support more file extensions. The rest of the code should be able to remain unmodified, as file creation is the only process that must parse the file type.

