#pragma once
#include <vector>
#include "RecipeDB.h"
using namespace std;

/*********************
   class Meal
   represents a meal.
   It stores list of foods
   as type as RecipeDB;

   It supports add/find/delete
   scale (by n times)/ print
**********************/
class Meal {
	RecipeDB* meal;
public:
	//create Meal with new RecipeDB
	Meal();
	//create Meal using exist RecipeDB
	Meal(RecipeDB* meal);
	~Meal();

	void print();
	void add_menu(Recipe* recipe);
	RecipeDB* get_all_menu();
	Recipe* find_menu(string title);
	vector<Ingredients*> get_all_ingredients();
	void delete_menu(string title);
};