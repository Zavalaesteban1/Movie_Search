/////////////////////////////////////////////////////////////////////
//
// Name: Esteban Zavala
// Date: 4/25/28
// Class: CSCI 1470.06
// Semester: Spring 2023
// CSCI 1470 Instructor: Gustavo Dietrich
//
// Program Description: Enter here your description of what the program does
//
/*




*/
/////////////////////////////////////////////////////////////////////

#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>

using namespace std;

const int MOVIES_SIZE = 20;


// Declare a struct named Movie with 3 members for:
// title, year released, and revenue
struct Movie
{
	string title;
	int year;
	int revenue;
};


// Enter here your function prototypes
void storeMoviesArray(ifstream & inFile, Movie topMovies[], const int SIZE);
void sortMoviesTitle(Movie topMovies[], const int SIZE);
void printMoviesArray(Movie topMovies[], const int SIZE);
int findMovieTitle(const Movie topMovies[], const int SIZE, string title);


int main()
{
// main() starts here

	// Declare file variable
	ifstream inputFile;
	// Open file Movies.txt
	inputFile.open("Movies.txt");
	// Check if file was opened
	if(!inputFile)
	{
		cout << "Error opening input file" << endl;
		return 1; 
	}
	// Declare array of movies
	Movie topMovies[MOVIES_SIZE];
	// Declare auxiliary variables
	int found; 
	string title; 
	char answer;
	// Read the information from the movies file and store it in the array
	storeMoviesArray(inputFile, topMovies, MOVIES_SIZE);
	// Sort the array by the movie title so the binary search can be used 
	sortMoviesTitle(topMovies, MOVIES_SIZE);
	// Start the loop
	do
	{
		// Clear the screen
		system("clear");
		// Print the movies array
		printMoviesArray(topMovies, MOVIES_SIZE);
		// Ask the user to input a title
		cout << endl << "Enter a movie title: ";
		cin >> title; 
		// Find the index of the movie that the user chooses
		found = findMovieTitle(topMovies, MOVIES_SIZE, title); 
		// If the movie was not found
		if(found == -1)
		{
		// Print the message indicating the title was not found
			cout << endl << endl << title << " was not found" << endl;
		}
		// Otherwise
		else
		//		Print the information about the chosen movie
		{
			cout << endl << endl << "Title: " << topMovies[found].title << endl;
			cout << "Year Released: " << topMovies[found].year << endl;
			cout << "Revnue: " << "$" << topMovies[found].revenue << endl; 
		}
		// Ask the user "Do you want to continue? (y/n): "
		cout << endl << "Do you want to contunie? (y/n): ";
		// Get the answer
		cin >> answer; 
	// Continue looping while the answer is 'y'
	}while(answer == 'y');
	// Close the file
	inputFile.close();
// main() ends here
}

// Function definitions start here


// This function receives the input file, the movies array, and the size of the 
// array. 
// It reads from the file the movie data and stores it in the array.
// Once all the data has been read in, it returns the array with the information 
// of the movies.
void storeMoviesArray(ifstream & inFile, Movie topMovies[], const int SIZE)
{
	// counter
	int i;

	// for loop to get each value from the file and store them in their corresponding memebers
	for(i = 0; i < SIZE; i++)
	{
		inFile >> topMovies[i].title >> topMovies[i].year >> topMovies[i].revenue;

	}
}



// This function receives the movies array and the size of the array and sorts
// the array by title. It returns the sorted array.
void sortMoviesTitle(Movie topMovies[], const int SIZE)
{
	// declare variable temp to hold the temporialy name
	Movie temp;
	// loop contrller to control outter and inner loops
	int i, j;
	// outter and inner loops
	for(i = 0; i < SIZE; i++)
	{
		for(j = 0; j < SIZE - 1; j++)
		{
			if(topMovies[j].title > topMovies[j + 1].title)
			{
				temp = topMovies[j];
				topMovies[j] = topMovies[j + 1];
				topMovies[j + 1] = temp; 
			}
		}

	}

}



// This function receives the movies array and the size of the array and prints
// the list of movies.
void printMoviesArray(Movie topMovies[], const int SIZE)
{
	// counter
	int i; 

	// Display title, year, and revenue
	cout << setw(38) << "Movie title " << "Year" << setw(11) << "Revenue" << endl << endl;

	// loop through each index and print the elements
	for(i = 0; i < SIZE; i++)
	{
		cout << setw(37) << topMovies[i].title << " " << topMovies[i].year << " $" << setw(10) << topMovies[i].revenue << endl;
	}
}



// This function receives the movies array, the size of the array, and the title
// of the movie to be searched for.
// It returns the index of the array where the title was found. If the title was 
// not found, it returns -1. It must use BINARY SEARCH to find the movie.
int findMovieTitle(const Movie topMovies[], const int SIZE, string title)
{
	int first = 0;
	int last = SIZE - 1;
	int middle;
	int pos = -1;
	bool found = false;

	while(!found && first <= last)
	{

		middle = (first + last) / 2;

		if(topMovies[middle].title == title)
		{
			pos = middle;
			found = true;

		}
		else if(topMovies[middle].title > title)
		{
			last = middle - 1;
		}
		else
		{
			first = middle + 1;
		}
	}
	return pos; 
}
