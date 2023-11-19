# Studio 21

2. Declaring a virtual destructor in the base class allows objects with dynamically inferred types to correctly link the right destructor for their inherited class.
   This is important because more specific types (i.e. children of the base class) might have their own resources that require specific attention in the destruction process.

3. The command prompt can easily be instantiated with different types of dependencies that conform to their respective interfaces, i.e. AbstractFileFactory, AbstractFileSystem, AbstractCommand.
   We need not rewrite the command prompt implementation to support new commands, only write them and pass them into an instantiated CommandPrompt object.

4. Using the command prompt environment with quitting, asking for help, and asking for help on specific commands worked as expected.
   However, when trying to add a file to the filesystem, nullptr was returned by the touch method. Modifications to the way it parsed input and notified the user of non-success conditions needed tweaking.
   Once touch worked correctly, the file was able to be accessed using the underlying filesystem via getName().