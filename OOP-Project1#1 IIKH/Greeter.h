#pragma once
#include "Recipe.h"
#include "RecipeDB.h"
#include "PlanManager.h"
#include <string>

using namespace std;
/*****************************
  Greeter Class does commmuncaite with user.
  It will process user input and display the result,
  using RecipeDB and PlanManager in its own methods.
*******************************/
class Greeter {
	RecipeDB* recipeDB;
	PlanManager* date;
public:
	Greeter(RecipeDB* recipeDB=NULL, PlanManager* manager=NULL);
	~Greeter();

	void main_menu();
	void recipe_menu();
	void plan_manager_menu();

	RecipeDB* get_recipeDB();
	Date* get_date(int year, int month, int day);
};