**File manager (web version)**

Common object:

- Folder object
- Raw text object
- Zip object
- ....
- Will be scaled in the future

**Object** (frame):

- info:
  - permission: string
  - type: string, size: int
  - location: string
  - modified: string, accessed: string

- act:
  - open
  - ~~move to trash~~ , delete →[remove(3): remove file/directory](https://linux.die.net/man/3/remove)
  - create archive →[C: Run a System Command and Get Output?](https://stackoverflow.com/questions/646241/c-run-a-system-command-and-get-output)
  - rename →[C Language: rename function (Rename File)](https://www.techonthenet.com/c_language/standard_library_functions/stdio_h/rename.php)

**File manager:**

- act → (base on other object):
  - create blank text →[C Files I/O: Opening, Reading, Writing and Closing a file](https://www.programiz.com/c-programming/c-file-input-output)
  - open
  - move to trash, delete
  - copy [save to self clipboard]
  - paste
    - using system or popen
  - create archive
  - send to (will be scaled)
  - rename
  - cd to another path → [chdir() in C language with Examples](https://www.geeksforgeeks.org/chdir-in-c-language-with-examples/)
- info:
  - selected file: string
  - virtual clipboard: string

**Path** : [path.h](https://github.com/shanenoi/Foliage/blob/master/path.h) 👌

- act:
  - get current permission of a file
    - →[Is there a C function to get permissions of a file?](https://stackoverflow.com/questions/20238042/is-there-a-c-function-to-get-permissions-of-a-file)
    - →[How to read linux file permission programmatically in C/C++](https://stackoverflow.com/questions/8812959/how-to-read-linux-file-permission-programmatically-in-c-c)
  - type, size ^
    - Above ||
  - modified, accessed ||
    - Above ||
- info:
  - link
