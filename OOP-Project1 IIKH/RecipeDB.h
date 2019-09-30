#pragma once
#include <vector>
#include "Recipe.h"

using namespace std;
class RecipeDB {
	vector<Recipe*> recipeV;
public:
	RecipeDB();
	RecipeDB(vector<Recipe*> recipes);
	//keyword in recipeV[i].name or their ingredients
	//return first value of the result.
	int search(string keyword);
	//return array of int.
	int* search_all(string keyword);

	//find Recipe with ingredient named keyword and return index of it
	int search_ingredients(string keyword);
	//find Recipe with Ingredients ingredient and return index of it
	int search_ingredients(Ingredients ingredient);

	//recipeV[i]
	Recipe* get_ith_recipe(int i);
	//recipeV.push_back(recipe)
	void add_recipe(Recipe* recipe);
	//recipeV.erase(i)
	void remove(int i);
	
	//print recipeV[i]
	void print(int i) { get_ith_recipe(i)->print(); };
	//print recipeV
	void print();

};