// CSCI 340
// Project 1
// Swapnil S 
// Meena R


//////////////////////////////////////
//Include Statements
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>
 
//////////////////////////////////////


// struct that holds all of the process information
struct proc{
	int pid;
	int ppid;
	char name[32];
	unsigned long vsize;
};

//////////////////////////////////////////////////////

//Function that determines whether a string contains only numbers.
int numbersOnly(const char *s)
{
    while (*s) {
        if (isdigit(*s++) == 0) return 0;
    }

    return 1;
}

//////////////////////////////////////////////////////

int main(){
	struct dirent *directory;
	int counter = 0;
	DIR *processDirectory = opendir("/proc");
	

	while ((directory = readdir(processDirectory)) != NULL)

		//checks to see if the process name is made up of numbers
		if(numbersOnly(directory->d_name)){
			counter = counter + counter;
		}
	closedir(processDirectory);

	//Init the index variable that will be used later to help with information storage.
	int index = 0;

	//list struct array
	struct proc list[counter];
	
	//opens directory
	processDirectory = opendir("/proc");

	//while directory has next entry...
	while ((directory = readdir(processDirectory)) != NULL){
		//if name only contains numbers...
		if (numbersOnly(directory->d_name)){
			int pid;
			int ppid;
			unsigned long vsize;
			char *name[32];
			char processPath[267];
			
			//writes directory name into path
			sprintf(processPath, "/proc/%s/stat", directory->d_name);
			FILE *stream = fopen(processPath, "r");


			//This is causing a weird message, and I don't know how to fix it, but it doesn't break it, so it's fine for now. :)
			fscanf(stream, "%d %s %*s %d %*d %*d %*d %*d %*u %*u %*u %*u %*u %*u %*u %*d %*d %*d %*d %*d %*d %*u %lu", &pid, name, &ppid, &vsize);

			//Stores all of the data
			list[index].pid = pid;
			list[index].ppid = ppid;
			strcpy(list[index].name, name);
			list[index].vsize = vsize;
			index = index + 1;
			//There was a weird duplication of code here that I took out.
		}

	}
	

	


}



