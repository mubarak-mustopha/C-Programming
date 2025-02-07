## Arrays And Pointers


### Starter Note
Array variables are nothing but pointers to the memory location of the first element of the array.

```
 char * letters = {'A','B','C','D','E','F'};
\\letters -> pointer to 'A'
(letters + i) == &letters[i] \\ == (memory location of ith element of the Array)
*(letters + i) == letters[i]  \\ == (ith element of the Array)

```