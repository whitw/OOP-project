#pragma once
#include <map>
#include <string>

using namespace std;
/*
Ingredients class
map<string type_of_nutrients, float grams(per 100g)> nutrients
price(per 100g)
calories(per 100g)
*/
class Ingredients {
	string name;
	//grams per 100grams
	//nutrients.find("carbohydrate") => 30.0f
	//--> 30 grams in total 100 grams.
	map<string, float> nutrients;
	
	//$ per 100g
	//get_price() => 3.0f
	//--> 3$ per 100gram
	float price;
	//kcal per 100g
	float calories;
public:
	Ingredients(string name, map<string, float> nutrients, float price, float calories);
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
