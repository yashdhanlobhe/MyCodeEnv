#include <bits/stdc++.h>
using namespace std;


int mstrcmp(char *a , char *b){
	while(*a != '\0' &&  *a == *b){
		a++;
		b++;
	}
	return *a - *b;
}

void mmemset(void* starting , char c , int size){
	char *ch = (char*) starting;
	for (int i = 0; i < size; ++i)
	{
		*ch = c;
		 ch++;
	}
}
// memmove() is similar to memcpy() as it also copies data from a source to destination.
// memcpy() leads to problems when source and destination addresses overlap as memcpy().
// simply copies data one by one from one location to another.For example consider below program. 

// suppose we are coping data to same location then updated value will updated
// ex memcpy(c1 , c1 + 5 , n) here we will start coping c1 to c1 5 so c1+5 will lost the data
// in memmove() we will make copy if first and then copy

void myMemCpy(void *dest, void *src, size_t n)
{
	// Typecast src and dest addresses to (char *)
	char *csrc = (char *)src;
	char *cdest = (char *)dest;
	 
	// Copy contents of src[] to dest[]
	for (int i=0; i<n; i++)
    cdest[i] = csrc[i];
}

void myMemMove(void *dest, void *src, size_t n)
{
	// Typecast src and dest addresses to (char *)
	char *csrc = (char *)src;
	char *cdest = (char *)dest;
	 
	// Create a temporary array to hold data of src
	char *temp = new char[n];
	 
	// Copy data from csrc[] to temp[]
	for (int i=0; i<n; i++)
	    temp[i] = csrc[i];
	 
	// Copy data from temp[] to cdest[]
	for (int i=0; i<n; i++)
	    cdest[i] = temp[i];
	 
	delete [] temp;
}

//	malloc(): It is a C library function that can also be used in C++, while the “new” operator is specific for C++ only. 
// 	Both malloc() and new are used to allocate the memory dynamically in heap. But “new” does call the constructor of a class whereas “malloc()” does not.
//  A* b = (A*)malloc(sizeof(A));
//	A* a = new A;

// free() is a C library function that can also be used in C++, while “delete” is a C++ keyword.
// free() frees memory but doesn’t call Destructor of a class
// whereas “delete” frees the memory and also calls the Destructor of the class.


int main() {
	char d[10];
	// char c[10] = "yash";
	mmemset(d , 'a' , 9);
	cout<<d;
    return 0;
}

