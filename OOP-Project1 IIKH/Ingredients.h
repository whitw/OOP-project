#pragma once
#include <string>

using namespace std;
/****************************
    class that represents
	a kind of ingredients.

	It doesn't store any
	data about informations,
	but it stores percentage
	of nutrients,
	calories, and prices.

****************************/
class Ingredients {
	string name;
	//grams per 100grams
	//if nutrient_name[1] == new string("Protein");
	//and nutrient_amount[1] == 30.0f then
	//--> 30 grams in total 100 grams.
	string* nutrient_name;
	float* nutrient_amount;
	
	//$ per 100g
	//get_price() => 3.0f
	//--> 3$ per 100gram
	float price;
	//kcal per 100g
	float calories;

public:
	Ingredients(string name, string nutrient_names[], float nutrients_amount[], float price, float calories);
	~Ingredients();
	string get_name();
	float get_price();
	//e.g. get_nutrient("protein");
	//if fail, return -1.0f
	float get_nutrient(string nutrient);
	float get_calories();

	//false if fail(amount < 0 or something like that...)
	bool set_name(string name);
	bool set_nutrient(string nutrient, float amount);
	bool set_price(float price);
	bool set_calories(float calories);

	void print();
	//for file io
	char* to_bytes();
	//for file io
	//false if bytes are not valid
	bool from_bytes(char* bytes);
};
