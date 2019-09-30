#pragma once
#include <vector>
#include <string>
#include "Ingredients.h"
using namespace std;

/**********************************
   class that manage one Recipe.
   it stores its name, ingredients
   and cooking steps.
************************************/

class Recipe {

	string name;
	vector<Ingredients*> ingredients;
	vector<float> amount_ingredients;
	//cooking steps.
	string* step[];

public:

	//construct without any data.
	Recipe();
	//get array of Ingredients, float string and init.
	Recipe(string name, Ingredients* ingredients[], float amount[], string step[]);
	~Recipe();


	int find_ingredient(Ingredients* ingredient);
	int find_ingredient(string name);

	//ingredients[i];
	Ingredients* get_ingredient(int ingredient);

	//amount_ingredients[i];
	float get_amount(int ingredient);

	//amount_ingredients[i] = amount;
	void set_ingredient_amount(int i, float amount);
	void set_ingredient_amount(Ingredients* ingredient, float amount); 

	string get_name();
	(vector<Ingredients*>)* get_all_ingredients();

	string* get_step(int i);
	(vector<string>)* get_all_step();

	void set_name(string name);
	//step[i] = newStep
	void set_step(int i, string newStep);

	//print out all ingredients and steps onto cout.
	void print();

	//for file io.
	char* to_bytes();
	//for file io. if fail, return false
	bool from_bytes(char* bytes);
};