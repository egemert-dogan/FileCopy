/*
 *	Written in NVim
 */

#include <stdio.h>
#include <stdlib.h>
//unistd MAY NOT work on Windows. You may want to change 'unistd.h' to 'io.h'
#include <unistd.h>
  
int main()
{
    // Define first and second file 
    FILE *file1, *file2;
    // Define file name and the content
    char fileName[1000], content;
  
    printf("Please enter the name of the file to open for reading: ");
    scanf("%s", fileName);
    
    // Check if the file exists
    if (access(fileName, F_OK) == 0) {
    	// Open the first file for reading
    	file1 = fopen(fileName, "r");
	if (file1 == NULL)
	{
	    printf("Couldn't open file %s \n", fileName);
	    exit(0);
	}
        printf("Please enter the name of the file to open for writing: ");
	scanf("%s", fileName);
  	// Open the second file for writing
	file2 = fopen(fileName, "w");
	if (file2 == NULL)
	{
	    printf("Cannot open file %s \n", fileName);
	    exit(0);
	}
  
	// Read content(s) from the first file
	content = fgetc(file1);
	// Check if content is empty
	while (content != EOF)
	{
	    // Writing content(s)
	    fputc(content, file2);
	    content = fgetc(file1);
        }
  	printf("\nContent(s) have been successfully copied to %s", fileName, "\n");
	// Close the first file
        fclose(file1);
	// Close the second file
	fclose(file2);
	return 0;

    }
    // If the first file does not exist
    else {
    	printf("There is no such file or directory named %s", fileName, "\n");
	exit(0);
    }
}
