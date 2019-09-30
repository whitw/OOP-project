#pragma once
#include <vector>
#include <string>
#include "Ingredients.h"
using namespace std;

class Recipe {
	//<Ingredients = ingredients, float = gram>
	vector<pair<Ingredients*, float>> ingredients;
	//cooking steps.
	vector<string> step;

public:

	//without any data.
	Recipe();
	//get array of Ingredients, float string and init.
	Recipe(Ingredients* ingredients, float* amount, string* step);
	Recipe(vector<pair<Ingredients*, float>> ingredients, vector<string> step);
	~Recipe();


	//ingredients[i].first == ingredient
	int find_ingredient(Ingredients* ingredient);
	//ingredients[i].first.get_name() == name;
	int find_ingredient(string name);
	//ingredients[i].first;
	Ingredients* get_ingredient(int ingredient);
	//ingredients[i].second;
	float get_amount(int ingredient);
	//ingredients[i].second = amount;
	void set_ingredient_amount(int i, float amount);
	//find ingredient and set amount if it as float amount.
	void set_ingredient_amount(Ingredients* ingredient, float amount); 

	vector<Ingredients*> get_all_ingredients();
	string* get_step(int i);
	vector<string>* get_all_step();

	//step[i] = newStep
	void set_step(int i, string newStep);

	//print out all ingredients and steps onto cout.
	void print();

	//for file io.
	char* to_bytes();
	//for file io. if fail, return false
	bool from_bytes(char* bytes);
};