#pragma once
#include "Recipe.h"
#include "RecipeDB.h"
#include <string>

using namespace std;

class Greeter {
	RecipeDB recipeDB;
public:
	Greeter();
	~Greeter();

	//get single keyword string and find all Recipe matches to it.
	RecipeDB searchRecipe(string keyword);
	//get array of keyword string and find intersection of searchRecipe(keyword[0]) and searchRecipe(keyword[1]) and so on.
	RecipeDB seearchRecipe(string* keyword, size_t length);
	
	//calls recipeDB.addRecipe(newRecipe);
	void addRecipe(Recipe newRecipe) { recipeDB.add_recipe(newRecipe); }
};