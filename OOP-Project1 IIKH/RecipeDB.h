#pragma once
#include <vector>
#include "Recipe.h"
class RecipeDB {
	std::vector<Recipe> recipeV;
public:
	int search(string keyword);
	int* search_all(string keyword);

	int search_ingredients(string keyword);
	int search_ingredients(Ingredients ingredients);

	Recipe get_ith_recipe(int i);
	void add_recipe(Recipe recipe);
	void remove(int i);
	
	void print_ith_recipe(int i) { get_ith_recipe(i).print(); };

};