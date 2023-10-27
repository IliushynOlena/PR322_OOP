#pragma once
#include <iostream>
using namespace std;
/*
const int None = 1;
const int Detective = 2;
const int Adventury = 3;
const int Drama = 4;
const int Comedy = 5;
const int History = 6;
const int Horror = 7;
const int Science = 8;
const int Biography = 9;
const int Roman = 10;
const int FairyTale = 11;
const int Thriller = 12;*/

enum Genre{ None = 1, Detective, Adventury, Drama, Comedy, History, Horror ,
         	Science, Biography, Roman, FairyTale , Thriller};

class Book
{
private:
	string title;
	string author;
	int pages;
	int year;
	Genre genre;
public:
	Book();
	Book(string t, string a, int p, int y, Genre g) :title(t), author(a), pages(p), year(y),
		genre(g) {}
	void ShowInfo()const;

	
};

