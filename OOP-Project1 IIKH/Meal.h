#pragma once
#include <vector>
#include "RecipeDB.h"

using namespace std;
class Meal {
	RecipeDB* meal;
public:
	Meal();
	Meal(RecipeDB* meal);
	~Meal();

	void print();
	void add_menu(Recipe* recipe);
	RecipeDB* get_all_menu();
	Recipe* find_menu(string title);
	vector<Ingredients*> get_all_ingredients();
	void delete_menu(string title);
	void scale(int people);
};