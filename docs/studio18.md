# Studio 18

2. Every concrete implementation of AbstractFileSystem would have to modify its createFile method to support files of additional types. Additional implementations would all have to be modified when even a single new file type is added.

3. The file factory approach requires client code to use different concrete implementations in every environment where a unique set of file types should be supported.
   Therefore, a new implementation would be needed wherever a different set of types should be supported, but the same implementation can be reused in other cases.
   To add to the set of supported types, the createFile method must be modified.

4. We tested creating, opening, writing to, and reading files created by the SimpleFileFactory that had been added to the filesystem. The contents of the modified files were output to the console via read(), and behaved as expected.

5. At this point, the filesystem depends only on the AbstractFile interface (as objects of such type are created by the factory), not the actual concrete file implementations themselves.

