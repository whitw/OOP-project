#pragma once
#include <vector>
#include <string>
#include "Ingredients.h"
using namespace std;

class Recipe {
	//float stands for the mass of each ingredients.
	vector<pair<Ingredients, float>> ingredients;
	//cooking steps.
	vector<string> step;
public:
	//step[i]
	string get_step(int i);
	//works simmilar to (string*)step
	string* get_all_step();
	//step[i] = newStep
	void set_step(int i, string newStep);
	//find(ingredients)
	Ingredients find_by_ingredient(string ingredient);
	//print out all ingredients and steps onto cout.
	void print();

	Ingredients get_ingredient(int i);
	Ingredients* get_
};




/*
memo

It replaces box of index cards of recipes
Assist in the planning of meals for, say a week.

browse the db of recipe by multiple words
add new recipe
edit, or annotate recipe
review a plan for
create a series of menus
scale the recipes to any number of servings
print out menus for the entire week, particular day, particular meal.
Integrated grocery list of all the items needed for the recipes for the entire period

*/