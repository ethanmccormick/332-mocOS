# Studio 20

2. The AbstractFile* member field must be deleted in order to avoid memory leaks when a proxy object goes out of scope.

4. A text file was dynamically allocated and passed to the password proxy constructor. Via the proxy, the file was written to and read from, with the correct password.
   Via the command prompt, both operations were successfully canceled when the password was incorrect.

5. All unit tests passed on the first run.