#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Film
{
    string filmname;
    string director;
    string genre;
    float rating;
    float price;

};

vector<Film> films;

void displayFilm(Film& film);
void addNew(Film& films);
void searchByName(string filmName);
void searchByGenre(string genre);
void searchByDirector(string director);
void popularInGenre(string genre);
void showAll();
void Menu();

int main()
{
    Menu();
    return 0;
}

void displayFilm(Film& film)
{
    cout << "Title: " << film.filmname << endl;
    cout << "Director: " << film.director << endl;
    cout << "Genre: " << film.genre << endl;
    cout << "Price: " << film.price << endl;
    cout << "Rating: " << film.rating << endl;
    cout << endl;
    
}

void addNew(Film& film)
{
    films.push_back(film);
}

void showAll()
{
    cout << "List of all films: " << endl;
    for (auto& film : films)
        displayFilm(film);
    cout << endl;
}

void searchByName(string filmName)
{
    cout << "Search result for title " << filmName << ": " << endl;
    for (auto& film : films)
    {
        if (film.filmname == filmName)
            displayFilm(film);
    }
}

void searchByGenre(string genre)
{
    cout << "Films in genre " << genre << ": ";
    for (auto& film : films)
        if (film.genre == genre)
            displayFilm(film);
    cout << endl;
}

void searchByDirector(string director)
{
    cout << "Films by director " << director << ":" << endl;
    for (auto& film : films)
        if (film.director == director)
            displayFilm(film);
}

void popularInGenre(string genre)
{
    vector<Film> filtered;
    copy_if(films.begin(), films.end(), back_inserter(filtered), [genre](Film& a) {return a.genre == genre; });
    cout << "The most popular film in genre " << genre << ": ";
    auto maxrating = max_element(films.begin(), films.end(), [genre](Film& a, Film& b) {
        return a.rating < b.rating;
        });
    Film result = *maxrating;
    displayFilm(result);
}

void Menu()
{
    int menuItem;
    string filmName, genre, director;
    float price = 0, rating = 0;
    while(true) {
        cout << "1. Add new film.\n";
        cout << "2. Search film by name.\n";
        cout << "3. Search film by genre.\n";
        cout << "4. Search film by director.\n";
        cout << "5. Popular in chosen genre.\n";
        cout << "6. Display all films.\n";
        cout << "0. Exit.\n";
        cin >> menuItem;

        switch(menuItem)
        {
        case 0:
            return;

        case 1:
	        {
	            cout << "Write title name: ";
	            cin >> filmName;
	            cout << "Write director: ";
	            cin >> director;
	            cout << "Write genre of the film: ";
	            cin >> genre;
	            cout << "Write rating of the film: ";
	            cin >> rating;
	            cout << "Write price for the film: ";
	            cin >> price;
	            Film film1 = { filmName, director, genre, rating, price };
	            addNew(film1);
	        }
            break;

        case 2:
	        {
        		cout << "Write film name: ";
	            cin >> filmName;
	            searchByName(filmName);   
	        }

            break;

        case 3:
	        {
		        cout << "Write genre of the film: ";
	            cin >> genre;
	            searchByGenre(genre);
	        }
            break;
        case 4:
	        {
	            cout << "Write director: ";
	            cin >> director;
	            searchByDirector(director);
	        }
            break;
        case 5:
	        {
	            cout << "Write genre to find the most popular film in genre: ";
	            cin >> genre;
	            popularInGenre(genre);
	        }

            break;
        case 6:
            showAll();
            break;

        default:
	        {
				cout << "No such function!" << endl;
	        }
            break;
        }
    }
}