#pragma once
#include "Recipe.h"
#include "RecipeDB.h"
#include "PlanManager.h"
#include <string>

using namespace std;

class Greeter {
	RecipeDB* recipeDB;
	PlanManager* date;
public:
	Greeter(RecipeDB* recipeDB=NULL, PlanManager* manager=NULL);
	~Greeter();

	void main_menu();
	void recipe_menu();
	void plan_manager_menu();

	RecipeDB* get_recipeDB(string recipe);
	Date* get_date(int year, int month, int day);
};